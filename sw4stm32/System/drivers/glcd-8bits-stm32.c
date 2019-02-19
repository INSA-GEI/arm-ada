/******************************************************************************/
/* GLCD_8bits_STM32.c: STM32 low level Graphic LCD (240x320 pixels) driven    */
/*                       with 8-bit parallel interface INT24BTFT              */
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
#include "glcd.h"

# include "sram.h"
/************************** Orientation  configuration ************************/

#ifndef LANDSCAPE
#define LANDSCAPE   1                   /* 1 for landscape, 0 for portrait    */
#endif

#ifndef ROTATE180
#define ROTATE180   0                   /* 1 to rotate the screen for 180 deg */
#endif

/*********************** Hardware specific configuration **********************/
#define GLCD_PIN_RST	GPIO_Pin_10
#define GLCD_PIN_CS		GPIO_Pin_2
#define GLCD_PIN_RS		GPIO_Pin_4
#define GLCD_PIN_WR		GPIO_Pin_9
#define GLCD_PIN_RD		GPIO_Pin_6
#define GLCD_PIN_INT	GPIO_Pin_4
#define GLCD_PIN_WAIT	GPIO_Pin_5
/*------------------------- Speed dependant settings -------------------------*/

/* If processor works on high frequency delay has to be increased, it can be 
   increased by factor 2^N by this constant                                   */
#define DELAY_2N    13

#define NB_NOP_RD	2
#define NB_NOP_WR   3

/*---------------------- Graphic LCD size definitions ------------------------*/

#if (LANDSCAPE == 1)
#define WIDTH       320                 /* Screen Width (in pixels)           */
#define HEIGHT      240                 /* Screen Hight (in pixels)           */
#else
#define WIDTH       240                 /* Screen Width (in pixels)           */
#define HEIGHT      320                 /* Screen Hight (in pixels)           */
#endif
#define BPP         16                  /* Bits per pixel                     */
#define BYPP        ((BPP+7)/8)         /* Bytes per pixel                    */

/*--------------- Graphic LCD interface hardware definitions -----------------*/

#define BG_COLOR  0                     /* Background color                   */
#define TXT_COLOR 1                     /* Text color                         */

#define cSetD0 0x01
#define cSetD1 0x02
#define cSetD2 0x04
#define cSetD3 0x08
#define cSetD4 0x10
#define cSetD5 0x20
#define cSetD6 0x40
#define cSetD7 0x80
#define cClrD0 0xfe
#define cClrD1 0xfd
#define cClrD2 0xfb
#define cClrD3 0xf7
#define cClrD4 0xef
#define cClrD5 0xdf
#define cClrD6 0xbf
#define cClrD7 0x7f

/* Macros for accessing pin */
#define LCD_CS_1	GPIOF->BSRR =  GLCD_PIN_CS
#define LCD_CS_0	GPIOF->BRR =  GLCD_PIN_CS
#define LCD_RS_1	GPIOF->BSRR =  GLCD_PIN_RS
#define LCD_RS_0	GPIOF->BRR =  GLCD_PIN_RS
#define LCD_WR_1	GPIOF->BSRR =  GLCD_PIN_WR
#define LCD_WR_0	GPIOF->BRR =  GLCD_PIN_WR
#define LCD_RD_1	GPIOF->BSRR =  GLCD_PIN_RD
#define LCD_RD_0	GPIOF->BRR =  GLCD_PIN_RD

#define LCD_GET_WAIT (GPIOB->IDR & GLCD_PIN_WAIT)

/*---------------------------- Global variables ------------------------------*/

/******************************************************************************/
// static volatile unsigned short Color[2] = {White, Black};

static uint8_t LTPR0_Reg =0;
/************************ Local auxiliary functions ***************************/

/*******************************************************************************
 * Delay in while loop cycles                                                   *
 *   Parameter:    cnt:    number of while cycles to delay                      *
 *   Return:                                                                    *
 *******************************************************************************/
static void delay (int cnt) 
{
	volatile uint32_t tmp =cnt;

	tmp <<= DELAY_2N;
	while (tmp--);
}

/*******************************************************************************
 * Set data port as output (for sending data to LCD)                            *
 *   Parameter:    																			                       *
 *   Return:                                                                    *
 *******************************************************************************/
