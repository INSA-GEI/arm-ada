/*
 * Name         : USART.c
 * Author       : S DIMERCURIO
 * Version      : V1.0
 * Date         : 02/05/2012
 * Purpose		: Fonctions pour la liason serie USART
 *
 *----------------------------------------------------------------------------
 * Ce pilote fait partie des pilotes pour STM32 de l'INSA de Toulouse, France.
 * Merci de consulter le fichier LICENCE.txt au sujet des conditions de redistribution,
 * modification et copyright concernant ce pilote. Le fichier LICENCE.txt doit faire partie
 * des fichiers fournis avec ce pilote.
 *
 * Copyright (c) 2012, INSA-GEI Toulouse, France.
 * Tout droits réservés.
 *---------------------------------------------------------------------------*/

#include "drivers_conf.h"

#if (_USE_USART_ != 0)

#include "usart.h"
#include "stdio.h"

#include "reprog.h"

struct USART_Buffer_TX_ST
{
	char buffer[_USART_BUFFER_LENGTH_TX_];
	char *in;
	char *out;
	u16 length;
};
typedef struct USART_Buffer_TX_ST USART_Buffer_TX;

struct USART_Buffer_RX_ST
{
	char buffer[_USART_BUFFER_LENGTH_RX_];
	char *in;
	char *out;
	u16 DMAlastcounter;
};
typedef struct USART_Buffer_RX_ST USART_Buffer_RX;

struct USART_Buffers_ST
{
	USART_Buffer_TX TX;
	USART_Buffer_RX RX;
};
typedef struct USART_Buffers_ST USART_Buffers;
USART_Buffers *USART1Buffer;

//static USART_Buffers *USART_GetBuffers(USART_TypeDef* usart);

/* Fonctions de reprog */
//static char USART_ReceivedChar;

void USART_Configure(USART_TypeDef* usart, u32 baudrate, USART_Remap remap)
{
GPIO_InitTypeDef GPIO_InitStructTx;
GPIO_InitTypeDef GPIO_InitStructRx;
NVIC_InitTypeDef NVIC_InitStructure;
DMA_InitTypeDef   DMA_InitStructure;
USART_InitTypeDef USART_InitStruct;
	
	/* Configuration de l'usart */
	USART_DeInit(usart);

	GPIO_InitStructTx.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructTx.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructTx.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructTx.GPIO_PuPd = GPIO_PuPd_UP;
	
	GPIO_InitStructRx.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructRx.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructRx.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructRx.GPIO_PuPd = GPIO_PuPd_UP;
	
	/* Activation de l'horloge et configuration des pins */
	/* Uniquement USART 1 */
	
	/* Activation de l'horloge de l'USART1 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	/* Enable the USART1 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART1_IRQ_LEVEL;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Activation des pins */
	if (remap == USART_NO_REMAP)
	{
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA , ENABLE);
		
		GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_10;

		GPIO_Init(GPIOA, &GPIO_InitStructTx);
		GPIO_Init(GPIOA, &GPIO_InitStructRx);	
		
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);
		GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_7);
	}

	/* Initialisation des buffers */
	USART1Buffer= (USART_Buffers*)(0x20000000);
	USART1Buffer->TX.in = USART1Buffer->TX.buffer;
	USART1Buffer->TX.out = USART1Buffer->TX.buffer;
  USART1Buffer->TX.length =0;
	
	USART1Buffer->RX.in = USART1Buffer->RX.buffer;
	USART1Buffer->RX.out = USART1Buffer->RX.buffer;
	USART1Buffer->RX.DMAlastcounter =_USART_BUFFER_LENGTH_RX_;
	
	/* Initialisation of USART */
	USART_InitStruct.USART_BaudRate = baudrate;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_Init(usart, &USART_InitStruct);
	
	/* Activation des DMA en reception (DMA1, channel 5)*/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel5); 
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART1->RDR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)(USART1Buffer->RX.buffer);
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = _USART_BUFFER_LENGTH_RX_;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; // Mode circulaire, sans IT
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel5, &DMA_InitStructure);

  /* Enable DMA1 Channel5 */
  DMA_Cmd(DMA1_Channel5, ENABLE);
	
	// Redirection des IT RX sur la DMA
	USART_DMACmd(USART1, USART_DMAReq_Rx, ENABLE);
	
	/* Enable the USART */
	USART_Cmd(usart, ENABLE);
}

