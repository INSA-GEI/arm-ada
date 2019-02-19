/******************************************************************************/
/* keys.h: Header for keys and buttons managment                              */
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
#ifndef __KEYS_H__
#define __KEYS_H__

#include "stm32f30x.h"

enum KEY_ID_ENUM
{
	KEY_A=0,
	KEY_B,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_CENTER,
	KEY_RIGHT,
	KEY_LEFT_UP,
	KEY_LEFT_DOWN,
	KEY_RIGHT_UP,
	KEY_RIGHT_DOWN,
	KEY_SYSTEM
};

enum KEY_STATE_ENUM
{
	KEY_RELEASED=0,
	KEY_PRESSED
};

typedef enum KEY_ID_ENUM KEY_ID;
typedef enum KEY_STATE_ENUM KEY_STATE;

void KEYS_Init(void);
KEY_STATE KEYS_GetState(KEY_ID key);

#endif /* __KEYS_H__ */
