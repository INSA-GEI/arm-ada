/******************************************************************************/
/* system.c: resident system main file                                        */
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

#include "system.h"
#include "tests.h"

#include "ressources.h"

char strbuf[30];

uint8_t Test_AudioBuffer[AUDIO_BUFFER_LENGTH];
uint8_t Test_SRAMBuffer[16];
uint8_t Test_SRAMBufferVerif[16];
uint8_t Test_AudioFlag;

float compteur;

//FATFS Test_SD_Disk;
//FIL Test_SD_File;
char Test_SD_Buffer[50];

const uint8_t Test_SinWave[55]=
{
		128, 142, 156, 171, 184, 197, 209, 219, 229, 237, 244, 249, 253,
		255, 255, 254, 251, 247, 241, 233, 224, 214, 203, 190, 177, 164,
		149, 135, 121, 107, 92, 79, 66, 53, 42, 32, 23, 15, 9, 5, 2, 1,
		1, 3, 7, 12, 19, 27, 37, 47, 59, 72, 85, 100, 114
};

extern volatile int DataReady;
uint8_t Xval, Yval = 0x00;
float fNormAcc,fSinRoll,fCosRoll,fSinPitch,fCosPitch = 0.0f, RollAng = 0.0f, PitchAng = 0.0f;
float fTiltedX,fTiltedY = 0.0f;

extern void Delay(volatile uint32_t nTime);
extern COLOR *data;

void Test_Keys(void);
void Test_Drawline(void);
void Test_DrawRectangle(void);
void Test_DrawFillRectangle(void);
void Test_DrawCircle(void);
void Test_DrawFillCircle(void);
void Test_VerticalScroll(void);
void Test_HorizontalScroll(void);
void Test_Audio(void);
void Test_AudioCallback(int buffer_nbr);
void Test_AudioBuildBuffer(uint8_t volume, uint16_t frequency);
void Test_SRAM(void);
//int Test_SD_Card(void);
//int Test_SD_Card2(void);
void Test_Gyro(void);
void Test_Accelero(void);
void Test_Magneto(void);
void Test_Synthetiseur(void);

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
uint8_t Buffer_Block_Tx[512], Buffer_Block_Rx[512];

void Tests (void)
{
	while (1)
	{
		GUI_CreateWindow("Synthetizer", White, White, Black);		
		Test_Synthetiseur();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Keys", White, White, Black);
		Test_Keys();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Gyroscope", White, White, Black);
		Test_Gyro();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Accelerometre", White, White, Black);
		Test_Accelero();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Magnetometre", White, White, Black);
		Test_Magneto();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		//		GUI_CreateWindow("Vertical scroll", White, White, Black);
		//		Test_VerticalScroll();
		//
		//		while (KEYS_GetState(KEY_A) == KEY_PRESSED);
		//
		//		GUI_CreateWindow("Horizontal scroll", White, White, Black);
		//		Test_HorizontalScroll();
		//
		//		while (KEYS_GetState(KEY_A) == KEY_PRESSED);
		//
		//		GUI_CreateWindow("Drawline", White, White, Black);
		//		Test_Drawline();

		//		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("DrawRectangle", White, White, Black);		
		Test_DrawRectangle();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("DrawFillRectangle", White, White, Black);		
		Test_DrawFillRectangle();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		//		GUI_CreateWindow("DrawCircle", White, White, Black);
		//		Test_DrawCircle();
		//
		//		while (KEYS_GetState(KEY_A) == KEY_PRESSED);
		//
		//		GUI_CreateWindow("DrawFillCircle", White, White, Black);
		//		Test_DrawFillCircle();
		//
		//		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Audio", White, White, Black);		
		Test_Audio();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("Synthetizer", White, White, Black);		
		Test_Synthetiseur();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);

		GUI_CreateWindow("External SRAM", White, White, Black);		
		Test_SRAM();

		while (KEYS_GetState(KEY_A) == KEY_PRESSED);
	}
}


