/* File Name          : startup_gcc.s
* Purpose: startup file for Cortex-M3 devices. Should use with 
 *   GCC for ARM Embedded Processors
 * Version: V1.2
 * Date: 15 Nov 2011
 * 
 * Copyright (c) 2011, ARM Limited
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the ARM Limited nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARM LIMITED BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	*/
	
	.syntax unified
	.arch armv7-m
	.cpu cortex-m4
	.fpu softvfp
	
	.section .stack
	.align 3
	
/*
  Amount of memory (in bytes) allocated for Stack
 Tailor this value to your application needs
 <h> Stack Configuration
   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
 </h>
	*/
	
#ifdef __STACK_SIZE
	.equ    Stack_Size, __STACK_SIZE
#else
	.equ    Stack_Size, 0x000050
#endif
	.global    __StackTop
	.global    __StackLimit
	.globl	__initial_sp
__StackLimit:
	.space    Stack_Size
	.size __StackLimit, . - __StackLimit
__StackTop:
	.size __StackTop, . - __StackTop
__initial_sp:	

/*
 <h> Heap Configuration
   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
 </h>
	*/
	
	.section .heap
	.align 3
#ifdef __HEAP_SIZE
	.equ    Heap_Size, __HEAP_SIZE
#else
	.equ    Heap_Size, 0x4
#endif
	.global    __HeapBase
	.global    __HeapLimit
	.globl	 __heap_base
	.globl	__heap_limit
__HeapBase:
__heap_base:	
	.space    Heap_Size
	.size __HeapBase, . - __HeapBase
__HeapLimit:
__heap_limit:
	.size _HeapLimit, . - __HeapLimit


	
	.section .isr_vector
	.align 2
	.global __isr_vector
__isr_vector:
	.long    Reset_Handler         /* Reset Handler */
	.long    ABI_Table             /* Abi Table Entry point */
	.size    __isr_vector, . - __isr_vector


	.text
	.thumb
	.thumb_func
	.align 2
	.global    Reset_Handler
	.type    Reset_Handler, %function
Reset_Handler:

	LDR     R0, =SystemInit
        BLX     R0
	
/*  Enable FPU */
	.equ  	_CPACR, 0xE000ED88		// CPACR is located at address 0xE000ED88

	LDR.W 	R0, =_CPACR				
	LDR 	R1, [R0]		// Read CPACR
	ORR 	R1, R1, #(0xF << 20)	// Set bits 20-23 to enable CP10 and CP11 coprocessors
	STR 	R1, [R0]		// Write back the modified value to the CPACR
	DSB				// Wait for store to complete
	ISB				// Reset pipeline now the FPU is enabled

/* Enable UsageFault, MemFault and Busfault interrupts */
	.equ 	_SHCSR, 0xE000ED24		// SHCSR is located at address 0xE000ED24
	
	LDR.W	R0, =_SHCSR				
	LDR 	R1, [R0]		// Read CPACR
	ORR 	R1, R1, #(0x7 << 16)	// Set bits 16,17,18 to enable usagefault, busfault, memfault interrupts
	STR 	R1, [R0]		// Write back the modified value to the CPACR
	DSB				// Wait for store to complete


/* Set priority grouping (PRIGROUP) in AIRCR to 3 (16 levels for group priority and 0 for subpriority) */

	.equ	_AIRCR,0xE000ED0C
	.equ	_AIRCR_VAL,0x05FA0300

	LDR.W	R0, =_AIRCR
	LDR.W	R1, =_AIRCR_VAL
	STR	R1,[R0]
		

/* Finaly, jump to main function (void main (void)) */
	
	LDR     R0, =main
	BX      R0

	.pool
	.size Reset_Handler, . - Reset_Handler
	
	.thumb
	.thumb_func
	.align 2
	.weak     SetStack
	.global    SetStack
	.type    SetStack, %function
SetStack:	
 
/* Set stack to 0x10002000 */

	LDR 	R0, = 0x10001FF4
	MOV	SP, R0
	BX	LR

	.pool
	.size SetStack, . - SetStack

	.thumb
	.thumb_func
	.align 2
	.weak     _fini
	.global    _fini
	.type    _fini, %function
_fini:

	bx 		lr
	.pool
	.size _fini, . - _fini
	
 
				
/* Dummy Exception Handlers (infinite loops which can be modified) */
	//IMPORT 	PANIC_ReadStack

	.weak	NMI_Handler
	.type	NMI_Handler, %function
NMI_Handler:	

	MOV	R0, #0
	MOV 	R1, SP
	B       PANIC_ReadStack
	.size	NMI_Handler, . - NMI_Handler

	.weak	HardFault_Handler
	.type	HardFault_Handler, %function	
HardFault_Handler:	
        MOV	R0, #1
	MOV 	R1, SP
        B       PANIC_ReadStack
        .size	HardFault_Handler, . - HardFault_Handler
	
	.weak	MemManage_Handler
	.type	MemManage_Handler, %function	
MemManage_Handler:	
	MOV	R0, #2
	MOV 	R1, SP
        B       PANIC_ReadStack
        .size	MemManage_Handler, . - MemManage_Handler
	
	.weak	BusFault_Handler
	.type	BusFault_Handler, %function
