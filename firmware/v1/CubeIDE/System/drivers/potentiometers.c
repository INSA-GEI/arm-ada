/******************************************************************************/
/* Potentiometers.c: STM32 low level driver for potentiometers                */
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

#include "stm32f30x.h"
#include "potentiometers.h"

#define POT_LEFT_GPIO 			GPIO_B
#define POT_RIGHT_GPIO 			GPIO_B

#define POT_LEFT_PIN 			GPIO_Pin_0
#define POT_RIGHT_PIN 			GPIO_Pin_1

#define POT_LEFT_ADC_CHANNEL	ADC_Channel_1
#define POT_RIGHT_ADC_CHANNEL	ADC_Channel_12

static uint16_t POT_ADC_BUFFER[2] __attribute__((section("DMA_BUFFERS")));
static uint8_t POT_FilteringBuffer[2][16];
static uint8_t POT_FilteredBuffer[2];

static uint8_t POT_StartFiltering=0;

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in milliseconds.
 * @retval None
 */
static void Delay(__IO uint32_t nTime)
{ 
	volatile uint32_t TimingDelay;
	TimingDelay = nTime*10000;

	while(TimingDelay != 0)
	{
		TimingDelay--;
	}
}

void POT_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	volatile uint32_t calibration_value=0;

	/* Demarre les horloges des gpio B */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

	/* Configure l'horloge ADC */
	RCC_ADCCLKConfig(RCC_ADC34PLLCLK_Div128);

	/* Configure les touches en entrée */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Pin = POT_LEFT_PIN | POT_RIGHT_PIN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Enable DMA2 clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

	/* DMA configuration */
	/* DMA2 Channel5 Init Test */
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(ADC3->DR);
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&POT_ADC_BUFFER;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = 2;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

	DMA_Init(DMA2_Channel5, &DMA_InitStructure);

	/* Demarre l'horloge de l'ADC 3 */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC34, ENABLE);

	ADC_StructInit(&ADC_InitStructure);

	/* Calibration procedure */ 
	ADC_VoltageRegulatorCmd(ADC3, ENABLE);

	/* Insert delay equal to 10 µs */
	Delay(10);

	ADC_SelectCalibrationMode(ADC3, ADC_CalibrationMode_Single);
	ADC_StartCalibration(ADC3);

	while(ADC_GetCalibrationStatus(ADC3) != RESET );
	calibration_value++;
	calibration_value = ADC_GetCalibrationValue(ADC3);

	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_1;
	ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_Circular;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = 0;

	ADC_CommonInit(ADC3, &ADC_CommonInitStructure);

	ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Enable;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0;
	ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_OverrunMode = ADC_OverrunMode_Disable;
	ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;
	ADC_InitStructure.ADC_NbrOfRegChannel = 2;
	ADC_Init(ADC3, &ADC_InitStructure);

	/* ADC3 regular channel7 and 8  configuration */
	ADC_RegularChannelConfig(ADC3, POT_LEFT_ADC_CHANNEL, 1, ADC_SampleTime_181Cycles5);
	ADC_RegularChannelConfig(ADC3, POT_RIGHT_ADC_CHANNEL, 2, ADC_SampleTime_181Cycles5);

	/* Configures the ADC DMA */
	ADC_DMAConfig(ADC3, ADC_DMAMode_Circular);
	/* Enable the ADC DMA */
	ADC_DMACmd(ADC3, ENABLE);

	/* Enable ADC3 */
	ADC_Cmd(ADC3, ENABLE);

	/* wait for ADRDY */
	while(!ADC_GetFlagStatus(ADC3, ADC_FLAG_RDY))
	{
		/* Enable ADC3 */
		ADC_Cmd(ADC3, ENABLE);
	}

	/* Enable the DMA channel */
	DMA_Cmd(DMA2_Channel5, ENABLE);

	/* Start ADC3 Software Conversion */
	ADC_StartConversion(ADC3);

	/* Demarre le filtrage */
	POT_StartFiltering=1;
}

uint8_t POT_GetValue(POT_ID pot)
{
	// uint16_t value=0;
	// 	if (pot == POT_LEFT) value=POT_ADC_BUFFER[0];
	// 	else value=POT_ADC_BUFFER[1];
	// 	return (uint8_t)(value>>4);

	uint8_t value=0;
	if (pot==POT_LEFT) value = POT_FilteredBuffer[0];
	else value = POT_FilteredBuffer[1];

	return value;
}

void POT_Filtering(void)
{
	int i;
	uint16_t tmp;

	if (POT_StartFiltering==1)
	{
		for (i=0; i<15; i++)
		{
			POT_FilteringBuffer[0][i] = POT_FilteringBuffer[0][i+1];
			POT_FilteringBuffer[1][i] = POT_FilteringBuffer[1][i+1];
		}

		POT_FilteringBuffer[0][15] = (uint8_t)(POT_ADC_BUFFER[0]>>4);
		POT_FilteringBuffer[1][15] = (uint8_t)(POT_ADC_BUFFER[1]>>4);

		tmp=0;
		for (i=0; i<16; i++)
		{
			tmp += POT_FilteringBuffer[0][i];
		}		

		POT_FilteredBuffer[0] = 0xFF-(uint8_t)(tmp>>4);

		tmp=0;
		for (i=0; i<16; i++)
		{
			tmp += POT_FilteringBuffer[1][i];
		}		

		POT_FilteredBuffer[1] = 0xFF-(uint8_t)(tmp>>4);
	}
}