int USART_GetRXBufferLength(USART_TypeDef* usart)
{
USART_Buffer_RX *localBuffer;
uint16_t currentCounter;
uint16_t length;
	
	localBuffer = &USART1Buffer->RX;

	currentCounter=DMA_GetCurrDataCounter(DMA1_Channel5);
	
	if (currentCounter !=localBuffer->DMAlastcounter)
	{
		if (currentCounter < localBuffer->DMAlastcounter) length =  localBuffer->DMAlastcounter - currentCounter ;
		else length = _USART_BUFFER_LENGTH_RX_ + localBuffer->DMAlastcounter - currentCounter;
		
		localBuffer->DMAlastcounter = currentCounter;
	} else length =0;
	
	if ((localBuffer->in + length) >= (localBuffer->buffer + _USART_BUFFER_LENGTH_RX_))
		localBuffer->in = localBuffer->in + length - _USART_BUFFER_LENGTH_RX_;
	else
		localBuffer->in = localBuffer->in + length;
	
	if (localBuffer->in < localBuffer->out)
		length = _USART_BUFFER_LENGTH_RX_ + localBuffer->in - localBuffer->out;
	else length = localBuffer->in - localBuffer->out;
	
	return length;
}

int USART_GetTXBufferLength(USART_TypeDef* usart)
{
USART_Buffer_TX *localBuffer;

	localBuffer = &USART1Buffer->TX;

	return (localBuffer->length);
}

static void USART_PutData_TX(USART_Buffer_TX *localBuffer, char data)
{
	*(localBuffer->in)=data;
	localBuffer->in ++;
	localBuffer->length ++;
	
	if (localBuffer->in - localBuffer->buffer >= _USART_BUFFER_LENGTH_TX_) localBuffer->in = localBuffer->buffer;
}

static char USART_GetData_TX(USART_Buffer_TX *localBuffer)
{
char data;
	
	data=*(localBuffer->out);
	localBuffer->out ++;
	localBuffer->length --;
	
	if (localBuffer->out - localBuffer->buffer >= _USART_BUFFER_LENGTH_TX_) localBuffer->out = localBuffer->buffer;
	
	return data;
}

static char USART_GetData_RX(USART_Buffer_RX *localBuffer)
{
char data;
	
	data=*(localBuffer->out);
	localBuffer->out ++;
	
	if (localBuffer->out - localBuffer->buffer >= _USART_BUFFER_LENGTH_RX_) localBuffer->out = localBuffer->buffer;
	
	return data;
}

int USART_Receive(USART_TypeDef* usart, char *data)
{
USART_Buffer_RX *localBuffer;
	
	localBuffer = &USART1Buffer->RX;
	
	while (USART_GetRXBufferLength(usart) ==0) 
	{
	}
		
	*data = USART_GetData_RX(localBuffer);
	PRG_CheckDownloadPattern(*data);
	
	return 1;
}

int USART_Send(USART_TypeDef* usart, char data)
{
USART_Buffer_TX *localBuffer;
	
	localBuffer = &USART1Buffer->TX;

	while (USART_GetTXBufferLength(usart) >=_USART_BUFFER_LENGTH_TX_) 
	{
		while (USART_GetTXBufferLength(usart) == _USART_BUFFER_LENGTH_TX_);
	}
	
	USART_PutData_TX(localBuffer,data);
	USART_ITConfig(usart, USART_IT_TXE, ENABLE);
	
	return 1;
}

void USART1_IRQHandler(void)
{
USART_Buffer_TX *localBuffer;
volatile uint32_t tmp;
	
	if (USART_GetITStatus(USART1, USART_IT_TXE)!=RESET)
	{
		/* Registre TX_DR vide */
		localBuffer = &(USART1Buffer->TX);

		GPIOE->ODR = GPIOE->ODR ^ (1<<14);
		
		/* Ecriture de l'octet suivant */
		if (localBuffer->length!=0)
		{
			USART_SendData(USART1, USART_GetData_TX(localBuffer));
		}
		else
		{
			USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
		}
	}

	USART_ClearFlag(USART1	,  USART_FLAG_WU| USART_FLAG_CM| USART_FLAG_EOB| USART_FLAG_RTO|
													USART_FLAG_CTS| USART_FLAG_LBD| USART_FLAG_TC| USART_FLAG_IDLE|
													USART_FLAG_ORE| USART_FLAG_NE| USART_FLAG_FE| USART_FLAG_PE);
	tmp = USART1->RDR;
	tmp = USART1->TDR;
	tmp = USART1->ISR;
	tmp = USART1->ICR;
	tmp = USART1->BRR;
	tmp = USART1->CR1;
	tmp = USART1->CR2;
	tmp = USART1->CR3;
	tmp = USART1->GTPR;
	tmp = USART1->RQR;
	tmp = USART1->RTOR;
}

#endif /* #if (_USE_USART_ != 0) */
