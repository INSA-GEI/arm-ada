/******************************************************************************/
/* Keys.c: STM32 low level driver for keys and buttons                        */
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
#include "keys.h"

#define KEY_A_GPIO 			GPIO_C
#define KEY_B_GPIO 			GPIO_C
#define KEY_UP_GPIO 		GPIO_C
#define KEY_DOWN_GPIO 		GPIO_C
#define KEY_LEFT_GPIO 		GPIO_C
#define KEY_CENTER_GPIO 	GPIO_C
#define KEY_RIGHT_GPIO 		GPIO_C
#define KEY_SYSTEM_GPIO 	GPIO_A

#define KEY_A_PIN 			GPIO_Pin_9
#define KEY_B_PIN 			GPIO_Pin_8
#define KEY_UP_PIN 			GPIO_Pin_14
#define KEY_DOWN_PIN		GPIO_Pin_13
#define KEY_LEFT_PIN 		GPIO_Pin_11
#define KEY_CENTER_PIN 		GPIO_Pin_15
#define KEY_RIGHT_PIN 		GPIO_Pin_12
//#define KEY_RIGHT_PIN 	GPIO_Pin_0
#define KEY_SYSTEM_PIN 		GPIO_Pin_0

void KEYS_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Demarre les horloges des gpio C et A */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOC| RCC_AHBPeriph_GPIOD, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure);

	/* Configure les touches en entr�e */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = KEY_A_PIN | KEY_B_PIN | KEY_UP_PIN | KEY_DOWN_PIN | 
			KEY_LEFT_PIN | KEY_RIGHT_PIN | KEY_CENTER_PIN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/*GPIO_InitStructure.GPIO_Pin = KEY_RIGHT_PIN ;
	GPIO_Init(GPIOD, &GPIO_InitStructure);*/

	GPIO_InitStructure.GPIO_Pin = KEY_SYSTEM_PIN ;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

KEY_STATE KEYS_GetState(KEY_ID key)
{
	int state=0;
	uint16_t pin;

	pin = KEY_SYSTEM_PIN;

	switch (key)
	{
	case KEY_A:
		pin = KEY_A_PIN;
		break;
	case KEY_B:
		pin = KEY_B_PIN;
		break;
	case KEY_UP:
		pin = KEY_UP_PIN;
		break;
	case KEY_DOWN:
		pin = KEY_DOWN_PIN;
		break;
	case KEY_LEFT:
		pin = KEY_LEFT_PIN;
		break;
	case KEY_RIGHT:
		pin = KEY_RIGHT_PIN;
		break;
	case KEY_CENTER:
		pin = KEY_CENTER_PIN;
		break;
	case KEY_SYSTEM:
		pin = KEY_SYSTEM_PIN;
		break;
	}

	if (key == KEY_SYSTEM) 
	{
		state = GPIO_ReadInputDataBit(GPIOA, pin);
		if (state == 0) state = 1;
		else state= 0;
	}
	else state = GPIO_ReadInputDataBit(GPIOC, pin);

	if (state == 0)	return KEY_PRESSED;
	else return KEY_RELEASED;
}
