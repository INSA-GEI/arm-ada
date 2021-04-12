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

#include "stm32746g_discovery_stdio.h"
#include "stm32746g_discovery_lcd_dma2d.h"
/* todo a supprimer */
#include "audio-synth/audio-synth.h"
#include "audio-synth/audio.h"
#include "audio-synth/audio-synth-const.h"
#include "stm32746g_discovery_audio.h"
/* todo a supprimer */

COLOR *data;
const PackedBMP_Header logo_insa;
const PackedBMP_Header logo_armada;

struct Magic_Header_ST
{
	const char magic_str[4];
	const uint32_t abi_version;
	const uint32_t ep; 
};

typedef struct Magic_Header_ST magicHeader;

/* Ces variables doivent rester globale ... liées à la stack systeme */
magicHeader *mh;
int (*AppEntryPoint)(void);
uint32_t *TestEntryPoint;
uint32_t SYSTEM_Stack;
/* Fin des variables liées à la stack */

void SYSTEM_PeripheralsReset(void);
void SYSTEM_PeripheralsInit(void);
void SYSTEM_SplashScreen(void);
void SetStack(uint32_t systemstack, uint32_t applistack);
void RETARGET_Init(void);
int SYSTEM_RunApp(void);
void PRG_ResetReprogRequest(void);
int PRG_CheckReprogRequest(void);
void SYSTEM_ShowSystemVersion(int MajV, int MinV);

#define PRG_RESET_REPROG		1
#define PRG_RESET_HARDRESET		2
#define PRG_RESET_SOFTRESET		3
#define PRG_SOFTRESET_PATTERN 	0xDEADBEEF
#define PRG_REPROG_PATTERN 		0xADDAADDA

volatile int DataReady=0;
int (*AppEntryPoint)(void);
uint32_t *TestEntryPoint;
int return_val;

char RunAutoTest=0;
extern const uint32_t* __app_stack_end__;
extern const uint32_t* __system_stack_end__;

extern uint32_t PRG_ReprogPatternAddr;

int LEGACY_System (void)
{	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
	/* !!!!! Ne pas mettre de variable locale ici            !!!! */
	/* !!!!! La stack va etre deplacée                       !!!! */
	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

	/* Pre init du system */
	SetStack((uint32_t)&__system_stack_end__,(uint32_t)&__app_stack_end__);
	//SYSTEM_MoveITVector();
	RETARGET_Init();

	/* Init du systeme */
	WRAPPER_Init();
	BSP_LCD_ResetScreen();

	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);

#ifndef ADA_TEST_SYSTEM	
	if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET)
	{
		SYSTEM_SplashScreen();
	}
#endif /* ADA_TEST_SYSTEM */

	/* Finalement, on positionne le drapeau de demarrage a froid */
	/* Desormais, lors d'un reset, le systeme ne ferra plus d'attente pour l'ecran, ni d'animation */
	PRG_ResetReprogRequest();

	/* Set screen in full black, except for emulated screen of legacy device (in white) */
	BSP_LCD_Clear(Black);
	GLCD_Clear(White);

	SYSTEM_ShowSystemVersion(BL_MAJOR_VERSION, BL_MINOR_VERSION);

	/* Lance l'application ADA (si les auto test n'ont pas été activés avant) */
	while (SYSTEM_RunApp()!= BAD_APPLICATION_RETURN_CODE);

	/* Redemarre le system (devrait rester bloqué dans le bootloader) */
	NVIC_SystemReset();	

	/* N'arrive jamais ici, normalement */
	return 0;
}

void SYSTEM_ShowSystemVersion(int MajV, int MinV)
{
	char str[30];

	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);

	sprintf (str, "System ver. %d.%d", BL_MAJOR_VERSION, BL_MINOR_VERSION);
	GLCD_DrawString((40-strlen(str))/2, 13, str);
	Delay(2000);
	GLCD_Clear(White);
}