void Test_VerticalScroll(void)
{
	int dy;

	/* Affiche l'image */
	/* allocation du buffer d'image */
	data = (COLOR*)MALLOC_GetMemory(logo_insa.width*logo_insa.height);
	if (data==0x0) while (1);
	UnpackBMP((PackedBMP_Header *)&logo_insa, data);
	GLCD_DrawImage((COLOR*)data, 80, 77, logo_insa.width, logo_insa.height);

	/* defini la zone de scrolling */
	GLCD_SetScrollWindow(80,20,160,200);

	dy=1;

	do 
	{
		Delay(10); /* Wait 10ms */
		GLCD_ScrollVertical(dy);
		dy++;
		if (dy>=200) dy=0;

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);

	GLCD_ScrollVertical(0);
	MALLOC_FreeMemory((void*)data);
}

void Test_HorizontalScroll(void)
{
	int dy;

	/* Affiche l'image */
	/* allocation du buffer d'image */
	data = (COLOR*)MALLOC_GetMemory(logo_insa.width*logo_insa.height);
	if (data==0x0) while (1);
	UnpackBMP((PackedBMP_Header *)&logo_insa, data);
	GLCD_DrawImage((COLOR*)data, 80, 77, logo_insa.width, logo_insa.height);

	/* defini la zone de scrolling */
	GLCD_SetScrollWindow(10,77,300,86);

	dy=1;

	do 
	{
		Delay(10); /* Wait 10ms */
		GLCD_ScrollHorizontal(dy);
		dy++;
		if (dy>=300) dy=0;

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);

	GLCD_ScrollHorizontal(0);
	MALLOC_FreeMemory((void*)data);
}

