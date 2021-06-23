/*
 * wrapper.c
 *
 *  Created on: 19 juin 2019
 *      Author: dimercur
 */

#include "stm32746g_discovery.h"
#include "wrapper.h"
#include "panic.h"

#include "stm32746g_discovery_acc_gyro.h"
#include "stm32746g_discovery_eeprom.h"
#include "stm32746g_discovery_keys.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_mag.h"
#include "stm32746g_discovery_rng.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_ts.h"

//#include "GUI/progressbar.h"
//#include "GUI/window.h"
/*#include "audio-synth/audio.h"
#include "audio-synth/audio-synth.h"
#include "audio-synth/audio-melody.h"*/

//#include <math.h>
#include "version.h"

#define LEGACY_LCD_WIDTH 	320
#define LEGACY_LCD_HEIGHT	240

#define RK043FN48H_WIDTH 480
#define RK043FN48H_HEIGHT 272
/*ALIGN_32BYTES (AUDIO_BufferTypeDef  AUDIO_Buffer);// __attribute__((section("DMA_BUFFERS")));
AUDIO_EventCallback AUDIO_Callback;*/

#define HORIZONTAL_COORD_CONVERSION(x) (((RK043FN48H_WIDTH-LEGACY_LCD_WIDTH)/2)+x)
#define VERTICAL_COORD_CONVERSION(y) (((RK043FN48H_HEIGHT-LEGACY_LCD_HEIGHT)/2)+y)

#define ABS(x) (x>=0 ? x: -x)

extern const uint32_t _legacysram_start; // Define allocated sram block used to simulate external ram in legacy system

float val[3]={0.0,0.0,0.0};
acceleration_t acc;
magnetic_t mag;
angularRate_t ang;

TIM_HandleTypeDef LegacyTimHandle;
TIMER_EventCallback LegacyTimerCallback=0x0;

/*MELODY_Status MELODY_Init(void);*/

void API_GetOSVersion(int* major, int* minor)
{
	*major = BL_MAJOR_VERSION;
	*minor = BL_MINOR_VERSION;
}

/**
 * Init function for legacy wrapper, in charge of initializing Timer 7, for example
 */
void WRAPPER_Init (void) {
	RCC_ClkInitTypeDef    clkconfig;
	uint32_t              uwTimclock, uwAPB1Prescaler = 0U;
	uint32_t              uwPrescalerValue = 0U;
	uint32_t              pFLatency;
	//uint8_t  			  status = 0;

	/* Configure the TIM7 IRQ priority */
	HAL_NVIC_SetPriority(TIM7_IRQn, 0xFU ,0U);

	/* Enable the TIM7 global Interrupt */
	HAL_NVIC_EnableIRQ(TIM7_IRQn);

	/* Enable TIM7 clock */
	__HAL_RCC_TIM7_CLK_ENABLE();

	/* Get clock configuration */
	HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);

	/* Get APB1 prescaler */
	uwAPB1Prescaler = clkconfig.APB1CLKDivider;

	/* Compute TIM7 clock */
	if (uwAPB1Prescaler == RCC_HCLK_DIV1)
	{
		uwTimclock = HAL_RCC_GetPCLK1Freq();
	}
	else
	{
		uwTimclock = 2*HAL_RCC_GetPCLK1Freq();
	}

	/* Compute the prescaler value to have TIM7 counter clock equal to 1MHz */
	uwPrescalerValue = (uint32_t) ((uwTimclock / 1000000U) - 1U);

	/* Initialize TIM7 */
	LegacyTimHandle.Instance = TIM7;

	/* Initialize TIMx peripheral as follow:
	  + Period = [(TIM7CLK/100) - 1]. to have a (1/100) s time base.
	  + Prescaler = (uwTimclock/100000 - 1) to have a 0.1MHz counter clock.
	  + ClockDivision = 0
	  + Counter direction = Up
	 */
	LegacyTimHandle.Init.Period = (1000000U / 100U) - 1U;
	LegacyTimHandle.Init.Prescaler = uwPrescalerValue*10;
	LegacyTimHandle.Init.ClockDivision = 0;
	LegacyTimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	LegacyTimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	if(HAL_TIM_Base_Init(&LegacyTimHandle) == HAL_OK)
	{
		/* Start the TIM time Base generation with interrupt disabled  */
		HAL_TIM_Base_Start(&LegacyTimHandle);
	}

	/* Init audio */
	/*AUDIO_Callback =0x0;
	AUDIO_Init();*/

	/* Init Melody timer */
	//MELODY_Init();
}