BusFault_Handler:	
	MOV	R0, #3
	MOV 	R1, SP
	B       PANIC_ReadStack
        .size	BusFault_Handler, . - BusFault_Handler

	.weak	UsageFault_Handler
	.type	UsageFault_Handler, %function	
UsageFault_Handler:	
        MOV	R0, #4
	MOV 	R1, SP
        B       PANIC_ReadStack
        .size	UsageFault_Handler, . - UsageFault_Handler

	.weak	SVC_Handler
	.type	SVC_Handler, %function	
SVC_Handler:	
        B       .
        .size	SVC_Handler, . - SVC_Handler

	.weak	DebugMon_Handler
	.type	DebugMon_Handler, %function	
DebugMon_Handler:	
        B       .
        .size	DebugMon_Handler, . - DebugMon_Handler

	.weak	PendSV_Handler
	.type	PendSV_Handler, %function	
PendSV_Handler:	
        B       .
        .size	PendSV_Handler, . - PendSV_Handler

	.weak	SysTick_Handler
	.type	SysTick_Handler, %function	
SysTick_Handler:	
        B       .
        .size	SysTick_Handler, . - SysTick_Handler

	.type 	Default_Handler, %function
Default_Handler:
	B	.
	.size	Default_Handler, . - Default_Handler

	/* this is the macro to point an handler on default handler */
	.macro IRQ handler
		.weak	\handler
		.type	\handler, %function
		.set 	\handler, Default_Handler
	.endm

	IRQ WWDG_IRQHandler                                                       
	IRQ PVD_IRQHandler                                      
	IRQ TAMPER_STAMP_IRQHandler                  
	IRQ RTC_WKUP_IRQHandler                                
	IRQ FLASH_IRQHandler                                                       
	IRQ RCC_IRQHandler                                                            
	IRQ EXTI0_IRQHandler                                                          
	IRQ EXTI1_IRQHandler                                                           
	IRQ EXTI2_TS_IRQHandler                                                          
	IRQ EXTI3_IRQHandler                                                         
	IRQ EXTI4_IRQHandler                                                          
	IRQ DMA1_Channel1_IRQHandler                                       
	IRQ DMA1_Channel2_IRQHandler                                          
	IRQ DMA1_Channel3_IRQHandler                                          
	IRQ DMA1_Channel4_IRQHandler                                          
	IRQ DMA1_Channel5_IRQHandler                                          
	IRQ DMA1_Channel6_IRQHandler                                          
	IRQ DMA1_Channel7_IRQHandler                                          
	IRQ ADC1_2_IRQHandler                                         
	IRQ USB_HP_CAN1_TX_IRQHandler                                                            
	IRQ USB_LP_CAN1_RX0_IRQHandler                                                          
	IRQ CAN1_RX1_IRQHandler                                                           
	IRQ CAN1_SCE_IRQHandler                                                           
	IRQ EXTI9_5_IRQHandler                                                
	IRQ TIM1_BRK_TIM15_IRQHandler                        
	IRQ TIM1_UP_TIM16_IRQHandler                      
	IRQ TIM1_TRG_COM_TIM17_IRQHandler  
	IRQ TIM1_CC_IRQHandler                                               
	IRQ TIM2_IRQHandler                                                           
	IRQ TIM3_IRQHandler                                                           
	IRQ TIM4_IRQHandler                                                           
	IRQ I2C1_EV_IRQHandler                                                         
	IRQ I2C1_ER_IRQHandler                                                         
	IRQ I2C2_EV_IRQHandler                                                        
	IRQ I2C2_ER_IRQHandler                                                           
	IRQ SPI1_IRQHandler                                                          
	IRQ SPI2_IRQHandler                                                           
	IRQ USART1_IRQHandler                                                       
	IRQ USART2_IRQHandler                                                       
	IRQ USART3_IRQHandler                                                      
	IRQ EXTI15_10_IRQHandler                                            
	IRQ RTC_Alarm_IRQHandler                            
	IRQ USBWakeUp_IRQHandler                                
	IRQ TIM8_BRK_IRQHandler                      
	IRQ TIM8_UP_IRQHandler                       
	IRQ TIM8_TRG_COM_IRQHandler  
	IRQ TIM8_CC_IRQHandler  
	IRQ ADC3_IRQHandler                                             
	IRQ SPI3_IRQHandler                                                            
	IRQ UART4_IRQHandler                                                          
	IRQ UART5_IRQHandler                                                          
	IRQ TIM6_DAC_IRQHandler                            
	IRQ TIM7_IRQHandler                              
	IRQ DMA2_Channel1_IRQHandler                                          
	IRQ DMA2_Channel2_IRQHandler                                           
	IRQ DMA2_Channel3_IRQHandler                                           
	IRQ DMA2_Channel4_IRQHandler                                        
	IRQ DMA2_Channel5_IRQHandler
	IRQ ADC4_IRQHandler
	IRQ COMP1_2_3_IRQHandler                                                          
	IRQ COMP4_5_6_IRQHandler                                                          
	IRQ COMP7_IRQHandler                                                          
	IRQ USB_HP_IRQHandler                           
	IRQ USB_LP_IRQHandler                            
	IRQ USBWakeUp_RMP_IRQHandler                                
	IRQ FPU_IRQHandler 

/*******************************************************************************
 User Stack and Heap initialization
*******************************************************************************/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****/