static void set_data_output(void) 
{
	uint32_t tmp;

	tmp=GPIOC->MODER ;
	tmp = tmp & 0xFFFF0000; /* met les lignes 0 � 7 en input  */
	tmp = tmp | 0x00005555; /* met les lignes 0 � 7 en output */
	GPIOC->MODER = tmp;
}

/*******************************************************************************
 * Set data port as input (for reading data from LCD)                           *
 *   Parameter:    																			                       *
 *   Return:                                                                    *
 *******************************************************************************/
static void set_data_input(void) 
{
	GPIOC->MODER &= 0xFFFF0000; /* met les lignes 0 � 7 en input */
}

/*******************************************************************************
 * Write data to LCD                                                            *
 *   Parameter: data to be write (uint8_t)								                       *
 *   Return:                                                                    *
 *******************************************************************************/
static void write_data(uint8_t data)
{
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
}

/*******************************************************************************
 * Read data from LCD                                                           *
 *   Parameter:                          								                       *
 *   Return: data read (uint8_t)                                                *
 *******************************************************************************/
static uint8_t read_data(void)
{
	return (uint8_t)(GPIOC->IDR & 0x00FF);
}

/*******************************************************************************
 * Read contents of a register                                                  *
 *   Parameter:  reg: register number to read (uint8_t)                         *
 *   Return: register content (uint8_t)                                         *
 *******************************************************************************/
static uint8_t LCD_RegisterRead(uint8_t reg)
{
	uint8_t value;

	while (!LCD_GET_WAIT); /* Attente que le signal wait repasse à 1 (fin du dernier traitement) */

	LCD_CS_0;

	set_data_output();
	write_data(reg);

	LCD_WR_0;
#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	LCD_CS_1;

	set_data_input();

	LCD_RS_0;
	LCD_CS_0;
	LCD_RD_0;

#if (NB_NOP_RD == 1)
	__NOP();
#endif /* NB_NOP_RD == 1 */

#if (NB_NOP_RD == 2)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_RD == 2 */

#if (NB_NOP_RD == 3)
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_RD == 3 */

	value = read_data();

	LCD_RD_1;
	LCD_RS_1;
	LCD_CS_1;

	//set_data_output();
	return value;
}

/*******************************************************************************
 * Write data to LCD                                                            *
 *   Parameter: Reg: register number (uint8_t) 					                       *
 *              data: value to write into register (uint8_t)                    *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_RegisterWrite(uint8_t reg, uint8_t data)
{
	while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

	LCD_CS_0;

	set_data_output();
	write_data(reg);

	LCD_WR_0;

#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	LCD_CS_1;

	LCD_RS_0;
	LCD_CS_0;

	write_data(data);
	LCD_WR_0;

#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	LCD_RS_1;
	LCD_CS_1;

	set_data_input();
}

/*******************************************************************************
 * Write buffer to LCD                                                          *
 *   Parameter: Reg: register number (uint8_t) 					                       *
 *              data: pointer to buffer to be write (uint8_t *)                   *
 *              length: length of buffer (int)                                  *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_RegisterWriteBuffer(uint8_t reg, uint8_t *data, int length)
{
	int i;

	i=0;
	while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

	LCD_CS_0;

	set_data_output();
	write_data(reg);

	LCD_WR_0;

#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	LCD_CS_1;

	LCD_CS_0;
	LCD_RS_0;

	while (i<length)
	{
		while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

		write_data(data[i]);
		i++;
		LCD_WR_0;

#if (NB_NOP_WR == 1)
		__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 3 */

		LCD_WR_1;

	}

	LCD_RS_1;
	LCD_CS_1;

	set_data_input();
}

/*******************************************************************************
 * Get LCD status                                                               *
 *   Parameter:                                                                 *
 *   Return: status (uint8_t)                                                   *
 *******************************************************************************/
static uint8_t LCD_GetStatus(void)
{
	uint8_t value;

	LCD_CS_0;

	//set_data_input();

	LCD_RD_0;

#if (NB_NOP_RD == 1)
	__NOP();
#endif /* NB_NOP_RD == 1 */

#if (NB_NOP_RD == 2)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_RD == 2 */

#if (NB_NOP_RD == 3)
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_RD == 3 */

	value = read_data();

	LCD_RD_1;
	LCD_CS_1;

	//set_data_output();

	return value;
}

