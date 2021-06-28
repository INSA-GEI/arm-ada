#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_ANANAS
#define LV_ATTRIBUTE_IMG_ANANAS
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_ANANAS uint8_t ananas_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0xf1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0xf1, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0xf1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x48, 0x6c, 0x48, 0x6c, 0x48, 0x6c, 0x48, 0x6c, 0x48, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x48, 0x48, 0x68, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x6c, 0x48, 0x4c, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x48, 0x68, 0x48, 0x48, 0x48, 0x48, 0x48, 0x68, 0x48, 0x48, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x48, 0x4c, 0x68, 0x4c, 0x68, 0x4c, 0x48, 0x4c, 0x68, 0x4c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x48, 0x1c, 0x1c, 0x48, 0x68, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x48, 0x6c, 0x1c, 0x1c, 0x48, 0x4c, 0x68, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x48, 0x68, 0x48, 0x68, 0x1c, 0x1c, 0x48, 0x48, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x48, 0x4c, 0x48, 0x4c, 0x1c, 0x1c, 0x48, 0x6c, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x68, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x6c, 0x1c, 0x1c, 0x1c, 0x1c, 0x48, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x48, 0x48, 0x68, 0x48, 0x48, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x6c, 0x48, 0x4c, 0x68, 0x4c, 0x1c, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xe4, 0xa9, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa9, 0xe4, 0xa9, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x52, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x40, 0x4a, 0x60, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x07, 0xe0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0xe4, 0xa9, 0xdc, 0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xa9, 0xe4, 0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xa9, 0xdc, 0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x52, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x4a, 0x60, 0x4a, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x4a, 0x60, 0x4a, 0x40, 0x07, 0x00, 0x06, 0xe0, 0x07, 0x00, 0x06, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0x4a, 0x4a, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t ananas = {
  .header.always_zero = 0,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = ananas_map,
};
