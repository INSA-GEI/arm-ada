/******************************************************************************/
/* AudioSynth.c: Sound synthetizer                                            */
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

#include "audio-synth.h"
#include "audio.h"

#define WaveTableLength		55
#define WaveNumber			3
#define TickAudio			(float)(1.0f/44100.0f)

typedef uint32_t SYNTH_Frequencies;

const SYNTH_Wave SYNTH_SinHachWave[WaveTableLength]=
{
		128, 0, 156, 0, 184, 0, 209, 0, 229, 0, 244, 0, 253,
		0, 255, 0, 251, 0, 241, 0, 224, 0, 203, 0, 177, 0,
		149, 0, 121, 0, 92, 0, 66, 0, 42, 0, 23, 0, 9, 0, 2, 0,
		1, 0, 7, 0, 19, 0, 37, 0, 59, 0, 85, 0, 114
};

const SYNTH_Wave SYNTH_SinWave[WaveTableLength]=
{
		128, 142, 156, 171, 184, 197, 209, 219, 229, 237, 244, 249, 253,
		255, 255, 254, 251, 247, 241, 233, 224, 214, 203, 190, 177, 164,
		149, 135, 121, 107, 92, 79, 66, 53, 42, 32, 23, 15, 9, 5, 2, 1,
		1, 3, 7, 12, 19, 27, 37, 47, 59, 72, 85, 100, 114
};

const SYNTH_Wave SYNTH_HalfSinWave[WaveTableLength]=
{
		128, 142, 156, 171, 184, 197, 209, 219, 229, 237, 244, 249, 253,
		255, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0,
		0, 0, 121, 107, 92, 79, 66, 53, 42, 32, 23, 15, 9, 5, 2, 1,
		0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0
};

