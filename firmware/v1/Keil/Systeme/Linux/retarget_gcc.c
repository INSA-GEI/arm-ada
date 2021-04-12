/*----------------------------------------------------------------------------
 * Name:    retarget_gcc.c
 * Purpose: Redirection des E/S et autres fonctions OS
 * Version: V1.00
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * Copyright (c) 2005-2007 Keil Software. All rights reserved.
 *---------------------------------------------------------------------------*/
 
#include <stm32f30x.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char *sbrk_buffer;
char *sbrk_UpperBound=(char*)0x20009000;
char sprintf_buf[128];

//char write_buffer[1000];
//struct ST_MY_FILE { int handler};
//typedef struct ST_MY_FILE MY_FILE;

struct __FILE { int handle; /* Add whatever you need here */ };
typedef struct __FILE C_FILE;

C_FILE __stdout={1};
C_FILE __stdin={1};
C_FILE __console={1};
C_FILE __lcd={10};
C_FILE __stderr={20};

int _write(int file, char *ptr, int len)
{
  int i;

  for (i=0; i< len; i++)
    {
      
      USART_Send(USART1, ptr[i]);
    }

  return 1;
}

int _read(int file, char *ptr, int len)
{
int c;

 USART_Receive(USART1, (char*)&c);
 
 return (c);
}

int fputc_ADA(int c, C_FILE *f) 
{
  if (f->handle == 1)  return (USART_Send(USART1, (char)c));
  if (f->handle == 2) // used for ADA exception 
    {
      USART_Send(USART1, (char)c);
      return (CONSOLE_PrintChar(c));
    }	
  if (f->handle == 10) return (CONSOLE_PrintChar(c));

  return -1;
}

int fgetc_ADA(C_FILE *f) 
{
  int c;
  
  if (f->handle == 1) USART_Receive(USART1, (char*)&c);
  else c=0;
  return (c);
}

void _exit(int exit_code)
{
  PANIC_SoftwarePanic("Unexpected exit", "System requests to exit");

  while (1);
}

/* void _free(void* ptr) */
/* { */
/*  C_free(ptr); */
/* } */

caddr_t _sbrk(int incr) 
{
int i;
  
 static char *heap_end;
 char *prev_heap_end;
	
 sprintf(sprintf_buf, "Request %i byte(s)\n", incr);

 for (i=0; i<strlen(sprintf_buf); i++)
   {
     _write(1, &sprintf_buf[i], 1);
   }
	
 if (heap_end == 0) 
   {
     heap_end = sbrk_buffer;
   }

 prev_heap_end = heap_end;

 if (heap_end + incr > sbrk_UpperBound) 
   {
     _write (1, "Heap exhausted\n", 15);
     _exit(1);
   }

 heap_end += incr;

 return (caddr_t) prev_heap_end;
}

void abort (void)
{
  _exit(1);
}

void _ttywrch(int c) {
  USART_Send(USART1, (char)c);
}


void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}
