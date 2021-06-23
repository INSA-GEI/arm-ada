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

static volatile uint32_t R0,R1,R2,R3,R12,PC,LR,XPSR,SP;
static uint32_t IT_Source;

LV_EVENT_CB_DECLARE(msgbox_event_cb);

void PANIC_ReadStack(uint32_t it_source, uint32_t *sp) {
	IT_Source = it_source;

	if ( (sp >= (uint32_t*)0x20000000) && (sp <= (uint32_t*)(0x20000000+(320*1024)-8*8)))
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
		SP = (uint32_t)sp;
	}

	PANIC_Display();
}

void PANIC_Display(void) {
	char *title;

	title ="";
	switch (IT_Source)
	{
	case 0:
		title ="NMI Error";
		break;
	case 1:
		title ="Hard Fault";
		break;
	case 2:
		title ="Memory Fault";
		break;
	case 3:
		title ="Bus Fault";
		break;
	case 4:
		title ="Usage Fault";
		break;
	case 5:
		title ="Stack Error";
		break;
	default:
		title ="Unknown Error";
	}

	static const char * btns[] ={"Reboot", ""};
	static char buf[100];

	lv_snprintf(buf, sizeof(buf), "%s\n%s\n\nFault address : 0x%08X", title,"An unrecoverable error occurred",PC);
	UI_MESSAGEBOX_Create(buf, btns, msgbox_event_cb);
}

LV_EVENT_CB_DECLARE(msgbox_event_cb)
{
	NVIC_SystemReset();
}
