/******************************************************************************/
/* m_alloc.h: Header for Memory allocator service                             */
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
#ifndef __M_ALLOC_H__
#define __M_ALLOC_H__

#include "stm32f30x.h"

extern unsigned int Image$$StartMemoryAlloc$$Base;

#define MALLOC_INITIAL_BASE (uint32_t)&(Image$$StartMemoryAlloc$$Base)
#define MALLOC_END_BASE 0x2000A000

void MALLOC_Init(uint32_t bound);
void* MALLOC_GetMemory(uint32_t size);
void MALLOC_FreeMemory(void* ptr);

#endif /* __M_ALLOC_H__ */
