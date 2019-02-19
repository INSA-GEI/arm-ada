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

#include "AudioSynth.h"
#include "audio.h"

#define WaveTableLength	55
#define WaveNumber			3

typedef uint32_t SYNTH_Frequencies;

const SYNTH_Wave SYNTH_SinWave[WaveTableLength] __attribute__((section("WAVES_TABLES")))=
{
	128, 142, 156, 171, 184, 197, 209, 219, 229, 237, 244, 249, 253,
  255, 255, 254, 251, 247, 241, 233, 224, 214, 203, 190, 177, 164,
  149, 135, 121, 107, 92, 79, 66, 53, 42, 32, 23, 15, 9, 5, 2, 1,
	1, 3, 7, 12, 19, 27, 37, 47, 59, 72, 85, 100, 114 
};

const SYNTH_Wave SYNTH_SquareWave[WaveTableLength] __attribute__((section("WAVES_TABLES")))=
{
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

/*const SYNTH_Wave SYNTH_TriangleWave[WaveTableLength] __attribute__((section("WAVES_TABLES")))=
{
	128,137,146,155,164,173,182,191,200,209,218,227,236,245,255,245,
	236,227,218,209,200,191,182,173,164,155,146,137,128,118,109,100,
	91,82,73,64,55,46,37,28,19,10,1,9,19,29,39,48,58,68,78,87,97,107,117
};*/

/*const SYNTH_Wave* SYNTH_WaveBanks[WaveNumber] =
{
	SYNTH_SinWave, SYNTH_SquareWave, SYNTH_TriangleWave
};*/

/*const SYNTH_Frequencies SYNTH_NoteFrequencies[] __attribute__((section("WAVES_TABLES")))=
{
	3270,3465,3671,3889,4120,4365,4625,4900,5191,5500,5827,6174,
	6541,6930,7342,7778,8241,8731,9250,9800,10383,1100,11654,12347,
	13081,13859,14683,15556,16481,17461,18500,19600,20765,22000,23308,24694,
	26163,27718,29366,31113,32963,34923,36999,39200,41530,44000,46616,49388,
	52325,55437,58733,62225,65926,69846,73999,78399,83061,88000,93233,98777,
	104650,110873,117466,124451,131851,139691,147998,156798,166122,176000,186466,197553,
	209300,221746,234932,248902,263702,279383,295996,313596,332244,352000,372931,395107,
	418601,443492,469864,497803,527404,558765,591991,627193,664488,704000,745862,790213
};*/

typedef struct {
	SYNTH_Wave *instrument;
	SYNTH_Note note;
	///float counter;
	///float increment;
	uint8_t volume;
} SYNTH_Channel;

static SYNTH_Channel SYNTH_Channel_1;
static void SYNTH_AudioCallback(int buffer_nbr);
static void SYNTH_FillBuffer(int buffer_nbr, SYNTH_Channel *channel);
static SYNTH_Wave *SYNTH_Buffer_1, *SYNTH_Buffer_2;

SYNTH_Status SYNTH_Start(void)
{
	AUDIO_Stop();
	
	AUDIO_SetEventCallback(SYNTH_AudioCallback);
	AUDIO_GetBuffersPtr(&SYNTH_Buffer_1, &SYNTH_Buffer_2);
	
	///SYNTH_Channel_1.counter=0.0f;
	///SYNTH_Channel_1.increment=0.0f;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Wave*)SYNTH_SquareWave;
	
	SYNTH_FillBuffer(1, &SYNTH_Channel_1);
	SYNTH_FillBuffer(2, &SYNTH_Channel_1);
	
	AUDIO_Start();
	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_Stop(void)
{
	AUDIO_Stop();
	
	AUDIO_SetEventCallback((AUDIO_EventCallback)0x0);
	
	///SYNTH_Channel_1.counter=0.0f;
	///SYNTH_Channel_1.increment=0.0f;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Wave*)SYNTH_SquareWave;
	
	SYNTH_FillBuffer(1, &SYNTH_Channel_1);
	SYNTH_FillBuffer(2, &SYNTH_Channel_1);
	
	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_NoteOn(SYNTH_Note note)
{
	if (note != MUTE)	{
		SYNTH_Channel_1.note = note;
	////	SYNTH_Channel_1.increment = (55.0f/44100.0f)*SYNTH_NoteFrequencies[note];
		SYNTH_Channel_1.volume = 0xFF;
		///SYNTH_Channel_1.counter = 0.0f;
	}
 	else {
		SYNTH_Channel_1.note = note;
		///SYNTH_Channel_1.increment = 0.0f;
		SYNTH_Channel_1.volume = 0;
		///SYNTH_Channel_1.counter = 0.0f;
	}
	
	return SYNTH_SUCCESS;
}

SYNTH_Status SYNTH_NoteOff(void)
{
	///SYNTH_Channel_1.counter=0.0f;
	///SYNTH_Channel_1.increment=0.0f;
	SYNTH_Channel_1.volume=0;
	SYNTH_Channel_1.note = MUTE;
	SYNTH_Channel_1.instrument = (SYNTH_Wave*)SYNTH_SquareWave;
	
	return SYNTH_SUCCESS;
}

static void SYNTH_FillBuffer(int buffer_nbr, SYNTH_Channel *channel)
{
int i;
///float counter;
///float increment;
SYNTH_Wave *wave;
SYNTH_Wave *buffer;
uint8_t volume;
	
	if ((buffer_nbr == 1) || (buffer_nbr ==2)) {
		
		if (buffer_nbr ==1) buffer=SYNTH_Buffer_1;
			else buffer=SYNTH_Buffer_2;
			
		/*if (increment == 0.0f) {
			for (i=0; i< AUDIO_BUFFER_LENGTH; i++) {
				buffer[i]=0;
			}
		}	else {
			counter = channel->counter;
			increment = channel->increment;
			wave = channel->instrument;
			volume = channel->volume;
			
			for (i=0; i< AUDIO_BUFFER_LENGTH; i++) {
				buffer[i] = (SYNTH_Wave)(((uint32_t)wave[(int)counter]*volume)/0xFF);
				
				counter = counter + increment;
				if (counter >= (float)WaveTableLength) counter = counter - (float)WaveTableLength;
			}
			
			channel->counter = counter;
		} */
	}
}

static void SYNTH_AudioCallback(int buffer_nbr)
{
	SYNTH_FillBuffer(buffer_nbr, &SYNTH_Channel_1);
}
