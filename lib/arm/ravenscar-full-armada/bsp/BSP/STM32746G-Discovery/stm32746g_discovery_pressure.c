/**
 ******************************************************************************
 * @file    stm32746g_discovery_pressure.c
 * @author  dimercur
 * @brief   This file includes a standard driver for barometric pressure
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================  
  [..] 
   (#) This driver is used to drive the N25Q128A QSPI external
       memory mounted on STM32746G-Discovery board.

   (#) This driver need a specific component driver (N25Q128A) to be included with.

   (#) Initialization steps:
       (++) Initialize the QPSI external memory using the BSP_QSPI_Init() function. This 
            function includes the MSP layer hardware resources initialization and the
            QSPI interface with the external memory.

   (#) QSPI memory operations
       (++) QSPI memory can be accessed with read/write operations once it is
            initialized.
            Read/write operation can be performed with AHB access using the functions
            BSP_QSPI_Read()/BSP_QSPI_Write(). 
       (++) The function BSP_QSPI_GetInfo() returns the configuration of the QSPI memory. 
            (see the QSPI memory data sheet)
       (++) Perform erase block operation using the function BSP_QSPI_Erase_Block() and by
            specifying the block address. You can perform an erase operation of the whole 
            chip by calling the function BSP_QSPI_Erase_Chip(). 
       (++) The function BSP_QSPI_GetStatus() returns the current status of the QSPI memory. 
            (see the QSPI memory data sheet)
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
- stm32f7xx_hal_spi.c
- stm32f7xx_hal_gpio.c
- stm32f7xx_hal_cortex.c
- stm32f7xx_hal_rcc_ex.h
EndDependencies */

/* Includes ------------------------------------------------------------------*/
#include "stm32746g_discovery_pressure.h"

/** @addtogroup BSP
 * @{
 */

/** @addtogroup STM32746G_DISCOVERY
 * @{
 */

/** @defgroup STM32746G_DISCOVERY_PRESSURE STM32746G-Discovery PRESSURE
 * @{
 */


/* Private variables ---------------------------------------------------------*/

/** @defgroup STM32746G_DISCOVERY_PRESSURE_Private_Variables STM32746G_DISCOVERY PRESSURE Private Variables
 * @{
 */
static SPI_HandleTypeDef SPIHandle;
BMP280_HandleTypedef PressureHandle;
BMP280_HandleTypedef* PressureHandlePtr;
//static char pressureSensorEnabled=0;

static I2C_HandleTypeDef I2CHandle;
static int32_t platform_write_i2c(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len);
static int32_t platform_read_i2c(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);

void BSP_PRESSURE_I2C_MspDeInit(void);
void BSP_PRESSURE_I2C_MspInit(void);

static stmdev_ctx_t sensorCtx;

typedef enum {
	PRESSURE_DEVICE_NONE=0,
	PRESSURE_DEVICE_BMP280,
	PRESSURE_DEVICE_LPS22DF
} PressureTypedDef;

PressureTypedDef pressureDevice=PRESSURE_DEVICE_NONE;

/**
 * @}
 */



/* Private functions ---------------------------------------------------------*/

/** @defgroup STM32746G_DISCOVERY_PRESSURE_Private_Functions STM32746G_DISCOVERY PRESSURE Private Functions
 * @{
 */


/**
 * @}
 */

/** @defgroup STM32746G_DISCOVERY_PRESSURE_Exported_Functions STM32746G_DISCOVERY PRESSURE Exported Functions
 * @{
 */

/**
 * @brief  Initializes interface for pressure sensor.
 * @retval Initialization status
 */
