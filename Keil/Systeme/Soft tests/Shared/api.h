#include "stm32f30x.h"

void API_GetOSVersion(int* major, int* minor);
void GLCD_SetTextColor(uint16_t color);
void GLCD_SetBackColor(uint16_t color);
void GLCD_DrawString(uint32_t x,  uint32_t y, const char *str);

#define API_GetOSVersion_Index 		0
#define GLCD_SetTextColor_Index 	1
#define GLCD_SetBackColor_Index 	2
#define GLCD_DrawString_Index 		3

#define Black           0x0000 
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */

// Return code
#define INVALID_ABI			0xDEAD0001
