#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CERISE
#define LV_ATTRIBUTE_IMG_CERISE
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_CERISE uint8_t Cerise_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xad, 0xd1, 0xd1, 0xad, 0x24, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xad, 0xd1, 0xf1, 0xf5, 0xf5, 0xd1, 0x24, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xad, 0xd1, 0xf1, 0xf5, 0xf5, 0xf5, 0xf5, 0xd1, 0x24, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xad, 0xd1, 0xf1, 0xd1, 0xf5, 0xf5, 0xf5, 0xd1, 0xd1, 0x44, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xad, 0xd1, 0xf1, 0xf5, 0xd1, 0x48, 0xd1, 0xf5, 0xd1, 0x44, 0x24, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xad, 0xf1, 0xd1, 0xd1, 0xd1, 0x44, 0x24, 0xd1, 0xf5, 0xd1, 0x24, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xad, 0xf1, 0xd1, 0x44, 0x24, 0x24, 0x20, 0xad, 0xf1, 0xd1, 0x44, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x24, 0xad, 0xf1, 0xd1, 0x44, 0x00, 0x00, 0x00, 0x24, 0xd1, 0xf5, 0xd1, 0x24, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x20, 0xa0, 0xc0, 0xc0, 0xc0, 0xcd, 0xf1, 0xd1, 0x44, 0x00, 0x00, 0x00, 0x20, 0xad, 0xf1, 0xd1, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x20, 0xa0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf1, 0xf1, 0xc4, 0x20, 0x00, 0x00, 0x00, 0x20, 0xd1, 0xf5, 0xd1, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0xa0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf1, 0xf1, 0xc4, 0x40, 0x00, 0x00, 0x00, 0x20, 0xd1, 0xd1, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe4, 0xed, 0xe4, 0xa0, 0x20, 0x00, 0x20, 0x20, 0xd1, 0xd1, 0x44, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x20, 0xa0, 0xc0, 0xf1, 0xf1, 0xc4, 0xa0, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0xc0, 0xe0, 0xe4, 0xe4, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x40, 0xa0, 0xe0, 0xe0, 0xf1, 0xf1, 0xe4, 0xe0, 0xa0, 0x20, 0x00, 0x00, 0x00, 
  0x20, 0xc0, 0xe4, 0xf7, 0xf7, 0xe4, 0xe0, 0xe0, 0xe0, 0xc0, 0x40, 0xa0, 0xe0, 0xe0, 0xe0, 0xf1, 0xf1, 0xe4, 0xe0, 0xe0, 0xa0, 0x20, 0x00, 0x00, 
  0x20, 0xa0, 0xe4, 0xf7, 0xf7, 0xe4, 0xe0, 0xe0, 0xe0, 0xc0, 0x40, 0xc0, 0xe0, 0xe0, 0xe0, 0xed, 0xf1, 0xe4, 0xe0, 0xe0, 0xc0, 0x20, 0x00, 0x00, 
  0x00, 0x20, 0xa0, 0xe4, 0xe4, 0xe0, 0xe0, 0xe0, 0xc0, 0x40, 0x20, 0xc0, 0xe0, 0xe0, 0xe0, 0xe4, 0xe4, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x00, 0x00, 
  0x00, 0x00, 0x20, 0xa0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x20, 0xc0, 0xe0, 0xe4, 0xe4, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0xc0, 0xe4, 0xf7, 0xf7, 0xe4, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa0, 0xe4, 0xf7, 0xf7, 0xe4, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x20, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa0, 0xe4, 0xe4, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x40, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0x81, 0x18, 0x81, 0x18, 0x61, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0xe2, 0x28, 0x67, 0xab, 0xe8, 0xc3, 0xe8, 0xc3, 0x87, 0xab, 0x81, 0x18, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0xe2, 0x28, 0x67, 0xab, 0x08, 0xc4, 0x89, 0xdc, 0xa9, 0xe4, 0xa9, 0xe4, 0x28, 0xcc, 0xa1, 0x20, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0xe2, 0x28, 0x67, 0xab, 0x08, 0xc4, 0x89, 0xdc, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0x89, 0xdc, 0xc7, 0xb3, 0x81, 0x18, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0xe2, 0x28, 0x67, 0xab, 0x08, 0xc4, 0x89, 0xdc, 0x48, 0xcc, 0x89, 0xdc, 0xa9, 0xe4, 0x89, 0xdc, 0x28, 0xcc, 0xc7, 0xb3, 0x02, 0x31, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x28, 0x67, 0xab, 0x08, 0xc4, 0x89, 0xdc, 0x89, 0xdc, 0xc8, 0xbb, 0x83, 0x49, 0x08, 0xc4, 0xa9, 0xe4, 0x28, 0xcc, 0x42, 0x39, 0x81, 0x18, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x28, 0x87, 0xab, 0x89, 0xdc, 0x28, 0xcc, 0x28, 0xcc, 0xc7, 0xb3, 0x22, 0x39, 0xe2, 0x30, 0x08, 0xc4, 0x89, 0xdc, 0xc7, 0xb3, 0x81, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x28, 0x87, 0xab, 0x89, 0xdc, 0xc8, 0xbb, 0x22, 0x39, 0xa1, 0x20, 0x81, 0x18, 0x81, 0x18, 0x67, 0xab, 0x89, 0xdc, 0x28, 0xcc, 0x22, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0xc1, 0x28, 0x87, 0xab, 0x89, 0xdc, 0xc8, 0xbb, 0x02, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe2, 0x28, 0x08, 0xc4, 0x89, 0xdc, 0xc7, 0xb3, 0x81, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xa8, 0x00, 0xc0, 0x00, 0xc0, 0x61, 0xc0, 0x67, 0xc3, 0x89, 0xdc, 0xc8, 0xcb, 0x02, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x10, 0x67, 0xab, 0x89, 0xdc, 0x28, 0xcc, 0x22, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x28, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe0, 0xe8, 0xe3, 0x28, 0xe4, 0x22, 0xc9, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x18, 0xe8, 0xc3, 0x89, 0xdc, 0xc7, 0xb3, 0x81, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x10, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x61, 0xe0, 0x87, 0xe3, 0x08, 0xe4, 0xa1, 0xc8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x18, 0xe8, 0xc3, 0x28, 0xcc, 0x22, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0xe2, 0xe0, 0x26, 0xe3, 0x81, 0xd8, 0x00, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x81, 0x28, 0xe8, 0xc3, 0x28, 0xcc, 0xa1, 0x30, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x28, 0x00, 0xa8, 0x81, 0xc0, 0xe8, 0xdb, 0x28, 0xdc, 0xa1, 0xc0, 0x00, 0xa8, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0xa2, 0xe0, 0xa2, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x40, 0x00, 0xa8, 0x00, 0xd8, 0x81, 0xe0, 0xe8, 0xe3, 0x28, 0xe4, 0xa1, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x18, 0x00, 0xc0, 0xa2, 0xe0, 0x14, 0xe5, 0x55, 0xe5, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x48, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x81, 0xe0, 0xe8, 0xe3, 0x28, 0xe4, 0xa1, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x10, 0x00, 0xa8, 0xa2, 0xd8, 0x55, 0xe5, 0x96, 0xe5, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x61, 0xe0, 0x87, 0xe3, 0xa7, 0xe3, 0x81, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x28, 0x20, 0xb0, 0xe3, 0xd8, 0xe3, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x30, 0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe0, 0x81, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xb0, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0xa2, 0xe0, 0xa2, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0xa2, 0xe0, 0x14, 0xe5, 0x55, 0xe5, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0xa8, 0xa2, 0xd8, 0x55, 0xe5, 0x96, 0xe5, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x20, 0xb0, 0xe3, 0xd8, 0xe3, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xb0, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0x18, 0x81, 0x18, 0x81, 0x10, 0x61, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0x28, 0xe2, 0xab, 0x67, 0xc3, 0xe8, 0xc3, 0xe8, 0xab, 0x87, 0x18, 0x81, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0x28, 0xe2, 0xab, 0x67, 0xc4, 0x08, 0xdc, 0x89, 0xe4, 0xa9, 0xe4, 0xa9, 0xcc, 0x28, 0x20, 0xa1, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0x28, 0xe2, 0xab, 0x67, 0xc4, 0x08, 0xdc, 0x89, 0xe4, 0xa9, 0xe4, 0xa9, 0xe4, 0xa9, 0xdc, 0x89, 0xb3, 0xc7, 0x18, 0x81, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0x28, 0xe2, 0xab, 0x67, 0xc4, 0x08, 0xdc, 0x89, 0xcc, 0x48, 0xdc, 0x89, 0xe4, 0xa9, 0xdc, 0x89, 0xcc, 0x28, 0xb3, 0xc7, 0x31, 0x02, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xc1, 0xab, 0x67, 0xc4, 0x08, 0xdc, 0x89, 0xdc, 0x89, 0xbb, 0xc8, 0x49, 0x83, 0xc4, 0x08, 0xe4, 0xa9, 0xcc, 0x28, 0x39, 0x42, 0x18, 0x81, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xc1, 0xab, 0x87, 0xdc, 0x89, 0xcc, 0x28, 0xcc, 0x28, 0xb3, 0xc7, 0x39, 0x22, 0x30, 0xe2, 0xc4, 0x08, 0xdc, 0x89, 0xb3, 0xc7, 0x18, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xc1, 0xab, 0x87, 0xdc, 0x89, 0xbb, 0xc8, 0x39, 0x22, 0x20, 0xa1, 0x18, 0x81, 0x18, 0x81, 0xab, 0x67, 0xdc, 0x89, 0xcc, 0x28, 0x39, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x28, 0xc1, 0xab, 0x87, 0xdc, 0x89, 0xbb, 0xc8, 0x31, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xe2, 0xc4, 0x08, 0xdc, 0x89, 0xb3, 0xc7, 0x18, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xa8, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x61, 0xc3, 0x67, 0xdc, 0x89, 0xcb, 0xc8, 0x39, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x61, 0xab, 0x67, 0xdc, 0x89, 0xcc, 0x28, 0x39, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x28, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe3, 0xe8, 0xe4, 0x28, 0xc9, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x81, 0xc3, 0xe8, 0xdc, 0x89, 0xb3, 0xc7, 0x18, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x61, 0xe3, 0x87, 0xe4, 0x08, 0xc8, 0xa1, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x81, 0xc3, 0xe8, 0xcc, 0x28, 0x39, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0xe2, 0xe3, 0x26, 0xd8, 0x81, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x81, 0xc3, 0xe8, 0xcc, 0x28, 0x30, 0xa1, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x28, 0x00, 0xa8, 0x00, 0xc0, 0x81, 0xdb, 0xe8, 0xdc, 0x28, 0xc0, 0xa1, 0xa8, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0xa2, 0xe0, 0xa2, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x40, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x81, 0xe3, 0xe8, 0xe4, 0x28, 0xe0, 0xa1, 0xd8, 0x00, 0xb0, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0xc0, 0x00, 0xe0, 0xa2, 0xe5, 0x14, 0xe5, 0x55, 0xe0, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x48, 0x00, 0xa8, 0x00, 0xd8, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe3, 0xe8, 0xe4, 0x28, 0xe0, 0xa1, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x10, 0x00, 0xa8, 0x00, 0xd8, 0xa2, 0xe5, 0x55, 0xe5, 0x96, 0xe0, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x61, 0xe3, 0x87, 0xe3, 0xa7, 0xe0, 0x81, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x28, 0x00, 0xb0, 0x20, 0xd8, 0xe3, 0xe0, 0xe3, 0xe0, 0x20, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x30, 0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x81, 0xe0, 0x81, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xb0, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0x00, 0xe0, 0xa2, 0xe0, 0xa2, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0x00, 0xe0, 0xa2, 0xe5, 0x14, 0xe5, 0x55, 0xe0, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xc8, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0xa8, 0x00, 0xd8, 0xa2, 0xe5, 0x55, 0xe5, 0x96, 0xe0, 0xe3, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb0, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xb0, 0x20, 0xd8, 0xe3, 0xe0, 0xe3, 0xe0, 0x20, 0xe0, 0x00, 0xe0, 0x00, 0xd8, 0x00, 0xb8, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0xb0, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xc8, 0x00, 0xb0, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x07, 0x0f, 0x17, 0xff, 0x07, 0x0f, 0x17, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x01, 0x02, 0x03, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x0d, 0x1b, 0x29, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x3f, 0x7e, 0xbd, 0xff, 0x3f, 0x7e, 0xbd, 0xff, 0x38, 0x70, 0xa9, 0xff, 0x08, 0x12, 0x1b, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x0d, 0x1b, 0x29, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x48, 0x90, 0xd9, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x41, 0x84, 0xc6, 0xff, 0x0a, 0x15, 0x1f, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x0d, 0x1b, 0x29, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x48, 0x90, 0xd9, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x09, 0x12, 0x1c, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x0d, 0x1b, 0x29, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x47, 0x8f, 0xd6, 0xff, 0x43, 0x87, 0xcc, 0xff, 0x48, 0x91, 0xda, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x11, 0x22, 0x34, 0xff, 0x01, 0x02, 0x04, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x0c, 0x18, 0x25, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x48, 0x90, 0xd9, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x3d, 0x7a, 0xb7, 0xff, 0x18, 0x32, 0x4b, 0xff, 0x40, 0x81, 0xc2, 0xff, 0x4a, 0x94, 0xde, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x13, 0x27, 0x3a, 0xff, 0x09, 0x12, 0x1c, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x0c, 0x18, 0x25, 0xff, 0x38, 0x70, 0xa9, 0xff, 0x47, 0x8f, 0xd6, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x41, 0x84, 0xc6, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x11, 0x24, 0x36, 0xff, 0x0e, 0x1e, 0x2d, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x09, 0x12, 0x1c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x0c, 0x18, 0x25, 0xff, 0x38, 0x70, 0xa9, 0xff, 0x47, 0x8f, 0xd6, 0xff, 0x3d, 0x7a, 0xb7, 0xff, 0x12, 0x24, 0x37, 0xff, 0x0a, 0x15, 0x1f, 0xff, 0x09, 0x12, 0x1c, 0xff, 0x07, 0x10, 0x18, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x48, 0x90, 0xd9, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x12, 0x24, 0x37, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x02, 0xff, 0x00, 0x00, 0x14, 0xff, 0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0x17, 0xff, 0x00, 0x01, 0x17, 0xff, 0x0c, 0x18, 0x29, 0xff, 0x38, 0x70, 0xa9, 0xff, 0x47, 0x8f, 0xd6, 0xff, 0x3d, 0x7a, 0xb7, 0xff, 0x11, 0x22, 0x34, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0x02, 0xff, 0x0d, 0x1b, 0x29, 0xff, 0x40, 0x80, 0xc1, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x09, 0x12, 0x1c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x02, 0xff, 0x00, 0x00, 0x25, 0xff, 0x00, 0x00, 0xa5, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x06, 0x0d, 0xbd, 0xff, 0x37, 0x6e, 0xc1, 0xff, 0x47, 0x8f, 0xd9, 0xff, 0x3d, 0x7a, 0xc9, 0xff, 0x11, 0x22, 0x37, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x06, 0x0d, 0x14, 0xff, 0x37, 0x6e, 0xa5, 0xff, 0x48, 0x90, 0xd9, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x12, 0x24, 0x37, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x02, 0xff, 0x00, 0x00, 0x25, 0xff, 0x00, 0x00, 0xa9, 0xff, 0x00, 0x00, 0xd9, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x07, 0x0f, 0xde, 0xff, 0x3f, 0x7e, 0xde, 0xff, 0x43, 0x86, 0xde, 0xff, 0x12, 0x24, 0xc6, 0xff, 0x01, 0x02, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x07, 0x0f, 0x17, 0xff, 0x3f, 0x7e, 0xbd, 0xff, 0x49, 0x92, 0xdb, 0xff, 0x3b, 0x78, 0xb4, 0xff, 0x09, 0x12, 0x1c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x14, 0xff, 0x00, 0x00, 0xa5, 0xff, 0x00, 0x00, 0xd9, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x06, 0x0d, 0xde, 0xff, 0x39, 0x72, 0xde, 0xff, 0x40, 0x81, 0xde, 0xff, 0x0a, 0x15, 0xc8, 0xff, 0x00, 0x00, 0x31, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x07, 0x0f, 0x17, 0xff, 0x3f, 0x7e, 0xbd, 0xff, 0x43, 0x86, 0xc9, 0xff, 0x12, 0x24, 0x37, 0xff, 0x01, 0x02, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x01, 0x02, 0xde, 0xff, 0x0e, 0x1d, 0xde, 0xff, 0x32, 0x65, 0xde, 0xff, 0x09, 0x12, 0xda, 0xff, 0x00, 0x00, 0xae, 0xff, 0x00, 0x00, 0x1b, 0xff, 0x00, 0x00, 0x02, 0xff, 0x00, 0x00, 0x14, 0xff, 0x07, 0x0f, 0x2c, 0xff, 0x3f, 0x7e, 0xc1, 0xff, 0x41, 0x84, 0xc8, 0xff, 0x0a, 0x15, 0x33, 0xff, 0x00, 0x00, 0x14, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x01, 0x02, 0xde, 0xff, 0x07, 0x0f, 0xde, 0xff, 0x01, 0x02, 0xde, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0x22, 0xff, 0x00, 0x00, 0x25, 0xff, 0x00, 0x00, 0xa5, 0xff, 0x07, 0x0f, 0xc1, 0xff, 0x3f, 0x7e, 0xd9, 0xff, 0x41, 0x84, 0xda, 0xff, 0x0a, 0x15, 0xc2, 0xff, 0x00, 0x00, 0xac, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x02, 0x02, 0xde, 0xff, 0x14, 0x14, 0xde, 0xff, 0x14, 0x14, 0xde, 0xff, 0x03, 0x03, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0xb6, 0xff, 0x00, 0x00, 0x42, 0xff, 0x00, 0x00, 0xa9, 0xff, 0x00, 0x00, 0xd9, 0xff, 0x07, 0x0f, 0xde, 0xff, 0x3f, 0x7e, 0xde, 0xff, 0x41, 0x84, 0xde, 0xff, 0x0a, 0x15, 0xde, 0xff, 0x00, 0x00, 0xda, 0xff, 0x00, 0x00, 0xb0, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x14, 0x14, 0xde, 0xff, 0xa2, 0xa2, 0xde, 0xff, 0xa9, 0xa9, 0xde, 0xff, 0x1b, 0x1b, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xc9, 0xff, 0x00, 0x00, 0x4b, 0xff, 0x00, 0x00, 0xaa, 0xff, 0x00, 0x00, 0xd9, 0xff, 0x00, 0x00, 0xde, 0xff, 0x07, 0x0f, 0xde, 0xff, 0x3f, 0x7e, 0xde, 0xff, 0x41, 0x84, 0xde, 0xff, 0x0a, 0x15, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xda, 0xff, 0x00, 0x00, 0xae, 0xff, 0x00, 0x00, 0x1b, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x14, 0xff, 0x00, 0x00, 0xac, 0xff, 0x14, 0x14, 0xda, 0xff, 0xa9, 0xa9, 0xde, 0xff, 0xb0, 0xb0, 0xde, 0xff, 0x1c, 0x1c, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0xb4, 0xff, 0x00, 0x00, 0x33, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x06, 0x0d, 0xde, 0xff, 0x38, 0x70, 0xde, 0xff, 0x3a, 0x75, 0xde, 0xff, 0x09, 0x12, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x03, 0x03, 0xb0, 0xff, 0x1b, 0x1b, 0xda, 0xff, 0x1c, 0x1c, 0xde, 0xff, 0x04, 0x04, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0xb7, 0xff, 0x00, 0x00, 0x34, 0xff, 0x00, 0x00, 0x1b, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x01, 0x02, 0xde, 0xff, 0x08, 0x12, 0xde, 0xff, 0x09, 0x12, 0xde, 0xff, 0x01, 0x02, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x00, 0x00, 0xae, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xb4, 0xff, 0x00, 0x00, 0x34, 0xff, 0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x02, 0x02, 0xde, 0xff, 0x14, 0x14, 0xde, 0xff, 0x14, 0x14, 0xde, 0xff, 0x03, 0x03, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x1b, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1c, 0xff, 0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x17, 0xff, 0x00, 0x00, 0xbd, 0xff, 0x14, 0x14, 0xde, 0xff, 0xa2, 0xa2, 0xde, 0xff, 0xa9, 0xa9, 0xde, 0xff, 0x1b, 0x1b, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x14, 0xff, 0x00, 0x00, 0xac, 0xff, 0x14, 0x14, 0xda, 0xff, 0xa9, 0xa9, 0xde, 0xff, 0xb0, 0xb0, 0xde, 0xff, 0x1c, 0x1c, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0xb4, 0xff, 0x00, 0x00, 0x1c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x03, 0x03, 0xb0, 0xff, 0x1b, 0x1b, 0xda, 0xff, 0x1c, 0x1c, 0xde, 0xff, 0x04, 0x04, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xde, 0xff, 0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0xb7, 0xff, 0x00, 0x00, 0x34, 0xff, 0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x2c, 0xff, 0x00, 0x00, 0xae, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xc6, 0xff, 0x00, 0x00, 0xb4, 0xff, 0x00, 0x00, 0x34, 0xff, 0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x1b, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x1c, 0xff, 0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t Cerise = {
  .header.always_zero = 0,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = Cerise_map,
};