uint8_t BSP_PRESSURE_Init(void)
{ 
	lps22df_pin_int_route_t int_route;
	lps22df_bus_mode_t bus_mode;
	lps22df_id_t id;
	lps22df_md_t md;
	int32_t ret;

	__disable_irq(); // Set PRIMASK
	pressureDevice=PRESSURE_DEVICE_NONE;

	/* SPi Configuration */
	SPIHandle.Instance = PRESSURE_SPIx;
	PressureHandle.hspi = &SPIHandle;
	PressureHandle.cs_gpio = PRESSURE_CS_GPIO_PORT;
	PressureHandle.cs_pin = PRESSURE_CS_PIN;
	PressureHandlePtr = &PressureHandle;

	/* Call the DeInit function to reset the driver */
	if (HAL_SPI_DeInit(&SPIHandle) == HAL_OK)
	{
		/* System level initialization */
		BSP_PRESSURE_MspInit();

		/* SPI2 initialization */
		SPIHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
		SPIHandle.Init.CLKPhase 		= SPI_PHASE_1EDGE;
		SPIHandle.Init.CLKPolarity 		= SPI_POLARITY_LOW;
		SPIHandle.Init.DataSize 		= SPI_DATASIZE_8BIT;
		SPIHandle.Init.Direction 		= SPI_DIRECTION_2LINES;
		SPIHandle.Init.FirstBit 		= SPI_FIRSTBIT_MSB;
		SPIHandle.Init.Mode 			= SPI_MODE_MASTER;
		SPIHandle.Init.NSS 				= SPI_NSS_SOFT;
		SPIHandle.Init.TIMode           = SPI_TIMODE_DISABLE;
		SPIHandle.Init.CRCCalculation   = SPI_CRCCALCULATION_DISABLE;
		SPIHandle.Init.CRCPolynomial    = 7;

		if (HAL_SPI_Init(&SPIHandle) == HAL_OK)	{
			PRESSURE_CS_DISABLE(PressureHandlePtr);

			bmp280_init_default_params(&PressureHandle.params);

			if (bmp280_init(&PressureHandle, &PressureHandle.params)) {
				if (PressureHandle.id == BMP280_CHIP_ID) {
					pressureDevice=PRESSURE_DEVICE_BMP280;
				}
			}
		}
	}

	if (pressureDevice == PRESSURE_DEVICE_NONE) { /* pas de peripherique sur bus SPI */
		HAL_SPI_DeInit(&SPIHandle); /* on libere le bus SPI */

		/* I2C Configuration */
		I2CHandle.Instance = PRESSURE_I2Cx;

		/* Call the DeInit function to reset the driver */
		if (HAL_I2C_DeInit(&I2CHandle) == HAL_OK) {

			/* System level initialization */
			BSP_PRESSURE_I2C_MspInit();

			I2CHandle.Init.Timing          = PRESSURE_I2C_TIMING;
			I2CHandle.Init.OwnAddress1     = 0xFF;
			I2CHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
			I2CHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
			I2CHandle.Init.OwnAddress2     = 0xFF;
			I2CHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
			I2CHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;

			if (HAL_I2C_Init(&I2CHandle) == HAL_OK)
			{
				/* Enable the Analog I2C Filter */
				HAL_I2CEx_ConfigAnalogFilter(&I2CHandle,I2C_ANALOGFILTER_ENABLE);

				sensorCtx.write_reg = platform_write_i2c;
				sensorCtx.read_reg = platform_read_i2c;
				sensorCtx.mdelay = HAL_Delay;

				sensorCtx.handle = &I2CHandle;

				/* Check device ID */
				id.whoami = 0xFF;
				ret = lps22df_id_get(&sensorCtx, &id);
				if ((ret==HAL_OK) && (id.whoami == LPS22DF_ID)) {
					/* Boot device */
//					if (lps22df_init_set(&sensorCtx, LPS22DF_BOOT) != HAL_OK)
//						return PRESSURE_ERROR;

					/* Reset device */
					if (lps22df_init_set(&sensorCtx, LPS22DF_RESET) != HAL_OK)
						return PRESSURE_ERROR;

					/* Set bdu and if_inc recommended for driver usage */
					lps22df_init_set(&sensorCtx, LPS22DF_DRV_RDY);

					/* Select bus interface */
					bus_mode.filter = LPS22DF_FILTER_AUTO;
					bus_mode.interface = LPS22DF_SEL_BY_HW;
					lps22df_bus_mode_set(&sensorCtx, &bus_mode);

					/* Set Output Data Rate */
					md.odr = LPS22DF_4Hz;
					md.avg = LPS22DF_16_AVG;
					md.lpf = LPS22DF_LPF_ODR_DIV_4;
					lps22df_mode_set(&sensorCtx, &md);

					/* Configure inerrupt pins */
					lps22df_pin_int_route_get(&sensorCtx, &int_route);
					int_route.drdy_pres   = PROPERTY_DISABLE;
					lps22df_pin_int_route_set(&sensorCtx, &int_route);

					pressureDevice=PRESSURE_DEVICE_LPS22DF;
				}
			}
		}
	}

	__enable_irq(); // Clear PRIMASK
	if (pressureDevice == PRESSURE_DEVICE_NONE)
		return PRESSURE_ERROR;
	else
		return PRESSURE_OK;
}