uint32_t WRAPPER_ColorConvertion_32bpp (COLOR color) {
	uint32_t val;

	if (color == 0xFF) val = 0xFFFFFFFF;
	else
	{
		/* Convertion 3:3:2 to 8:8:8:8 */
		val = (uint32_t)0xFF000000 | (((uint32_t)(color&0xE0))<<16) | (((uint32_t)(color&0x1C))<<11) | (((uint32_t)(color&0x03))<<6);
	}

	return val;
}

uint16_t WRAPPER_ColorConvertion_16bpp (COLOR color) {
	uint16_t val;

	if (color == 0xFF) val = 0xFFFF;
	else
	{
		/* Convertion 3:3:2 to 5:6:5 */
		val = (((uint16_t)(color&0xE0))<<8) | (((uint16_t)(color&0x1C))<<6) | (((uint16_t)(color&0x03))<<3);
	}

	return val;
}

// Basic OS services
// void API_InvalidFunction(void)
// Already defined in abi-table.c

void Delay(volatile uint32_t nTime) {
	HAL_Delay(nTime);
}

// Keys services
KEY_STATE KEYS_GetState(KEY_ID key)  {
	KEY_STATE state=KEY_RELEASED;

	switch (key)
	{
	case KEY_A:
		if (BSP_PB_GetState(BUTTON_A)) state = KEY_PRESSED;
		break;
	case KEY_B:
		if (BSP_PB_GetState(BUTTON_B)) state = KEY_PRESSED;
		break;
	case KEY_CENTER:
		if (BSP_PB_GetState(BUTTON_Y)) state = KEY_PRESSED;
		break;
	case KEY_UP:
		if (BSP_PB_GetState(BUTTON_UP)) state = KEY_PRESSED;
		break;
	case KEY_DOWN:
		if (BSP_PB_GetState(BUTTON_DOWN)) state = KEY_PRESSED;
		break;
	case KEY_RIGHT:
		if (BSP_PB_GetState(BUTTON_RIGHT)) state = KEY_PRESSED;
		break;
	case KEY_LEFT:
		if (BSP_PB_GetState(BUTTON_LEFT)) state = KEY_PRESSED;
		break;
	case KEY_LEFT_UP:
		if (BSP_PB_GetState(BUTTON_UP) && BSP_PB_GetState(BUTTON_LEFT)) state = KEY_PRESSED;
		break;
	case KEY_RIGHT_UP:
		if (BSP_PB_GetState(BUTTON_UP) && BSP_PB_GetState(BUTTON_RIGHT)) state = KEY_PRESSED;
		break;
	case KEY_LEFT_DOWN:
		if (BSP_PB_GetState(BUTTON_DOWN) && BSP_PB_GetState(BUTTON_LEFT)) state = KEY_PRESSED;
		break;
	case KEY_RIGHT_DOWN:
		if (BSP_PB_GetState(BUTTON_DOWN) && BSP_PB_GetState(BUTTON_RIGHT)) state = KEY_PRESSED;
		break;
	case KEY_SYSTEM:
		if (BSP_PB_GetState(BUTTON_X)) state = KEY_PRESSED;
		break;
	default:
		break;
	}

	return state;
}

// Random generator services
uint16_t RNG_GetValue(void) {
	return (uint16_t)(BSP_RNG_GetNumber());
}

