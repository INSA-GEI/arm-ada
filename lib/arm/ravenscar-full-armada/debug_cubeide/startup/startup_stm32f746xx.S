/**
  ******************************************************************************
  * @file      startup_stm32f746xx.s
  * @author    MCD Application Team
  * @brief     STM32F746xx Devices vector table for GCC based toolchain. 
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M7 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
    
        .syntax unified
        .cpu cortex-m7
        .fpu softvfp
        .thumb

        .global  g_pfnVectors
        .global  Default_Handler

/* start address for the initialization values of the .data section. 
defined in linker script */
        .word  _sidata
/* start address for the .data section. defined in linker script */  
        .word  _sdata
/* end address for the .data section. defined in linker script */
        .word  _edata
/* start address for the .bss section. defined in linker script */
        .word  _sbss
/* end address for the .bss section. defined in linker script */
        .word  _ebss

/* start and end addresses of stack, used for filling with pattern */
        .word  __stack_start
        .word  __stack_end

/* start and end addresses of interrupt stack, used for filling with pattern */
        .word  __interrupt_stack_start
        .word  __interrupt_stack_end

/* start, end and load addresses for vector tables in ram */
        .word  _svector_table
        .word  _evector_table
        .word  _sivector_table

/**
 * @brief  This code fill stack with pattern for computing usage
 * @param  None
 * @retval : None
*/
        .section  .text._fill_stack
        .thumb_func
        .globl	_fill_stack
        .type   _fill_stack, #function
_fill_stack:
1:      cmp  r0, r1
        beq  0f

        str  r2,[r0], #4
        b    1b

0:      bx lr
        .size _fill_stack, . - _fill_stack

/**
 * @brief  : This code copy vector table from flash to ram
 * @param  : None
 * @retval : None
*/
        .section  .text._copy_vector_table
        .thumb_func
        .globl	_copy_vector_table
        .type   _copy_vector_table, #function
_copy_vector_table:
        ldr   r0, =_svector_table
        ldr   r1, =_evector_table
        ldr   r2, =_sivector_table

1:      cmp   r0, r1
        beq   0f

        ldr   r3, [r2], #4
        str   r3, [r0], #4
        b     1b

0:      bx    lr
        .size _copy_vector_table, . - _copy_vector_table

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called. 
 * @param  None
 * @retval : None
*/
        .section  .text._stm32_start_common
      	.thumb_func
        .globl	_stm32_start_common
        .type   _stm32_start_common, #function
_stm32_start_common:

        /************************
        * Enable debug Monitor *
        ************************/

        /* Debug register definition */
        .set    DEMCR,  0xE000EDFC

        /* Enable the debug monitor so that bkpt instructions are not treated
         * as hard fault when no debugger is attached */
        ldr     r0, =DEMCR
        ldr     r1, [r0]
        orr     r1, r1, #0x10000 /* Set MON_EN in DEMCR */
        str     r1, [r0]

        /**************/
        /* Enable FPU */
        /**************/
        .set     CPACR, 0xE000ED88
        .set     FPU_MASK,(0xF << 20)

        ldr      r0, =CPACR
        ldr      r1, [r0]
        orr      r1, r1,#FPU_MASK
        str      r1, [r0]

        dsb
        isb

        /*************************/
        /* Enable Fault handlers */
        /*************************/
        .set     SHCSR, 0xE000ED24
        .set     FAULT_MASK, (0x1<<18) + (0x1<<17) + (0x1<<16)

        ldr      r0, =SHCSR
        ldr      r1, [r0]
        orr      r1, r1,#FAULT_MASK
        str      r1, [r0]

        dsb
        isb

        /*************************
         * Check MCU = Cortex-M7 *
        *************************/
        .set    MCU_ID_REG, 0xE0042000

        ldr     r0, =MCU_ID_REG
        ldr     r1, [r0]
        ldr     r2, =#0xFFF
        and     r1, r1, r2  /* Retrieve the DEV_ID field of the MCU_ID reg */
        ldr     r2, =#0x449
        cmp     r1, r2      /* Compare to STM32F74xxx/75xxx Dev ID */
        beq      init_cache
        ldr     r2, =#0x451
        cmp     r1, r2      /* Compare to STM32F76xxx/77xxx Dev ID */
        bne     end         /* Do not initialize cache on STM32F4 */

