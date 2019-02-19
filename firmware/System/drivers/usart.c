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

struct USART_Buffer_ST
{
	char buffer[_USART_BUFFER_LENGTH_];
	char *in;
	char *out;
	u16 length;
};
typedef struct USART_Buffer_ST USART_Buffer;

struct USART_Buffers_ST
{
	USART_Buffer TX;
	USART_Buffer RX;
};
typedef struct USART_Buffers_ST USART_Buffers;

USART_Buffers USART1Buffer;
static USART_Buffers USART2Buffer;
#if defined (__WITH_USART3__)
static USART_Buffers USART3Buffer;
#endif

static USART_Buffers *USART_GetBuffers(USART_TypeDef* usart);

static void USART_GenericInterruptHandler(USART_TypeDef* usart, USART_Buffers *usartBuffer);

/* Fonction "weak" pour le support des OS RT */
void USART_InitRtos(void) __attribute__ ((weak, alias ("_USART_InitRtos")));
void USART_GetMutexRX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_GetMutexRX")));
void USART_GetMutexTX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_GetMutexTX")));
void USART_LeaveMutexRX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_LeaveMutexRX")));
void USART_LeaveMutexTX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_LeaveMutexTX")));
void USART_WaitEventRX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_WaitEventRX")));
void USART_WaitEventTX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_WaitEventTX")));
void USART_SendEventRX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_SendEventRX")));
void USART_SendEventTX(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_SendEventTX")));
//void USART_EnterCriticalSection(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_EnterCriticalSection")));
//void USART_LeaveCriticalSection(USART_TypeDef* usart) __attribute__ ((weak, alias ("_USART_LeaveCriticalSection")));

/* Fonctions de reprog */
static char USART_ReceivedChar;

void USART_Configure(USART_TypeDef* usart, u32 baudrate, USART_Remap remap)
{
	GPIO_InitTypeDef GPIO_InitStructTx;
	GPIO_InitTypeDef GPIO_InitStructRx;
	NVIC_InitTypeDef NVIC_InitStructure;
	USART_Buffers *buffers;
	USART_InitTypeDef USART_InitStruct;

	/* TODO 
	 * Gerer les champs Mode et flowcontrol de la structure d'init
	 * Mode: indique si on est en RX, TX ou RX/TX -> impact sur les GPIo et IT que l'on configure
	 * flowControl: indique si on a des lignes de control en plus -> impact sur les GPIO
	 */

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
	if (usart==USART1) 
	{
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

		// 		else
		// 		{
		// 			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_AFIO, ENABLE);
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		// 			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_6;
		// 			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_7;

		// 			GPIO_Init(GPIOB, &GPIO_InitStructTx);
		// 			GPIO_Init(GPIOB, &GPIO_InitStructRx);

		// 			GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);
		// 		}
	}

	if (usart==USART2) 
	{
		/* Activation de l'horloge de l'USART2 */
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

		/* Enable the USART1 Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART2_IRQ_LEVEL;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

		/* Activation des pins */
		if (remap == USART_NO_REMAP)
		{
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_2;
			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_3;

			GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7);
			GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);

			GPIO_Init(GPIOA, &GPIO_InitStructTx);
			GPIO_Init(GPIOA, &GPIO_InitStructRx);
		}
		// 		else
		// 		{
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		// 			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_5;
		// 			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_6;

		// 			GPIO_Init(GPIOD, &GPIO_InitStructTx);
		// 			GPIO_Init(GPIOD, &GPIO_InitStructRx);

		// 			GPIO_PinRemapConfig(GPIO_Remap_USART2, ENABLE);
		// 		}
	}