/**
 * @brief  De-Initializes pressure sensor interface.
 * @retval De-init status
 */
uint8_t BSP_PRESSURE_DeInit(void)
{ 
	if (pressureDevice == PRESSURE_DEVICE_BMP280) {
		PRESSURE_CS_DISABLE(PressureHandlePtr);

		BSP_PRESSURE_MspDeInit();
	} else if (pressureDevice == PRESSURE_DEVICE_LPS22DF) {
		BSP_PRESSURE_I2C_MspDeInit();
	}

	return PRESSURE_OK;
}

/**
 * @brief  Pressure value in pascal
 * @retval Read status
 */
uint8_t BSP_PRESSURE_ReadValues(uint32_t *pressure)
{
	uint8_t status= PRESSURE_OK;
	int32_t temperature;
	uint32_t humidity;
	lps22df_data_t data;
	lps22df_all_sources_t all_sources;
	static uint32_t last_pressure;

	if (pressureDevice == PRESSURE_DEVICE_BMP280) {
		/*
		 * Read output only if new value is available
		 */
		while (bmp280_is_measuring(&PressureHandle));

		if (!bmp280_read_raw(&PressureHandle, &temperature, pressure, &humidity))
		{
			status =  PRESSURE_NO_DATA;
		}
	} else if (pressureDevice == PRESSURE_DEVICE_LPS22DF) {
		lps22df_all_sources_get(&sensorCtx, &all_sources);
		 if ( all_sources.drdy_pres) {
		      if (lps22df_data_get(&sensorCtx, &data)!= HAL_OK)
		    	  return PRESSURE_NO_DATA;

		      *pressure = (uint32_t)data.pressure.hpa;
		      last_pressure = *pressure;
		 } else
		      *pressure = last_pressure;

	} else {
		*pressure=0;
		status = PRESSURE_NO_DATA;
	}

	return status;
}

/**
 * @brief  Reads T° values in °C
 * @retval Read status
 */
uint8_t BSP_PRESSURE_ReadTemperature(int32_t *temperature_degC)
{
	uint8_t status= PRESSURE_OK;
	uint32_t pressure;
	uint32_t humidity;
	lps22df_data_t data;
	lps22df_all_sources_t all_sources;
	static int32_t last_temp =0;

	if (pressureDevice == PRESSURE_DEVICE_BMP280) {
		/*
		 * Read output only if new value is available
		 */
		while (bmp280_is_measuring(&PressureHandle));

		if (!bmp280_read_raw(&PressureHandle, temperature_degC, &pressure, &humidity))
		{
			status =  PRESSURE_NO_DATA;
		}
	} else if (pressureDevice == PRESSURE_DEVICE_LPS22DF){
		lps22df_all_sources_get(&sensorCtx, &all_sources);
		if ( all_sources.drdy_temp ) {
			if (lps22df_data_get(&sensorCtx, &data)!= HAL_OK)
				return PRESSURE_NO_DATA;

			*temperature_degC = (int32_t)data.heat.deg_c;
			last_temp = *temperature_degC;
		} else
			*temperature_degC = last_temp;
	} else {
		*temperature_degC=0;
		status =  PRESSURE_NO_DATA;
	}

	return status;
}

/**
 * @brief  Pressure and temperature compensated
 * @retval Read status
 */
