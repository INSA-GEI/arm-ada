/*
 * audio-melody.c
 *
 *  Created on: 9 nov. 2017
 *      Author: dimercur
 */

#include "audio-synth.h"
#include "audio-melody.h"

uint16_t MELODY_CurrentPtr;
MELODY_Notes *MELODY_CurrentMusic;
uint32_t MELODY_Length;

MELODY_Status MELODY_Start(MELODY_Notes *music, uint32_t length)
{
	//int i;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	/* TIM4 Periph clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	/* Time base configuration */
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Period = 65535; // Valeur max -> 65.536 s
	TIM_TimeBaseStructure.TIM_Prescaler = 7200-1; // prescaler pour avoir un increment minimal de 0.1 ms
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	/* TIM4 IRQ channel configuration */
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable Up IT */
	TIM_Cmd(TIM4, DISABLE);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	MELODY_CurrentMusic = music;
	MELODY_CurrentPtr = 0;
	MELODY_Length = length;
	/*for (i=0; i<music->instruments_length; i++)
	{
		SYNTH_SetInstrument(i, music->instrument[i]);
		SYNTH_SetVolume(i,music->channels_volume[i]);
	}*/

	do {
		SYNTH_NoteOn(music[MELODY_CurrentPtr].channel, music[MELODY_CurrentPtr].note);

		if (music[MELODY_CurrentPtr].duree != 0) TIM_SetAutoreload(TIM4, music[MELODY_CurrentPtr].duree);

		MELODY_CurrentPtr++;
	} while (music[MELODY_CurrentPtr-1].duree == 0);

	/* relance le timer4 */
	TIM_Cmd(TIM4, ENABLE);

	return MELODY_SUCCESS;
}

MELODY_Status MELODY_Stop(void)
{
	/* arret du Timer 4 */
	TIM_Cmd(TIM4, DISABLE);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);

	MELODY_CurrentPtr=0;
	MELODY_CurrentMusic = 0;


	return MELODY_SUCCESS;
}

MELODY_Status MELODY_GetPosition(uint8_t *pos)
{
	*pos = (uint8_t)(MELODY_CurrentPtr*255/MELODY_Length);
	return MELODY_SUCCESS;
}

void TIM4_IRQHandler(void)
{
	/* arret du Timer 4 */
	TIM_Cmd(TIM4, DISABLE);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);

	if (MELODY_CurrentPtr<MELODY_Length)
	{
		do {
			SYNTH_NoteOn(
					MELODY_CurrentMusic[MELODY_CurrentPtr].channel,
					MELODY_CurrentMusic[MELODY_CurrentPtr].note);

			if (MELODY_CurrentMusic[MELODY_CurrentPtr].duree != 0) TIM_SetAutoreload(TIM4, MELODY_CurrentMusic[MELODY_CurrentPtr].duree);

			MELODY_CurrentPtr++;
		} while (MELODY_CurrentMusic[MELODY_CurrentPtr-1].duree == 0);

		/* relance le timer4 */
		TIM_Cmd(TIM4, ENABLE);
	}
}
