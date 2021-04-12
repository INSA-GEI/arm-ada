/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the �Vision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
//#include <rt_misc.h>
#include <time.h>
#include <string.h>

//#include "usart.h"
#include "system.h"
#include "panic.h"

//#pragma import(__use_no_semihosting_swi)


//extern int sendchar (int c);
//extern int getkey   (void);

//struct __FILE { int handle; /* Add whatever you need here */ };
/*FILE __stdout={_file=1};
FILE __stdin={1};
FILE __console={1};
FILE __lcd={10};
FILE __stderr={20};*/

int fputc(int c, FILE *f) 
{
	if (f->_file == 1)  return (USART_Send(USART1, (char)c));
	if (f->_file == 2) // used for ADA exception
	{
		USART_Send(USART1, (char)c);
		return (CONSOLE_PrintChar(c));
	}	
	if (f->_file == 10) return (CONSOLE_PrintChar(c));

	return -1;
}

int fgetc(FILE *f) 
{
int c;
	if (f->_file == 1) USART_Receive(USART1, (char*)&c);
	else c=0;
  return (c);
}

void _exit(int exit_code)
{

	PANIC_SoftwarePanic("Unexpected exit", "System requests to exit");
	
	while (1);
}

//void _free(void* ptr)
//{
//	C_free(ptr);
//}

//caddr_t _sbrk(int incr) 
//{
//  int i;
//	static char *heap_end;
//	char *prev_heap_end;
//	
//	sprintf(sprintf_buf, "Request %i byte(s)\n", incr);

//	for (i=0; i<strlen(sprintf_buf); i++)
//	{
//	  _write(1, &sprintf_buf[i], 1);
//	}

//	if (heap_end == 0) 
//	{
//		heap_end = sbrk_buffer;
//	}

//	prev_heap_end = heap_end;

//	if (heap_end + incr > sbrk_UpperBound) 
//	{
//		_write (1, "Heap exhausted\n", 15);
//		_exit(1);
//	}

//	heap_end += incr;
//	return (caddr_t) prev_heap_end;
//}

void abort (void)
{
	while (1);
}

int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int c) {
  USART_Send(USART1, (char)c);
}


void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}