/*******************************************************************************
 * Wait while LCD is busy                                                       *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_CheckBusy(void)
{
	while(LCD_GetStatus()&0x80);
}

/*******************************************************************************
 * Switch to text mode                                                          *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_SetTextMode(void)
{ 
	uint8_t temp;

	temp= LCD_RegisterRead(0x40); //MWCR0
	temp |= cSetD7 ;
	LCD_RegisterWrite(0x40,temp);
	temp=LCD_RegisterRead(0x40);
}

/*******************************************************************************
 * Switch to graphic mode                                                       *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_SetGraphicMode(void)
{ 
	uint8_t temp;

	//while (LCD_GetStatus() & 0x80); /* attente de la fin de la derniere operation */

	temp= LCD_RegisterRead(0x40); //MWCR0
	temp &= ~cSetD7 ;
	LCD_RegisterWrite(0x40,temp);
}

/*******************************************************************************
 * Set geometric coordinate for futur drawing operation                         *
 *   Parameter: XL,XR,YT,YB: coordinates                                        *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_GeometricCoordinate(uint32_t XL, uint32_t YT, uint32_t XR, uint32_t YB)//
{ 
	uint8_t	temp;

	temp=XL;
	LCD_RegisterWrite(0x91,temp);

	temp=XL>>8;
	LCD_RegisterWrite(0x92,temp);

	temp=XR;
	LCD_RegisterWrite(0x95,temp);

	temp=XR>>8;
	LCD_RegisterWrite(0x96,temp);

	temp=YT;
	LCD_RegisterWrite(0x93,temp);

	temp=YT>>8;
	LCD_RegisterWrite(0x94,temp);

	temp=YB;
	LCD_RegisterWrite(0x97,temp);

	temp=YB>>8;
	LCD_RegisterWrite(0x98,temp);
}

/*******************************************************************************
 * Set circle coordinates                                                       *
 *   Parameter: X,Y,R: coordinates                                              *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_CircleCoordinateRadius(uint32_t X, uint32_t Y, uint32_t R)
{ 
	uint8_t temp;

	temp=X;
	LCD_RegisterWrite(0x99,temp);

	temp=X>>8;
	LCD_RegisterWrite(0x9a,temp);

	temp=Y;
	LCD_RegisterWrite(0x9b,temp);

	temp=Y>>8;
	LCD_RegisterWrite(0x9c,temp);

	temp=R;
	LCD_RegisterWrite(0x9d,temp);
}

/*******************************************************************************
 * Set active area for drawing                                                  *
 *   Parameter: XL,XR,YT,YB: coordinate of viewing area rectangle (uint32_t)    *
 *   Return:                                                                    *
 *******************************************************************************/
static void LCD_SetActiveWindow(uint32_t XL, uint32_t XR ,uint32_t YT ,uint32_t YB)
{
	uint8_t temp;
	//setting active window X
	temp=XL;
	LCD_RegisterWrite(0x30,temp); //HSAW0

	temp=XL>>8;
	LCD_RegisterWrite(0x31,temp); //HSAW1

	temp=XR;
	LCD_RegisterWrite(0x34,temp);//HEAW0

	temp=XR>>8;
	LCD_RegisterWrite(0x35,temp); //HEAW1

	//setting active window Y
	temp=YT;
	LCD_RegisterWrite(0x32,temp); //VSAW0

	temp=YT>>8;
	LCD_RegisterWrite(0x33,temp);//VSAW1

	temp=YB;
	LCD_RegisterWrite(0x36,temp); //VEAW0

	temp=YB>>8;
	LCD_RegisterWrite(0x37,temp); //VEAW1
}

/*******************************************************************************
 * Convert 16 bits color to 8bit color used for text background and foreground  *
 *   Parameter: color: 16 bit color                                             *
 *   Return: 8 bit color                                                        *
 *******************************************************************************/
