/******************************************************************************/
/* Reprog.c: Reprogramming functionalities                                    */
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
#include "config.h"

#include "stdio.h"
#include "stdlib.h"

#include "glcd.h"
#include "usart.h"

#include "reprog.h"

#include <ctype.h>

typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

#define FLASH_PAGE_SIZE         ((uint32_t)0x00000800)   /* FLASH Page Size */
#define FLASH_USER_START_ADDR   ((uint32_t)0x0800C000)   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ((uint32_t)0x08040000)   /* End @ of user Flash area */
#define DATA_32                 ((uint32_t)0x12345678)

#define FLASH_VERIFY_START		(0x0800C000)

#define PROGRAM_PACKET_SIZE		32

#define PRG_REPROG_PATTERN 		0xADDAADDA
#define PRG_SOFTRESET_PATTERN 	0xDEADBEEF

uint32_t NbrOfPage = 0x00;
uint32_t EraseCounter = 0x00;
uint32_t Address = 0x00;
uint32_t Base_Address = 0x00;
uint32_t Data = 0x3210ABCD;
__IO FLASH_Status FLASHStatus = FLASH_COMPLETE;
__IO TestStatus MemoryProgramStatus = PASSED;

/* Variables et fonctions pour tester et entrer en mode reprog */
static const char PRG_ReprogEscapeChar = '`';
volatile char PRG_ReprogEscapeCharCounter=0;
static volatile uint32_t PRG_ReprogPattern = 0xADDAADDA;

uint32_t *PRG_ReprogPatternAddr=(uint32_t*)REPROG_PATTERN_ADDR;

uint32_t baseAddress=0;

/* Fonction pour gerer le depart en reprog */
void PRG_CheckDownloadPattern(char c)
{
	if (c == PRG_ReprogEscapeChar) PRG_ReprogEscapeCharCounter++;
	else PRG_ReprogEscapeCharCounter =0;

	if (PRG_ReprogEscapeCharCounter>=5) 
	{
		/* Depart en mode download */
		PRG_ReprogEscapeCharCounter=0;

		/* Ecriture d'un pattern en memoire */
		*PRG_ReprogPatternAddr = PRG_ReprogPattern;

		/* Disable all interrupts */
		NVIC->ICER[0]=0xFFFFFFFF;
		NVIC->ICER[1]=0xFFFFFFFF;
		NVIC->ICER[1]=0xFFFFFFFF;
		SysTick->CTRL=0;

		/* Reset de l'ecran */
		GLCD_ResetScreen();

		/* et reboot */
		NVIC_SystemReset();
	}
}

/* Fonction pour tester si une reprog est necessaire */
int PRG_CheckReprogRequest(void)
{
	if (*PRG_ReprogPatternAddr == PRG_REPROG_PATTERN) return PRG_RESET_REPROG;
	else if (*PRG_ReprogPatternAddr == PRG_SOFTRESET_PATTERN) return PRG_RESET_SOFTRESET;
	else return PRG_RESET_HARDRESET;
}

/* Fonction pour nettoyer la condition de reprog */
void PRG_ResetReprogRequest(void)
{
	*PRG_ReprogPatternAddr = PRG_SOFTRESET_PATTERN;
}