init_cache:
        /********************
         * Enable I/D cache *
        ********************/

        /* Register definition for cache handling */
        .set    CCSIDR,  0xE000ED80
        .set    CSSELR,  0xE000ED84
        .set    DCISW,   0xE000EF60
        .set    ICIALLU, 0xE000EF50
        .set    CCR,     0xE000ED14

        /* First invalidate the data cache */
        mov     r0, #0x0
        ldr     r11, =CSSELR
        str     r0, [r11]       /* Select the data cache size */
        dsb

        ldr     r11, =CCSIDR
        ldr     r2, [r11]       /* Cache size identification */
        and     r1, r2, #0x7    /* Number of words in a cache line */
        add     r7, r1, #0x4

        ubfx    r4, r2, #3, #10  /* r4 = number of ways - 1 of data cache */
        ubfx    r2, r2, #13, #15 /* r2 = number of sets - 1 of data cache */
        clz     r6, r4           /* Calculate bit offset for "way" in DCISW */

        ldr     r11, =DCISW

inv_loop1:                       /* For each set */
        mov     r1, r4
        lsls    r8, r2, r7

inv_loop2:                       /* For each way */
        lsls    r3, r1, r6
        orrs    r3, r3, r8

        str     r3, [r11]        /* Invalidate the D-Cache line */
        subs    r1, r1, #1
        bge     inv_loop2
        subs    r2, r2, #1
        bge     inv_loop1

        dsb

        /* Now invalidate the instruction cache */
        mov     r0, #0x0
        ldr     r11, =ICIALLU
        str     r0, [r11]

        dsb
        isb

        /* Finally enable Instruction and Data cache */
        ldr     r11, =CCR
        ldr     r0, [r11]
        orr     r0, r0, #(0x30000) /* Sets the I and D cache enabled fields */
        str     r0, [r11]

        dsb
        isb

        /* Wait for store to complete and reset pipeline with FPU enabled  */
        dsb
        isb

        /*****************************
         * TCM Memory initialisation *
        *****************************/
tcm_init:
        .set    CM7_ITCMCR, 0xE000EF90
        .set    CM7_DTCMCR, 0xE000EF94

        ldr     r0, =CM7_ITCMCR
        ldr     r1, [r0]
        orr     r1, r1, #0x1 /* set the EN field */
        str     r1, [r0]

        ldr     r0, =CM7_DTCMCR
        ldr     r1, [r0]
        orr     r1, r1, #0x1 /* set the EN field */
        str     r1, [r0]

        dsb
        isb

end:
        bx lr
        .size _stm32_start_common, . - _stm32_start_common

        .section  .text.Reset_Handler
        .weak  Reset_Handler
        .type  Reset_Handler, %function
Reset_Handler:  
        ldr  sp, =_estack      /* set stack pointer */

        /* Copy the data segment initializers from flash to SRAM */  
        movs r1, #0
        b    LoopCopyDataInit

CopyDataInit:
        ldr  r3, =_sidata
        ldr  r3, [r3, r1]
        str  r3, [r0, r1]
        adds r1, r1, #4
    
LoopCopyDataInit:
        ldr  r0, =_sdata
        ldr  r3, =_edata
        adds r2, r0, r1
        cmp  r2, r3
        bcc  CopyDataInit
        ldr  r2, =_sbss
        b    LoopFillZerobss

        /* Zero fill the bss segment. */  
FillZerobss:
        movs r3, #0
        str  r3, [r2], #4
    