//static uint8_t LCD_ConvertColor16bTo8b(COLOR color)
//{
//uint8_t temp;
//uint8_t R,G,B;
//	
//		/* color format : RRRRR GGGGGG BBBBB
//	     8 bit color format: RRR GGG BB */
//	
//	R= (color & 0xF800)>>11;
//	G= (color & 0x07E0)>>5;
//	B= (color & 0x001F);
//	
//	R = R >>2;
//	G = G >>3;
//	B = B >>3;
//	
//	temp = (R<<5) + (G<<2) + B;
//	return temp;
//}

/************************ Exported functions **********************************/

/*******************************************************************************
 * Wait for LCD ready                                                           *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_Wait(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Attente de 2 secondes */
	delay(3000);

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_SetBits(GPIOE, GPIO_Pin_15);
}

/*******************************************************************************
 * Initialize the Graphic LCD controller                                        *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_Init (void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure les lignes */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOF, ENABLE);

	/* Config de IT et WAIT */
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4| GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Config des lignes de data */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | 
			GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Config des lignes de controle */
	/* On met toutes les lignes de controle � '1' */
	GPIO_SetBits(GPIOF, GLCD_PIN_RD | GLCD_PIN_CS | GLCD_PIN_WR  | GLCD_PIN_RS );

	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GLCD_PIN_RD | GLCD_PIN_CS | GLCD_PIN_WR  | GLCD_PIN_RS ;
	GPIO_Init(GPIOF, &GPIO_InitStructure);

	/* On passe le bus en sortie */
	set_data_output();

	/* Dernieres initialisations de l'ecran */
	LCD_SetActiveWindow(0,319,0,239); // setup display resolution to 320x240 pixels
	LCD_RegisterWrite(0x20,0x89); //Rotation de 90� et HDIR=1
	LCD_RegisterWrite(0x01,0x80); // Display on
	//LCD_RegisterWrite(0x10, 0x08);
	LCD_RegisterWrite(0x10,0x00); // 256 color, parrallel mode
	LCD_RegisterWrite(0x40, 0x0);
}

/*******************************************************************************
 * Clear whole screen and paint it with given color                             *
 *   Parameter: color: color used for clearing display                          *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_Clear (COLOR color)
{
	uint8_t temp;

	/* Set background color as color to be used for clearing display */
	temp = LCD_RegisterRead(0x8E); //MCLR
	temp |= cSetD0 ;
	LCD_RegisterWrite(0x8e,temp); //MCLR
	LCD_CheckBusy();

	GLCD_SetBackColor(color); /* Set background color */

	/* Clear display with background color */
	temp = LCD_RegisterRead(0x8E); //MCLR
	temp |= cSetD7 ;
	LCD_RegisterWrite(0x8e,temp); //MCLR
	LCD_CheckBusy();
}

/*******************************************************************************
 * Reset all screen layer, paint all white                                      *
 *   Parameter: none                                                            *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_ResetScreen(void)
{
	/* Remember:
	 * Layer 1 is on foreground, layer 2 is background
	 *
	 * By default, we use layer 1 (foreground) and set layer 1 transparent by painting it white and set transparent color as white
	 */

	/* Reset scroll */

	GLCD_SetLayer(GLCD_LAYER2);
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);
	GLCD_ScrollVertical(0);
	GLCD_ScrollHorizontal(0);

	GLCD_SetLayer(GLCD_LAYER1);
	GLCD_SetTextColor(White);
	GLCD_DrawFillRectangle(0,0,319,239);
	GLCD_ScrollVertical(0);
	GLCD_ScrollHorizontal(0);
	GLCD_LayerDisplayMode(GLCD_LAYER_DISPLAY_LAYER1);
}

