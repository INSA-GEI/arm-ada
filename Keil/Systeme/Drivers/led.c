/******************************************************************************/
/* led.c: STM32 low level driver for led                                      */
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
#include "led.h"

#define LED_PWR_GPIO 			GPIOE
#define LED_PWR_PIN 			GPIO_Pin_5

void LED_Init(void)
{
//GPIO_InitTypeDef GPIO_InitStructure;
//
//	/* Demarre les horloges des gpio E */
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
//	
//	GPIO_StructInit(&GPIO_InitStructure);
//	
//	/* Configure les touches en entrée */
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_OType= GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStructure.GPIO_Pin = LED_PWR_PIN ;
//	GPIO_Init(LED_PWR_GPIO, &GPIO_InitStructure);
}

void LED_Set(LED_STATE state)
{
//	if (state == LED_ON)
//	{
//		GPIO_SetBits(LED_PWR_GPIO, LED_PWR_PIN);
//	}
//	else
//	{
//		GPIO_ResetBits(LED_PWR_GPIO, LED_PWR_PIN);
//	}
}
