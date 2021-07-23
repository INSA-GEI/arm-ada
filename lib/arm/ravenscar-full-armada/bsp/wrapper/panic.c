/******************************************************************************/
/* panic.c: panic managment                                                   */
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

#include "stm32746g_discovery.h"
#include "wrapper.h"
#include "panic.h"
#include "stdlib.h"

static volatile uint32_t R0,R1,R2,R3,R12,PC,LR,XPSR,SP,PSP;
static uint32_t IT_Source;

extern void* __interrupt_stack_start;
extern void* __interrupt_stack_end;
extern void* __stack_start;
extern void* __stack_end;

char* panic_storage_error = "STORAGE ERROR";
char* panic_abort_signal = "ABORT SIGNAL";

LV_EVENT_CB_DECLARE(msgbox_event_cb);

/**
 * @brief  This function retrieves information on stack.
 * @retval None
 */
void PANIC_ReadStack(uint32_t it_source, uint32_t *sp) {
	IT_Source = it_source;
	SP = (uint32_t)sp;
	PSP = __get_PSP();

	if (((void*)sp >= (void *)&__interrupt_stack_start) && ((void*)sp <= (void *)&__interrupt_stack_end))
	{
		R0 = sp[0];
		R1 = sp[1];
		R2 = sp[2];
		R3 = sp[3];
		R12 = sp[4];
		LR = sp[5];
		PC = sp[6];
		XPSR = sp[7];
	}
	else
	{
		IT_Source = 5;
		R0=R1=R2=R3=R12=LR=PC=XPSR=0x0;
	}

	if ((PSP < (uint32_t)((void *)&__stack_start)) || (PSP > (uint32_t)((void *)&__stack_end)))
	{
		IT_Source = 6;
	}

	PANIC_Display();
}

/**
 * @brief  This function gather information and compose mainingfull message for user,
 * eventually displaying a popup window.
 * @retval None
 */
void PANIC_Display(void) {

	char* title;
	title = panic_abort_signal;
	char message[150];

	switch (IT_Source)
	{
	case 0:
		lv_snprintf(message, sizeof(message),"%s\n\nNMI fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 1:
		lv_snprintf(message, sizeof(message),"%s\n\nHard fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 2:
		lv_snprintf(message, sizeof(message),"%s\n\nMemory fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 3:
		lv_snprintf(message, sizeof(message),"%s\n\nBus fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 4:
		lv_snprintf(message, sizeof(message),"%s\n\nUsage fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 5:
		lv_snprintf(message, sizeof(message),"%s\n\nStack error raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
		break;
	case 6:
		title = panic_storage_error;

		if (SCB->CFSR & (1<<15)) // bit BFAR_VALID =1; l'adresse de la faute est dans BFAR
			lv_snprintf(message, sizeof(message),"%s\n\nStack memory exhausted,\nprobably due to recursive function\n\nFault address : 0x%08X\nStack address : 0x%08X",title,SCB->BFAR, PSP);
		else /* aucune adresse valide */
			lv_snprintf(message, sizeof(message),"%s\n\nStack memory exhausted,\nprobably due to recursive function\n\nFault address : N/A\nStack address : 0x%08X",title, PSP);
		break;
	default:
		lv_snprintf(message, sizeof(message),"%s\n\nUndefined fault raised\n\nFault address : 0x%08X\nStack address : 0x%08X",title,PC, PSP);
	}

	static const char *btns[] ={"Reboot", ""};

	UI_MESSAGEBOX_Create(message, btns, msgbox_event_cb);

	volatile uint32_t counter=0;
	volatile uint32_t counter2=0;
	while (1)
	{
		counter++;
		counter2++;

		if (counter>100000) {
			lv_tick_inc(1);
			counter=0;
		}

		if (counter2>500000) {
			lv_task_handler();
			counter2=0;
		}
	}
}

/**
 * @brief  function for rebooting system, used by last_chance_handler.
 * @retval None
 */
void Reboot_System (void)
{
  NVIC_SystemReset();
}

/**
 * @brief  Handler for messagebox, reset system.
 * @retval None
 */
LV_EVENT_CB_DECLARE(msgbox_event_cb)
{
	NVIC_SystemReset();
}