const SYNTH_Wave SYNTH_SquareWave[WaveTableLength]=
{
		255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
		255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

/*const SYNTH_Wave SYNTH_TriangleWave[WaveTableLength]=
{
		128,137,146,155,164,173,182,191,200,209,218,227,236,245,255,245,
		236,227,218,209,200,191,182,173,164,155,146,137,128,118,109,100,
		91,82,73,64,55,46,37,28,19,10,1,9,19,29,39,48,58,68,78,87,97,107,117
};*/

const SYNTH_Wave SYNTH_TriangleWave[WaveTableLength]=
{
		128,137,146,155,164,173,182,191,200,209,218,227,236,245,255,245,
		236,227,218,209,200,191,182,173,164,155,146,137,128,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

const SYNTH_Wave* SYNTH_WaveBanks[WaveNumber] =
{
		SYNTH_SinWave, SYNTH_SquareWave, SYNTH_TriangleWave
};

const SYNTH_Frequencies SYNTH_NoteFrequencies[]=
{
		3270,3465,3671,3889,4120,4365,4625,4900,5191,5500,5827,6174,
		6541,6930,7342,7778,8241,8731,9250,9800,10383,11000,11654,12347,
		13081,13859,14683,15556,16481,17461,18500,19600,20765,22000,23308,24694,
		26163,27718,29366,31113,32963,34923,36999,39200,41530,44000,46616,49388,
		52325,55437,58733,62225,65926,69846,73999,78399,83061,88000,93233,98777,
		104650,110873,117466,124451,131851,139691,147998,156798,166122,176000,186466,197553,
		209300,221746,234932,248902,263702,279383,295996,313596,332244,352000,372931,395107,
		418601,443492,469864,497803,527404,558765,591991,627193,664488,704000,745862,790213
};

const SYNTH_Instrument SYNTH_Inst_Piano=
{
	(SYNTH_Wave*)SYNTH_SinWave,
	TickAudio/0.01f,				// 10ms d'attaque
	0,								// Pas de maintient
	TickAudio/0.04f,				// 20 ms de decente (à 50% de volume, donc 40ms pour arriver à zero)
	0.5f,							// Sustain à 50%
//	0.09f/TickAudio,				// Sustain pendant 90 ms
	0.03f/TickAudio,				// Sustain pendant 90 ms
	TickAudio/0.40f					// Retrait pendant 180 ms
};

/*const SYNTH_Instrument SYNTH_Inst_Guitar=
{

};

const SYNTH_Instrument SYNTH_Inst_Drum=
{

};*/

typedef struct {
	SYNTH_Instrument *instrument;

	// Partie table d'onde (wavetable)
	SYNTH_Note 	note;
	uint32_t	counter;
	uint32_t	increment;
	uint8_t 	volume;

	// Partie AHDSR
	uint32_t 	AHDSR_counter;
	float 	 	AHDSR_increment;
	uint8_t  	AHDSR_level;
	SYNTH_Instrument_State AHDSR_state;
} SYNTH_Channel;

SYNTH_Channel SYNTH_Channel_1;
static void SYNTH_AudioCallback(int buffer_nbr);
static void SYNTH_FillBuffer(int buffer_nbr, SYNTH_Channel *channel);
SYNTH_Wave *SYNTH_Buffer_1, *SYNTH_Buffer_2;
int SYNTH_MainVolume;

SYNTH_Status SYNTH_Start(void)
{
	AUDIO_Stop();

	AUDIO_SetEventCallback(SYNTH_AudioCallback);
	//AUDIO_GetBuffersPtr(**SYNTH_Buffer_1, **SYNTH_Buffer_2);
	SYNTH_Buffer_1 = AUDIO_Buffer.buffer1;
	SYNTH_Buffer_2 = AUDIO_Buffer.buffer2;

	SYNTH_Channel_1.counter=0;
	SYNTH_Channel_1.increment=0;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Instrument*)&SYNTH_Inst_Piano;
	SYNTH_Channel_1.AHDSR_state = AHDSR_IDLE;

	SYNTH_FillBuffer(1, &SYNTH_Channel_1);
	SYNTH_FillBuffer(2, &SYNTH_Channel_1);

	AUDIO_Start();
	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_Stop(void)
{
	AUDIO_Stop();

	AUDIO_SetEventCallback((AUDIO_EventCallback)0x0);

	SYNTH_Channel_1.counter=0;
	SYNTH_Channel_1.increment=0;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Instrument*)&SYNTH_Inst_Piano;
	SYNTH_Channel_1.AHDSR_state = AHDSR_IDLE;

	SYNTH_FillBuffer(1, &SYNTH_Channel_1);
	SYNTH_FillBuffer(2, &SYNTH_Channel_1);

	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_SetVolume(int volume)
{
	SYNTH_MainVolume=volume;
	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_NoteOn(SYNTH_Note note)
{
	if (note != MUTE) {
		SYNTH_Channel_1.note = note;
		//SYNTH_Channel_1.increment = ((55.0f/44100.0f)*SYNTH_NoteFrequencies[note])/100;
		SYNTH_Channel_1.increment = (uint32_t)(((55*SYNTH_NoteFrequencies[note])/44100)*2.56f);
		SYNTH_Channel_1.volume = (uint8_t)SYNTH_MainVolume;
		SYNTH_Channel_1.counter = 0;
		SYNTH_Channel_1.AHDSR_state = AHDSR_ATTACK;
		SYNTH_Channel_1.AHDSR_counter = 0;
		SYNTH_Channel_1.AHDSR_increment=0.0f;
		SYNTH_Channel_1.AHDSR_level=0;
		SYNTH_Channel_1.instrument = (SYNTH_Instrument*)&SYNTH_Inst_Piano;
	}
	else {
		SYNTH_Channel_1.note = note;
		SYNTH_Channel_1.increment = 0;
		SYNTH_Channel_1.volume = 0;
		SYNTH_Channel_1.counter = 0;
		SYNTH_Channel_1.AHDSR_state = AHDSR_IDLE;
	}

	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_NoteOff(void)
{
	SYNTH_Channel_1.counter=0;
	SYNTH_Channel_1.increment=0;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Instrument*)&SYNTH_Inst_Piano;
	SYNTH_Channel_1.AHDSR_state = AHDSR_IDLE;

	return SYNTH_SUCCESS;
}

static void SYNTH_FillBuffer(int buffer_nbr, SYNTH_Channel *channel)
{
	int 		i;
	uint32_t 	counter;
	uint32_t 	increment;
	float 		AHDSR_increment;
	uint32_t 	AHDSR_counter;
	uint8_t  	AHDSR_level;
	SYNTH_Instrument_State AHDSR_state;

	SYNTH_Wave 	*wave;
	SYNTH_Wave 	*buffer;
	uint8_t 	volume;
	uint32_t 	tmp;

	SYNTH_Instrument *instrument;

	if (buffer_nbr ==1) buffer=SYNTH_Buffer_1;
	else buffer=SYNTH_Buffer_2;

	increment = channel->increment;

	if ((increment == 0) || (channel->AHDSR_state==AHDSR_IDLE)) {
		/* TODO: A supprimer */
		GPIOD->BSRR = 2;

		for (i=0; i< AUDIO_BUFFER_LENGTH; i++) {
			buffer[i]=0;
		}
		/* TODO: A supprimer */
		GPIOD->BRR = 2;
	} else {
		/* TODO: A supprimer */
		/* Met PD0 à 1 */
		GPIOD->BSRR = 1;

		counter = channel->counter;
		wave = channel->instrument->wavetable;
		volume = channel->volume;
		AHDSR_state = channel->AHDSR_state;
		AHDSR_level=channel->AHDSR_level;
		AHDSR_increment=channel->AHDSR_increment;
		AHDSR_counter = channel->AHDSR_counter;
		instrument = channel->instrument;

		for (i=0; i< AUDIO_BUFFER_LENGTH; i++) {
			tmp = (SYNTH_Wave)(((uint32_t)wave[counter>>8]*volume)>>8);
			counter = counter + increment;
			if (counter >= (WaveTableLength<<8)) counter = counter - (WaveTableLength<<8);

			switch (AHDSR_state)
			{
			case AHDSR_ATTACK:
				tmp = (uint32_t)(tmp * AHDSR_increment);
				AHDSR_increment += instrument->attack_increment;

				if (AHDSR_increment >= 1.0f)
				{
					AHDSR_state = AHDSR_HOLD;
					AHDSR_counter=0;
				}
				break;
			case AHDSR_HOLD:
				AHDSR_counter++;

				if (AHDSR_counter>=instrument->hold_time)
				{
					AHDSR_state = AHDSR_DECAY;
					AHDSR_increment = 1.0f;
				}
				break;
			case AHDSR_DECAY:
				tmp = (uint32_t)(tmp * AHDSR_increment);
				AHDSR_increment -= instrument->decay_increment;

				if (AHDSR_increment <= instrument->decay_level)
				{
					AHDSR_state = AHDSR_SUSTAIN;
					AHDSR_counter=0;
				}
				break;
			case AHDSR_SUSTAIN:
				AHDSR_counter++;
				tmp = (uint32_t)(tmp * instrument->decay_level);

				if (AHDSR_counter>=instrument->sustain_time)
				{
					AHDSR_state = AHDSR_RELEASE;
					AHDSR_increment = instrument->decay_level;
				}
				break;
			case AHDSR_RELEASE:
				tmp = (uint32_t)(tmp * AHDSR_increment);
				AHDSR_increment -= instrument->release_increment;

				if (AHDSR_increment <= 0.0f)
				{
					AHDSR_state = AHDSR_IDLE;
					AHDSR_counter=0;
					AHDSR_increment=0;
				}
				break;
			default: // AHDSR_IDLE
				tmp=0;
			}

			buffer[i]=(SYNTH_Wave)tmp;
		}

		channel->counter = counter;
		channel->AHDSR_state = AHDSR_state;
		channel->AHDSR_counter = AHDSR_counter;
		channel->AHDSR_level = AHDSR_level;
		channel->AHDSR_increment = AHDSR_increment;

		/* TODO: A supprimer */
		/* Met PD0 à 0 */
		GPIOD->BRR = 1;
	}
}

static void SYNTH_AudioCallback(int buffer_nbr)
{
	SYNTH_FillBuffer(buffer_nbr, &SYNTH_Channel_1);
}