/*******************************************************************************
 * Set working area to maximum size (320 * 240 )                                *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_WindowMax (void)
{
	LCD_SetActiveWindow(0,319,0,239);
}

/*******************************************************************************
 * Set Layer scroll mode                                                        *
 *   Parameter:    mode                                                         *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_LayerScrollMode(uint8_t mode)
{
	LTPR0_Reg = LTPR0_Reg & 0x3F;
	LTPR0_Reg = LTPR0_Reg  + (mode & 0xC0);
	LCD_RegisterWrite(0x52, LTPR0_Reg);
}

/*******************************************************************************
 * Set Layer scroll mode                                                        *
 *   Parameter:    mode                                                         *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_LayerDisplayMode(uint8_t mode)
{
	LTPR0_Reg = LTPR0_Reg & 0xC0;
	LTPR0_Reg = LTPR0_Reg  + (mode & 0x07);
	LCD_RegisterWrite(0x52, LTPR0_Reg);
}

/*******************************************************************************
 * Set Layer transparency                                                       *
 *   Parameter:    mode                                                         *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_LayerTransparency(uint8_t layer1_trans, uint8_t layer2_trans)
{
	LCD_RegisterWrite(0x53, (layer1_trans & 0x0F)+((layer2_trans & 0x0F)<<4));
}

/*******************************************************************************
 * Set Layer mode                                                               *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetLayer(uint8_t layerNbr)
{
	LCD_RegisterWrite(0x41, (layerNbr & 0x01)); //MWCR1
}

/*******************************************************************************
 * Set Source point for BTE engine                                              *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetSource(uint32_t X, uint32_t Y, uint8_t layer)
{
	uint8_t temp;

	temp=X;
	LCD_RegisterWrite(0x54, temp); //HSBE0

	temp = (X>>8) & 0x03;
	LCD_RegisterWrite(0x55, temp); //HSBE1

	temp=Y;
	LCD_RegisterWrite(0x56, temp); //VSBE0

	temp = (Y>>8) & 0x01;
	temp = temp + (layer<<7);
	LCD_RegisterWrite(0x57, temp); //VSBE1	
}

/*******************************************************************************
 * Set destination point for BTE engine                                         *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetDestination(uint32_t X, uint32_t Y, uint8_t layer)
{
	uint8_t temp;

	temp=X;
	LCD_RegisterWrite(0x58, temp); //HDBE0

	temp = (X>>8) & 0x03;
	LCD_RegisterWrite(0x59, temp); //HDBE1

	temp=Y;
	LCD_RegisterWrite(0x5A, temp); //VDBE0

	temp = (Y>>8) & 0x01;
	temp = temp + (layer<<7);
	LCD_RegisterWrite(0x5B, temp); //VDBE1	
}

/*******************************************************************************
 * Set size for BTE engine                                                      *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetSize(uint32_t width, uint32_t height)
{
	uint8_t temp;

	temp=width;
	LCD_RegisterWrite(0x5C, temp); //BEWR0

	temp = (width>>8) & 0x03;
	LCD_RegisterWrite(0x5D, temp); //BEWR1

	temp=height;
	LCD_RegisterWrite(0x5E, temp); //BEHR0

	temp = (height>>8) & 0x01;
	LCD_RegisterWrite(0x5F, temp); //BEHR1	
}

/*******************************************************************************
 * Set background color for BTE                                                 *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetBackgroundColor(uint32_t red, uint32_t green, uint32_t blue)
{
	uint8_t temp;

	temp=red & 0x1F;
	LCD_RegisterWrite(0x60, temp); //BGCR0

	temp=green & 0x3F;
	LCD_RegisterWrite(0x61, temp); //BGCR1

	temp=blue & 0x1F;
	LCD_RegisterWrite(0x62, temp); //BGCR2
}

/*******************************************************************************
 * Set foreground color for BTE                                                 *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetForegroundColor(uint32_t red, uint32_t green, uint32_t blue)
{
	uint8_t temp;

	temp=red & 0x1F;
	LCD_RegisterWrite(0x63, temp); //FGCR0

	temp=green & 0x3F;
	LCD_RegisterWrite(0x64, temp); //FGCR1

	temp=blue & 0x1F;
	LCD_RegisterWrite(0x65, temp); //FGCR2
}

/*******************************************************************************
 * Set pattern set number                                                       *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTESetPatternNumber(uint8_t pattern)
{
	LCD_RegisterWrite(0x66, pattern & 0x1F); //PTNO
}

/*******************************************************************************
 * Set background color for transparency                                        *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetTransparentColor(COLOR color)
{
	LCD_RegisterWrite(0x67, color); //BGTR
}

/*******************************************************************************
 * Start BTE                                                                    *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTEStart(uint8_t source_mode, uint8_t dest_mode, uint8_t ROP, uint8_t operation)
{
	uint8_t temp;

	LCD_RegisterWrite(0x51, (ROP<<4)+operation); //BECR1
	LCD_RegisterWrite(0x50, (source_mode<<6)+(dest_mode<<5)+0x80); //BECR0

	temp=0x40;
	while ((temp & 0x40)!=0 )
	{
		temp=LCD_GetStatus() & 0x40;
	}
}

/*******************************************************************************
 * Start BTE and fill from SRAM                                                 *
 *   Parameter:                                                                 *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_BTEStartAndFillFromSRAM(uint8_t dest_mode, uint8_t ROP, uint8_t operation, uint32_t SRAM_Ptr, uint32_t size)
{
	uint32_t i;

	LCD_RegisterWrite(0x51, (ROP<<4)+operation); //BECR1
	LCD_RegisterWrite(0x50, (1<<6)+(dest_mode<<5)+0x80); //BECR0

	i=0;
	while (!LCD_GET_WAIT); /* Attente que le signal wait LCD repasse � 1 (fin du dernier traitement) */

	GPIOA->BRR = GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_15 ;
	LCD_CS_0;

	set_data_output();
	write_data(0x02);

	LCD_WR_0;

