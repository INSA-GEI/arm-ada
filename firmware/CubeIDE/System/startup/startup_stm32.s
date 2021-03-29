/**
  ******************************************************************************
  * @file      startup_stm32.s
  * @author    Ac6
  * @version   V1.0.0
  * @date      12-June-2014
  ******************************************************************************
  */

	.syntax unified
	.cpu cortex-m4
	.thumb

	.global	g_pfnVectors
	.global	Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
	.word	_sidata
/* start address for the .data section. defined in linker script */
	.word	_sdata
/* end address for the .data section. defined in linker script */
	.word	_edata
/* start address for the .bss section. defined in linker script */
	.word	_sbss
/* end address for the .bss section. defined in linker script */
	.word	_ebss

	.equ  BootRAM,        0xF1E0F85F
	.equ _System_Stack_Size, 0x200
	.equ _App_Stack_Size, 0x4

/**
 * @brief  Area for interrupt vector located in RAM
 * @param  None
 * @retval : None
*/
/*	.section	.VECTORTABLE
	.global VectorTable
	.align 9
VectorTable:
	.fill 96, 4, 0
	.size	VectorTable, .-VectorTable*/

/**
 * @brief  Area for system stack
 * @param  None
 * @retval : None
*/
	.section	SYSSTACK
	.global SystemStack
SystemStack:
	.space _System_Stack_Size
	.size	SystemStack, .-SystemStack

/**
 * @brief  Area for application stack
 * @param  None
 * @retval : None
*/
	.section	APPSTACK
	.global AppStack
AppStack:
	.space _App_Stack_Size
	.size	AppStack, .-AppStack

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
*/

    .section	.text.Reset_Handler
	.type	Reset_Handler, %function
	.global Reset_Handler
Reset_Handler:

	ldr r0, =SystemInit
    blx r0

/* Copy the data segment initializers from flash to SRAM */
  	movs	r1, #0
  	b	LoopCopyDataInit

CopyDataInit:
	ldr	r3, =_sidata
	ldr	r3, [r3, r1]
	str	r3, [r0, r1]
	adds	r1, r1, #4

LoopCopyDataInit:
	ldr	r0, =_sdata
	ldr	r3, =_edata
	adds	r2, r0, r1
	cmp	r2, r3
	bcc	CopyDataInit
	ldr	r2, =_sbss
	b	LoopFillZerobss
/* Zero fill the bss segment. */
FillZerobss:
	movs r3, #0
 	str  r3, [r2]
	adds r2, r2, #4

LoopFillZerobss:
	ldr	r3, = _ebss
	cmp	r2, r3
	bcc	FillZerobss

//
// Enable FPU
//
.equ _CPACR,	0xE000ED88		// CPACR is located at address 0xE000ED88

	LDR.W 	R0, =_CPACR
	LDR 	R1, [R0]				// Read CPACR
	ORR 	R1, R1, #(0xF << 20)	// Set bits 20-23 to enable CP10 and CP11 coprocessors
	STR 	R1, [R0]				// Write back the modified value to the CPACR
	DSB								// Wait for store to complete
	ISB								// Reset pipeline now the FPU is enabled

//
// Enable UsageFault, MemFault and Busfault interrupts
//
.equ _SHCSR,	0xE000ED24		// SHCSR is located at address 0xE000ED24
	LDR.W	R0, =_SHCSR
	LDR 	R1, [R0]				// Read CPACR
	ORR 	R1, R1, #(0x7 << 16)	// Set bits 16,17,18 to enable usagefault, busfault, memfault interrupts
	STR 	R1, [R0]				// Write back the modified value to the CPACR
	DSB								// Wait for store to complete

//
// Set priority grouping (PRIGROUP) in AIRCR to 3 (16 levels for group priority and 0 for subpriority)
//
.equ _AIRCR,		0xE000ED0C
.equ _AIRCR_VAL,	0x05FA0300
	LDR.W	R0, =_AIRCR
	LDR.W	R1, =_AIRCR_VAL
	STR		R1,[R0]

// reset stack
	LDR     R0, =__initial_sp
	MOV		SP,R0

/* Call static constructors */
//    bl __libc_init_array
/* Call the application's entry point.*/
	bl	main

LoopForever:
    b LoopForever

	.size	Reset_Handler, .-Reset_Handler

/**
 * @brief  This function help move stack ptr to defined area
 *
 * @param  R0: System stack
 * @param  R1: Application stack
 * @retval : None
*/
	.section	.text.SetStack
	.type	SetStack, %function
	.global SetStack
SetStack:
	CPSID	i // Disable interrupts

	//LDR 	R0, =__initial_sp
	MSR		MSP, R0
	MSR		PSP, R1

	MOV		R0, #0
	MSR		CONTROL, R0 // MSP in use, Privileged, Float point registers will not be saved

	ISB		// Flush cache

	LDR 	R0, =#0xDEADBEEF
	LDR		R1, =#0x10000000
	LDR		R2, =#0x10000400
SetStack_LoopSystemStack:
	STR		R0,[R1]
	ADD		R1,R1,#4
	CMP		R1,R2
	BNE		SetStack_LoopSystemStack

	LDR		R1, =#0x20009000
	LDR		R2, =#0x2000A000
SetStack_LoopApplicationStack:
	STR		R0,[R1]
	ADD		R1,R1,#4
	CMP		R1,R2
	BNE		SetStack_LoopApplicationStack

	CPSIE	i // Enable back interrupts
	BX		LR
	.size	SetStack, .-SetStack

// Dummy Exception Handlers (infinite loops which can be modified)
	.section	.text.NMI_Handler
	.type	NMI_Handler, %function
	.global NMI_Handler
NMI_Handler:
	MOV		R0, #0
	MOV 	R1, SP
    B       PANIC_ReadStack

	.section	.text.HardFault_Handler
	.type	HardFault_Handler, %function
	.global HardFault_Handler
HardFault_Handler:
    MOV		R0, #1
	MOV 	R1, SP
    B       PANIC_ReadStack

	.section	.text.MemManage_Handler
	.type	MemManage_Handler, %function
	.global MemManage_Handler
MemManage_Handler:
    MOV		R0, #2
	MOV 	R1, SP
    B       PANIC_ReadStack

	.section	.text.BusFault_Handler
	.type	BusFault_Handler, %function
	.global BusFault_Handler
BusFault_Handler:
    MOV		R0, #3
	MOV 	R1, SP
    B       PANIC_ReadStack

	.section	.text.UsageFault_Handler
	.type	UsageFault_Handler, %function
	.global UsageFault_Handler
UsageFault_Handler:
    MOV		R0, #4
	MOV 	R1, SP
    B       PANIC_ReadStack


/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
*/
    .section	.text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
	b	Infinite_Loop
	.size	Default_Handler, .-Default_Handler
/******************************************************************************
*
* The minimal vector table for a Cortex-M.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
 	.section	.isr_vector,"a",%progbits
	.type	g_pfnVectors, %object
	.size	g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
	.word	Reset_Handler
	.word	ABI_Table

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

	.weak	SystemInit

/************************ (C) COPYRIGHT Ac6 *****END OF FILE****/