uint8_t BSP_PRESSURE_ReadCompensatedValues(float *pressure, float *temperature)
{
	uint8_t status= PRESSURE_OK;
	float humidity;
	lps22df_data_t data;
	lps22df_all_sources_t all_sources;

	static float last_temp =0;
	static float last_pressure=0;

	if (pressureDevice == PRESSURE_DEVICE_BMP280) {
		/*
		 * Read output only if new value is available
		 */
		while (bmp280_is_measuring(&PressureHandle));

		if (bmp280_read_float(&PressureHandle, temperature, pressure, &humidity)==false)
		{
			status =  PRESSURE_NO_DATA;
		}
	} else if (pressureDevice == PRESSURE_DEVICE_LPS22DF) {
		lps22df_all_sources_get(&sensorCtx, &all_sources);
		if ( all_sources.drdy_pres | all_sources.drdy_temp ) {
			if (lps22df_data_get(&sensorCtx, &data)!= HAL_OK)
				return PRESSURE_NO_DATA;

			if (all_sources.drdy_pres) {
				*pressure = data.pressure.hpa;
				last_pressure = data.pressure.hpa;
			} else
				*pressure =last_pressure;

			if (all_sources.drdy_temp) {
				*temperature = data.heat.deg_c;
				last_temp = data.heat.deg_c;
			} else
				*temperature = last_temp;

		}
	} else {
		*pressure=0.0;
		*temperature=0.0;
		status =  PRESSURE_NO_DATA;
	}

	return status;
}
/**
 * @}
 */

/** @addtogroup STM32746G_DISCOVERY_PRESSURE_Private_Functions
 * @{
 */

/**
 * @brief PRESSURE MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 *           - NVIC configuration for QSPI interrupt
 * @retval None
 */
__weak void BSP_PRESSURE_MspInit(void)
{
	GPIO_InitTypeDef gpio_init_structure;

	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* Enable the Keys (SPI) interface clock */
	PRESSURE_CLK_ENABLE();

	/* Enable GPIO clocks */
	PRESSURE_CS_GPIO_CLK_ENABLE();
	PRESSURE_CLK_GPIO_CLK_ENABLE();
	PRESSURE_MISO_GPIO_CLK_ENABLE();
	PRESSURE_MOSI_GPIO_CLK_ENABLE();

	/*##-2- Configure peripheral GPIO ##########################################*/
	/* PRESSURE CS GPIO pin configuration  */
	gpio_init_structure.Pin       = PRESSURE_CS_PIN;
	gpio_init_structure.Mode      = GPIO_MODE_OUTPUT_PP;
	gpio_init_structure.Pull      = GPIO_NOPULL;
	gpio_init_structure.Speed     = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(PRESSURE_CS_GPIO_PORT, &gpio_init_structure);

	HAL_GPIO_WritePin(PRESSURE_CS_GPIO_PORT, PRESSURE_CS_PIN, GPIO_PIN_SET );

	/* PRESSURE CLK GPIO pin configuration  */
	gpio_init_structure.Pin       = PRESSURE_CLK_PIN;
	gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
	gpio_init_structure.Pull      = GPIO_NOPULL;
	gpio_init_structure.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(PRESSURE_CLK_GPIO_PORT, &gpio_init_structure);

	/* PRESSURE MISO GPIO pin configuration  */
	gpio_init_structure.Pin       = PRESSURE_MISO_PIN;
	gpio_init_structure.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(PRESSURE_MISO_GPIO_PORT, &gpio_init_structure);

	/* PRESSURE MISO GPIO pin configuration  */
	gpio_init_structure.Pin       = PRESSURE_MOSI_PIN;
	gpio_init_structure.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(PRESSURE_MOSI_GPIO_PORT, &gpio_init_structure);

	/*##-3- Configure the NVIC for SPI2 #########################################*/
	/* NVIC configuration for SPI2 interrupt */
	HAL_NVIC_SetPriority(SPI2_IRQn, 0x0C, 0);
	HAL_NVIC_EnableIRQ(SPI2_IRQn);
}

/**
 * @brief PRESSURE MSP De-Initialization
 *        This function frees the hardware resources used in this example:
 *          - Disable the Peripheral's clock
 *          - Revert GPIO and NVIC configuration to their default state
 * @retval None
 */
