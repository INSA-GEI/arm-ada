/******************************************************************************/
/* sram.c: external static ram driver                                         */
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
#include "sram.h"



/*---------------------------- Global variables ------------------------------*/
const uint16_t SRAM_AddrConvertionTable[]=
{
		0, (1<<1), (1<<8), (1<<1) | (1<<8),
		(1<<15), (1<<15) | (1<<1), (1<<15) | (1<<8), (1<<15) | (1<<1) | (1<<8)
};

#define SRAM_ADDR_CONV_MASK (~((1<<15) | (1<<1) | (1<<8)))

/************************ Local auxiliary functions ***************************/

/*******************************************************************************
 * Set data port as output (for sending data to SRAM)                            *
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
 * Set data port as input (for reading data from SRAM)                           *
 *   Parameter:    																			                       *
 *   Return:                                                                    *
 *******************************************************************************/
static void set_data_input(void) 
{
	GPIOC->MODER &= 0xFFFF0000; /* met les lignes 0 � 7 en input */
}

/*******************************************************************************
 * Write data to SRAM                                                            *
 *   Parameter: data to be write (uint8_t)								                       *
 *   Return:                                                                    *
 *******************************************************************************/
static void write_data(uint8_t data)
{
	GPIOC->ODR &= 0xFF00;
	GPIOC->ODR |= data;
}

/*******************************************************************************
 * Write address on address bus                                                 *
 *   Parameter: address to be write (uint32_t)	  				                       *
 *   Return:                                                                    *
 *******************************************************************************/
void write_addr(uint32_t addr)
{
	GPIOD->ODR =  addr & 0xFFFF;
	/*GPIOC->BRR = GPIO_Pin_12;
	GPIOC->ODR |= (addr & 0x01)<<12;*/
	//	GPIOA->ODR &= SRAM_ADDR_CONV_MASK;
	GPIOA->BRR = GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_15 ;
	GPIOA->ODR |= SRAM_AddrConvertionTable[(addr>>16)];
}

/*******************************************************************************
 * Read data from SRAM                                                           *
 *   Parameter:                          								                       *
 *   Return: data read (uint8_t)                                                *
 *******************************************************************************/
static uint8_t read_data(void)
{
	return (uint8_t)(GPIOC->IDR & 0x00FF);
}

/* partie public */
void SRAM_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure les lignes */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC | RCC_AHBPeriph_GPIOD, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure);

	/* Config des adresses */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1| GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4| 
			GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7| GPIO_Pin_8|
			GPIO_Pin_9| GPIO_Pin_10| GPIO_Pin_11| GPIO_Pin_12|
			GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15 | GPIO_Pin_0;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	/*GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_Init(GPIOC, &GPIO_InitStructure);*/

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1| GPIO_Pin_8| GPIO_Pin_15;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Config des lignes de controle */
	GPIO_InitStructure.GPIO_Pin = SRAM_PIN_CE | SRAM_PIN_WE | SRAM_PIN_OE;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Config des lignes de data */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | 
			GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* On met toutes les lignes de controle � 1 */
	SRAM_CE_1;
	SRAM_WE_1;
	SRAM_OE_1;	
}

uint8_t SRAM_ReadByte(uint32_t addr)
{
	uint8_t value;

	//	while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

	write_addr(addr);
	__NOP();
	__NOP();

	SRAM_CE_0;
	SRAM_OE_0;

	__NOP();
	__NOP();
	__NOP();

	value = read_data();

	SRAM_OE_1;
	SRAM_CE_1;

	return value;
}

void SRAM_WriteByte(uint32_t addr, uint8_t data)
{
	//		while (!LCD_GET_WAIT); /* Attente que le signal wait repasse � 1 (fin du dernier traitement) */

	write_addr(addr);
	__NOP();
	__NOP();

	set_data_output();

	SRAM_CE_0;
	write_data(data);

	SRAM_WE_0;

	__NOP();
	__NOP();
	__NOP();

	SRAM_WE_1;
	SRAM_CE_1;

	set_data_input();
}

void SRAM_ReadBuffer(uint32_t addr, uint8_t *buffer, int length)
{
	int i;

	for (i=0; i<length; i++)
	{
		buffer[i]=SRAM_ReadByte(addr+i);
	}
}

void SRAM_WriteBuffer(uint32_t addr, uint8_t *buffer, int length)
{
	int i;

	for (i=0; i<length; i++)
	{
		SRAM_WriteByte(addr+i, buffer[i]);
	}
}
