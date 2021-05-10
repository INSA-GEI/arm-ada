/******************************************************************************/
/* system.c: resident system main file                                        */
/*                                                                            */
/******************************************************************************/
/* This program is free software: you can redistribute it and/or modify       */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program.  If not, see <http://www.gnu.org/licenses/>.   */
/******************************************************************************/

#include "system.h"
//#include "tests.h"
#include "memory_mapping.h"

#include "ressources.h"

#include "stm32746g_discovery_stdio.h"
#include "stm32746g_discovery_lcd_dma2d.h"
/* todo a supprimer */
/* #include "audio-synth/audio-synth.h"       */
/* #include "audio-synth/audio.h"             */
/* #include "audio-synth/audio-synth-const.h" */
/* #include "stm32746g_discovery_audio.h"     */
/* todo a supprimer */

void BSP_Init(void);
void RUNTIME_Main(void);
void MAIN_SystemInit(void);

COLOR *data;
const PackedBMP_Header logo_insa;
const PackedBMP_Header logo_armada;

void SYSTEM_PeripheralsReset(void);
void SYSTEM_PeripheralsInit(void);
void SYSTEM_SplashScreen(void);

void RETARGET_Init(void);
int SYSTEM_RunApp(void);
void PRG_ResetReprogRequest(void);
int PRG_CheckReprogRequest(void);
int8_t  lcd_status = LCD_OK;

#define PRG_RESET_REPROG		1
#define PRG_RESET_HARDRESET		2
#define PRG_RESET_SOFTRESET		3
#define PRG_SOFTRESET_PATTERN 	0xDEADBEEF
#define PRG_REPROG_PATTERN 		0xADDAADDA

volatile int DataReady=0;
int return_val;

char RunAutoTest=0;
extern const uint32_t* __stack_end;
extern const uint32_t* __interrupt_stack_end;

extern uint32_t PRG_ReprogPatternAddr;
//extern AUDIO_BufferTypeDef  AUDIO_Buffer;
//volatile double tmp,value;
//int i=0;
//int myvar=0;
//
//typedef struct {
//	const SYNTH_Instrument *instrument;
//	const char* str;
//} INSTR_TEST;
//
//INSTR_TEST Instr_Test_Array []=
//{
//		{&SYNTH_Inst_Sin, "Sinus"},
//		{&SYNTH_Inst_Triangle,"Triangle"},
//		{&SYNTH_Inst_Square,"Square"},
//		{&SYNTH_Inst_Saw,"Saw"},
//		{&SYNTH_Inst_HalfSin,"Half Sinus"},
//		{&SYNTH_Inst_HalfTriangle,"Half Triangle"},
//		{&SYNTH_Inst_HalfSquare,"Half Square"},
//		{&SYNTH_Inst_QuaterSin,"Quater Sinus"},
//		{&SYNTH_Inst_HalfSaw,"Half Saw"},
//		{&SYNTH_Inst_SinHach,"Hach Sinus"},
//		{&SYNTH_Inst_SquareHach,"Hach Square"},
//		{&SYNTH_Inst_Noise,"Noise"},
//		{&SYNTH_Inst_HalfNoise,"Half Noise"}
//};

void BSP_Init(void)
{
  /* STM32F7xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
	 */
	HAL_Init();

	/* Configure system and BSP peripherals (except LCD) */
	MAIN_SystemInit();

	/*##-1- Initialize the LCD #################################################*/
	/* Initialize the LCD */
	lcd_status = BSP_LCD_Init();

	/* Initialize the LCD Layers */
	//BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_LayerRgb565Init(LTDC_FOREGROUND_LAYER, LCD_FRAME_BUFFER_LAYER_FOREGROUND);
	BSP_LCD_LayerRgb565Init(LTDC_BACKGROUND_LAYER, LCD_FRAME_BUFFER_LAYER_BACKGROUND);

	BSP_LCD_ResetScreen();

	//if (BSP_PB_GetState(BUTTON_X) != RESET)	{
	//	TESTS_Run();
	//} 
}

