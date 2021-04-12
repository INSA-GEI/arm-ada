#include "stm32f30x.h"
#include "api.h"
#include "stdio.h"

int major_ver, minor_ver;
char str[30];

int main (void)
{
	API_GetOSVersion(&major_ver, &minor_ver);
	
	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	
	sprintf (str, "OS version %d.%d", major_ver, minor_ver);
	GLCD_DrawString(7, 3, str);
	
	return 5;
}
