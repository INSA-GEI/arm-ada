/******************************************************************************/
/* audio.h: Header for audio driver                                           */
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
#ifndef __AUDIO_H__
#define __AUDIO_H__

#include "stm32f30x.h"

#define AUDIO_BUFFER_LENGTH 512
typedef void (*AUDIO_EventCallback)(int buffer_nbr);

void AUDIO_Init(void);
void AUDIO_Start(void);
void AUDIO_Stop(void);
void AUDIO_FillBuffer(int buffer_nbr, uint8_t* buffer);
void AUDIO_GetBuffersPtr(uint8_t* *buffer_1, uint8_t* *buffer_2);
void AUDIO_SetEventCallback(AUDIO_EventCallback callback);

#endif /* __AUDIO_H__ */