#if defined (__WITH_USART3__)
	if (usart==USART3) 
	{
		/* Activation de l'horloge de l'USART3 */
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

		/* Enable the USART1 Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = USART3_IRQ_LEVEL;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

		/* Activation des pins */
		if (remap == USART_NO_REMAP)
		{
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_10;
			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_11;

			GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_7);
			GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_7);

			GPIO_Init(GPIOB, &GPIO_InitStructTx);
			GPIO_Init(GPIOB, &GPIO_InitStructRx);
		}
		// 		else if (remap == USART_PARTIAL_REMAP)
		// 		{
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		// 			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_10;
		// 			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_11;

		// 			GPIO_Init(GPIOC, &GPIO_InitStructTx);
		// 			GPIO_Init(GPIOC, &GPIO_InitStructRx);

		// 			GPIO_PinRemapConfig(GPIO_PartialRemap_USART3, ENABLE);
		// 		}
		// 		else
		// 		{
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
		// 			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

		// 			GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_8;
		// 			GPIO_InitStructRx.GPIO_Pin = GPIO_Pin_9;

		// 			GPIO_Init(GPIOD, &GPIO_InitStructTx);
		// 			GPIO_Init(GPIOD, &GPIO_InitStructRx);

		// 			GPIO_PinRemapConfig(GPIO_FullRemap_USART3, ENABLE);
		// 		}
	}

#endif /* #if defined (__WITH_USART3__) */

	/* Initialisation des buffers */
	buffers= USART_GetBuffers(usart);
	buffers->TX.in = buffers->TX.buffer;
	buffers->TX.out = buffers->TX.buffer;
	buffers->TX.length =0;

	buffers->RX.in = buffers->RX.buffer;
	buffers->RX.out = buffers->RX.buffer;
	buffers->RX.length =0;

	/* Initialisation of USART */
	USART_InitStruct.USART_BaudRate = baudrate;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	USART_Init(usart, &USART_InitStruct);
	USART_InitRtos();

	USART_ITConfig(usart, USART_IT_RXNE, ENABLE);

	/* Enable the USART */
	USART_Cmd(usart, ENABLE);

	/* GPIO5 */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);

	GPIO_InitStructTx.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructTx.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructTx.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructTx.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructTx.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOD, &GPIO_InitStructTx);
}

static USART_Buffers *USART_GetBuffers(USART_TypeDef* usart)
{
	USART_Buffers *localBuffer=NULL;

	if (usart==USART1)
	{
		localBuffer = &USART1Buffer;
	}
	else if (usart == USART2)
	{
		localBuffer = &USART2Buffer;
	}
#if defined (__WITH_USART3__)
	else
	{
		localBuffer = &USART3Buffer;
	}
#endif

	return localBuffer;
}

static int USART_GetBufferLength(USART_Buffer *localBuffer)
{
	int size;

	size =localBuffer->length;
	return size;
}

int USART_GetRXBufferLength(USART_TypeDef* usart)
{
	USART_Buffer *localBuffer;

	localBuffer = &USART_GetBuffers(usart)->RX;

	return (USART_GetBufferLength(localBuffer));
}

int USART_GetTXBufferLength(USART_TypeDef* usart)
{
	USART_Buffer *localBuffer;

	localBuffer = &USART_GetBuffers(usart)->TX;

	return (USART_GetBufferLength(localBuffer));
}

static void USART_PutData(USART_Buffer *localBuffer, char data)
{
	*(localBuffer->in)=data;
	localBuffer->in ++;
	localBuffer->length ++;

	if (localBuffer->in - localBuffer->buffer >= _USART_BUFFER_LENGTH_) localBuffer->in = localBuffer->buffer;
}

static char USART_GetData(USART_Buffer *localBuffer)
{
	char data;

	data=*(localBuffer->out);
	localBuffer->out ++;
	localBuffer->length --;

	if (localBuffer->out - localBuffer->buffer >= _USART_BUFFER_LENGTH_) localBuffer->out = localBuffer->buffer;

	return data;
}

int USART_Receive(USART_TypeDef* usart, char *data)
{
	USART_Buffer *localBuffer;

	/* Take OS MUTEX */
	USART_GetMutexRX(usart);

	localBuffer = &USART_GetBuffers(usart)->RX;

	while (USART_GetRXBufferLength(usart) ==0) 
	{
		USART_WaitEventRX(usart);
	}

	*data = USART_GetData(localBuffer);

	/* Leave OS MUTEX */
	USART_LeaveMutexRX(usart);

	return 1;
}