LoopFillZerobss:
        ldr  r3, = _ebss
        cmp  r2, r3
        bcc  FillZerobss

        /* Call the clock system initialization function.*/
        bl   SystemInit

        /* Init cache, FPU and fault handlers */
        bl   _stm32_start_common

        /* fill stack with pattern */
        .set STACK_PATTERN,  0xDEADBEEF

        ldr  r0, =__stack_start
        ldr  r1, =__stack_end
        ldr  r2, =STACK_PATTERN
        bl   _fill_stack

        /* fill interrupt stack with pattern */
        .set INTERRUPT_STACK_PATTERN,  0xCAFEBABE

        ldr  r0, =__interrupt_stack_start
        ldr  r1, =__interrupt_stack_end
        ldr  r2, =INTERRUPT_STACK_PATTERN
        bl   _fill_stack

        /* copy vector table in ram */
        bl   _copy_vector_table

        /* Call static constructors */
        bl   __libc_init_array
        
        /* Call the application's entry point.*/
        bl   main
        bx   lr
        .size  Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an 
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 * @param  None     
 * @retval None       
*/
        .section  .text.Default_Handler,"ax",%progbits
        .thumb
        .type      Default_Handler, %function
Default_Handler:
Infinite_Loop:
        b  Infinite_Loop
        .size  Default_Handler, .-Default_Handler

/**
 * @brief  Dummy function for __libc_init_array.
 * @param  None     
 * @retval None       
*/
        .section   .text.__libc_init_array
        .weak      __libc_init_array
        .thumb_func
        .globl	   __libc_init_array
        .type      __libc_init_array, %function
__libc_init_array:
        bx  lr
        .size  __libc_init_array, .-__libc_init_array
/******************************************************************************
*
* The minimal vector table for a Cortex M7. Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
* 
*******************************************************************************/
        .section  .isr_vector,"a",%progbits
        .type  g_pfnVectors, %object
        .size  g_pfnVectors, .-g_pfnVectors   
   
g_pfnVectors:
        .word  _estack
        .word  Reset_Handler

        .word  NMI_Handler
        .word  HardFault_Handler
        .word  MemManage_Handler
        .word  BusFault_Handler
        .word  UsageFault_Handler
        .word  0
        .word  0
        .word  0
        .word  0
        .word  SVC_Handler
        .word  DebugMon_Handler
        .word  0
        .word  PendSV_Handler
        .word  SysTick_Handler
  
  /* External Interrupts */
        .word     WWDG_IRQHandler                   /* Window WatchDog              */
        .word     PVD_IRQHandler                    /* PVD through EXTI Line detection */
        .word     TAMP_STAMP_IRQHandler             /* Tamper and TimeStamps through the EXTI line */
        .word     RTC_WKUP_IRQHandler               /* RTC Wakeup through the EXTI line */
        .word     FLASH_IRQHandler                  /* FLASH                        */
        .word     RCC_IRQHandler                    /* RCC                          */
        .word     EXTI0_IRQHandler                  /* EXTI Line0                   */
        .word     EXTI1_IRQHandler                  /* EXTI Line1                   */
        .word     EXTI2_IRQHandler                  /* EXTI Line2                   */
        .word     EXTI3_IRQHandler                  /* EXTI Line3                   */
        .word     EXTI4_IRQHandler                  /* EXTI Line4                   */
        .word     DMA1_Stream0_IRQHandler           /* DMA1 Stream 0                */
        .word     DMA1_Stream1_IRQHandler           /* DMA1 Stream 1                */
        .word     DMA1_Stream2_IRQHandler           /* DMA1 Stream 2                */
        .word     DMA1_Stream3_IRQHandler           /* DMA1 Stream 3                */
        .word     DMA1_Stream4_IRQHandler           /* DMA1 Stream 4                */
        .word     DMA1_Stream5_IRQHandler           /* DMA1 Stream 5                */
        .word     DMA1_Stream6_IRQHandler           /* DMA1 Stream 6                */
        .word     ADC_IRQHandler                    /* ADC1, ADC2 and ADC3s         */
        .word     CAN1_TX_IRQHandler                /* CAN1 TX                      */
        .word     CAN1_RX0_IRQHandler               /* CAN1 RX0                     */
        .word     CAN1_RX1_IRQHandler               /* CAN1 RX1                     */
        .word     CAN1_SCE_IRQHandler               /* CAN1 SCE                     */
        .word     EXTI9_5_IRQHandler                /* External Line[9:5]s          */
        .word     TIM1_BRK_TIM9_IRQHandler          /* TIM1 Break and TIM9          */
        .word     TIM1_UP_TIM10_IRQHandler          /* TIM1 Update and TIM10        */
        .word     TIM1_TRG_COM_TIM11_IRQHandler     /* TIM1 Trigger and Commutation and TIM11 */
        .word     TIM1_CC_IRQHandler                /* TIM1 Capture Compare         */
        .word     TIM2_IRQHandler                   /* TIM2                         */
        .word     TIM3_IRQHandler                   /* TIM3                         */
        .word     TIM4_IRQHandler                   /* TIM4                         */
        .word     I2C1_EV_IRQHandler                /* I2C1 Event                   */
        .word     I2C1_ER_IRQHandler                /* I2C1 Error                   */
        .word     I2C2_EV_IRQHandler                /* I2C2 Event                   */
        .word     I2C2_ER_IRQHandler                /* I2C2 Error                   */
        .word     SPI1_IRQHandler                   /* SPI1                         */
        .word     SPI2_IRQHandler                   /* SPI2                         */
        .word     USART1_IRQHandler                 /* USART1                       */
        .word     USART2_IRQHandler                 /* USART2                       */
        .word     USART3_IRQHandler                 /* USART3                       */
        .word     EXTI15_10_IRQHandler              /* External Line[15:10]s        */
        .word     RTC_Alarm_IRQHandler              /* RTC Alarm (A and B) through EXTI Line */
        .word     OTG_FS_WKUP_IRQHandler            /* USB OTG FS Wakeup through EXTI line */
        .word     TIM8_BRK_TIM12_IRQHandler         /* TIM8 Break and TIM12         */
        .word     TIM8_UP_TIM13_IRQHandler          /* TIM8 Update and TIM13        */
        .word     TIM8_TRG_COM_TIM14_IRQHandler     /* TIM8 Trigger and Commutation and TIM14 */
        .word     TIM8_CC_IRQHandler                /* TIM8 Capture Compare         */
        .word     DMA1_Stream7_IRQHandler           /* DMA1 Stream7                 */
        .word     FMC_IRQHandler                    /* FMC                          */
        .word     SDMMC1_IRQHandler                 /* SDMMC1                       */
        .word     TIM5_IRQHandler                   /* TIM5                         */
        .word     SPI3_IRQHandler                   /* SPI3                         */
        .word     UART4_IRQHandler                  /* UART4                        */
        .word     UART5_IRQHandler                  /* UART5                        */
        .word     TIM6_DAC_IRQHandler               /* TIM6 and DAC1&2 underrun errors */
        .word     TIM7_IRQHandler                   /* TIM7                         */
        .word     DMA2_Stream0_IRQHandler           /* DMA2 Stream 0                */
        .word     DMA2_Stream1_IRQHandler           /* DMA2 Stream 1                */
        .word     DMA2_Stream2_IRQHandler           /* DMA2 Stream 2                */
        .word     DMA2_Stream3_IRQHandler           /* DMA2 Stream 3                */
        .word     DMA2_Stream4_IRQHandler           /* DMA2 Stream 4                */
        .word     ETH_IRQHandler                    /* Ethernet                     */
        .word     ETH_WKUP_IRQHandler               /* Ethernet Wakeup through EXTI line */
        .word     CAN2_TX_IRQHandler                /* CAN2 TX                      */
        .word     CAN2_RX0_IRQHandler               /* CAN2 RX0                     */
        .word     CAN2_RX1_IRQHandler               /* CAN2 RX1                     */
        .word     CAN2_SCE_IRQHandler               /* CAN2 SCE                     */
        .word     OTG_FS_IRQHandler                 /* USB OTG FS                   */
        .word     DMA2_Stream5_IRQHandler           /* DMA2 Stream 5                */
        .word     DMA2_Stream6_IRQHandler           /* DMA2 Stream 6                */
        .word     DMA2_Stream7_IRQHandler           /* DMA2 Stream 7                */
        .word     USART6_IRQHandler                 /* USART6                       */
        .word     I2C3_EV_IRQHandler                /* I2C3 event                   */
        .word     I2C3_ER_IRQHandler                /* I2C3 error                   */
        .word     OTG_HS_EP1_OUT_IRQHandler         /* USB OTG HS End Point 1 Out   */
        .word     OTG_HS_EP1_IN_IRQHandler          /* USB OTG HS End Point 1 In    */
        .word     OTG_HS_WKUP_IRQHandler            /* USB OTG HS Wakeup through EXTI */
        .word     OTG_HS_IRQHandler                 /* USB OTG HS                   */
        .word     DCMI_IRQHandler                   /* DCMI                         */
        .word     0                                 /* Reserved                     */
        .word     RNG_IRQHandler                    /* Rng                          */
        .word     FPU_IRQHandler                    /* FPU                          */
        .word     UART7_IRQHandler                  /* UART7                        */
        .word     UART8_IRQHandler                  /* UART8                        */
        .word     SPI4_IRQHandler                   /* SPI4                         */
        .word     SPI5_IRQHandler                   /* SPI5                           */
        .word     SPI6_IRQHandler                   /* SPI6                         */
        .word     SAI1_IRQHandler                   /* SAI1                          */
        .word     LTDC_IRQHandler                   /* LTDC                          */
        .word     LTDC_ER_IRQHandler                /* LTDC error                      */
        .word     DMA2D_IRQHandler                  /* DMA2D                          */
        .word     SAI2_IRQHandler                   /* SAI2                         */
        .word     QUADSPI_IRQHandler                /* QUADSPI                      */
        .word     LPTIM1_IRQHandler                 /* LPTIM1                       */
        .word     CEC_IRQHandler                    /* HDMI_CEC                     */
        .word     I2C4_EV_IRQHandler                /* I2C4 Event                   */
        .word     I2C4_ER_IRQHandler                /* I2C4 Error                   */
        .word     SPDIF_RX_IRQHandler               /* SPDIF_RX                     */
  
/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler. 
* As they are weak aliases, any function with the same name will override 
* this definition.
* 
*******************************************************************************/
   .weak      NMI_Handler
   .thumb_set NMI_Handler,Default_Handler
  
   .weak      HardFault_Handler
   .thumb_set HardFault_Handler,Default_Handler
  
   .weak      MemManage_Handler
   .thumb_set MemManage_Handler,Default_Handler
  
   .weak      BusFault_Handler
   .thumb_set BusFault_Handler,Default_Handler

   .weak      UsageFault_Handler
   .thumb_set UsageFault_Handler,Default_Handler

   .weak      SVC_Handler
   .thumb_set SVC_Handler,Default_Handler

   .weak      DebugMon_Handler
   .thumb_set DebugMon_Handler,Default_Handler

   .weak      PendSV_Handler
   .thumb_set PendSV_Handler,Default_Handler

   .weak      SysTick_Handler
   .thumb_set SysTick_Handler,Default_Handler              
  
   .weak      WWDG_IRQHandler                   
   .thumb_set WWDG_IRQHandler,Default_Handler      
                  
   .weak      PVD_IRQHandler      
   .thumb_set PVD_IRQHandler,Default_Handler
               
   .weak      TAMP_STAMP_IRQHandler            
   .thumb_set TAMP_STAMP_IRQHandler,Default_Handler
            
   .weak      RTC_WKUP_IRQHandler                  
   .thumb_set RTC_WKUP_IRQHandler,Default_Handler
            
   .weak      FLASH_IRQHandler         
   .thumb_set FLASH_IRQHandler,Default_Handler
                  
   .weak      RCC_IRQHandler      
   .thumb_set RCC_IRQHandler,Default_Handler
                  
   .weak      EXTI0_IRQHandler         
   .thumb_set EXTI0_IRQHandler,Default_Handler
                  
   .weak      EXTI1_IRQHandler         
   .thumb_set EXTI1_IRQHandler,Default_Handler
                     
   .weak      EXTI2_IRQHandler         
   .thumb_set EXTI2_IRQHandler,Default_Handler 
                 
   .weak      EXTI3_IRQHandler         
   .thumb_set EXTI3_IRQHandler,Default_Handler
                        
   .weak      EXTI4_IRQHandler         
   .thumb_set EXTI4_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream0_IRQHandler               
   .thumb_set DMA1_Stream0_IRQHandler,Default_Handler
         
   .weak      DMA1_Stream1_IRQHandler               
   .thumb_set DMA1_Stream1_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream2_IRQHandler               
   .thumb_set DMA1_Stream2_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream3_IRQHandler               
   .thumb_set DMA1_Stream3_IRQHandler,Default_Handler 
                 
   .weak      DMA1_Stream4_IRQHandler              
   .thumb_set DMA1_Stream4_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream5_IRQHandler               
   .thumb_set DMA1_Stream5_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream6_IRQHandler               
   .thumb_set DMA1_Stream6_IRQHandler,Default_Handler
                  
   .weak      ADC_IRQHandler      
   .thumb_set ADC_IRQHandler,Default_Handler
               
   .weak      CAN1_TX_IRQHandler   
   .thumb_set CAN1_TX_IRQHandler,Default_Handler
            
   .weak      CAN1_RX0_IRQHandler                  
   .thumb_set CAN1_RX0_IRQHandler,Default_Handler
                           
   .weak      CAN1_RX1_IRQHandler                  
   .thumb_set CAN1_RX1_IRQHandler,Default_Handler
            
   .weak      CAN1_SCE_IRQHandler                  
   .thumb_set CAN1_SCE_IRQHandler,Default_Handler
            
   .weak      EXTI9_5_IRQHandler   
   .thumb_set EXTI9_5_IRQHandler,Default_Handler
            
   .weak      TIM1_BRK_TIM9_IRQHandler            
   .thumb_set TIM1_BRK_TIM9_IRQHandler,Default_Handler
            
   .weak      TIM1_UP_TIM10_IRQHandler            
   .thumb_set TIM1_UP_TIM10_IRQHandler,Default_Handler

   .weak      TIM1_TRG_COM_TIM11_IRQHandler      
   .thumb_set TIM1_TRG_COM_TIM11_IRQHandler,Default_Handler
      
   .weak      TIM1_CC_IRQHandler   
   .thumb_set TIM1_CC_IRQHandler,Default_Handler
                  
   .weak      TIM2_IRQHandler            
   .thumb_set TIM2_IRQHandler,Default_Handler
                  
   .weak      TIM3_IRQHandler            
   .thumb_set TIM3_IRQHandler,Default_Handler
                  
   .weak      TIM4_IRQHandler            
   .thumb_set TIM4_IRQHandler,Default_Handler
                  
   .weak      I2C1_EV_IRQHandler   
   .thumb_set I2C1_EV_IRQHandler,Default_Handler
                     
   .weak      I2C1_ER_IRQHandler   
   .thumb_set I2C1_ER_IRQHandler,Default_Handler
                     
   .weak      I2C2_EV_IRQHandler   
   .thumb_set I2C2_EV_IRQHandler,Default_Handler
                  
   .weak      I2C2_ER_IRQHandler   
   .thumb_set I2C2_ER_IRQHandler,Default_Handler
                           
   .weak      SPI1_IRQHandler            
   .thumb_set SPI1_IRQHandler,Default_Handler
                        
   .weak      SPI2_IRQHandler            
   .thumb_set SPI2_IRQHandler,Default_Handler
                  
   .weak      USART1_IRQHandler      
   .thumb_set USART1_IRQHandler,Default_Handler
                     
   .weak      USART2_IRQHandler      
   .thumb_set USART2_IRQHandler,Default_Handler
                     
   .weak      USART3_IRQHandler      
   .thumb_set USART3_IRQHandler,Default_Handler
                  
   .weak      EXTI15_10_IRQHandler               
   .thumb_set EXTI15_10_IRQHandler,Default_Handler
               
   .weak      RTC_Alarm_IRQHandler               
   .thumb_set RTC_Alarm_IRQHandler,Default_Handler
            
   .weak      OTG_FS_WKUP_IRQHandler         
   .thumb_set OTG_FS_WKUP_IRQHandler,Default_Handler
            
   .weak      TIM8_BRK_TIM12_IRQHandler         
   .thumb_set TIM8_BRK_TIM12_IRQHandler,Default_Handler
         
   .weak      TIM8_UP_TIM13_IRQHandler            
   .thumb_set TIM8_UP_TIM13_IRQHandler,Default_Handler
         
   .weak      TIM8_TRG_COM_TIM14_IRQHandler      
   .thumb_set TIM8_TRG_COM_TIM14_IRQHandler,Default_Handler
      
   .weak      TIM8_CC_IRQHandler   
   .thumb_set TIM8_CC_IRQHandler,Default_Handler
                  
   .weak      DMA1_Stream7_IRQHandler               
   .thumb_set DMA1_Stream7_IRQHandler,Default_Handler
                     
   .weak      FMC_IRQHandler            
   .thumb_set FMC_IRQHandler,Default_Handler
                     
   .weak      SDMMC1_IRQHandler            
   .thumb_set SDMMC1_IRQHandler,Default_Handler
                     
   .weak      TIM5_IRQHandler            
   .thumb_set TIM5_IRQHandler,Default_Handler
                     
   .weak      SPI3_IRQHandler            
   .thumb_set SPI3_IRQHandler,Default_Handler
                     
   .weak      UART4_IRQHandler         
   .thumb_set UART4_IRQHandler,Default_Handler
                  
   .weak      UART5_IRQHandler         
   .thumb_set UART5_IRQHandler,Default_Handler
                  
   .weak      TIM6_DAC_IRQHandler                  
   .thumb_set TIM6_DAC_IRQHandler,Default_Handler
               
   .weak      TIM7_IRQHandler            
   .thumb_set TIM7_IRQHandler,Default_Handler
         
   .weak      DMA2_Stream0_IRQHandler               
   .thumb_set DMA2_Stream0_IRQHandler,Default_Handler
               
   .weak      DMA2_Stream1_IRQHandler               
   .thumb_set DMA2_Stream1_IRQHandler,Default_Handler
                  
   .weak      DMA2_Stream2_IRQHandler               
   .thumb_set DMA2_Stream2_IRQHandler,Default_Handler
            
   .weak      DMA2_Stream3_IRQHandler               
   .thumb_set DMA2_Stream3_IRQHandler,Default_Handler
            
   .weak      DMA2_Stream4_IRQHandler               
   .thumb_set DMA2_Stream4_IRQHandler,Default_Handler
   
   .weak      DMA2_Stream4_IRQHandler               
   .thumb_set DMA2_Stream4_IRQHandler,Default_Handler   

   .weak      ETH_IRQHandler   
   .thumb_set ETH_IRQHandler,Default_Handler
   
   .weak      ETH_WKUP_IRQHandler   
   .thumb_set ETH_WKUP_IRQHandler,Default_Handler

   .weak      CAN2_TX_IRQHandler   
   .thumb_set CAN2_TX_IRQHandler,Default_Handler   
                           
   .weak      CAN2_RX0_IRQHandler                  
   .thumb_set CAN2_RX0_IRQHandler,Default_Handler
                           
   .weak      CAN2_RX1_IRQHandler                  
   .thumb_set CAN2_RX1_IRQHandler,Default_Handler
                           
   .weak      CAN2_SCE_IRQHandler                  
   .thumb_set CAN2_SCE_IRQHandler,Default_Handler
                           
   .weak      OTG_FS_IRQHandler      
   .thumb_set OTG_FS_IRQHandler,Default_Handler
                     
   .weak      DMA2_Stream5_IRQHandler               
   .thumb_set DMA2_Stream5_IRQHandler,Default_Handler
                  
   .weak      DMA2_Stream6_IRQHandler               
   .thumb_set DMA2_Stream6_IRQHandler,Default_Handler
                  
   .weak      DMA2_Stream7_IRQHandler               
   .thumb_set DMA2_Stream7_IRQHandler,Default_Handler
                  
   .weak      USART6_IRQHandler      
   .thumb_set USART6_IRQHandler,Default_Handler
                        
   .weak      I2C3_EV_IRQHandler   
   .thumb_set I2C3_EV_IRQHandler,Default_Handler
                        
   .weak      I2C3_ER_IRQHandler   
   .thumb_set I2C3_ER_IRQHandler,Default_Handler
                        
   .weak      OTG_HS_EP1_OUT_IRQHandler         
   .thumb_set OTG_HS_EP1_OUT_IRQHandler,Default_Handler
               
   .weak      OTG_HS_EP1_IN_IRQHandler            
   .thumb_set OTG_HS_EP1_IN_IRQHandler,Default_Handler
               
   .weak      OTG_HS_WKUP_IRQHandler         
   .thumb_set OTG_HS_WKUP_IRQHandler,Default_Handler
            
   .weak      OTG_HS_IRQHandler      
   .thumb_set OTG_HS_IRQHandler,Default_Handler
                  
   .weak      DCMI_IRQHandler            
   .thumb_set DCMI_IRQHandler,Default_Handler

   .weak      RNG_IRQHandler            
   .thumb_set RNG_IRQHandler,Default_Handler   

   .weak      FPU_IRQHandler                  
   .thumb_set FPU_IRQHandler,Default_Handler

   .weak      UART7_IRQHandler                  
   .thumb_set UART7_IRQHandler,Default_Handler

   .weak      UART8_IRQHandler                  
   .thumb_set UART8_IRQHandler,Default_Handler   

   .weak      SPI4_IRQHandler            
   .thumb_set SPI4_IRQHandler,Default_Handler
   
   .weak      SPI5_IRQHandler            
   .thumb_set SPI5_IRQHandler,Default_Handler

   .weak      SPI6_IRQHandler            
   .thumb_set SPI6_IRQHandler,Default_Handler   

   .weak      SAI1_IRQHandler            
   .thumb_set SAI1_IRQHandler,Default_Handler
   
   .weak      LTDC_IRQHandler            
   .thumb_set LTDC_IRQHandler,Default_Handler

   .weak      LTDC_ER_IRQHandler            
   .thumb_set LTDC_ER_IRQHandler,Default_Handler

   .weak      DMA2D_IRQHandler            
   .thumb_set DMA2D_IRQHandler,Default_Handler   

   .weak      SAI2_IRQHandler            
   .thumb_set SAI2_IRQHandler,Default_Handler
   
   .weak      QUADSPI_IRQHandler            
   .thumb_set QUADSPI_IRQHandler,Default_Handler
 
   .weak      LPTIM1_IRQHandler            
   .thumb_set LPTIM1_IRQHandler,Default_Handler

   .weak      CEC_IRQHandler            
   .thumb_set CEC_IRQHandler,Default_Handler
   
   .weak      I2C4_EV_IRQHandler            
   .thumb_set I2C4_EV_IRQHandler,Default_Handler 
 
   .weak      I2C4_ER_IRQHandler            
   .thumb_set I2C4_ER_IRQHandler,Default_Handler
   
   .weak      SPDIF_RX_IRQHandler            
   .thumb_set SPDIF_RX_IRQHandler,Default_Handler 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/        
 