// Sound services
/* void AUDIO_Init(void) {                                                                                  */
/* 	uint32_t freq=44100;                                                                                    */
/*                                                                                                          */
/* 	BSP_AUDIO_OUT_DeInit();                                                                                 */
/* 	BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_BOTH, 92, freq);                                                       */
/* }                                                                                                        */
/*                                                                                                          */
/* void AUDIO_Start(void) {                                                                                 */
// 	/* Clean Data Cache to update the content of the SRAM */                                                */
/* 	SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*8);                      */
/*                                                                                                          */
/* 	BSP_AUDIO_OUT_Play((uint16_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*8);                           */
/* }                                                                                                        */
/*                                                                                                          */
/* void AUDIO_Stop(void) {                                                                                  */
/* 	BSP_AUDIO_OUT_Stop(CODEC_PDWN_SW);                                                                      */
/* }                                                                                                        */
/*                                                                                                          */
/* void AUDIO_FillBuffer(int buffer_nbr, uint8_t* buffer) {                                                 */
/* 	int i;                                                                                                  */
/* 	int16_t *ptr;                                                                                           */
/* 	int16_t tmp;                                                                                            */
/*                                                                                                          */
/* 	if (buffer_nbr == 1) ptr = &AUDIO_Buffer.buffer1[0];                                                    */
/* 	else ptr =  &AUDIO_Buffer.buffer2[0];                                                                   */
/*                                                                                                          */
/* 	for (i=0; i<AUDIO_BUFFER_SIZE; i++)                                                                     */
/* 	{                                                                                                       */
/* 		tmp = buffer[i];                                                                                       */
/* 		tmp = tmp -128;                                                                                        */
/* 		tmp = tmp *256;                                                                                        */
/*                                                                                                          */
/* 		*ptr=tmp;                                                                                              */
/* 		ptr++;                                                                                                 */
/* 		*ptr=tmp;                                                                                              */
/* 		ptr++;                                                                                                 */
/* 	}                                                                                                       */
/*                                                                                                          */
/* 	if (buffer_nbr == 1) SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4); */
/* 	else SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer2[0], AUDIO_BUFFER_SIZE*4);                 */
/* }                                                                                                        */
/*                                                                                                          */
/* void AUDIO_FillBuffer16(int buffer_nbr, int16_t* buffer) {                                               */
/* 	int i;                                                                                                  */
/* 	int16_t *ptr;                                                                                           */
/*                                                                                                          */
/* 	if (buffer_nbr == 1) ptr = &AUDIO_Buffer.buffer1[0];                                                    */
/* 	else ptr =  &AUDIO_Buffer.buffer2[0];                                                                   */
/*                                                                                                          */
/* 	for (i=0; i<AUDIO_BUFFER_SIZE; i++)                                                                     */
/* 	{                                                                                                       */
/* 		*ptr=buffer[i];                                                                                        */
/* 		ptr++;                                                                                                 */
/* 		*ptr=buffer[i];                                                                                        */
/* 		ptr++;                                                                                                 */
/* 	}                                                                                                       */
/*                                                                                                          */
/* 	if (buffer_nbr == 1) SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4); */
/* 	else SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer2[0], AUDIO_BUFFER_SIZE*4);                 */
/* }                                                                                                        */
/*                                                                                                          */
/* void AUDIO_SetEventCallback(AUDIO_EventCallback callback) {                                              */
/* 	if (callback != 0x00)                                                                                   */
/* 	{                                                                                                       */
/* 		AUDIO_Callback= callback;                                                                              */
/* 	}                                                                                                       */
/* }                                                                                                        */
/*                                                                                                          */
/* */ /**                                                                                                      */
/*  * @brief  Manages the full Transfer complete event.                                                     */
/*  * @param  None                                                                                          */
/*  * @retval None                                                                                          */
//  */                                                                                                      */
/* void BSP_AUDIO_OUT_TransferComplete_CallBack(void)                                                       */
/* {                                                                                                        */
/* 	if (AUDIO_Callback != 0x00)                                                                             */
/* 	{                                                                                                       */
/* 		AUDIO_Callback(2);                                                                                     */
/* 	}                                                                                                       */
/* }                                                                                                        */
/*                                                                                                          */
/* *//**                                                                                                      */
/*  * @brief  Manages the DMA Half Transfer complete event.                                                 */
/*  * @param  None                                                                                          */
/*  * @retval None                                                                                          */
//  */                                                                                                      */
/* void BSP_AUDIO_OUT_HalfTransfer_CallBack(void)                                                           */
/* {                                                                                                        */
/* 	if (AUDIO_Callback != 0x00)                                                                             */
/* 	{                                                                                                       */
/* 		AUDIO_Callback(1);                                                                                     */
/* 	}                                                                                                       */
/* }                                                                                                        */
/*                                                                                                          */