#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	__NOP();

	LCD_CS_1;
	__NOP();
	__NOP();

	set_data_input();

	LCD_CS_0;
	__NOP();

	LCD_RS_0;
	__NOP();

	SRAM_WE_1;
	__NOP();

	SRAM_OE_0;
	__NOP();

	SRAM_CE_0;
	__NOP();

	while (i< size)
	{
		/* Positionne l'adresse cot� SRAM */
		GPIOD->ODR =  SRAM_Ptr & 0xFFFF;
		if (SRAM_Ptr>65535)
		{
			GPIOA->BRR = GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_15 ;
			GPIOA->ODR |= SRAM_AddrConvertionTable[(SRAM_Ptr>>16)];
		}

		while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

		SRAM_Ptr++;
		i++;
			__NOP();
			__NOP();
			__NOP();

		LCD_WR_0;

#if (NB_NOP_WR == 1)
		__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 3 */

		LCD_WR_1;
		__NOP();
		__NOP();
	}

	LCD_RS_1;
	__NOP();

	LCD_CS_1;
	__NOP();

	SRAM_OE_1;
	__NOP();

	SRAM_CE_1;
	__NOP();
}

/*******************************************************************************
 * Set color to be used for foreground                                          *
 *   Parameter: color: color to be used for foreground                          *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetTextColor (COLOR color)
{
	LCD_RegisterWrite(0x42, color); //TFCR
}

/*******************************************************************************
 * Set color to be used for background                                          *
 *   Parameter: color: color to be used for background                          *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetBackColor (COLOR color)
{
	LCD_RegisterWrite(0x43,color);  //TBCR
}

/*******************************************************************************
 * Set Cursor coordinate                                                        *
 *   Parameter:  X,Y: cursor coordinates(int32_t)                               *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetCursor(int32_t X, uint32_t Y)
{ 
	uint8_t temp;

	temp=X;
	LCD_RegisterWrite(0x46,temp);

	temp=X>>8;
	LCD_RegisterWrite(0x47,temp);

	temp=Y;
	LCD_RegisterWrite(0x48,temp);

	temp=Y>>8;
	LCD_RegisterWrite(0x49,temp);
}

/*******************************************************************************
 * Draw a single character                                                      *
 *   Parameter:  X,Y: cursor coordinates(int32_t)                               *
 *               c: character to write                                          *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawChar (uint32_t x, uint32_t y, uint8_t  c)
{
	uint32_t col,row;

	if (x>((320/8)-1)) x= ((320/8)-1);
	if (y>((240/16)-1)) y= ((240/16)-1);
	col = x*8;
	row = (y*16)-1;

	LCD_SetTextMode();
	GLCD_SetCursor(col, row);

	LCD_RegisterWrite(0x02, c);
	LCD_SetGraphicMode();
}

/*******************************************************************************
 * Set Cursor coordinate                                                        *
 *   Parameter:  X,Y: cursor coordinates(int32_t)                               *
 *               str: string to write                                           *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawString (uint32_t x, uint32_t y, const char *str)
{
	int length=0;
	uint32_t col,row;

	if (x>((320/8)-1)) x= ((320/8)-1);
	if (y>((240/16)-1)) y= ((240/16)-1);
	col = x*8;
	row = (y*16)-1;

	LCD_SetTextMode();
	GLCD_SetCursor(col, row);

	while(str[length] != '\0')
	{
		length++;
	}

	LCD_RegisterWriteBuffer(0x02, (uint8_t *)str, length);
	LCD_SetGraphicMode();
}

/*******************************************************************************
 * Draw an ADA formated string (not null terminated)                            *
 *   Parameter:  X,Y: cursor coordinates(int32_t)                               *
 *               len: length of the string                                      *
 *               str: string to write                                           *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawADAString (uint32_t x, uint32_t y, uint32_t len, const char *str)
{
	uint32_t col,row;

	if (x>((320/8)-1)) x= ((320/8)-1);
	if (y>((240/16)-1)) y= ((240/16)-1);
	col = x*8;
	row = (y*16)-1;

	LCD_SetTextMode();
	GLCD_SetCursor(col, row);

	LCD_RegisterWriteBuffer(0x02, (uint8_t *)str, len);
	LCD_SetGraphicMode();
}

/*******************************************************************************
 * Select font to use                                                           *
 *   Parameter:  font: pointer to font descriptor                               *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetFont(FONT* font)
{
}

/*******************************************************************************
 * Write a single pixel using foreground color                                  *
 *   Parameter:  X,Y: cursor coordinates(int32_t)                               *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_PutPixel (uint32_t x, uint32_t y, COLOR color)
{
	GLCD_SetCursor(x, y);
	LCD_RegisterWrite(0x02, color);
}

/*******************************************************************************
 * Draw a single line on screen                                                 *
 *   Parameter:  X1,Y1,X2,Y2: line dimension and coordinates                    *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawLine (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	if (x1>x2) LCD_GeometricCoordinate(x2,y2,x1,y1); // setup rectangle coordinates
	else LCD_GeometricCoordinate(x1,y1,x2,y2);
	LCD_RegisterWrite(0x90, 0x80); // draw a line
}

/*******************************************************************************
 * Draw an empty rectangle on screen                                            *
 *   Parameter:  X1,Y1,X2,Y2: line dimension and coordinates                    *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	if (x1>x2) LCD_GeometricCoordinate(x2,y2,x1,y1); // setup rectangle coordinates
	else LCD_GeometricCoordinate(x1,y1,x2,y2);
	LCD_RegisterWrite(0x90, 0x90); // draw a rectangle
}

/*******************************************************************************
 * Draw a filled rectangle on screen                                            *
 *   Parameter:  X1,Y1,X2,Y2: line dimension and coordinates                    *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawFillRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
	if (x1>x2) LCD_GeometricCoordinate(x2,y2,x1,y1); // setup rectangle coordinates
	else LCD_GeometricCoordinate(x1,y1,x2,y2);
	LCD_RegisterWrite(0x90, 0xB0); // draw a filled rectangle
}

/*******************************************************************************
 * Draw an empty circle on screen                                               *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawCircle (uint32_t x, uint32_t y, uint32_t radius)
{
	LCD_CircleCoordinateRadius(x, y, radius);
	LCD_RegisterWrite(0x90,0x40); // Draw an hollow circle
}

/*******************************************************************************
 * Draw a filled circle on screen                                               *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawFillCircle (uint32_t x, uint32_t y, uint32_t radius)
{
	LCD_CircleCoordinateRadius(x, y, radius);
	LCD_RegisterWrite(0x90,0x60); // Draw a filled circle
}

/*******************************************************************************
 * Draw an image on screen                                                      *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawImage	(COLOR* data, uint32_t x, uint32_t y, uint32_t w, int32_t h)
{
	LCD_SetActiveWindow(x, x+w-1, y, y+h-1);
	GLCD_SetCursor(x,y);

	LCD_RegisterWriteBuffer(0x02, (uint8_t*)data, w*h);

	GLCD_WindowMax();
}

/*******************************************************************************
 * Draw an image on screen from SRAM                                            *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_DrawImagefromSRAM	(uint32_t SRAM_Ptr, uint32_t x, uint32_t y, uint32_t w, int32_t h)
{
	uint32_t i, length;

	LCD_SetActiveWindow(x, x+w-1, y, y+h-1);
	GLCD_SetCursor(x,y);

	i=0;
	length = w*h;
	while (!LCD_GET_WAIT); /* Attente que le signal wait LCD repasse � 1 (fin du dernier traitement) */


	GPIOA->BRR = GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_15 ;
	LCD_CS_0;

	set_data_output();
	write_data(0x02);

	LCD_WR_0;