/**
 * @brief EXTI line detection callbacks.
 * @param GPIO_Pin: Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)        
 {                                                     
 	static uint32_t debounce_time = 0;                   
 	static volatile uint32_t counter_mag=0;              
 	static volatile uint32_t counter_acc_gyro=0;         
                                                       
 	switch (GPIO_Pin)                                    
 	{                                                    
 	case KEY_BUTTON_PIN:                                 
 		/* Prevent debounce effect for user key */
 		if ((HAL_GetTick() - debounce_time) > 50)           
 		{                                                   
 			debounce_time = HAL_GetTick();                     
 		}                                                                                                   
 		break;                                              
 	case AUDIO_IN_INT_GPIO_PIN:                          
 		/* Audio IN interrupt */                            
 		break;                                              
 	case MAG_DRDY_PIN:                                   
 		/* MAG DRDY interrupt */                            
 		counter_mag++;                                      
 		break;                                              
 	case ACC_GYRO_DRDY_PIN:                              
 		/* ACC and Gyro DRDY interrupt */                   
 		counter_acc_gyro++;                                 
 		break;                                              
 	case SD_DETECT_PIN:                                  
		/* SD Detect and TS interrupt (shared) */           
 		if (HAL_GPIO_ReadPin(TS_INT_GPIO_PORT, TS_INT_PIN)) 
 		{                                                   
 			/* Touchscreen it */                               
 			BSP_TS_ITClear();                                  
 		}                                                   
 		else                                                
 		{                                                   
 			/* SD Detect it */                                 
 		}                                                   
 		break;                                              
                                                       
 	default:                                             
 		/* Unknown interrupt */                             
 		break;                                             
 	}                                                    
 }                                                     

/**
 * @brief  Fault Manager Enable.
 * @param  None
 * @retval None
 */
void MAIN_SystemInit(void)              
{   
  /* Init standard IO serial link */            
 	BSP_STDIO_Init();                             
                                                
 	/* Init led1 */                               
 	BSP_LED_Init(LED1);                           
                                                
 	/* Configure the User Button in GPIO Mode */  
 	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);    
                 
  /* Init External SRAM */                      
  BSP_SDRAM_Init();
  
 	/* Init QSPI */                               
 	BSP_QSPI_Init();                              
 	BSP_QSPI_EnableMemoryMappedMode();            
                                                
 	/* Init Keys */                               
 	BSP_KEYS_Init();                              
                                                
 	/* Init magnetic sensor */                    
 	BSP_MAG_Init();                               
                                                
 	/* Init accelerometer and gyroscope sensor */ 
 	BSP_ACC_GYRO_Init();                          
                                                
 	/* Init pressure sensor */                    
 	BSP_PRESSURE_Init();                                                                                            
                                                
 	/* Init RNG */                                
 	BSP_RNG_InitGenerator();                      
                                                
 }                                              

void RUNTIME_Main(void)
{
  int return_code;
	/* Pre init du system */
	//SetStack((uint32_t)&__system_stack_end__,(uint32_t)&__app_stack_end__);
	//SYSTEM_MoveITVector();
	//RETARGET_Init();

	/* Init du systeme */
	WRAPPER_Init();
	BSP_LCD_ResetScreen();

	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);

#ifndef ADA_TEST_SYSTEM	
	//if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET) 
	//{
	//	SYSTEM_SplashScreen();
	//}