/* Fonction pour tester si une reprog est necessaire */
int PRG_CheckReprogRequest(void)
{
	if (PRG_ReprogPatternAddr == PRG_REPROG_PATTERN) return PRG_RESET_REPROG;
	else if (PRG_ReprogPatternAddr == PRG_SOFTRESET_PATTERN) return PRG_RESET_SOFTRESET;

	return PRG_RESET_HARDRESET;
}

/* Fonction pour nettoyer la condition de reprog */
void PRG_ResetReprogRequest(void)
{
	PRG_ReprogPatternAddr = PRG_SOFTRESET_PATTERN;
}
/**
 * @brief  Peripheral Reset.
 * @param  None
 * @retval None
 */
int SYSTEM_RunApp(void)
{
	TestEntryPoint = (uint32_t*)APPLICATION_FIRST_ADDR;
	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);

	if (*TestEntryPoint == 0xFFFFFFFF)
	{
		/* Pas d'appli en memoire */
		GLCD_DrawString(1,12, "No program loaded");
		GLCD_DrawString(1,14, "Please, flash a program.");

		while (KEYS_GetState(KEY_CENTER)!=KEY_PRESSED);
		/* Don't wait for key C to be released, used in bootloader to stop and wait for fresh program to be load */

		return BAD_APPLICATION_RETURN_CODE;
	}
	else 
	{
		mh=(magicHeader*)TestEntryPoint;

		if ((mh->magic_str[0] == 'I') && 
				(mh->magic_str[1] == 'N') &&
				(mh->magic_str[2] == 'S') &&
				(mh->magic_str[3] == 'A'))
		{
			/* Verification de la version d'abi */
			if (mh->abi_version <= ABI_VERSION)
			{
				/* Lancement de l'appli */
				/* Sauvegarde de la stack systeme */
				SYSTEM_Stack = __get_MSP();

				/* On remet la console à 0 */
				CONSOLE_GotoXY(0,0);

				__disable_irq(); 	// Desactive les IT, le temps de changer la stack */
				/* Bascule vers la stack applicative */
				/* La stack appli va de 0x20009000 à 0x2000A000, la stack systeme de 0x10000000 à 0x10000400,
				   le reste (0x1600) est reservée pour les données (data et bss) du systeme et le vecteur d'IT */

				//__set_PSP((uint32_t)(0x2000A000-0x4));
				__set_PSP((uint32_t)((uint32_t)&__app_stack_end__-0x4));

				__set_CONTROL(0x2); // bascule en mode thread + psp
				__ISB();			// Vide le cache
				__enable_irq(); 	// réactive les IT

				/* Appelle l'applicatif ADA */
				AppEntryPoint = (int (*)(void))(mh->ep);
				return_val=AppEntryPoint();

				/* Rebascule vers la stack system */
				__disable_irq(); 	// Desactive les IT, le temps de changer la stack */
				__set_CONTROL(0x0); // bascule en mode thread + msp
				__ISB();			// Vide le cache
				__enable_irq(); 	// réactive les IT

				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);

				if (return_val == 0xDEAD0001)
				{
					GLCD_DrawString(1,11, "Invalid ABI");
					GLCD_DrawString(1,12, "Program requires a more recent system");
					GLCD_DrawString(1,14, "Please, upgrade system");
				}
				else
				{
					char buffer[50];
					int i;

					sprintf(buffer,"Program terminated with exit code 0x%08X\n",return_val);
					for (i=0; i<strlen(buffer); i++)
					{
						BSP_STDIO_SendData((uint8_t *)&buffer[i],1);
					}

					GLCD_DrawString(1,14, "A -> Run again");
				}

				while ((KEYS_GetState(KEY_A)!=KEY_PRESSED) && (KEYS_GetState(KEY_B)!=KEY_PRESSED));
				while ((KEYS_GetState(KEY_A)==KEY_PRESSED) || (KEYS_GetState(KEY_B)==KEY_PRESSED));

				BSP_LCD_Clear(Black);
				GLCD_Clear(White);
				GLCD_SetTextColor(Black);
				GLCD_SetBackColor(White);

				return 0;
			}
			else /* L'appli demande une version plus recente d'abi */
			{
				GLCD_DrawString(1,11, "Invalid ABI");
				GLCD_DrawString(1,12, "Program requires a more recent system");
				GLCD_DrawString(1,14, "Please, upgrade system");

				while (KEYS_GetState(KEY_CENTER)!=KEY_PRESSED);
				/* Don't wait for key C to be released, used in bootloader to stop and wait for fresh program to be load */

				return BAD_APPLICATION_RETURN_CODE;
			}
		}
		else
		{
			/* Appli incompatible ou corrompue */
			GLCD_DrawString(1,12, "Invalid or corrupted program");
			GLCD_DrawString(1,14, "Please, update your program");

			while (KEYS_GetState(KEY_CENTER)!=KEY_PRESSED);
			/* Don't wait for key C to be released, used in bootloader to stop and wait for fresh program to be load */

			return BAD_APPLICATION_RETURN_CODE;
		}
	}

	return BAD_APPLICATION_RETURN_CODE;
}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in 10 ms.
 * @retval None
 */