#if (NB_NOP_WR == 1)
	__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
	__NOP();
	__NOP();
	__NOP();
	__NOP();
#endif /* NB_NOP_WR == 3 */

	LCD_WR_1;
	LCD_CS_1;

	set_data_input();

	LCD_CS_0;
	LCD_RS_0;

	SRAM_WE_1;
	SRAM_OE_0;
	SRAM_CE_0;

	while (i<length)
	{
		/* Positionne l'adresse cot� SRAM */
		GPIOD->ODR =  SRAM_Ptr & 0xFFFF;
		if (SRAM_Ptr>65535)
		{
			GPIOA->BRR = GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_15 ;
			GPIOA->ODR |= SRAM_AddrConvertionTable[(SRAM_Ptr>>16)];
		}

		while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

		i++;
		SRAM_Ptr++;
		//	__NOP();
		//	__NOP();
		//	__NOP();

		LCD_WR_0;

#if (NB_NOP_WR == 1)
		__NOP();
#endif /* NB_NOP_WR == 1 */

#if (NB_NOP_WR == 2)
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 2 */

#if (NB_NOP_WR == 3)
		__NOP();
		__NOP();
		__NOP();
		__NOP();
#endif /* NB_NOP_WR == 3 */

		LCD_WR_1;
	}

	LCD_RS_1;
	LCD_CS_1;

	SRAM_OE_1;
	SRAM_CE_1;
	GLCD_WindowMax();
}