#endif /* ADA_TEST_SYSTEM */

	/* Finalement, on positionne le drapeau de demarrage a froid */
	/* Desormais, lors d'un reset, le systeme ne ferra plus d'attente pour l'ecran, ni d'animation */
	//PRG_ResetReprogRequest();

	/* Set screen in full black, except for emulated screen of legacy device (in white) */
	BSP_LCD_Clear(Black);

	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);
  CONSOLE_GotoXY(0,0);
 
	//	/* Essai du synthe */
	//	if (BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_BOTH, 92, 44100)== 0) {
	//		GLCD_DrawString(1,10, "Codec Init OK: 44100 Khz");
	//		/* Clean Data Cache to update the content of the SRAM */
	//		SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4);
	//
	//		//BSP_AUDIO_OUT_Play((uint16_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4);
	//	}
	//	else GLCD_DrawString(1,10, "Codec Init fail");
	//
	//	i=0;
	//
	//	GLCD_DrawString(1,11, Instr_Test_Array[i].str);
	//
	//	SYNTH_Start();
	//	SYNTH_SetMainVolume(0xFF);
	//	SYNTH_SetInstrument(0,(SYNTH_Instrument* )Instr_Test_Array[i].instrument);
	//	SYNTH_SetVolume(0,0xFF);
	//
	//	while (1) {
	//		if (BSP_PB_GetState(BUTTON_A) != RESET)
	//		{
	//			while (BSP_PB_GetState(BUTTON_A) != RESET) {}
	//
	//			i++;
	//			if (i >= (sizeof(Instr_Test_Array)/sizeof(INSTR_TEST))) i=0;
	//
	//			GLCD_DrawString(1,11, Instr_Test_Array[i].str);
	//			SYNTH_SetInstrument(0,(SYNTH_Instrument* )Instr_Test_Array[i].instrument);
	//		}
	//
	//		//SYNTH_NoteOff(0);
	//		GLCD_DrawString(10,11, "G4");
	//		SYNTH_NoteOn(0,G4);
	//		HAL_Delay(400);
	//
	//		//SYNTH_NoteOff(0);
	//		GLCD_DrawString(10,11, "C5");
	//		SYNTH_NoteOn(0,C5);
	//		HAL_Delay(400);
	//		//SYNTH_NoteOff(0);
	//
	//		GLCD_DrawString(10,11, "C4");
	//		SYNTH_NoteOn(0,C4);
	//		HAL_Delay(2000);
	//	}

	/* Lance l'application ADA (si les auto test n'ont pas été activés avant) */
	//while (SYSTEM_RunApp()!= BAD_APPLICATION_RETURN_CODE);

	/* Redemarre le system (devrait rester bloqué dans le bootloader) */
	//NVIC_SystemReset();	
  //while (1);
}

/* Fonction pour tester si une reprog est necessaire */
int PRG_CheckReprogRequest(void)
{
	if (PRG_ReprogPatternAddr == PRG_REPROG_PATTERN) return PRG_RESET_REPROG;
	else if (PRG_ReprogPatternAddr == PRG_SOFTRESET_PATTERN) return PRG_RESET_SOFTRESET;

	return PRG_RESET_HARDRESET;
}

/* Fonction pour nettoyer la condition de reprog */
void PRG_ResetReprogRequest(void)
{
	PRG_ReprogPatternAddr = PRG_SOFTRESET_PATTERN;
}

/**
 * @brief  Peripheral Reset.
 * @param  None
 * @retval None
 */
//void SYSTEM_PeripheralsReset(void)
//{
//	/* Switch off all clock */
//	RCC_AHBPeriphClockCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
//			RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
//			RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
//			RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
//			RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, DISABLE);
//
//	RCC_APB2PeriphClockCmd( RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
//			RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
//			RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, DISABLE);
//
//	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
//			RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
//			RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
//			RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
//			RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
//			RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, ENABLE);
//
//	__DSB();
//	__ISB();
//
//	/* Reset Every periph on AHB */
//	RCC_AHBPeriphResetCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
//			RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
//			RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
//			RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
//			RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, ENABLE);
//
//	RCC_APB2PeriphResetCmd(	RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
//			RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
//			RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, ENABLE);
//
//	RCC_APB1PeriphResetCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
//			RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
//			RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
//			RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
//			RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
//			RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, ENABLE);
//
//	__DSB();
//	__ISB();
//
//	/* Reset SYSTICK */
//	SysTick->CTRL=0;
//
//	/* Reset NVIC */
//	NVIC->ICER[0]=0xFFFFFFFF;
//	NVIC->ICER[1]=0xFFFFFFFF;
//	NVIC->ICER[1]=0xFFFFFFFF;
//
//	/* Release Reset */
//	RCC_AHBPeriphResetCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
//			RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
//			RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
//			RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
//			RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, DISABLE);
//
//	RCC_APB2PeriphResetCmd( RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
//			RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
//			RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, DISABLE);
//
//
//	RCC_APB1PeriphResetCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
//			RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
//			RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
//			RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
//			RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
//			RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, DISABLE);
//	__DSB();
//	__ISB();
//}

/**
 * @brief  Peripheral initialisation.
 * @param  None
 * @retval None
 */
