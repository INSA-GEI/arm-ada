/******************************************************************************/
/* system.c: resident system main file                                        */
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

#include "bios.h"

#define INIT_WITH_SCREEN 1
#define INIT_WITH_SCREEN_AND_WAIT 2
#define INIT_WITHOUT_SCREEN 0

#define HALT_SOURCE_REPROG 1
#define HALT_SOURCE_KEY	2
#define HALT_SOURCE_INVALID_OS 3
#define HALT_SOURCE_NO_HALT 0

static __IO uint32_t TimingDelay;
void Delay(__IO uint32_t nTime);
void BIOS_PeripheralsReset(void);
void BIOS_PeripheralsInit(char mode);
void BIOS_MoveITVector(void);
void SetStack(void);

volatile int DataReady=0;
int (*AppEntryPoint)(void);
uint32_t *TestEntryPoint;
int return_val;

char data;
volatile uint8_t HaltSource;

//extern uint32_t VectorTable[4*96];

int main (void)
{
	SetStack();
	KEYS_Init();
	
	HaltSource = HALT_SOURCE_NO_HALT;
	
	/* Pointeur sur le point d'entrée de l'OS */
	TestEntryPoint = (uint32_t*)(0x8040000-8);
	
	/* Si un demande de reprog est en cours ou 
	   si le bouton C est pressé ou
	   si l'OS n'est pas là, on passe en mode reprog, sans essayer de lancer l'OS */
	if (PRG_CheckReprogRequest()==PRG_RESET_REPROG) HaltSource = HALT_SOURCE_REPROG;
  else if (KEYS_GetState(KEY_CENTER) == KEY_PRESSED) HaltSource = HALT_SOURCE_KEY;
	else if (*TestEntryPoint == 0xFFFFFFFF) HaltSource = HALT_SOURCE_INVALID_OS;
  
	if (HaltSource != HALT_SOURCE_NO_HALT)
	{
		/* Reinitialisation des periph */
		BIOS_PeripheralsReset();
		
		/* Si c'est un demarrage à chaud, pas d'attente lors de l'init de l'ecran */
		if (PRG_CheckReprogRequest()==PRG_RESET_HARDRESET)
			BIOS_PeripheralsInit(INIT_WITH_SCREEN_AND_WAIT);
		else
			BIOS_PeripheralsInit(INIT_WITH_SCREEN);
			
		/* Effacement de la condition de reset */
		PRG_ResetReprogRequest();
		
		GLCD_SetTextColor(Black);
		GLCD_SetBackColor(White);
		
		/* si c'est un reset provoqué pour une reprogrammation, on part directement en reprog */
		if (HaltSource == HALT_SOURCE_REPROG) 
		{
			/* lance la reprog */
			PRG_Run();
		
			/* et reboot en fin de telechargement */
			NVIC_SystemReset();
		}
		else
		{
			/* sinon, petit message pour l'utilisateur */
			GLCD_DrawString(10,8, "Ready for download");
			
			if (HaltSource == HALT_SOURCE_KEY) 
			{
				GLCD_DrawString(10,6, "Key 'C' pressed");
			}
			else if  (HaltSource == HALT_SOURCE_INVALID_OS) 
			{
				GLCD_DrawString(10,6, "No valid OS found");
			}
			else 
			{
				GLCD_DrawString(10,6, "Unknown condition");
			}
			
			/* Attente du demarrage du telechargement */
			while (1)
			{
				USART_Receive(USART1, &data);
				PRG_CheckDownloadPattern(data);
			}
		}
	}
 
	/* Sinon, pas de besoin de reprog, demarrage normal, init juste du strict minimum */
	BIOS_PeripheralsReset();

	BIOS_PeripheralsInit(INIT_WITHOUT_SCREEN);

	while (1)
	{
		/* Deplace le vecteur d'IT en RAM */
		//BIOS_MoveITVector();
		
		/* et lance l'OS */
		AppEntryPoint = (int (*)(void))*TestEntryPoint;
		return_val=AppEntryPoint();
	}

#pragma diag_suppress 111
	/* N'arrive jamais ici, normalement */
	return 0;
#pragma diag_default 111
}

/**
  * @brief  Move IT vector to a better place (start of 0x2000000)
  * @param  None
  * @retval None
  */