void GLCD_DrawBargraph  (uint32_t x,  uint32_t y, uint32_t w, uint32_t h, uint32_t val)
{
}

/*******************************************************************************
 * Draw an image on screen                                                      *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_SetScrollWindow (uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	LCD_RegisterWrite(0x3A, (uint8_t)(y&0xFF)); 				// VSSW0
	LCD_RegisterWrite(0x3B, (uint8_t)((y&0x100)>>8)); 	// VSSW1
	LCD_RegisterWrite(0x38, (uint8_t)(x&0xFF)); 				// HSSW0
	LCD_RegisterWrite(0x39, (uint8_t)((x&0x300)>>8)); 	// HSSW1

	LCD_RegisterWrite(0x3E, (uint8_t)((y+h-1)&0xFF)); 				// VESW0
	LCD_RegisterWrite(0x3F, (uint8_t)(((y+h-1)&0x100)>>8)); 	// VESW1
	LCD_RegisterWrite(0x3C, (uint8_t)((x+w-1)&0xFF)); 				// HESW0
	LCD_RegisterWrite(0x3D, (uint8_t)(((x+w-1)&0x300)>>8)); 	// HESW1
}

/*******************************************************************************
 * Draw an image on screen                                                      *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_ScrollVertical (uint32_t dy)
{
	LCD_RegisterWrite(0x27, (uint8_t)((dy&0x100)>>8)); 	// VOFS1
	LCD_RegisterWrite(0x26, (uint8_t)(dy&0xFF)); 				// VOFS0
}

/*******************************************************************************
 * Draw an image on screen                                                      *
 *   Parameter:  X,Y, radius: circle dimension and coordinates                  *
 *   Return:                                                                    *
 *******************************************************************************/
void GLCD_ScrollHorizontal (uint32_t dy)
{
	LCD_RegisterWrite(0x25, (uint8_t)((dy&0x300)>>8)); 	// VOFS1
	LCD_RegisterWrite(0x24, (uint8_t)(dy&0xFF)); 				// VOFS0
}

/******************************************************************************/
