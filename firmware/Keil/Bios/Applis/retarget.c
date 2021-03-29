/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the µVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <rt_misc.h>
#include <time.h>
#include <string.h>

//#include "usart.h"
#include "bios.h"
#include "panic.h"

#pragma import(__use_no_semihosting_swi)

//extern int sendchar (int c);
//extern int getkey   (void);

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout={1};
FILE __stdin={1};
FILE __console={1};
FILE __lcd={10};
FILE __stderr={20};

int fputc(int c, FILE *f) 
{
	return (USART_Send(USART1, (char)c));
}

int fgetc(FILE *f) 
{
int c;
	if (f->handle == 1) USART_Receive(USART1, (char*)&c);
	else c=0;
  return (c);
}

void _exit(int exit_code)
{
	while (1);
}

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