void Test_Gyro(void)
{
	int val;
	float *GyroBuffer;

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(15, 11, "Press key A");

	GLCD_DrawString(5, 4, "Axe X: ");
	GLCD_DrawString(5, 6, "Axe Y: ");
	GLCD_DrawString(5, 8, "Axe Z: ");

	do 
	{
		while(DataReady < 0x05)
		{}
		DataReady = 0x00;

		/* Read Gyro Angular data */
		GyroBuffer=L3GD20_GetGyroscopicValues();

		val=(int)GyroBuffer[0];
		GUI_CenterBar(12*8,4*16,200,20,val, 256);

		val=(int)GyroBuffer[1];
		GUI_CenterBar(12*8,6*16,200,20,val, 256);

		val=(int)GyroBuffer[2];
		GUI_CenterBar(12*8,8*16,200,20,val, 256);		
	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_Accelero(void)
{
	int val;
	float* 	AccBuffer;

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(15, 11, "Press key A");

	GLCD_DrawString(5, 4, "Axe X: ");
	GLCD_DrawString(5, 6, "Axe Y: ");
	GLCD_DrawString(5, 8, "Axe Z: ");

	do 
	{
		while(DataReady < 0x05)
		{}
		DataReady = 0x00;

		/* Read accelero data */
		AccBuffer=LSM303DLHC_GetAccelerometerValues();

		val=(int)AccBuffer[0];
		GUI_CenterBar(12*8,4*16,200,20,val, 1100);

		val=(int)AccBuffer[1];
		GUI_CenterBar(12*8,6*16,200,20,val, 1100);

		val=(int)AccBuffer[2];
		GUI_CenterBar(12*8,8*16,200,20,val, 1100);		
	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_Magneto(void)
{
	int val;
	float* MagBuffer;

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(15, 11, "Press key A");

	GLCD_DrawString(5, 4, "Axe X: ");
	GLCD_DrawString(5, 6, "Axe Y: ");
	GLCD_DrawString(5, 8, "Axe Z: ");

	do 
	{
		while(DataReady < 0x05)
		{}
		DataReady = 0x00;

		/* Read Magnetic data */
		MagBuffer = LSM303DLHC_GetMagneticValues();

		val=(int)MagBuffer[0];
		GUI_CenterBar(12*8,4*16,200,20,val, 500);

		val=(int)MagBuffer[1];
		GUI_CenterBar(12*8,6*16,200,20,val, 500);

		val=(int)MagBuffer[2];
		GUI_CenterBar(12*8,8*16,200,20,val, 500);		

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_Keys(void)
{
	KEY_STATE state;
	uint8_t val;

	do 
	{
		state= KEYS_GetState(KEY_A);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(30, 10, 'A');

		state= KEYS_GetState(KEY_B);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(36, 10, 'B');

		state= KEYS_GetState(KEY_UP);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(8, 8, 'U');

		state= KEYS_GetState(KEY_DOWN);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(8, 12, 'D');

		state= KEYS_GetState(KEY_LEFT);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(4, 10, 'L');

		state= KEYS_GetState(KEY_RIGHT);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(12, 10, 'R');

		state= KEYS_GetState(KEY_CENTER);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawChar(8, 10, 'C');

		state= KEYS_GetState(KEY_SYSTEM);
		if (state == KEY_PRESSED) 
		{
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);
		}
		else 
		{
			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
		}

		GLCD_DrawString(19, 13, "SYS");

		val = POT_GetValue(POT_LEFT);
		sprintf(strbuf, "0x%02X     ",val);
		//GLCD_DrawString(6, 2, strbuf);

		GLCD_SetTextColor(Black);
		GLCD_SetBackColor(White);
		GLCD_DrawString(4, 3, "Left : ");
		GUI_ProgressBar(100,46,200,20,val, 0xFF);

		val = POT_GetValue(POT_RIGHT);
		sprintf(strbuf, "Right: 0x%02X     ",val);
		//GLCD_DrawString(6, 4, strbuf);

		GLCD_SetTextColor(Black);
		GLCD_SetBackColor(White);
		GLCD_DrawString(4, 5, "Right : ");
		GUI_ProgressBar(100,78,200,20,val, 0xFF);
	} while (!((KEYS_GetState(KEY_A) == KEY_PRESSED) &&  
			(KEYS_GetState(KEY_CENTER) == KEY_PRESSED)));
}

void Test_Drawline(void)
{
	uint32_t rng_val;

	uint16_t x1,y1,x2,y2,color;
	uint16_t	tmp;

	do
	{
		color = RNG_GetValue();
		rng_val = RNG_GetValue();
		x1 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		x2 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		y1 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y1 +=16;

		rng_val = RNG_GetValue();
		y2 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y2 +=16;

		if (x1>x2)
		{
			tmp= x1;
			x1=x2;
			x2=tmp;
		}

		if (y1>y2)
		{
			tmp= y1;
			y1=y2;
			y2=tmp;
		}

		GLCD_SetTextColor(color);
		GLCD_DrawLine(x1,y1,x2,y2);
	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_DrawRectangle(void)
{
	uint32_t rng_val;

	uint16_t x1,y1,x2,y2,color;
	uint16_t	tmp;

	do
	{
		color = RNG_GetValue();
		rng_val = RNG_GetValue();
		x1 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		x2 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		y1 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y1 +=16;

		rng_val = RNG_GetValue();
		y2 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y2 +=16;

		if (x1>x2)
		{
			tmp= x1;
			x1=x2;
			x2=tmp;
		}

		if (y1>y2)
		{
			tmp= y1;
			y1=y2;
			y2=tmp;
		}

		GLCD_SetTextColor(color);
		GLCD_DrawRectangle(x1,y1,x2,y2);

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_DrawFillRectangle(void)
{
	uint32_t rng_val;

	uint16_t x1,y1,x2,y2,color;
	uint16_t	tmp;

	do
	{
		color = RNG_GetValue();
		rng_val = RNG_GetValue();
		x1 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		x2 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		y1 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y1 +=16;

		rng_val = RNG_GetValue();
		y2 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y2 +=16;

		if (x1>x2)
		{
			tmp= x1;
			x1=x2;
			x2=tmp;
		}

		if (y1>y2)
		{
			tmp= y1;
			y1=y2;
			y2=tmp;
		}

		GLCD_SetTextColor(color);
		GLCD_DrawFillRectangle(x1,y1,x2,y2);

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_DrawCircle(void)
{
	uint32_t rng_val;
	uint16_t x1,y1,radius,color;

	do
	{
		color = RNG_GetValue();
		rng_val = RNG_GetValue();
		x1 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		y1 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y1 +=16;

		rng_val = RNG_GetValue();
		radius = (uint16_t) ((rng_val*(y1-16))/0xFFFF);

		GLCD_SetTextColor(color);
		GLCD_DrawCircle(x1,y1,radius);

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_DrawFillCircle(void)
{
	uint32_t rng_val;
	uint16_t x1,y1,radius,color;

	do
	{
		color = RNG_GetValue();
		rng_val = RNG_GetValue();
		x1 = (uint16_t)((rng_val*319)/0xFFFF);

		rng_val = RNG_GetValue();
		y1 = (uint16_t)((rng_val*(239-16))/0xFFFF);
		y1 +=16;

		rng_val = RNG_GetValue();
		radius = (uint16_t) ((rng_val*(y1-16))/0xFFFF);

		GLCD_SetTextColor(color);
		GLCD_DrawFillCircle(x1,y1,radius);

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

void Test_Audio(void)
{
	uint8_t volume, val;
	uint8_t vol_percent;

	uint16_t frequency;

	Test_AudioBuildBuffer(0,100);

	AUDIO_FillBuffer(1,Test_AudioBuffer);
	AUDIO_FillBuffer(2,Test_AudioBuffer);
	Test_AudioFlag=0;
	compteur=0;

	AUDIO_SetEventCallback(Test_AudioCallback);

	AUDIO_Start();

	do
	{
		/* Rewrite buffer */
		if (Test_AudioFlag!=0)
		{
			volume = POT_GetValue(POT_LEFT); /* Volume */
			val = POT_GetValue(POT_RIGHT); /* Frequence */
			val = val /16;
			frequency = (uint16_t)(((uint32_t)val*5000)/15);

			Test_AudioBuildBuffer(volume, frequency);
			AUDIO_FillBuffer(Test_AudioFlag, Test_AudioBuffer);
			Test_AudioFlag=0;

			GLCD_SetTextColor(Black);
			GLCD_SetBackColor(White);
			GLCD_DrawString(3, 5, "Volume : ");
			GLCD_DrawString(3, 10, "Frequence : ");

			vol_percent= (uint8_t)(((uint32_t)volume *100)/0xFF);
			sprintf(strbuf, "%d%%     ",vol_percent);
			GLCD_DrawString(3, 7, strbuf);

			sprintf(strbuf, "%d Hz       ",frequency);
			GLCD_DrawString(3, 12, strbuf);

			GUI_ProgressBar(120,78,170,20,volume, 0xFF);
			GUI_ProgressBar(120,158,170,20,val, 15);
		}

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);

	AUDIO_Stop();
}

void Test_AudioBuildBuffer(uint8_t volume, uint16_t frequency)
{
	int i, cnt;
	float increment;

	cnt=0;
	increment = 44100.0f/frequency;
	increment = 55.0f/increment;

	for (i=0; i< AUDIO_BUFFER_LENGTH; i++)
	{
		cnt =(int)compteur;
		Test_AudioBuffer[i] = Test_SinWave[cnt]*volume/0xFF;

		compteur = compteur + increment;
		if (compteur >=55.0f) compteur = compteur -55.0f;
	}
}

void Test_AudioCallback(int buffer_nbr)
{
	Test_AudioFlag=buffer_nbr;
}

/*const char* Test_Synth[] = {
	"C0","C0_S","D0","D0_S","E0","F0","F0_S","G0","G0_S","A0","A0_S","B0",
	"C1","C1_S","D1","D1_S","E1","F1","F1_S","G1","G1_S","A1","A1_S","B1",
	"C2","C2_S","D2","D2_S","E2","F2","F2_S","G2","G2_S","A2","A2_S","B2",
	"C3","C3_S","D3","D3_S","E3","F3","F3_S","G3","G3_S","A3","A3_S","B3",
	"C4","C4_S","D4","D4_S","E4","F4","F4_S","G4","G4_S","A4","A4_S","B4",
	"C5","C5_S","D5","D5_S","E5","F5","F5_S","G5","G5_S","A5","A5_S","B5",
	"C6","C6_S","D6","D6_S","E6","F6","F6_S","G6","G6_S","A6","A6_S","B6",
	"C7","C7_S","D7","D7_S","E7","F7","F7_S","G7","G7_S","A7","A7_S","B7"
};*/

const SYNTH_Instrument* test_instruments[2] = {
		(SYNTH_Instrument*)&SYNTH_Inst_Guitar,
		(SYNTH_Instrument*)&SYNTH_Inst_Guitar
};

const uint8_t channels_volume[2] = {
		255, 128
};

const MELODY_Notes test_notes[76] = {
		{C4,	1,	0},
		{G3,	0,	2000},
		{G3,	0,	2000},
		{C4,	1,	0},
		{G3,	0,	2000},
		{A3,	0,	2000},
		{C4,	1,	0},
		{B3,	0,	4000},
		{C4,	1,	0},
		{A3,	0,	4000},

		{C4,	1,	0},
		{G3,	0,	2000},
		{B3,	0,	2000},
		{C4,	1,	0},
		{A3,	0,	2000},
		{A3,	0,	2000},
		{C4,	1,	0},
		{G3,	0,	4000},
		{C4,	1,	0},
		{MUTE,	0, 	2000},

		{G3,	0,	2000},
		{B3,	1,	0},
		{G3,	0,	2000},
		{G3,	0,	2000},
		{B3,	1,	0},
		{A3,	0,	2000},
		{B3,	1,	2000},
		{B3,	0,	2000},
		{A3,	0,	2000},
		{B3,	1,	2000},

		{G3,	0,	2000},
		{B3,	0,	2000},
		{B3,	1,	0},
		{A3,	0,	2000},
		{A3,	0,	2000},
		{B3,	1,	0},
		{G3,	0,	4000},
		{B3,	1,	0},
		{MUTE,	0, 	2000},

		{A3,	0,	2000},
		{D4,	1,	0},
		{A3,	0,	2000},
		{A3,	0,	2000},
		{D4,	1,	0},
		{A3,	0,	2000},
		{E3,	0,	2000},
		{D4,	1,	2000},
		{E3,	0,	2000},
		{D4,	1,	2000},

		{A3,	0,	2000},
		{G3,	0,	2000},
		{D4,	1,	0},
		{F3_S,	0,	2000},
		{E3,	0,	2000},
		{D4,	1,	0},
		{D3,	0,	4000},
		{D4,	1,	0},
		{MUTE,	0, 	2000},

		{G3,	0,	2000},
		{F4,	1,	0},
		{G3,	0,	2000},
		{G3,	0,	2000},
		{F4,	1,	0},
		{A3,	0,	2000},
		{B3,	0,	2000},
		{F4,	1,	2000},
		{A3,	0,	2000},
		{F4,	1,	2000},

		{G3,	0,	2000},
		{B3,	0,	2000},
		{F4,	1,	0},
		{A3,	0,	2000},
		{A3,	0,	2000},
		{F4,	1,	0},
		{G3,	0,	4000},
		{F4,	1,	0}
		//{MUTE,	0, 	2000}
} ;

const MELODY_Music melody = {
		//2,
		76,
		//(SYNTH_Instrument**) test_instruments,
		//(uint8_t*) channels_volume,
		(MELODY_Notes*) test_notes
};

void Test_Synthetiseur(void)
{
	uint8_t volume;
	uint8_t vol_percent;
	int melodyrunning;
	uint8_t melody_pos;
	uint8_t i;

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(15, 11, "Press key A");

	GLCD_DrawString(10, 9, "Press B to play music");
	GLCD_DrawString(3, 5, "Vol : ");
	GLCD_DrawString(3, 7, "Stop : ");

	SYNTH_Start();

	melodyrunning=0;
	melody_pos =0;

	do {
		volume = POT_GetValue(POT_LEFT); /* Volume */

		vol_percent= (uint8_t)(((uint32_t)volume *100)/0xFF);
		sprintf(strbuf, "%d%%   ",vol_percent);
		GLCD_DrawString(9, 5, strbuf);

		GUI_ProgressBar(120,78,170,20,volume, 0xFF);
		GUI_ProgressBar(120,115,170,20,melody_pos, 255);

		if (melodyrunning==1)
		{
			MELODY_GetPosition(&melody_pos);

			if (melody_pos == 255) {
				melodyrunning=0;
				melody_pos=0;

				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);
				GLCD_DrawString(3, 7, "Stop : ");

				MELODY_Stop();
			}
		}

		if (KEYS_GetState(KEY_B) == KEY_PRESSED) {
			if (melodyrunning==0)
			{
				melodyrunning=1;
				melody_pos=0;

				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);
				GLCD_DrawString(3, 7, "Play : ");

				SYNTH_SetMainVolume(volume);

				for (i=0; i<2; i++)
				{
					SYNTH_SetVolume(i,channels_volume[i]);
					SYNTH_SetInstrument(i,(SYNTH_Instrument *)test_instruments[i]);
				}

				MELODY_Start(melody.notes, melody.music_length);
			}
		}

	} while (KEYS_GetState(KEY_A) != KEY_PRESSED);

	MELODY_Stop();
	SYNTH_Stop();
}

void Test_SRAM(void)
{
	uint8_t cnt,tmp;
	uint32_t addr,i;
	uint8_t state;

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(5, 5, "Byte W/R :");
	GLCD_DrawString(5, 8, "Block W/R :");

	/* Test les adresses */
	cnt =0;
	state=0;

	for (addr=0; addr<512*1024; addr++)	{
		SRAM_WriteByte(addr, cnt);
		cnt++;
	}

	cnt =0;
	state=0;

	for (addr=0; addr<512*1024; addr++)	{
		tmp = SRAM_ReadByte(addr);

		if (tmp!=cnt) {
			addr=512*1024;
			state = 1;
		}

		cnt++;
	}

	if (state==0) {
		GLCD_SetTextColor(Green);
		GLCD_DrawString(16, 5, "OK");
	}
	else {
		GLCD_SetTextColor(Red);
		GLCD_DrawString(16, 5, "FAIL");
	}

	cnt=0;
	for (i=0; i<16; i++) {
		Test_SRAMBuffer[i]=cnt;
		cnt++;
	}

	state =0;

	for (addr=0; addr<512*64*16; addr+=16) {
		SRAM_WriteBuffer(addr, Test_SRAMBuffer, 16);
		SRAM_ReadBuffer(addr,Test_SRAMBufferVerif,16);

		for (i=0; i<16; i++) {
			if (Test_SRAMBuffer[i]!=Test_SRAMBufferVerif[i]) {
				addr=512*64*16;
				i=16;
				state = 1;
			}
		}
	}

	if (state==0) {
		GLCD_SetTextColor(Green);
		GLCD_DrawString(17, 8, "OK");
	}
	else
	{
		GLCD_SetTextColor(Red);
		GLCD_DrawString(17, 8, "FAIL");
	}

	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	GLCD_DrawString(15, 11, "Press key A");

	while (KEYS_GetState(KEY_A) != KEY_PRESSED);
}

/**
 * @brief  Fill the gloal buffer.
 * @param  pBuffer: pointer on the Buffer to fill
 * @param  BufferSize: size of the buffer to fill
 * @param  Offset: first value to fill on the Buffer
 * @retval None.
 */
//static void Fill_Buffer(uint8_t *pBuffer, uint16_t BufferLenght, uint8_t Offset)
//{
//  uint16_t IndexTmp;
//  
//  /* Put in global buffer same values */
//  for( IndexTmp = 0; IndexTmp < BufferLenght; IndexTmp++ )
//  {
//    pBuffer[IndexTmp] =IndexTmp + Offset;
//  }
//}

/**
 * @brief  Compares two buffers.
 * @param  pBuffer1, pBuffer2: buffers to be compared.
 * @param  BufferLength: buffer's length
 * @retval PASSED: pBuffer1 identical to pBuffer2
 *         FAILED: pBuffer1 differs from pBuffer2
 */
//static TestStatus Buffercmp(uint8_t* pBuffer1, uint8_t* pBuffer2, uint32_t BufferLength)
//{
//  while (BufferLength--)
//  {
//    if (*pBuffer1 != *pBuffer2)
//    {
//      return FAILED;
//    }

//    pBuffer1++;
//    pBuffer2++;
//  }

//  return PASSED;
//}

//int Test_SD_Card(void)
//{
// TestStatus TransferStatus1 = FAILED;
// u32 Status;
// 	
// 	/* Fill the buffer to send */
//   Fill_Buffer(Buffer_Block_Tx, 512, 0x0);
//   
//   /* Write block of 512 bytes on address 0 */
//   Status = SD_WriteBlock(Buffer_Block_Tx, 0, 512);
// 	
//   /* Read block of 512 bytes from address 0 */
//   Status = SD_ReadBlock(Buffer_Block_Rx, 0, 512);
//   
//   /* Check the corectness of written dada */
//   TransferStatus1 = Buffercmp(Buffer_Block_Tx, Buffer_Block_Rx, 512);
//	
//	
//	while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//		
//	return 0;
//}

//int Test_SD_Card2(void)
//{
//FRESULT result;
//int card_not_present;
//UINT length;
//	
//		GLCD_SetTextColor(Black);
//		GLCD_SetBackColor(White);
//		GLCD_DrawString(5, 5, "Card present: ");
//		GLCD_DrawString(5, 7, "Mount disk: ");
//		GLCD_DrawString(5, 9, "Open file: ");
//		GLCD_DrawString(5, 11, "Read file: ");
//	
//		/* Test les adresses */
//	  do
//		{
//			card_not_present = socket_is_empty();
//			
//			if (!card_not_present)
//			{
//				GLCD_SetTextColor(Green);
//				GLCD_SetBackColor(White);
//				GLCD_DrawString(19, 5, "Yes     ");
//				
//				result = f_mount(0, &Test_SD_Disk);
//				if (result !=FR_OK)
//				{
//					GLCD_SetTextColor(Red);
//					GLCD_DrawString(19, 7, "No       ");
//					
//					while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//					return 0;
//				}
//				else
//				{
//					GLCD_SetTextColor(Green);
//					GLCD_DrawString(19, 7, "Yes       ");
//					
//					result = f_open(&Test_SD_File, "README.txt", FA_READ);
//					if (result !=FR_OK)
//					{
//						GLCD_SetTextColor(Red);
//						GLCD_DrawString(19, 9, "No       ");
//						
//						while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//						return 0;
//					}
//					else
//					{
//						GLCD_SetTextColor(Green);
//						GLCD_DrawString(19, 9, "Yes       ");
//						
//						result = f_read(&Test_SD_File, Test_SD_Buffer, 50, &length);
//						if (result !=FR_OK)
//						{
//							GLCD_SetTextColor(Red);
//							GLCD_DrawString(19, 9, "No       ");
//							
//							while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//							return 0;
//						}
//						else
//						{
//							GLCD_SetTextColor(Green);
//							GLCD_DrawString(19, 9, "Yes       ");
//							
//							while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//							return 0;
//						}
//					}
//				}
//			}
//			else
//			{
//				GLCD_SetTextColor(Red);
//				GLCD_SetBackColor(White);
//				GLCD_DrawString(19, 5, "No     ");
//				GLCD_DrawString(19, 7, "       ");
//				GLCD_DrawString(19, 9, "       ");
//				GLCD_DrawString(19, 11, "       ");
//			}
//		
//		}
//		while (KEYS_GetState(KEY_A) != KEY_PRESSED);
//		
//		return 0;
//}