//void SYSTEM_PeripheralsInit(void)
//{
//	//uint32_t Status = 0;
//	L3GD20_InitTypeDef L3GD20_InitStructure;
//	L3GD20_FilterConfigTypeDef L3GD20_FilterStructure;
//
//	LSM303DLHCMag_InitTypeDef LSM303DLHC_InitStructure;
//	LSM303DLHCAcc_InitTypeDef LSM303DLHCAcc_InitStructure;
//	LSM303DLHCAcc_FilterConfigTypeDef LSM303DLHCFilter_InitStructure;
//
//	/* Vectorize IT */
//	SYSTEM_AddITtoVector(NonMaskableInt_IRQn, (int*)NMI_Handler);
//	SYSTEM_AddITtoVector(NonMaskableInt_IRQn+1, (int*)HardFault_Handler);
//	SYSTEM_AddITtoVector(MemoryManagement_IRQn, (int*)MemManage_Handler);
//	SYSTEM_AddITtoVector(BusFault_IRQn , (int*)BusFault_Handler);
//	SYSTEM_AddITtoVector(UsageFault_IRQn, (int*)UsageFault_Handler);
//
//	SYSTEM_AddITtoVector(SysTick_IRQn, (int*)SysTick_Handler);
//	SYSTEM_AddITtoVector(USART1_IRQn, (int*)USART1_IRQHandler);
//	SYSTEM_AddITtoVector(USART2_IRQn, (int*)USART2_IRQHandler);
//	SYSTEM_AddITtoVector(DMA2_Channel3_IRQn, (int*)DMA2_Channel3_IRQHandler);
//	SYSTEM_AddITtoVector(TIM4_IRQn, (int*)TIM4_IRQHandler);
//
//	/* Demarrage du systick */
//	SysTick_Config(SystemCoreClock/1000);
//	NVIC_SetPriority(SysTick_IRQn,15);
//
//	//MALLOC_Init(MALLOC_INITIAL_BASE);
//
//	USART_Configure(USART1, BAUDRATE, USART_NO_REMAP);
//
//	//puts ("\r\rSystem %d.%d\r", BL_MAJOR_VERSION, BL_MINOR_VERSION);
//	//puts ("Init [");
//
//	//puts ("Usart Systick IT Led ");
//	LED_Init();
//	LED_Set(LED_ON);
//
//	//puts ("Keys ");
//	KEYS_Init();
//	POT_Init();
//
//	/* Demarrage du generateur de nombre aleatoire */
//	//puts ("Rng ");
//	RNG_Init();
//
//	/* Demarrage de l'audio */
//	//puts ("Audio ");
//	AUDIO_Init();
//
//	/* Demarrage de la RAM externe */
//	//puts ("Sram ");
//	SRAM_Init();
//
//	/* Demarrage de la carte SD */
//	//	socket_cp_init();
//	//	disk_timerproc();
//	//	disk_timerproc();
//	//  printf ("SD Card ");
//	//	Status = SD_Init();
//
//	//#ifndef ADA_TEST_SYSTEM
//	if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET)
//		GLCD_Wait();
//	//#endif /* ADA_TEST_SYSTEM */
//
//	//puts ("Lcd ");
//	GLCD_Init();
//	GLCD_Clear(White);
//
//	/* Configure Mems L3GD20 */
//	//puts ("L3gd20 ");
//	L3GD20_InitStructure.Power_Mode = L3GD20_MODE_ACTIVE;
//	L3GD20_InitStructure.Output_DataRate = L3GD20_OUTPUT_DATARATE_1;
//	L3GD20_InitStructure.Axes_Enable = L3GD20_AXES_ENABLE;
//	L3GD20_InitStructure.Band_Width = L3GD20_BANDWIDTH_4;
//	L3GD20_InitStructure.BlockData_Update = L3GD20_BlockDataUpdate_Continous;
//	L3GD20_InitStructure.Endianness = L3GD20_BLE_LSB;
//	L3GD20_InitStructure.Full_Scale = L3GD20_FULLSCALE_500;
//	L3GD20_Init(&L3GD20_InitStructure);
//
//	L3GD20_FilterStructure.HighPassFilter_Mode_Selection =L3GD20_HPM_NORMAL_MODE_RES;
//	L3GD20_FilterStructure.HighPassFilter_CutOff_Frequency = L3GD20_HPFCF_0;
//	L3GD20_FilterConfig(&L3GD20_FilterStructure) ;
//
//	L3GD20_FilterCmd(L3GD20_HIGHPASSFILTER_ENABLE);
//
//	/* Configure MEMS magnetometer main parameters: temp, working mode, full Scale and Data rate */
//	//puts ("Lsm303dlhc ");
//	LSM303DLHC_InitStructure.Temperature_Sensor = LSM303DLHC_TEMPSENSOR_DISABLE;
//	LSM303DLHC_InitStructure.MagOutput_DataRate =LSM303DLHC_ODR_30_HZ ;
//	LSM303DLHC_InitStructure.MagFull_Scale = LSM303DLHC_FS_8_1_GA;
//	LSM303DLHC_InitStructure.Working_Mode = LSM303DLHC_CONTINUOS_CONVERSION;
//	LSM303DLHC_MagInit(&LSM303DLHC_InitStructure);
//
//	/* Fill the accelerometer structure */
//	LSM303DLHCAcc_InitStructure.Power_Mode = LSM303DLHC_NORMAL_MODE;
//	LSM303DLHCAcc_InitStructure.AccOutput_DataRate = LSM303DLHC_ODR_50_HZ;
//	LSM303DLHCAcc_InitStructure.Axes_Enable= LSM303DLHC_AXES_ENABLE;
//	LSM303DLHCAcc_InitStructure.AccFull_Scale = LSM303DLHC_FULLSCALE_2G;
//	LSM303DLHCAcc_InitStructure.BlockData_Update = LSM303DLHC_BlockUpdate_Continous;
//	LSM303DLHCAcc_InitStructure.Endianness=LSM303DLHC_BLE_LSB;
//	LSM303DLHCAcc_InitStructure.High_Resolution=LSM303DLHC_HR_ENABLE;
//	/* Configure the accelerometer main parameters */
//	LSM303DLHC_AccInit(&LSM303DLHCAcc_InitStructure);
//
//	/* Fill the accelerometer LPF structure */
//	LSM303DLHCFilter_InitStructure.HighPassFilter_Mode_Selection =LSM303DLHC_HPM_NORMAL_MODE;
//	LSM303DLHCFilter_InitStructure.HighPassFilter_CutOff_Frequency = LSM303DLHC_HPFCF_16;
//	LSM303DLHCFilter_InitStructure.HighPassFilter_AOI1 = LSM303DLHC_HPF_AOI1_DISABLE;
//	LSM303DLHCFilter_InitStructure.HighPassFilter_AOI2 = LSM303DLHC_HPF_AOI2_DISABLE;
//
//	/* Configure the accelerometer LPF main parameters */
//	LSM303DLHC_AccFilterConfig(&LSM303DLHCFilter_InitStructure);
//
//	//puts ("] Done\r");
//}

