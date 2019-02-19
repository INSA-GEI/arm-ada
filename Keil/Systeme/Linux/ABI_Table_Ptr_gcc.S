/******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
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
;*******************************************************************************/


// Vector Table Mapped to Address 0 at Reset

	.text
	.align 	2
	.globl 	ABI_Ptr_Table
ABI_Ptr_Table:	

// Basic OS services
	.long	API_GetOSVersion		
	.long   fputc_ADA    			    
        .long   fgetc_ADA					
        .long   MALLOC_Init				
	.long   MALLOC_GetMemory		
	.long   MALLOC_FreeMemory	 	
	.long	Delay

// Graphics services
	.long	GLCD_Clear
        .long 	GLCD_SetTextColor		
        .long   GLCD_SetBackColor		
        .long   GLCD_PutPixel			
        .long   GLCD_DrawChar				
	.long   GLCD_DrawADAString		
	.long   GLCD_DrawLine	 	
        .long   GLCD_DrawRectangle		
        .long   GLCD_DrawFillRectangle		
        .long   GLCD_DrawCircle			
	.long	GLCD_DrawFillCircle
	.long	GLCD_DrawImage

// Graphics widgets
	.long	GUI_ProgressBar
	.long	GUI_CenterBar

// Keys and potar services
        .long 	KEYS_GetState			
	.long	POT_GetValue

// Led services
	.long	LED_Set

// Random generator services
        .long   RNG_GetValue			

// Sound services
        .long	AUDIO_Start
        .long	AUDIO_Stop
        .long	AUDIO_FillBuffer
        .long	AUDIO_SetEventCallback

// Sensors services
	.long	L3GD20_GetGyroscopicValues
	.long	LSM303DLHC_GetMagneticValues
	.long	LSM303DLHC_GetAccelerometerValues

// External RAM
	.long 	SRAM_ReadByte
	.long	SRAM_WriteByte
	.long	SRAM_ReadBuffer
	.long	SRAM_WriteBuffer

// Timer event managment
	.long 	TIMER_Start
	.long  	TIMER_Stop
	.long  	TIMER_SetEventCallback
			
// Second set of function for GLCD
	.long  	GLCD_DrawImagefromSRAM
	.long  	GLCD_LayerScrollMode
	.long  	GLCD_SetScrollWindow
	.long 	GLCD_ScrollVertical
	.long  	GLCD_ScrollHorizontal
	.long  	GLCD_LayerDisplayMode
	.long  	GLCD_LayerTransparency
	.long  	GLCD_SetLayer
	.long  	GLCD_BTESetSource
	.long  	GLCD_BTESetDestination
	.long  	GLCD_BTESetSize
	.long  	GLCD_BTESetBackgroundColor
	.long  	GLCD_BTESetForegroundColor
	.long  	GLCD_BTESetPatternNumber

.long  	GLCD_SetTransparentColor
	.long  	GLCD_BTEStart
	.long   GLCD_BTEStartAndFillFromSRAM
			
ABI_Ptr_Table_End:	

        .size	ABI_Ptr_Table, . - ABI_Ptr_Table

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****/
