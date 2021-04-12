/******************************************************************************/
/* system.h: Header file for system include                                   */
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
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "stm32f30x.h"

#include "version.h"
#include "ABI.h"
#include "panic.h"

#include "glcd.h"
#include "usart.h"
#include "keys.h"

#include "gui.h"

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "reprog.h"

extern FILE __stdout;
extern FILE __stdin;
extern FILE __console;
extern FILE __lcd;
extern FILE __stderr;

#define BAUDRATE 500000
//#define BAUDRATE 115200

#endif /* __SYSTEM_H__ */
