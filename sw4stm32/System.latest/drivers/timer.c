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
#include "timer.h"

static TIMER_EventCallback TIMER_Callback;
static char TIMER_Enable;
static uint8_t TIMER_Cnt;

#define TIMER_CNT_MAX 100

void TIMER_Init(void)
{
	TIMER_Enable=0;
	TIMER_Cnt=0;
	TIMER_Callback=0;
}

int  TIMER_Start(void)
{
	if (TIMER_Callback!=0)
	{
		TIMER_Enable=1;
		return 1;
	}
	else return 0;
}

void TIMER_Stop(void)
{
	TIMER_Enable=0;
}

void TIMER_SetEventCallback(TIMER_EventCallback callback)
{
	TIMER_Callback=callback;
}

void TIMER_Handler(void)
{
	if (TIMER_Enable)
	{
		TIMER_Cnt++;

		if (TIMER_Cnt >= TIMER_CNT_MAX)
		{
			TIMER_Cnt=0;

			if (TIMER_Callback !=0)
			{
				TIMER_Callback();
			}
		}
	}
}
