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

				AREA    VECTORTABLE, DATA, READWRITE, ALIGN=9
VectorTable		SPACE	4*96
				EXPORT  VectorTable
					
; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x0001FC

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB
				
; Import ABI_Table Symbol
 IMPORT  ABI_Table 

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     Reset_Handler              ; Reset Handler
                DCD     ABI_Table                  ; ABI Tablea address  
                         
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
        IMPORT  __main

                LDR     R0, =SystemInit
                BLX     R0		
;
; Enable FPU
;
_CPACR			EQU     0xE000ED88		; CPACR is located at address 0xE000ED88

				LDR.W 	R0, =_CPACR				
				LDR 	R1, [R0]				; Read CPACR
				ORR 	R1, R1, #(0xF << 20)	; Set bits 20-23 to enable CP10 and CP11 coprocessors
				STR 	R1, [R0]				; Write back the modified value to the CPACR
				DSB								; Wait for store to complete
				ISB								; Reset pipeline now the FPU is enabled

;
; Enable UsageFault, MemFault and Busfault interrupts
;
_SHCSR			EQU     0xE000ED24		; SHCSR is located at address 0xE000ED24
				LDR.W	R0, =_SHCSR				
				LDR 	R1, [R0]				; Read CPACR
				ORR 	R1, R1, #(0x7 << 16)	; Set bits 16,17,18 to enable usagefault, busfault, memfault interrupts
				STR 	R1, [R0]				; Write back the modified value to the CPACR
				DSB								; Wait for store to complete

;
; Set priority grouping (PRIGROUP) in AIRCR to 3 (16 levels for group priority and 0 for subpriority)
;
_AIRCR			EQU		0xE000ED0C
_AIRCR_VAL		EQU		0x05FA0300
				LDR.W	R0, =_AIRCR
				LDR.W	R1, =_AIRCR_VAL
				STR		R1,[R0]
		
; reset stack
				LDR     R0, =__initial_sp
				MOV		SP,R0

;
; Finaly, jump to main function (void main (void))
;
                LDR     R0, =__main
                BX      R0
                ENDP

SystemInit		PROC				 
				EXPORT  SystemInit                    [WEAK]    
				BX		LR
				ENDP


SetStack		PROC				 
				EXPORT  SetStack                   
; 
; Set stack to 0x10000800
;
				LDR 	R0, =__initial_sp
				MOV		SP, R0
				BX		LR
				ENDP
				
; Dummy Exception Handlers (infinite loops which can be modified)
				IMPORT 	PANIC_ReadStack
				
NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
				MOV		R0, #0
				MOV 	R1, SP
                B       PANIC_ReadStack
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                MOV		R0, #1
				MOV 	R1, SP
                B       PANIC_ReadStack
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler          [WEAK]
                MOV		R0, #2
				MOV 	R1, SP
                B       PANIC_ReadStack
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler           [WEAK]
                MOV		R0, #3
				MOV 	R1, SP
                B       PANIC_ReadStack
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler         [WEAK]
                MOV		R0, #4
				MOV 	R1, SP
                B       PANIC_ReadStack
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler           [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WWDG_IRQHandler                   [WEAK]                                        
                EXPORT  PVD_IRQHandler                    [WEAK]                      
                EXPORT  TAMPER_STAMP_IRQHandler             [WEAK]         
                EXPORT  RTC_WKUP_IRQHandler               [WEAK]                     
                EXPORT  FLASH_IRQHandler                  [WEAK]                                         
                EXPORT  RCC_IRQHandler                    [WEAK]                                            
                EXPORT  EXTI0_IRQHandler                  [WEAK]                                            
                EXPORT  EXTI1_IRQHandler                  [WEAK]                                             
                EXPORT  EXTI2_TS_IRQHandler                  [WEAK]                                            
                EXPORT  EXTI3_IRQHandler                  [WEAK]                                           
                EXPORT  EXTI4_IRQHandler                  [WEAK]                                            
                EXPORT  DMA1_Channel1_IRQHandler          [WEAK]                                
                EXPORT  DMA1_Channel2_IRQHandler          [WEAK]                                   
                EXPORT  DMA1_Channel3_IRQHandler          [WEAK]                                   
                EXPORT  DMA1_Channel4_IRQHandler          [WEAK]                                   
                EXPORT  DMA1_Channel5_IRQHandler          [WEAK]                                   
                EXPORT  DMA1_Channel6_IRQHandler          [WEAK]                                   
                EXPORT  DMA1_Channel7_IRQHandler          [WEAK]                                   
                EXPORT  ADC1_2_IRQHandler                 [WEAK]                         
                EXPORT  USB_HP_CAN1_TX_IRQHandler         [WEAK]                                                
                EXPORT  USB_LP_CAN1_RX0_IRQHandler        [WEAK]                                               
                EXPORT  CAN1_RX1_IRQHandler               [WEAK]                                                
                EXPORT  CAN1_SCE_IRQHandler               [WEAK]                                                
                EXPORT  EXTI9_5_IRQHandler                [WEAK]                                    
                EXPORT  TIM1_BRK_TIM15_IRQHandler         [WEAK]                  
                EXPORT  TIM1_UP_TIM16_IRQHandler          [WEAK]                
                EXPORT  TIM1_TRG_COM_TIM17_IRQHandler     [WEAK] 
                EXPORT  TIM1_CC_IRQHandler                [WEAK]                                   
                EXPORT  TIM2_IRQHandler                   [WEAK]                                            
                EXPORT  TIM3_IRQHandler                   [WEAK]                                            
                EXPORT  TIM4_IRQHandler                   [WEAK]                                            
                EXPORT  I2C1_EV_IRQHandler                [WEAK]                                             
                EXPORT  I2C1_ER_IRQHandler                [WEAK]                                             
                EXPORT  I2C2_EV_IRQHandler                [WEAK]                                            
                EXPORT  I2C2_ER_IRQHandler                [WEAK]                                               
                EXPORT  SPI1_IRQHandler                   [WEAK]                                           
                EXPORT  SPI2_IRQHandler                   [WEAK]                                            
                EXPORT  USART1_IRQHandler                 [WEAK]                                          
                EXPORT  USART2_IRQHandler                 [WEAK]                                          
                EXPORT  USART3_IRQHandler                 [WEAK]                                         
                EXPORT  EXTI15_10_IRQHandler              [WEAK]                                  
                EXPORT  RTC_Alarm_IRQHandler              [WEAK]                  
                EXPORT  USBWakeUp_IRQHandler               [WEAK]                        
                EXPORT  TIM8_BRK_IRQHandler               [WEAK]                 
                EXPORT  TIM8_UP_IRQHandler                [WEAK]                 
                EXPORT  TIM8_TRG_COM_IRQHandler           [WEAK] 
                EXPORT  TIM8_CC_IRQHandler                [WEAK]
                EXPORT  ADC3_IRQHandler                   [WEAK]                                   
                EXPORT  SPI3_IRQHandler                   [WEAK]                                             
                EXPORT  UART4_IRQHandler                  [WEAK]                                            
                EXPORT  UART5_IRQHandler                  [WEAK]                                            
                EXPORT  TIM6_DAC_IRQHandler               [WEAK]                   
                EXPORT  TIM7_IRQHandler                   [WEAK]                    
                EXPORT  DMA2_Channel1_IRQHandler          [WEAK]                                  
                EXPORT  DMA2_Channel2_IRQHandler          [WEAK]                                   
                EXPORT  DMA2_Channel3_IRQHandler          [WEAK]                                    
                EXPORT  DMA2_Channel4_IRQHandler          [WEAK]                                    
                EXPORT  DMA2_Channel5_IRQHandler          [WEAK]
                EXPORT  ADC4_IRQHandler                   [WEAK]                                 
                EXPORT  COMP1_2_3_IRQHandler              [WEAK]                                               
                EXPORT  COMP4_5_6_IRQHandler              [WEAK]                                               
                EXPORT  COMP7_IRQHandler                  [WEAK]                                               
                EXPORT  USB_HP_IRQHandler                 [WEAK]                      
                EXPORT  USB_LP_IRQHandler                 [WEAK]                      
                EXPORT  USBWakeUp_RMP_IRQHandler              [WEAK]                        
                EXPORT  FPU_IRQHandler                    [WEAK]                

WWDG_IRQHandler                                                       
PVD_IRQHandler                                      
TAMPER_STAMP_IRQHandler                  
RTC_WKUP_IRQHandler                                
FLASH_IRQHandler                                                       
RCC_IRQHandler                                                            
EXTI0_IRQHandler                                                          
EXTI1_IRQHandler                                                           
EXTI2_TS_IRQHandler                                                          
EXTI3_IRQHandler                                                         
EXTI4_IRQHandler                                                          
DMA1_Channel1_IRQHandler                                       
DMA1_Channel2_IRQHandler                                          
DMA1_Channel3_IRQHandler                                          
DMA1_Channel4_IRQHandler                                          
DMA1_Channel5_IRQHandler                                          
DMA1_Channel6_IRQHandler                                          
DMA1_Channel7_IRQHandler                                          
ADC1_2_IRQHandler                                         
USB_HP_CAN1_TX_IRQHandler                                                            
USB_LP_CAN1_RX0_IRQHandler                                                          
CAN1_RX1_IRQHandler                                                           
CAN1_SCE_IRQHandler                                                           
EXTI9_5_IRQHandler                                                
TIM1_BRK_TIM15_IRQHandler                        
TIM1_UP_TIM16_IRQHandler                      
TIM1_TRG_COM_TIM17_IRQHandler  
TIM1_CC_IRQHandler                                               
TIM2_IRQHandler                                                           
TIM3_IRQHandler                                                           
TIM4_IRQHandler                                                           
I2C1_EV_IRQHandler                                                         
I2C1_ER_IRQHandler                                                         
I2C2_EV_IRQHandler                                                        
I2C2_ER_IRQHandler                                                           
SPI1_IRQHandler                                                          
SPI2_IRQHandler                                                           
USART1_IRQHandler                                                       
USART2_IRQHandler                                                       
USART3_IRQHandler                                                      
EXTI15_10_IRQHandler                                            
RTC_Alarm_IRQHandler                            
USBWakeUp_IRQHandler                                
TIM8_BRK_IRQHandler                      
TIM8_UP_IRQHandler                       
TIM8_TRG_COM_IRQHandler  
TIM8_CC_IRQHandler  
ADC3_IRQHandler                                             
SPI3_IRQHandler                                                            
UART4_IRQHandler                                                          
UART5_IRQHandler                                                          
TIM6_DAC_IRQHandler                            
TIM7_IRQHandler                              
DMA2_Channel1_IRQHandler                                          
DMA2_Channel2_IRQHandler                                           
DMA2_Channel3_IRQHandler                                           
DMA2_Channel4_IRQHandler                                        
DMA2_Channel5_IRQHandler
ADC4_IRQHandler
COMP1_2_3_IRQHandler                                                          
COMP4_5_6_IRQHandler                                                          
COMP7_IRQHandler                                                          
USB_HP_IRQHandler                           
USB_LP_IRQHandler                            
USBWakeUp_RMP_IRQHandler                                
FPU_IRQHandler                                                      

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap
                 
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****