int USART_Send(USART_TypeDef* usart, char data)
{
	USART_Buffer *localBuffer;

	/* Take OS MUTEX */
	USART_GetMutexTX(usart);

	localBuffer = &USART_GetBuffers(usart)->TX;

	while (USART_GetTXBufferLength(usart) >=_USART_BUFFER_LENGTH_) 
	{
		USART_WaitEventTX(usart);
	}

	USART_PutData(localBuffer,data);
	USART_ITConfig(usart, USART_IT_TXE, ENABLE);

	/* Leave OS MUTEX */
	USART_LeaveMutexTX(usart);

	return 1;
}

static void USART_GenericInterruptHandler(USART_TypeDef* usart, USART_Buffers *usartBuffer)
{
	USART_Buffer *localBuffer;
	volatile uint32_t tmp=0;

	if (USART_GetITStatus(usart, USART_IT_TXE)!=RESET)
	{
		/* Registre TX_DR vide */
		localBuffer = &(usartBuffer->TX);

		GPIOE->ODR = GPIOE->ODR ^ (1<<14);

		/* Ecriture de l'octet suivant */
		if (localBuffer->length!=0)
		{
			USART_SendData(usart, USART_GetData(localBuffer));
		}
		else
		{
			USART_ITConfig(usart, USART_IT_TXE, DISABLE);
		}

		/* Send event TX */
		USART_SendEventTX(usart);
	}

	if (USART_GetITStatus(usart, USART_IT_RXNE)!=RESET)
	{
		/* Registre RX_DR plein */
		localBuffer = &usartBuffer->RX;

		GPIOD->ODR = GPIOD->ODR ^ (1<<15);

		/* Lecture de l'octet suivant */
		USART_ReceivedChar = (char)usart->RDR;
		USART_PutData(localBuffer,USART_ReceivedChar);

		if (usart == USART1) PRG_CheckDownloadPattern(USART_ReceivedChar);

		/* Send event RX */
		USART_SendEventRX(usart);
	}

	USART_ClearFlag(usart,  USART_FLAG_WU| USART_FLAG_CM| USART_FLAG_EOB| USART_FLAG_RTO|
			USART_FLAG_CTS| USART_FLAG_LBD| USART_FLAG_TC| USART_FLAG_IDLE|
			USART_FLAG_ORE| USART_FLAG_NE| USART_FLAG_FE| USART_FLAG_PE);

	tmp++;
	tmp = usart->RDR;
	tmp = usart->TDR;
	tmp = usart->ISR;
	tmp = usart->ICR;
	tmp = usart->BRR;
	tmp = usart->CR1;
	tmp = usart->CR2;
	tmp = usart->CR3;
	tmp = usart->GTPR;
	tmp = usart->RQR;
	tmp = usart->RTOR;
}

void USART1_IRQHandler (void)
{
	USART_GenericInterruptHandler(USART1, &USART1Buffer);
}

void USART2_IRQHandler (void)
{
	USART_GenericInterruptHandler(USART2, &USART2Buffer);
}

#if defined (__WITH_USART3__)
void USART3_IRQHandler (void)
{
	USART_GenericInterruptHandler(USART3, &USART3Buffer);
}
#endif

/* Fonctions par defaut dans le cas où il n'y a pas d'OS RT */
void _USART_InitRtos(void)
{
}

void _USART_GetMutexRX(USART_TypeDef* usart)
{
}

void _USART_GetMutexTX(USART_TypeDef* usart)
{
}

void _USART_LeaveMutexRX(USART_TypeDef* usart)
{
}

void _USART_LeaveMutexTX(USART_TypeDef* usart)
{
}

void _USART_WaitEventRX(USART_TypeDef* usart)
{
	while (USART_GetRXBufferLength(usart) == 0);
}

void _USART_WaitEventTX(USART_TypeDef* usart)
{
	while (USART_GetTXBufferLength(usart) == _USART_BUFFER_LENGTH_);
}

void _USART_SendEventRX(USART_TypeDef* usart)
{
}

void _USART_SendEventTX(USART_TypeDef* usart)
{
}

void _USART_EnterCriticalSection(USART_TypeDef* usart)
{
}

void _USART_LeaveCriticalSection(USART_TypeDef* usart)
{
}

#endif /* #if (_USE_USART_ != 0) */
