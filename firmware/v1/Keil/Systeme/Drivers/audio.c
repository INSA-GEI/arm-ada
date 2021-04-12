/******************************************************************************/
/* audio.c: Audio driver                                                      */
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
#include "audio.h"

#define AUDIO_Pin GPIO_Pin_4

struct AUDIO_BUFFER_ST
{
	uint8_t buffer1[AUDIO_BUFFER_LENGTH];
	uint8_t buffer2[AUDIO_BUFFER_LENGTH];
};

typedef struct AUDIO_BUFFER_ST  AUDIO_BUFFER_TYPE;

static AUDIO_BUFFER_TYPE AUDIO_Buffer __attribute__((section("DMA_BUFFERS")));
static AUDIO_EventCallback AUDIO_Callback;
static int AUDIO_BufferNbr;
static DMA_InitTypeDef AUDIO_DMA_InitStructure;

static void AUDIO_DummyEventHandler(int buffer_nbr) {}

void AUDIO_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
DAC_InitTypeDef DAC_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
	
	AUDIO_Callback = AUDIO_DummyEventHandler;
	
	/* DMA2 clock enable (to be used with DAC) */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

  /* DAC Periph clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);

  /* GPIOA clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  
  /* Configure PA.04 (DAC_OUT1) as analog */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  /* TIM2 Periph clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  /* Time base configuration */
  TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
  TIM_TimeBaseStructure.TIM_Period = (72000000/44100)-1;          
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0;       
  TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  /* TIM2 TRGO selection */
  TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);
  
  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);
	
	/* DAC channel1 Configuration */
	DAC_DeInit(); 
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T2_TRGO;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	
	/* DAC1 DMA IRQ channel configuration */
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Channel3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

void AUDIO_Start(void)
{
	/* DMA2 channel3 configuration */
	DMA_DeInit(DMA2_Channel3);
	AUDIO_DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(DAC->DHR8R1);
	AUDIO_DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)AUDIO_Buffer.buffer1;
	AUDIO_DMA_InitStructure.DMA_BufferSize = 2*AUDIO_BUFFER_LENGTH;
	AUDIO_DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	AUDIO_DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	AUDIO_DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	AUDIO_DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  AUDIO_DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  AUDIO_DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  AUDIO_DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  AUDIO_DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;	
	DMA_Init(DMA2_Channel3, &AUDIO_DMA_InitStructure);
	
	DMA_ITConfig(DMA2_Channel3, DMA_IT_TC | DMA_IT_HT, ENABLE);
	
	/* Enable DMA2 Channel3 */
	DMA_Cmd(DMA2_Channel3, ENABLE);

	/* Enable DAC1 Channel1: Once the DAC1 channel1 is enabled, PA.05 is 
		 automatically connected to the DAC converter. */
	DAC_Cmd(DAC_Channel_1, ENABLE);

	/* Enable DMA for DAC Channel1 */
	DAC_DMACmd(DAC_Channel_1, ENABLE);
}

void AUDIO_Stop(void)
{
	/* Disable DAC1 Channel1 */
	DAC_Cmd(DAC_Channel_1, DISABLE);
	
	/* Disable DMA2 Channel3 */
	DMA_Cmd(DMA2_Channel3, DISABLE);

	/* Disable DMA for DAC Channel1 */
	DAC_DMACmd(DAC_Channel_1, DISABLE);
}

void AUDIO_FillBuffer(int buffer_nbr, uint8_t* buffer)
{
int i;
uint8_t *ptr;
	
	if (buffer_nbr == 1) ptr = AUDIO_Buffer.buffer1;
	else ptr = AUDIO_Buffer.buffer2;
	
	for (i=0; i<AUDIO_BUFFER_LENGTH; i++)
	{
		*ptr=buffer[i];
		ptr++;
	}
}

void AUDIO_SetEventCallback(AUDIO_EventCallback callback)
{
	if (callback != 0x00)
	{
		AUDIO_Callback= callback;
	}
}

void AUDIO_GetBuffersPtr(uint8_t* *buffer_1, uint8_t* *buffer_2)
{
	buffer_1 = (uint8_t**)&AUDIO_Buffer.buffer1;
	buffer_2 = (uint8_t**)&AUDIO_Buffer.buffer2;
}

void DMA2_Channel3_IRQHandler(void)
{
	/* Transfer complete interrupt */
  if (DMA_GetITStatus(DMA2_IT_TC3) != RESET)
  {
		//DMA_Cmd(DMA2_Channel3, DISABLE);
		DMA_ClearITPendingBit(DMA2_IT_TC3);
		DMA_ITConfig(DMA2_Channel3, DMA_IT_HT, ENABLE);
		
		AUDIO_BufferNbr=2;
//		AUDIO_DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)(AUDIO_Buffer.buffer1);
//		DMA_Init(DMA2_Channel3, &AUDIO_DMA_InitStructure);
		
		//DMA_Cmd(DMA2_Channel3, ENABLE);
	}
	else if (DMA_GetITStatus(DMA2_IT_HT3) != RESET)
  { 
		//DMA_Cmd(DMA2_Channel3, DISABLE);
		DMA_ClearITPendingBit(DMA2_IT_HT3);
		DMA_ITConfig(DMA2_Channel3, DMA_IT_TC, ENABLE);
		
		AUDIO_BufferNbr=1;
//		AUDIO_DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)(AUDIO_Buffer.buffer2);
//		DMA_Init(DMA2_Channel3, &AUDIO_DMA_InitStructure);
		
		//DMA_Cmd(DMA2_Channel3, ENABLE);
	}
	
	AUDIO_Callback(AUDIO_BufferNbr);
}