// Sensors services
float* L3GD20_GetGyroscopicValues (void) {
	if (BSP_GYRO_ReadValues(&ang)==ACC_OK) return (float*)&ang;
	else return val;
}

float* LSM303DLHC_GetMagneticValues (void) {
	if (BSP_MAG_ReadValues(&mag) == MAG_OK) return (float*)&mag;
	else return val;
}

float* LSM303DLHC_GetAccelerometerValues(void) {
	float tmp;

	HAL_Delay(25);

	while (BSP_ACC_ReadValues(&acc) != ACC_OK) {
	}

	// invert X and Y
	tmp = -acc.y;
	acc.y=acc.x;
	acc.x=tmp;

	return (float*)&acc;
}

// External RAM
uint8_t SRAM_ReadByte(uint32_t addr) {
	uint8_t *p=(uint8_t*)(&_legacysram_start);
	p+=addr;
	return *p;
}

void SRAM_WriteByte(uint32_t addr, uint8_t data) {
	uint8_t *p=(uint8_t*)(&_legacysram_start);
	p+=addr;
	*p = data;
}

void SRAM_ReadBuffer(uint32_t addr, uint8_t *buffer, int length) {
	uint8_t *p=(uint8_t*)(&_legacysram_start);
	p+=addr;

	for (int i=0;i < length; i++)
	{
		*(buffer++)= *(p++);
	}
}

void SRAM_WriteBuffer(uint32_t addr, uint8_t *buffer, int length) {
	uint8_t *p=(uint8_t*)(&_legacysram_start);
	p+=addr;

	for (int i=0;i < length; i++)
	{
		*(p++) = *(buffer++);
	}
}

// Timer event managment

/**
 * @brief  This function handles TIM7 interrupt request.
 * @retval None
 */
void TIM7_IRQHandler (void)
{
	HAL_TIM_IRQHandler(&LegacyTimHandle);

	if (LegacyTimerCallback != 0x0) LegacyTimerCallback();
}

int TIMER_Start(void) {
	if (LegacyTimerCallback != 0x0) {
		/* Enable TIM7 Update interrupt */
		__HAL_TIM_ENABLE_IT(&LegacyTimHandle, TIM_IT_UPDATE);
		return 1;
	} else
		return 0;
}

void TIMER_Stop(void) {

	/* Disable TIM7 update Interrupt */
	__HAL_TIM_DISABLE_IT(&LegacyTimHandle, TIM_IT_UPDATE);
}

void TIMER_SetEventCallback(TIMER_EventCallback callback) {
	LegacyTimerCallback = callback;
}
//
//// Soft Synthetizer
//SYNTH_Status SYNTH_Start(void)  {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_Stop(void)  {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_SetMainVolume(int volume) {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_SetVolume(int channel, int volume) {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_SetInstrument(int channel, SYNTH_Instrument *instrument) {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_NoteOn(int channel, SYNTH_Note note) {
//
//	return SYNTH_SUCCESS;
//}
//
//SYNTH_Status SYNTH_NoteOff(int channel) {
//
//	return SYNTH_SUCCESS;
//}
//
//MELODY_Status MELODY_Start(MELODY_Notes *music, uint32_t length) {
//
//	return MELODY_SUCCESS;
//}
//
//MELODY_Status MELODY_Stop(void) {
//
//	return MELODY_SUCCESS;
//}
//
//MELODY_Status MELODY_GetPosition(uint8_t *pos) {
//
//	return MELODY_SUCCESS;
//}
