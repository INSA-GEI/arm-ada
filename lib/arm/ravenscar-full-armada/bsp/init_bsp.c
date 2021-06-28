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
#include "memory_mapping.h"

#include "stm32746g_discovery_stdio.h"
#include "lvgl/lvgl.h"

#include "hal_stm_lvgl/tft/tft.h"
#include "hal_stm_lvgl/touchpad/touchpad.h"

#include "tests/tests.h"

/* todo a supprimer */
/* #include "audio-synth/audio-synth.h"       */
/* #include "audio-synth/audio.h"             */
/* #include "audio-synth/audio-synth-const.h" */
/* #include "stm32746g_discovery_audio.h"     */
/* todo a supprimer */

void MAIN_SystemInit(void);
void SYSTEM_ShowSystemVersion(int MajV, int MinV);

int return_val;
/* Flag utilisé pour afficher ou pas le logo au demarrage */
uint32_t *rebootFlag=(uint32_t*)(0xC0000000+4*1024*1024-4);
//char RunAutoTest=0;
//extern const uint32_t* __stack_end;
//extern const uint32_t* __interrupt_stack_end;

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

void Pipo(void);

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

//void RUNTIME_Main(void)
//{
//  /* Pre init du system */
//  //SetStack((uint32_t)&__system_stack_end__,(uint32_t)&__app_stack_end__);
//  //SYSTEM_MoveITVector();
//  //RETARGET_Init();
//
//  /* Init du systeme */
//  WRAPPER_Init();
//  BSP_LCD_ResetScreen();
//
//  GLCD_SetBackColor(White);
//  GLCD_SetTextColor(Black);
//
//#ifndef ADA_TEST_SYSTEM	
//  //if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET) 
//  //{
//  //	SYSTEM_SplashScreen();
//  //}
//#endif /* ADA_TEST_SYSTEM */
//
//  /* Set screen in full black, except for emulated screen of legacy device (in white) */
//  BSP_LCD_Clear(Black);
//
//  GLCD_Clear(White);
//  GLCD_SetBackColor(White);
//  GLCD_SetTextColor(Black);
//  CONSOLE_GotoXY(0,0);
// 
//  //	/* Essai du synthe */
//  //	if (BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_BOTH, 92, 44100)== 0) {
//  //		GLCD_DrawString(1,10, "Codec Init OK: 44100 Khz");
//  //		/* Clean Data Cache to update the content of the SRAM */
//  //		SCB_CleanDCache_by_Addr((uint32_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4);
//  //
//  //		//BSP_AUDIO_OUT_Play((uint16_t*)&AUDIO_Buffer.buffer1[0], AUDIO_BUFFER_SIZE*4);
//  //	}
//  //	else GLCD_DrawString(1,10, "Codec Init fail");
//  //
//  //	i=0;
//  //
//  //	GLCD_DrawString(1,11, Instr_Test_Array[i].str);
//  //
//  //	SYNTH_Start();
//  //	SYNTH_SetMainVolume(0xFF);
//  //	SYNTH_SetInstrument(0,(SYNTH_Instrument* )Instr_Test_Array[i].instrument);
//  //	SYNTH_SetVolume(0,0xFF);
//  //
//  //	while (1) {
//  //		if (BSP_PB_GetState(BUTTON_A) != RESET)
//  //		{
//  //			while (BSP_PB_GetState(BUTTON_A) != RESET) {}
//  //
//  //			i++;
//  //			if (i >= (sizeof(Instr_Test_Array)/sizeof(INSTR_TEST))) i=0;
//  //
//  //			GLCD_DrawString(1,11, Instr_Test_Array[i].str);
//  //			SYNTH_SetInstrument(0,(SYNTH_Instrument* )Instr_Test_Array[i].instrument);
//  //		}
//  //
//  //		//SYNTH_NoteOff(0);
//  //		GLCD_DrawString(10,11, "G4");
//  //		SYNTH_NoteOn(0,G4);
//  //		HAL_Delay(400);
//  //
//  //		//SYNTH_NoteOff(0);
//  //		GLCD_DrawString(10,11, "C5");
//  //		SYNTH_NoteOn(0,C5);
//  //		HAL_Delay(400);
//  //		//SYNTH_NoteOff(0);
//  //
//  //		GLCD_DrawString(10,11, "C4");
//  //		SYNTH_NoteOn(0,C4);
//  //		HAL_Delay(2000);
//  //	}
//
//  /* Lance l'application ADA (si les auto test n'ont pas été activés avant) */
//  //while (SYSTEM_RunApp()!= BAD_APPLICATION_RETURN_CODE);
//
//  /* Redemarre le system (devrait rester bloqué dans le bootloader) */
//  //NVIC_SystemReset();	
//  //while (1);
//}

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
void CPU_CACHE_Enable(void)
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
void CPU_EnableFPU(void)
{
  SCB->CPACR=(0x3<<20)+(0x3<<22); // Enable full access to CP11 and CP10 FPU
}

/**
 * @brief  Fault Manager Enable.
 * @param  None
 * @retval None
 */
void CPU_EnableFaultHandler(void)
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
  Pipo();

  /* Configure the system clock to 200 Mhz */
  SystemClock_Config();

  CPU_CACHE_Enable();
  CPU_EnableFPU();
  CPU_EnableFaultHandler();

  HAL_Init();

  /* Configure system and BSP peripherals (except LCD) */
  MAIN_SystemInit();

  lv_init();

  tft_init();
  touchpad_init();

  WRAPPER_Init();
  
  lv_obj_clean(lv_scr_act()); 
  lv_task_handler();
  HAL_Delay(200);
  
  if (*rebootFlag != 0xDEADBEEF) {
	  *rebootFlag = 0xDEADBEEF;
	  SYSTEM_ShowSystemVersion(BL_MAJOR_VERSION, BL_MINOR_VERSION);
  }

  if (BSP_PB_GetState(BUTTON_X) && BSP_PB_GetState(BUTTON_Y)) {
	  /* Enter Test mode */
	  tests();
  }
}

void SYSTEM_ShowSystemVersion(int MajV, int MinV)
{
  char str[30];
  sprintf (str, "System ver. %d.%d", BL_MAJOR_VERSION, BL_MINOR_VERSION);
  
  LV_IMG_DECLARE(logo);
  
  lv_obj_t *label1 = lv_label_create(lv_scr_act(),NULL);
  lv_label_set_text(label1, str);
  lv_obj_set_width(label1, 150);  /*Set smaller width to make the lines wrap*/
  lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 80);

  lv_obj_t *img = lv_img_create(lv_scr_act(),NULL);
  lv_img_set_src(img, &logo);
  lv_obj_align(img, NULL, LV_ALIGN_CENTER, 0, -30);
  
  lv_task_handler();
  HAL_Delay(2000);
  
  lv_obj_clean(lv_scr_act()); 
  lv_task_handler(); 
  HAL_Delay(200);
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





