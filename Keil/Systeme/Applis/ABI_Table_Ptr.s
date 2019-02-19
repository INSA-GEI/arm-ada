;******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
;* File Name          : startup_stm32f4xx.s
;* Author             : MCD Application Team
;* Version            : V1.0.0
;* Date               : 30-September-2011
;* Description        : STM32F4xx devices vector table for MDK-ARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Configure the system clock and the external SRAM mounted on
;*                        STM324xG-EVAL board to be used as data memory (optional,
;*                        to be enabled by user)
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM4 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************


; Vector Table Mapped to Address 0 at Reset
        AREA    |.text|, DATA, READONLY
        EXPORT  ABI_Ptr_Table

		IMPORT  API_GetOSVersion
		IMPORT	MALLOC_Init
		IMPORT	MALLOC_GetMemory
		IMPORT	MALLOC_FreeMemory
		IMPORT	fputc
		IMPORT  fgetc
		IMPORT	Delay
		IMPORT	GLCD_Clear
        IMPORT  GLCD_SetTextColor		;
        IMPORT  GLCD_SetBackColor		;
        IMPORT  GLCD_PutPixel			;
        IMPORT  GLCD_DrawChar				;
		IMPORT  GLCD_DrawADAString		;
		IMPORT  GLCD_DrawLine	 	;
        IMPORT  GLCD_DrawRectangle		;
        IMPORT  GLCD_DrawFillRectangle		;
        IMPORT  GLCD_DrawCircle			;
		IMPORT	GLCD_DrawFillCircle
		IMPORT	GLCD_DrawImage
		IMPORT  KEYS_GetState			;
		IMPORT	POT_GetValue
		IMPORT  RNG_GetValue

		IMPORT	GUI_ProgressBar
		IMPORT	GUI_CenterBar
		IMPORT	AUDIO_Start
        IMPORT	AUDIO_Stop
        IMPORT	AUDIO_FillBuffer
        IMPORT	AUDIO_SetEventCallback
		IMPORT	LED_Set
		IMPORT	L3GD20_GetGyroscopicValues
		IMPORT	LSM303DLHC_GetMagneticValues
		IMPORT	LSM303DLHC_GetAccelerometerValues
		IMPORT 	SRAM_ReadByte
		IMPORT	SRAM_WriteByte
		IMPORT	SRAM_ReadBuffer
		IMPORT	SRAM_WriteBuffer
		IMPORT 	TIMER_Start
		IMPORT  TIMER_Stop
		IMPORT  TIMER_SetEventCallback

		IMPORT  GLCD_DrawImagefromSRAM
		IMPORT  GLCD_LayerScrollMode
		IMPORT  GLCD_SetScrollWindow
		IMPORT  GLCD_ScrollVertical
		IMPORT  GLCD_ScrollHorizontal
		IMPORT  GLCD_LayerDisplayMode
		IMPORT  GLCD_LayerTransparency
		IMPORT  GLCD_SetLayer
		IMPORT  GLCD_BTESetSource
		IMPORT  GLCD_BTESetDestination
		IMPORT  GLCD_BTESetSize
		IMPORT  GLCD_BTESetBackgroundColor
		IMPORT  GLCD_BTESetForegroundColor
		IMPORT  GLCD_BTESetPatternNumber
		IMPORT  GLCD_SetTransparentColor
		IMPORT  GLCD_BTEStart
		IMPORT  GLCD_BTEStartAndFillFromSRAM
			
		ALIGN

ABI_Ptr_Table

; Basic OS services
		DCD     API_GetOSVersion		
		DCD     fputc    			    
        DCD     fgetc					
        DCD     MALLOC_Init				
		DCD     MALLOC_GetMemory		
		DCD     MALLOC_FreeMemory	 	
		DCD		Delay

; Graphics services
		DCD		GLCD_Clear
        DCD 	GLCD_SetTextColor		
        DCD     GLCD_SetBackColor		
        DCD     GLCD_PutPixel			
        DCD     GLCD_DrawChar				
		DCD     GLCD_DrawADAString		
		DCD     GLCD_DrawLine	 	
        DCD     GLCD_DrawRectangle		
        DCD     GLCD_DrawFillRectangle		
        DCD     GLCD_DrawCircle			
		DCD		GLCD_DrawFillCircle
		DCD		GLCD_DrawImage

; Graphics widgets
		DCD		GUI_ProgressBar
		DCD		GUI_CenterBar

; Keys and potar services
        DCD 	KEYS_GetState			
		DCD		POT_GetValue

; Led services
		DCD		LED_Set

; Random generator services
        DCD     RNG_GetValue			

; Sound services
        DCD		AUDIO_Start
        DCD		AUDIO_Stop
        DCD		AUDIO_FillBuffer
        DCD		AUDIO_SetEventCallback

; Sensors services
		DCD		L3GD20_GetGyroscopicValues
		DCD		LSM303DLHC_GetMagneticValues
		DCD		LSM303DLHC_GetAccelerometerValues

; External RAM
		DCD 	SRAM_ReadByte
		DCD		SRAM_WriteByte
		DCD		SRAM_ReadBuffer
		DCD		SRAM_WriteBuffer

; Timer event managment
		DCD 	TIMER_Start
		DCD  	TIMER_Stop
		DCD  	TIMER_SetEventCallback
			
; second set of function for GLCD
		DCD  	GLCD_DrawImagefromSRAM
		DCD  	GLCD_LayerScrollMode
		DCD  	GLCD_SetScrollWindow
		DCD 	GLCD_ScrollVertical
		DCD  	GLCD_ScrollHorizontal
		DCD  	GLCD_LayerDisplayMode
		DCD  	GLCD_LayerTransparency
		DCD  	GLCD_SetLayer
		DCD  	GLCD_BTESetSource
		DCD  	GLCD_BTESetDestination
		DCD  	GLCD_BTESetSize
		DCD  	GLCD_BTESetBackgroundColor
		DCD  	GLCD_BTESetForegroundColor
		DCD  	GLCD_BTESetPatternNumber
		DCD  	GLCD_SetTransparentColor
		DCD  	GLCD_BTEStart
		DCD     GLCD_BTEStartAndFillFromSRAM
			
ABI_Ptr_Table_End

        END

;******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****
