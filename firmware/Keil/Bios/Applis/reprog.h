/******************************************************************************/
/* reprog.h: Header for reprogramming features                                */
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

#define PRG_RESET_REPROG		1
#define PRG_RESET_HARDRESET	2
#define PRG_RESET_SOFTRESET	3

void PRG_Run(void);

/* Fonctions pour tester et entrer en mode reprog */
void PRG_Init(void);
void PRG_CheckDownloadPattern(char c);
int PRG_CheckReprogRequest(void);
void PRG_ResetReprogRequest(void);