__weak void BSP_PRESSURE_MspDeInit(void)
{
	/*##-1- Disable the NVIC for QSPI ###########################################*/
	HAL_NVIC_DisableIRQ(SPI2_IRQn);

	/*##-2- Disable peripherals and GPIO Clocks ################################*/
	/* De-Configure QSPI pins */
	HAL_GPIO_DeInit(PRESSURE_CS_GPIO_PORT, PRESSURE_CS_PIN);
	HAL_GPIO_DeInit(PRESSURE_CLK_GPIO_PORT, PRESSURE_CLK_PIN);
	HAL_GPIO_DeInit(PRESSURE_MISO_GPIO_PORT, PRESSURE_MISO_PIN);
	HAL_GPIO_DeInit(PRESSURE_MOSI_GPIO_PORT, PRESSURE_MOSI_PIN);
	/* Disable the QuadSPI memory interface clock */

	PRESSURE_CLK_DISABLE();
}

/**
 * @}
 */

/** @addtogroup STM32746G_DISCOVERY_ACC_GYRO_Private_Functions
 * @{
 */


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
static int32_t platform_write_i2c(void *handle, uint8_t reg, const uint8_t *bufp,
		uint16_t len)
{
	return HAL_I2C_Mem_Write(handle, LPS22DF_I2C_ADD_H, reg,
			I2C_MEMADD_SIZE_8BIT, (uint8_t*) bufp, len, 1000);
}

/*
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
static int32_t platform_read_i2c(void *handle, uint8_t reg, uint8_t *bufp,
		uint16_t len)
{
	return HAL_I2C_Mem_Read(handle, LPS22DF_I2C_ADD_H, reg,
			I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
}

/**
 * @brief ACC Gyro MSP Initialization
 *        This function configures the hardware resources used in this example:
 *           - Peripheral's clock enable
 *           - Peripheral's GPIO Configuration
 *           - NVIC configuration for QSPI interrupt
 * @retval None
 */
__weak void BSP_PRESSURE_I2C_MspInit(void)
{
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

	//	/* IT DRDY GPIO pin configuration  */
	//	gpio_init_structure.Pin       = ACC_GYRO_DRDY_PIN;
	//	gpio_init_structure.Pull 	  = GPIO_NOPULL;
	//	gpio_init_structure.Speed 	  = GPIO_SPEED_FAST;
	//	gpio_init_structure.Mode 	  = GPIO_MODE_IT_RISING;
	//	HAL_GPIO_Init(ACC_GYRO_DRDY_GPIO_PORT, &gpio_init_structure);

	/*##-3- Configure NVIC for IT_LIS2MDL #########################################*/
	/* NVIC configuration for SPI2 interrupt */
	//	HAL_NVIC_SetPriority(I2C1_IRQn, 0x0F, 0);
	//	HAL_NVIC_EnableIRQ(I2C1_  SPI2_IRQn);


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

	//	/* Enable and set EXTI9-5 Interrupt to the lowest priority */
	//	HAL_NVIC_SetPriority(ACC_GYRO_DRDY_EXTI_IRQn, 0xFF, 0);
	//	HAL_NVIC_EnableIRQ(ACC_GYRO_DRDY_EXTI_IRQn);
}

/**
 * @brief ACC GYRO MSP De-Initialization
 *        This function frees the hardware resources used in this example:
 *          - Disable the Peripheral's clock
 *          - Revert GPIO and NVIC configuration to their default state
 * @retval None
 */
__weak void BSP_PRESSURE_I2C_MspDeInit(void)
{
	/*##-1- Disable NVIC for IT_LIS2MDL ###########################################*/
	//	HAL_NVIC_DisableIRQ(SPI2_IRQn);
	PRESSURE_I2Cx_FORCE_RESET();
	PRESSURE_I2Cx_RELEASE_RESET();

	/*##-2- Disable peripherals and GPIO Clocks ################################*/
	/* De-Configure QSPI pins */
	HAL_GPIO_DeInit(PRESSURE_I2Cx_SDA_GPIO_PORT, PRESSURE_I2Cx_SDA_PIN);
	HAL_GPIO_DeInit(PRESSURE_I2Cx_SCL_GPIO_PORT, PRESSURE_I2Cx_SCL_PIN);

	//HAL_NVIC_DisableIRQ(PRESSURE_DRDY_EXTI_IRQn);

	PRESSURE_I2Cx_CLK_DISABLE();
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

