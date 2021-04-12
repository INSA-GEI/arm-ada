/******************************************************************************/
/* sram.h: Header for static ram acces                                        */
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
#ifndef __SRAM_H__
#define __SRAM_H__

#include "stm32f30x.h"

void SRAM_Init(void);
uint8_t SRAM_ReadByte(uint32_t addr);
void SRAM_WriteByte(uint32_t addr, uint8_t data);
void SRAM_ReadBuffer(uint32_t addr, uint8_t *buffer, int length);
void SRAM_WriteBuffer(uint32_t addr, uint8_t *buffer, int length);

/* Fonctions exportées pour GLCD */
extern const uint16_t SRAM_AddrConvertionTable[];

/*********************** Hardware specific configuration **********************/
#define SRAM_PIN_CE		GPIO_Pin_8
#define SRAM_PIN_WE		GPIO_Pin_9
#define SRAM_PIN_OE		GPIO_Pin_10

/*------------------------- Speed dependant settings -------------------------*/

/* If processor works on high frequency delay has to be increased, it can be 
   increased by factor 2^N by this constant                                   */
#define DELAY_2N    13

/* Macros for accessing pin */
#define SRAM_CE_1	GPIOB->BSRR =  SRAM_PIN_CE
#define SRAM_CE_0	GPIOB->BRR =  SRAM_PIN_CE
#define SRAM_WE_1	GPIOB->BSRR =  SRAM_PIN_WE
#define SRAM_WE_0	GPIOB->BRR =  SRAM_PIN_WE
#define SRAM_OE_1	GPIOB->BSRR =  SRAM_PIN_OE
#define SRAM_OE_0	GPIOB->BRR =  SRAM_PIN_OE

#endif /* __SRAM_H__ */

