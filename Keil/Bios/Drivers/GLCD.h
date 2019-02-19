/******************************************************************************/
/* GLCD.h: Graphic LCD function prototypes and defines                        */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2011 Keil - An ARM Company. All rights reserved.        */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#ifndef _GLCD_H
#define _GLCD_H
#include "stm32f30x.h"

/*------------------------------------------------------------------------------
  Color coding
  GLCD is coded:   15..11 red, 10..5 green, 4..0 blue  (uint16_t)  GLCD_R5, GLCD_G6, GLCD_B5   
  original coding: 17..12 red, 11..6 green, 5..0 blue                    ORG_R6,  ORG_G6,  ORG_B6

  ORG_R1..5 = GLCD_R0..4,  ORG_R0 = GLCD_R4
  ORG_G0..5 = GLCD_G0..5,
  ORG_B1..5 = GLCD_B0..4,  ORG_B0 = GLCD_B4
 *----------------------------------------------------------------------------*/
                            
/* GLCD RGB color definitions                                                 */
//#define Black           0x0000      /*   0,   0,   0 */
//#define Navy            0x000F      /*   0,   0, 128 */
//#define DarkGreen       0x03E0      /*   0, 128,   0 */
//#define DarkCyan        0x03EF      /*   0, 128, 128 */
//#define Maroon          0x7800      /* 128,   0,   0 */
//#define Purple          0x780F      /* 128,   0, 128 */
//#define Olive           0x7BE0      /* 128, 128,   0 */
//#define LightGrey       0xC618      /* 192, 192, 192 */
//#define DarkGrey        0x7BEF      /* 128, 128, 128 */
//#define Blue            0x001F      /*   0,   0, 255 */
//#define Green           0x07E0      /*   0, 255,   0 */
//#define Cyan            0x07FF      /*   0, 255, 255 */
//#define Red             0xF800      /* 255,   0,   0 */
//#define Magenta         0xF81F      /* 255,   0, 255 */
//#define Yellow          0xFFE0      /* 255, 255, 0   */
//#define White           0xFFFF      /* 255, 255, 255 */

#define Black           0x00      /*   0,   0,   0 */
#define Navy            0x01      /*   0,   0, 1 */
#define DarkGreen       0x0C      /*   0, 3,   0 */
#define DarkCyan        0x0D      /*   0, 3, 1 */
#define Maroon          0x60      /* 3,   0,   0 */
#define Purple          0x61      /* 3,   0, 1 */
#define Olive           0x6C      /* 3, 3,   0 */
#define LightGrey       0xB5      /* 5, 5, 2 */
#define DarkGrey        0x6D      /* 3, 3, 1 */
#define Blue            0x03      /*   0,   0, 3 */
#define Green           0x1C      /*   0, 7,   0 */
#define Cyan            0x1F      /*   0, 7, 3 */
#define Red             0xE0      /* 7,   0,   0 */
#define Magenta         0xE3      /* 7,   0, 3 */
#define Yellow          0xFC      /* 7, 7, 0   */
#define White           0xFF      /* 7, 7, 3 */

typedef uint8_t COLOR;
struct FONT_ST
{
	uint32_t height;
	uint32_t width;
	uint8_t data;
};

typedef struct FONT_ST FONT;

#define GLCD_MAX_COLUMN	(320/8)
#define GLCD_MAX_ROW	(240/16)

extern void GLCD_Wait  (void);
extern void GLCD_Init  (void);
extern void GLCD_Clear (COLOR color);
extern void GLCD_WindowMax (void);
extern void GLCD_SetTextColor (COLOR color);
extern void GLCD_SetBackColor (COLOR color);
extern void GLCD_SetFont(FONT* font);
extern void GLCD_PutPixel (uint32_t x, uint32_t y, COLOR color);
extern void GLCD_SetCursor(int32_t X, uint32_t Y);
extern void GLCD_DrawChar (uint32_t x,  uint32_t y, uint8_t c);
extern void GLCD_DrawString (uint32_t x,  uint32_t y, const char *str);
extern void GLCD_DrawADAString (uint32_t x, uint32_t y, uint32_t len, const char *str);
extern void GLCD_DrawLine (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
extern void GLCD_DrawImage (COLOR* data, uint32_t x, uint32_t y, uint32_t w, int32_t h);
extern void GLCD_DrawRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2); 
extern void GLCD_DrawFillRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2); 
extern void GLCD_DrawCircle (uint32_t x, uint32_t y, uint32_t radius); 
extern void GLCD_DrawFillCircle (uint32_t x, uint32_t y, uint32_t radius); 
extern void GLCD_DrawBargraph  (uint32_t x,  uint32_t y, uint32_t w, uint32_t h, uint32_t val);
extern void GLCD_SetScrollWindow (uint32_t x, uint32_t y, uint32_t w, uint32_t h);
extern void GLCD_ScrollVertical (uint32_t dy);
extern void GLCD_ScrollHorizontal (uint32_t dy);

#endif /* _GLCD_H */