//void BIOS_MoveITVector(void)
//{
//	uint32_t* porg=0x0;
//	int i;
//	
//	/* Recopie la table des vecteurs d'IT */
//	for (i=0; i<96; i++)
//	{
//		VectorTable[i] = porg[i];
//	}
//	
//	/* et mets a jour VTOR */
//	SCB->VTOR = (uint32_t)0x20000000;
//}

/**
  * @brief  Peripheral Reset.
  * @param  None
  * @retval None
  */
void BIOS_PeripheralsReset(void)
{
	/* Switch off all clock */
	RCC_AHBPeriphClockCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
													RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
													RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
													RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
													RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, DISABLE);
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
													RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
													RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, DISABLE);
	
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
													RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
													RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
													RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
													RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
													RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, ENABLE);
	
	__DSB();
	__ISB();
	
	/* Reset Every periph on AHB */
	RCC_AHBPeriphResetCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
													RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
													RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
													RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
													RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, ENABLE);
	
	RCC_APB2PeriphResetCmd(	RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
													RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
													RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, ENABLE);
													
	RCC_APB1PeriphResetCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
													RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
													RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
													RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
													RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
													RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, ENABLE);
													
	__DSB();
	__ISB();
	
	/* Reset SYSTICK */
	SysTick->CTRL=0;
	
	/* Reset NVIC */
	NVIC->ICER[0]=0xFFFFFFFF;
	NVIC->ICER[1]=0xFFFFFFFF;
	NVIC->ICER[1]=0xFFFFFFFF;
	
	/* Release Reset */
	RCC_AHBPeriphResetCmd(	RCC_AHBPeriph_ADC34 | RCC_AHBENR_ADC12EN | RCC_AHBPeriph_GPIOA |
													RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOC |	RCC_AHBPeriph_GPIOD |
													RCC_AHBPeriph_GPIOE |	RCC_AHBPeriph_GPIOF |	RCC_AHBPeriph_TS |
													RCC_AHBPeriph_CRC |	RCC_AHBPeriph_FLITF |	RCC_AHBPeriph_SRAM |
													RCC_AHBPeriph_DMA2 |	RCC_AHBPeriph_DMA1, DISABLE);
	
	RCC_APB2PeriphResetCmd( RCC_APB2Periph_SYSCFG | RCC_APB2Periph_TIM1 | RCC_APB2Periph_SPI1 |
													RCC_APB2Periph_TIM8 | RCC_APB2Periph_USART1 | RCC_APB2Periph_TIM15 |
													RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, DISABLE);

	
	RCC_APB1PeriphResetCmd( RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4 |
													RCC_APB1Periph_TIM6 | RCC_APB1Periph_TIM7 | RCC_APB1Periph_WWDG |
													RCC_APB1Periph_SPI2 | RCC_APB1Periph_SPI3 | RCC_APB1Periph_USART2 |
													RCC_APB1Periph_USART3 | RCC_APB1Periph_UART4 | RCC_APB1Periph_UART5 |
													RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2 | RCC_APB1Periph_USB |
													RCC_APB1Periph_CAN1  | RCC_APB1Periph_PWR | RCC_APB1Periph_DAC, DISABLE);
	__DSB();
	__ISB();
}

/**
  * @brief  Peripheral initialisation.
  * @param  None
  * @retval None
  */
void BIOS_PeripheralsInit(char mode)
{
	if (mode == INIT_WITHOUT_SCREEN)
	{
		KEYS_Init();
	}
	else if (mode == INIT_WITH_SCREEN)
	{
		/* Demarrage du systick */
	
		//SysTick_Config(SystemCoreClock/5);
		//NVIC_SetPriority(SysTick_IRQn,15);
		//SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
		
		USART_Configure(USART1, BAUDRATE, USART_NO_REMAP);
	
		GLCD_Init();
		GLCD_Clear(White);
	}
	else
	{
		/* Demarrage du systick */
		//SysTick_Config(SystemCoreClock/1000);
		//NVIC_SetPriority(SysTick_IRQn,15);
		//SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
		
		USART_Configure(USART1, BAUDRATE, USART_NO_REMAP);
	
		GLCD_Wait();
		GLCD_Init();
		GLCD_Clear(White);
	}
}

