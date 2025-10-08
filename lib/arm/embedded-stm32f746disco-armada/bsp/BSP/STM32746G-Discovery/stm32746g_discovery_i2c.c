/**
 ******************************************************************************
 * @file    stm32746g_discovery_i2c.c
 * @author  MCD Application Team
 * @brief   i2c helper
  @verbatim

  @endverbatim
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
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

/* Dependencies

EndDependencies */

/* Includes ------------------------------------------------------------------*/
#include "stm32746g_discovery_i2c.h"

/** @addtogroup BSP
 * @{
 */

/** @addtogroup STM32746G_DISCOVERY
 * @{
 */

/** @defgroup STM32746G_DISCOVERY_TS STM32746G_DISCOVERY_TS
 * @{
 */

/** @defgroup STM32746G_DISCOVERY_TS_Private_Types_Definitions STM32746G_DISCOVERY_TS Types Definitions
 * @{
 */
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_TS_Private_Defines STM32746G_DISCOVERY_TS Types Defines
 * @{
 */
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_TS_Private_Macros STM32746G_DISCOVERY_TS Private Macros
 * @{
 */
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_TS_Imported_Variables STM32746G_DISCOVERY_TS Imported Variables
 * @{
 */
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_TS_Private_Variables STM32746G_DISCOVERY_TS Private Variables
 * @{
 */
static I2C_HandleTypeDef I2CMemsHandle;

static void BSP_I2C_MEMS_MspInit(void);
static void BSP_I2C_MEMS_MspDeInit(void);
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_I2C_Private_Function_Prototypes STM32746G_DISCOVERY_TS Private Function Prototypes
 * @{
 */
/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_I2C_Exported_Functions STM32746G_DISCOVERY_TS Exported Functions
 * @{
 */

/**
 * @brief  Initializes and configures the touch screen functionalities and
 *         configures all necessary hardware resources (GPIOs, I2C, clocks..).
 * @retval HAL_OK if all initializations are OK. Other value if error.
 */
int32_t BSP_I2C_MEMS_Init(void) {
	/* I2C Configuration */
	I2CMemsHandle.Instance = DISCOVERY_EXT_I2Cx;

	/* Call the DeInit function to reset the driver */
	if (HAL_I2C_DeInit(&I2CMemsHandle) != HAL_OK)
		return HAL_ERROR;

	/* System level initialization */
	BSP_I2C_MEMS_MspInit();

	I2CMemsHandle.Init.Timing          = DISCOVERY_I2Cx_TIMING;
	I2CMemsHandle.Init.OwnAddress1     = 0xFF;
	I2CMemsHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	I2CMemsHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2CMemsHandle.Init.OwnAddress2     = 0xFF;
	I2CMemsHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2CMemsHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

	if (HAL_I2C_Init(&I2CMemsHandle) != HAL_OK)
		return HAL_ERROR;


	/* Enable the Analog I2C Filter */
	HAL_I2CEx_ConfigAnalogFilter(&I2CMemsHandle,I2C_ANALOGFILTER_ENABLE);

	return HAL_OK;
}

/**
 * @brief  DeInitializes the TouchScreen.
 * @retval TS state
 */
int32_t BSP_I2C_MEMS_DeInit(void) {
	/* Actually ts_driver does not provide a DeInit function */
	BSP_I2C_MEMS_MspDeInit();

	return HAL_OK;
}

/**
 * @brief ACC Gyro MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 *           - NVIC configuration for QSPI interrupt
 * @retval None
 */
static void BSP_I2C_MEMS_MspInit(void) {
	GPIO_InitTypeDef gpio_init_structure;

	DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_CLK_ENABLE();

	/*##-2- Configure peripheral GPIO ##########################################*/
	/* KEYS CS GPIO pin configuration  */
	gpio_init_structure.Pin = DISCOVERY_EXT_I2Cx_SCL_PIN;
	gpio_init_structure.Mode = GPIO_MODE_AF_OD;
	gpio_init_structure.Pull = GPIO_PULLUP;
	gpio_init_structure.Speed = GPIO_SPEED_FAST;
	gpio_init_structure.Alternate = DISCOVERY_EXT_I2Cx_SCL_SDA_AF;
	HAL_GPIO_Init(DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_PORT, &gpio_init_structure);

	/* Configure I2C Rx as alternate function */
	gpio_init_structure.Pin = DISCOVERY_EXT_I2Cx_SDA_PIN;
	HAL_GPIO_Init(DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_PORT, &gpio_init_structure);

	/*** Configure the I2C peripheral ***/
	/* Enable I2C clock */
	DISCOVERY_EXT_I2Cx_CLK_ENABLE();

	/* Force the I2C peripheral clock reset */
	DISCOVERY_EXT_I2Cx_FORCE_RESET();

	/* Release the I2C peripheral clock reset */
	DISCOVERY_EXT_I2Cx_RELEASE_RESET();

	/* Enable and set I2Cx Interrupt to a lower priority */
	HAL_NVIC_SetPriority(DISCOVERY_EXT_I2Cx_EV_IRQn, 0x0D, 0);
	HAL_NVIC_EnableIRQ(DISCOVERY_EXT_I2Cx_EV_IRQn);

	/* Enable and set I2Cx Interrupt to a lower priority */
	HAL_NVIC_SetPriority(DISCOVERY_EXT_I2Cx_ER_IRQn, 0x0D, 0);
	HAL_NVIC_EnableIRQ(DISCOVERY_EXT_I2Cx_ER_IRQn);
}

/**
 * @brief ACC GYRO MSP De-Initialization
 *        This function frees the hardware resources used in this example:
 *          - Disable the Peripheral's clock
 *          - Revert GPIO and NVIC configuration to their default state
 * @retval None
 */
static void BSP_I2C_MEMS_MspDeInit(void) {
	/*##-1- Disable NVIC for IT_LIS2MDL ###########################################*/
	//	HAL_NVIC_DisableIRQ(SPI2_IRQn);
	DISCOVERY_EXT_I2Cx_FORCE_RESET();
	DISCOVERY_EXT_I2Cx_RELEASE_RESET();

	/*##-2- Disable peripherals and GPIO Clocks ################################*/
	/* De-Configure QSPI pins */
	HAL_GPIO_DeInit(DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_PORT, DISCOVERY_EXT_I2Cx_SDA_PIN);
	HAL_GPIO_DeInit(DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_PORT, DISCOVERY_EXT_I2Cx_SCL_PIN);

	HAL_NVIC_DisableIRQ(DISCOVERY_EXT_I2Cx_EV_IRQn);
	HAL_NVIC_DisableIRQ(DISCOVERY_EXT_I2Cx_ER_IRQn);

	DISCOVERY_EXT_I2Cx_CLK_DISABLE();
}

/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
I2C_HandleTypeDef* BSP_I2C_MEMS_GetHandle() {
	return &I2CMemsHandle;
}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
