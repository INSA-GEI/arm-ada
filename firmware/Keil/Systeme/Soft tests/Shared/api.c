#include "stm32f30x.h"
#include "api.h"

#define ABI_VERSION	2

struct ABI_Table_ST
{
	char magic_str[4];
	unsigned int version;
	void *ptr;
};

typedef struct ABI_Table_ST ABI_Table_Type;

void** API_Ptr_Table;
uint32_t* IT_Ptr;
ABI_Table_Type* ABI_Table;

int API_Init(void)
{
	IT_Ptr = (void*)0x0000001C;
	ABI_Table = (ABI_Table_Type*)(*IT_Ptr);
	API_Ptr_Table = (void*)(ABI_Table->ptr);
	
	if (ABI_Table->version<ABI_VERSION) return INVALID_ABI;
	else return 0;
}

void API_GetOSVersion(int* major, int* minor)
{
void (*ptrFunc)(int* major, int* minor);

	ptrFunc = (void (*)(int* major, int* minor))API_Ptr_Table[API_GetOSVersion_Index];
	ptrFunc(major, minor);
}

void GLCD_SetTextColor(uint16_t color)
{
void (*ptrFunc)(uint16_t color);

	ptrFunc = (void (*)(uint16_t color))API_Ptr_Table[GLCD_SetTextColor_Index];
	ptrFunc(color);
}

void GLCD_SetBackColor(uint16_t color)
{
void (*ptrFunc)(uint16_t color);

	ptrFunc = (void (*)(uint16_t color))API_Ptr_Table[GLCD_SetBackColor_Index];
	ptrFunc(color);
}

void GLCD_DrawString(uint32_t x,  uint32_t y, const char *str)
{
void (*ptrFunc)(uint32_t x,  uint32_t y, const char *str);

	ptrFunc = (void (*)(uint32_t x,  uint32_t y, const char *str))API_Ptr_Table[GLCD_DrawString_Index];
	ptrFunc(x, y, str);
}
