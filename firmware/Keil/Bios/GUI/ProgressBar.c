/******************************************************************************/
/* ProgressBar.c: Progress Bar widget                                         */
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
#include "gui.h"
#include "glcd.h"

uint16_t X;
uint16_t Y;
uint16_t W;
uint16_t H;
uint16_t MaxVal;
uint16_t LastVal;

void GUI_CreateProgressBar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t maxval)
{
	/* Sauvegarde des parametres */
	X=x;
	Y=y;
	W=w;
	H=h;
	MaxVal = maxval;
	LastVal = 0;
	
	/* dessin du cadre */
	GLCD_SetTextColor(Black);
	GLCD_DrawLine(x,y,x+w,y);
	GLCD_DrawLine(x,y,x,y+h);
	GLCD_DrawLine(x+w,y,x+w,y+h);
	GLCD_DrawLine(x,y+h,x+w,y+h);
}

void GUI_UpdateProgressBar(uint16_t val)
{
	uint16_t length;
	uint16_t org;
	
	if (val>MaxVal) val = MaxVal;
	
	if (val > LastVal)
	{
		/* Dessin du remplissage */
		length = (uint32_t)((uint32_t)((val-LastVal) * (W-4)) /MaxVal);
		if (length != 0)
		{
			org = (uint16_t)((uint32_t)(LastVal * (W-4)) /MaxVal);
		
			GLCD_SetTextColor(Blue);
			GLCD_DrawFillRectangle(X+2+org, Y+2, (X+2)+org+length , (Y+2)+H-4);
			
			LastVal = val;
		}
	}
}