#ifndef ADA_TEST_SYSTEM
void SYSTEM_SplashScreen(void)
{
	int dx,i;
	int x;
	char str[30];

	//GLCD_SetLayer(GLCD_LAYER2);
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);
	//GLCD_SetLayer(GLCD_LAYER1);
	//GLCD_SetTextColor(White);
	//GLCD_DrawFillRectangle(0,0,319,239);

	//GLCD_SetTransparentColor(Green);
	//GLCD_LayerScrollMode(GLCD_LAYER_SCROLL_BOTH);
	//GLCD_LayerDisplayMode(GLCD_LAYER_DISPLAY_TRANSPARENT);
	//GLCD_LayerTransparency(GLCD_LAYER_TRANSPARENT_TOTAL,GLCD_LAYER_TRANSPARENT_TOTAL);

	if (KEYS_GetState(KEY_A)==KEY_PRESSED) 
	{
		GLCD_SetTextColor(Black);
		GLCD_SetBackColor(White);

		sprintf (str, "System ver. %d.%d", BL_MAJOR_VERSION, BL_MINOR_VERSION);
		GLCD_DrawString((40-strlen(str))/2, 13, str);
	}

	//	/* allocation du buffer pour l'image */
	//	//data = (COLOR*)MALLOC_GetMemory(logo_armada.height*logo_armada.width);
	//	data = (COLOR*)malloc(logo_armada.height*logo_armada.width);
	//	if (data ==0x0) while (1);
	//
	//	UnpackBMP((PackedBMP_Header *)&logo_armada, data);
	//
	//	/* Animation du logo de demarrage */
	//	GLCD_SetLayer(GLCD_LAYER2);
	//	GLCD_DrawImage(data, (320-logo_armada.width)/2, (240-logo_armada.height)/2, logo_armada.width, logo_armada.height);
	//
	//	//MALLOC_FreeMemory(data);
	//	free(data);
	//	GLCD_SetLayer(GLCD_LAYER1);
	//	GLCD_SetTextColor(Green);
	//
	//	for (i=1; i<33; i++)
	//	{
	//		dx=(logo_armada.width*i)/(2*32);
	//		x=(320/2)-dx;
	//
	//		GLCD_DrawFillRectangle(x,(240-logo_armada.height)/2,x+(dx*2),((240-logo_armada.height)/2)+logo_armada.height);
	//		Delay(20);
	//	}

	Delay(2000);

	//BSP_LCD_ResetScreen();
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);
	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
}
#endif /* ADA_TEST_SYSTEM*/

/**
 * @brief  Move IT vector to a better place (start of 0x2000000)
 * @param  None
 * @retval None
 */
//void SYSTEM_MoveITVector(void)
//{
//	uint32_t* porg=0x0;
//	int i;
//	uint32_t *VectorTable=(uint32_t*)VECTOR_TABLE_ADDR;
//
//	/* Recopie la table des vecteurs d'IT */
//	for (i=0; i<96; i++)
//	{
//		VectorTable[i] = porg[i];
//	}
//
//	/* et mets a jour VTOR */
//	SCB->VTOR = (uint32_t)VectorTable;
//}