/**
 * @brief  Vectorise une routine d'interruption
 * @param  it: numero de l'interruption
 * @param  *p: Pointeur vers la routine d'it
 * @retval None
 */
//void SYSTEM_AddITtoVector (int it, int *p)
//{
//	uint32_t *VectorTable=(uint32_t*)VECTOR_TABLE_ADDR;
//	VectorTable[it+16] = (int)p;
//}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in 10 ms.
 * @retval None
 */
void SYSTEM_SplashScreen(void)
{
	int dx,i;
	int x;
	char str[15];

	GLCD_SetLayer(GLCD_LAYER2);
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);
	GLCD_SetLayer(GLCD_LAYER1);
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);

	GLCD_SetTransparentColor(Green);
	GLCD_LayerScrollMode(GLCD_LAYER_SCROLL_BOTH);
	GLCD_LayerDisplayMode(GLCD_LAYER_DISPLAY_TRANSPARENT);
	GLCD_LayerTransparency(GLCD_LAYER_TRANSPARENT_TOTAL,GLCD_LAYER_TRANSPARENT_TOTAL);

	if (KEYS_GetState(KEY_A)==KEY_PRESSED) 
	{
		GLCD_SetTextColor(Black);
		GLCD_SetBackColor(White);

		sprintf (str, "System ver. %d.%d", BL_MAJOR_VERSION, BL_MINOR_VERSION);
		GLCD_DrawString((40-strlen(str))/2, 13, str);
	}

	/* allocation du buffer pour l'image */
	//data = (COLOR*)MALLOC_GetMemory(logo_armada.height*logo_armada.width);
	data = (COLOR*)malloc(logo_armada.height*logo_armada.width);
	if (data ==0x0) while (1);

	UnpackBMP((PackedBMP_Header *)&logo_armada, data);

	/* Animation du logo de demarrage */
	GLCD_SetLayer(GLCD_LAYER2);
	GLCD_DrawImage(data, (320-logo_armada.width)/2, (240-logo_armada.height)/2, logo_armada.width, logo_armada.height);

	//MALLOC_FreeMemory(data);
	free(data);
	GLCD_SetLayer(GLCD_LAYER1);
	GLCD_SetTextColor(Green);

	for (i=1; i<33; i++)
	{
		dx=(logo_armada.width*i)/(2*32);
		x=(320/2)-dx;

		GLCD_DrawFillRectangle(x,(240-logo_armada.height)/2,x+(dx*2),((240-logo_armada.height)/2)+logo_armada.height);
		Delay(20);
	}

	Delay(2000);

	BSP_LCD_ResetScreen();
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 200000000
 *            HCLK(Hz)                       = 200000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 400
 *            PLL_P                          = 2
 *            PLL_Q                          = 8
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 * @param  None
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	HAL_StatusTypeDef ret = HAL_OK;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 400;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 8;

	ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
	if(ret != HAL_OK)
	{
		while(1) { ; }
	}

	/* Activate the OverDrive to reach the 216 MHz Frequency */
	ret = HAL_PWREx_EnableOverDrive();
	if(ret != HAL_OK)
	{
		while(1) { ; }
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
	if(ret != HAL_OK)
	{
		while(1) { ; }
	}
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void)
{
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

/**
 * @brief  FPU Coprocessors enable.
 * @param  None
 * @retval None
 */
static void CPU_EnableFPU(void)
{
	SCB->CPACR=(0x3<<20)+(0x3<<22); // Enable full access to CP11 and CP10 FPU
}

/**
 * @brief  Fault Manager Enable.
 * @param  None
 * @retval None
 */
static void CPU_EnableFaultHandler(void)
{
	SCB->SHCSR = SCB->SHCSR | (SCB_SHCSR_BUSFAULTENA_Msk + SCB_SHCSR_MEMFAULTENA_Msk + SCB_SHCSR_USGFAULTENA_Msk);
}

/**
 * @brief  Init of runtime
 * @param  None
 * @retval None
 */
void init_bsp(void)
{
	/* Enable User fault, Bus fault, Memory Fault handlers */
	CPU_EnableFaultHandler();

	/* Configure the system clock to 200 Mhz */
	//SystemClock_Config();

  HAL_Init();

	/* Configure system and BSP peripherals (except LCD) */
	MAIN_SystemInit();

	/*##-1- Initialize the LCD #################################################*/
	/* Initialize the LCD */
	lcd_status = BSP_LCD_Init();

	/* Initialize the LCD Layers */
	//BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
	BSP_LCD_LayerRgb565Init(LTDC_FOREGROUND_LAYER, LCD_FRAME_BUFFER_LAYER_FOREGROUND);
	BSP_LCD_LayerRgb565Init(LTDC_BACKGROUND_LAYER, LCD_FRAME_BUFFER_LAYER_BACKGROUND);

	BSP_LCD_ResetScreen();

  /* Init du wrapper */
  RETARGET_Init();
	WRAPPER_Init();
	BSP_LCD_ResetScreen();

	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);

	if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET) 
	{
		SYSTEM_SplashScreen();
	}

	/* Finalement, on positionne le drapeau de demarrage a froid */
	/* Desormais, lors d'un reset, le systeme ne ferra plus d'attente pour l'ecran, ni d'animation */
	PRG_ResetReprogRequest();

	/* Set screen in full black, except for emulated screen of legacy device (in white) */
	BSP_LCD_Clear(Black);

	GLCD_Clear(White);
	GLCD_SetBackColor(White);
  GLCD_SetTextColor(Black);
  
  CONSOLE_GotoXY(0,0);
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */





