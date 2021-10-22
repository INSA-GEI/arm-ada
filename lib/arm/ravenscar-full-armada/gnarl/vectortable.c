/*
 * gnat_it.c
 *
 *  Created on: 11 mai 2021
 *      Author: dimercur
 */

typedef void (*it_handler)(void);

extern unsigned int IT_Source;
void PANIC_Display(void);

void __gnat_irq_trap(void) __attribute__ ((weak));
void __gnat_irq_trap(void)
{
	while (1)
		;
}

void fault(void) __attribute__ ((weak));
void fault(void)
{
	while (1)
		;
}

void NMI_Handler(void) __attribute__ ((weak)); /* 2 NMI */
void NMI_Handler(void)
{
	IT_Source=0;
	PANIC_Display();

	while (1)
		;
}

void HardFault_Handler(void) __attribute__ ((weak)); /* 3 HardFault */
void HardFault_Handler(void)
{
	IT_Source=1;
	PANIC_Display();

	while (1)
		;
}

void MemManageFault_Handler(void) __attribute__ ((weak)); /* 4 MemManageFault */
void MemManageFault_Handler(void)
{
	IT_Source=2;
	PANIC_Display();

	while (1)
		;
}

void BusFault_Handler(void) __attribute__ ((weak)); /* 5 BusFault */
void BusFault_Handler(void)
{
	IT_Source=3;
	PANIC_Display();

	while (1)
		;
}

void UsageFault_Handler(void) __attribute__ ((weak));
void UsageFault_Handler(void)
{
	IT_Source=4;
	PANIC_Display();

	while (1)
		;
}

void __gnat_sv_call_trap(void) __attribute__ ((weak)); /* 11 SVCHandler */
void __gnat_sv_call_trap(void)
{
	while (1)
	;
}

void __gnat_bkpt_trap(void) __attribute__ ((weak)); /* 12 DebugMon */
void __gnat_bkpt_trap(void)
{
	while (1)
	;
}

void __gnat_pend_sv_trap(void) __attribute__ ((weak)); /* 14 PendSV */
void __gnat_pend_sv_trap(void)
{
	while (1)
	;
}

void __gnat_sys_tick_trap(void) __attribute__ ((weak));
void __gnat_sys_tick_trap(void)
{
	while (1)
		;
}

void WWDG_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* Window WatchDog              */
void PVD_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* PVD through EXTI Line detection */
void TAMP_STAMP_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* Tamper and TimeStamps through the EXTI line */
void RTC_WKUP_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* RTC Wakeup through the EXTI line */
void FLASH_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* FLASH                        */
void RCC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* RCC                          */
void EXTI0_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* EXTI Line0                   */
void EXTI1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* EXTI Line1                   */
void EXTI2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* EXTI Line2                   */
void EXTI3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* EXTI Line3                   */
void EXTI4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* EXTI Line4                   */
void DMA1_Stream0_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 0                */
void DMA1_Stream1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 1                */
void DMA1_Stream2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 2                */
void DMA1_Stream3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 3                */
void DMA1_Stream4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 4                */
void DMA1_Stream5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 5                */
void DMA1_Stream6_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream 6                */
void ADC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* ADC1, ADC2 and ADC3s         */
void CAN1_TX_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN1 TX                      */
void CAN1_RX0_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN1 RX0                     */
void CAN1_RX1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN1 RX1                     */
void CAN1_SCE_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN1 SCE                     */
void EXTI9_5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* External Line[9:5]s          */
void TIM1_BRK_TIM9_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM1 Break and TIM9          */
void TIM1_UP_TIM10_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM1 Update and TIM10        */
void TIM1_TRG_COM_TIM11_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM1 Trigger and Commutation and TIM11 */
void TIM1_CC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM1 Capture Compare         */
void TIM2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM2                         */
void TIM3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM3                         */
void TIM4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM4                         */
void I2C1_EV_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C1 Event                   */
void I2C1_ER_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C1 Error                   */
void I2C2_EV_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C2 Event                   */
void I2C2_ER_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C2 Error                   */
void SPI1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI1                         */
void SPI2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI2                         */
void USART1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USART1                       */
void USART2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USART2                       */
void USART3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USART3                       */
void EXTI15_10_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* External Line[15:10]s        */
void RTC_Alarm_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* RTC Alarm (A and B) through EXTI Line */
void OTG_FS_WKUP_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG FS Wakeup through EXTI line */
void TIM8_BRK_TIM12_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM8 Break and TIM12         */
void TIM8_UP_TIM13_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM8 Update and TIM13        */
void TIM8_TRG_COM_TIM14_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM8 Trigger and Commutation and TIM14 */
void TIM8_CC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM8 Capture Compare         */
void DMA1_Stream7_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA1 Stream7                 */
void FMC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* FMC                          */
void SDMMC1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SDMMC1                       */
void TIM5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM5                         */
void SPI3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI3                         */
void UART4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* UART4                        */
void UART5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* UART5                        */
void TIM6_DAC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM6 and DAC1&2 underrun errors */
void TIM7_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* TIM7                         */
void DMA2_Stream0_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 0                */
void DMA2_Stream1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 1                */
void DMA2_Stream2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 2                */
void DMA2_Stream3_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 3                */
void DMA2_Stream4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 4                */
void ETH_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* Ethernet                     */
void ETH_WKUP_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* Ethernet Wakeup through EXTI line */
void CAN2_TX_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN2 TX                      */
void CAN2_RX0_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN2 RX0                     */
void CAN2_RX1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN2 RX1                     */
void CAN2_SCE_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* CAN2 SCE                     */
void OTG_FS_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG FS                   */
void DMA2_Stream5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 5                */
void DMA2_Stream6_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 6                */
void DMA2_Stream7_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2 Stream 7                */
void USART6_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USART6                       */
void I2C3_EV_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C3 event                   */
void I2C3_ER_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C3 error                   */
void OTG_HS_EP1_OUT_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG HS End Point 1 Out   */
void OTG_HS_EP1_IN_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG HS End Point 1 In    */
void OTG_HS_WKUP_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG HS Wakeup through EXTI */
void OTG_HS_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* USB OTG HS                   */
void DCMI_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DCMI                         */
void RNG_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* Rng                          */
void FPU_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* FPU                          */
void UART7_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* UART7                        */
void UART8_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* UART8                        */
void SPI4_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI4                         */
void SPI5_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI5                         */
void SPI6_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPI6                         */
void SAI1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SAI1                         */
void LTDC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* LTDC                         */
void LTDC_ER_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* LTDC error                   */
void DMA2D_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* DMA2D                        */
void SAI2_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SAI2                         */
void QUADSPI_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* QUADSPI                      */
void LPTIM1_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* LPTIM1                       */
void CEC_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* HDMI_CEC                     */
void I2C4_EV_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C4 Event                   */
void I2C4_ER_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* I2C4 Error                   */
void SPDIF_RX_IRQHandler() __attribute__ ((weak, alias ("__gnat_irq_trap"))); /* SPDIF_RX                     */

it_handler __vectors[116] __attribute__((section(".ccmdata"),aligned (512))) = {
		0, /* stack top address */
		0, /* 1 Reset */
		NMI_Handler, /* 2 NMI */
		HardFault_Handler, /* 3 HardFault */
		MemManageFault_Handler, /* 4 MemManageFault */
		BusFault_Handler, /* 5 BusFault */
		UsageFault_Handler, /* 6 UsageFault */
		fault, /* 7 RFU */
		fault, /* 8 RFU */
		fault, /* 9 RFU */
		fault, /* 10 RFU */
		__gnat_sv_call_trap, /* 11 SVCHandler */
		__gnat_bkpt_trap, /* 12 DebugMon */
		fault, /* 13 RFU */
		__gnat_pend_sv_trap, /* 14 PendSV */
		__gnat_sys_tick_trap, /* 15 SysTick */

		/* External Interrupts */
		WWDG_IRQHandler, /* Window WatchDog              */
		PVD_IRQHandler, /* PVD through EXTI Line detection */
		TAMP_STAMP_IRQHandler, /* Tamper and TimeStamps through the EXTI line */
		RTC_WKUP_IRQHandler, /* RTC Wakeup through the EXTI line */
		FLASH_IRQHandler, /* FLASH                        */
		RCC_IRQHandler, /* RCC                          */
		EXTI0_IRQHandler, /* EXTI Line0                   */
		EXTI1_IRQHandler, /* EXTI Line1                   */
		EXTI2_IRQHandler, /* EXTI Line2                   */
		EXTI3_IRQHandler, /* EXTI Line3                   */
		EXTI4_IRQHandler, /* EXTI Line4                   */
		DMA1_Stream0_IRQHandler, /* DMA1 Stream 0                */
		DMA1_Stream1_IRQHandler, /* DMA1 Stream 1                */
		DMA1_Stream2_IRQHandler, /* DMA1 Stream 2                */
		DMA1_Stream3_IRQHandler, /* DMA1 Stream 3                */
		DMA1_Stream4_IRQHandler, /* DMA1 Stream 4                */
		DMA1_Stream5_IRQHandler, /* DMA1 Stream 5                */
		DMA1_Stream6_IRQHandler, /* DMA1 Stream 6                */
		ADC_IRQHandler, /* ADC1, ADC2 and ADC3s         */
		CAN1_TX_IRQHandler, /* CAN1 TX                      */
		CAN1_RX0_IRQHandler, /* CAN1 RX0                     */
		CAN1_RX1_IRQHandler, /* CAN1 RX1                     */
		CAN1_SCE_IRQHandler, /* CAN1 SCE                     */
		EXTI9_5_IRQHandler, /* External Line[9:5]s          */
		TIM1_BRK_TIM9_IRQHandler, /* TIM1 Break and TIM9          */
		TIM1_UP_TIM10_IRQHandler, /* TIM1 Update and TIM10        */
		TIM1_TRG_COM_TIM11_IRQHandler, /* TIM1 Trigger and Commutation and TIM11 */
		TIM1_CC_IRQHandler, /* TIM1 Capture Compare         */
		TIM2_IRQHandler, /* TIM2                         */
		TIM3_IRQHandler, /* TIM3                         */
		TIM4_IRQHandler, /* TIM4                         */
		I2C1_EV_IRQHandler, /* I2C1 Event                   */
		I2C1_ER_IRQHandler, /* I2C1 Error                   */
		I2C2_EV_IRQHandler, /* I2C2 Event                   */
		I2C2_ER_IRQHandler, /* I2C2 Error                   */
		SPI1_IRQHandler, /* SPI1                         */
		SPI2_IRQHandler, /* SPI2                         */
		USART1_IRQHandler, /* USART1                       */
		USART2_IRQHandler, /* USART2                       */
		USART3_IRQHandler, /* USART3                       */
		EXTI15_10_IRQHandler, /* External Line[15:10]s        */
		RTC_Alarm_IRQHandler, /* RTC Alarm (A and B) through EXTI Line */
		OTG_FS_WKUP_IRQHandler, /* USB OTG FS Wakeup through EXTI line */
		TIM8_BRK_TIM12_IRQHandler, /* TIM8 Break and TIM12         */
		TIM8_UP_TIM13_IRQHandler, /* TIM8 Update and TIM13        */
		TIM8_TRG_COM_TIM14_IRQHandler, /* TIM8 Trigger and Commutation and TIM14 */
		TIM8_CC_IRQHandler, /* TIM8 Capture Compare         */
		DMA1_Stream7_IRQHandler, /* DMA1 Stream7                 */
		FMC_IRQHandler, /* FMC                          */
		SDMMC1_IRQHandler, /* SDMMC1                       */
		TIM5_IRQHandler, /* TIM5                         */
		SPI3_IRQHandler, /* SPI3                         */
		UART4_IRQHandler, /* UART4                        */
		UART5_IRQHandler, /* UART5                        */
		TIM6_DAC_IRQHandler, /* TIM6 and DAC1&2 underrun errors */
		TIM7_IRQHandler, /* TIM7                         */
		DMA2_Stream0_IRQHandler, /* DMA2 Stream 0                */
		DMA2_Stream1_IRQHandler, /* DMA2 Stream 1                */
		DMA2_Stream2_IRQHandler, /* DMA2 Stream 2                */
		DMA2_Stream3_IRQHandler, /* DMA2 Stream 3                */
		DMA2_Stream4_IRQHandler, /* DMA2 Stream 4                */
		ETH_IRQHandler, /* Ethernet                     */
		ETH_WKUP_IRQHandler, /* Ethernet Wakeup through EXTI line */
		CAN2_TX_IRQHandler, /* CAN2 TX                      */
		CAN2_RX0_IRQHandler, /* CAN2 RX0                     */
		CAN2_RX1_IRQHandler, /* CAN2 RX1                     */
		CAN2_SCE_IRQHandler, /* CAN2 SCE                     */
		OTG_FS_IRQHandler, /* USB OTG FS                   */
		DMA2_Stream5_IRQHandler, /* DMA2 Stream 5                */
		DMA2_Stream6_IRQHandler, /* DMA2 Stream 6                */
		DMA2_Stream7_IRQHandler, /* DMA2 Stream 7                */
		USART6_IRQHandler, /* USART6                       */
		I2C3_EV_IRQHandler, /* I2C3 event                   */
		I2C3_ER_IRQHandler, /* I2C3 error                   */
		OTG_HS_EP1_OUT_IRQHandler, /* USB OTG HS End Point 1 Out   */
		OTG_HS_EP1_IN_IRQHandler, /* USB OTG HS End Point 1 In    */
		OTG_HS_WKUP_IRQHandler, /* USB OTG HS Wakeup through EXTI */
		OTG_HS_IRQHandler, /* USB OTG HS                   */
		DCMI_IRQHandler, /* DCMI                         */
		0, /* Reserved                     */
		RNG_IRQHandler, /* Rng                          */
		FPU_IRQHandler, /* FPU                          */
		UART7_IRQHandler, /* UART7                        */
		UART8_IRQHandler, /* UART8                        */
		SPI4_IRQHandler, /* SPI4                         */
		SPI5_IRQHandler, /* SPI5                         */
		SPI6_IRQHandler, /* SPI6                         */
		SAI1_IRQHandler, /* SAI1                         */
		LTDC_IRQHandler, /* LTDC                         */
		LTDC_ER_IRQHandler, /* LTDC error                   */
		DMA2D_IRQHandler, /* DMA2D                        */
		SAI2_IRQHandler, /* SAI2                         */
		QUADSPI_IRQHandler, /* QUADSPI                      */
		LPTIM1_IRQHandler, /* LPTIM1                       */
		CEC_IRQHandler, /* HDMI_CEC                     */
		I2C4_EV_IRQHandler, /* I2C4 Event                   */
		I2C4_ER_IRQHandler, /* I2C4 Error                   */
		SPDIF_RX_IRQHandler /* SPDIF_RX                     */
		};
