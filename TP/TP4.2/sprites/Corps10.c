#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif
#ifndef LV_ATTRIBUTE_IMG_CORPS10
#define LV_ATTRIBUTE_IMG_CORPS10
#endif
const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_CORPS10 uint8_t Corps10_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xa2, 0xe3, 0xe3, 0xe3, 0xe3, 0xa2, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x21, 0xc3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0x21, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x41, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x41, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x21, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x21, 0x00, 0x00, 
  0x00, 0x00, 0xc3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0x00, 0x00, 
  0x00, 0x41, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x41, 0x00, 
  0x00, 0xa2, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xa2, 0x00, 
  0x00, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x00, 
  0x00, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x00, 
  0x00, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x00, 
  0x00, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x00, 
  0x00, 0xa2, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xa2, 0x00, 
  0x00, 0x41, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x41, 0x00, 
  0x00, 0x00, 0xc3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0x00, 0x00, 
  0x00, 0x00, 0x21, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x21, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x41, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0x41, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x21, 0xc3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xc3, 0x21, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xa2, 0xe3, 0xe3, 0xe3, 0xe3, 0xa2, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x48, 0x12, 0xa0, 0x18, 0xe0, 0x1b, 0xf8, 0x1b, 0xf8, 0x18, 0xe0, 0x12, 0xa0, 0x08, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x28, 0x16, 0xc8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x16, 0xc8, 0x04, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x40, 0x1a, 0xf0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1a, 0xf0, 0x07, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0x28, 0x1a, 0xf0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1a, 0xf0, 0x05, 0x28, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x16, 0xc8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x16, 0xc8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x48, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x08, 0x48, 0x00, 0x00, 
  0x00, 0x00, 0x12, 0xa0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x12, 0xa8, 0x00, 0x00, 
  0x00, 0x00, 0x18, 0xe0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x18, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x00, 0x00, 
  0x00, 0x00, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x00, 0x00, 
  0x00, 0x00, 0x18, 0xe0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x18, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0x12, 0xa0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x12, 0xa8, 0x00, 0x00, 
  0x00, 0x00, 0x08, 0x48, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x08, 0x48, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x16, 0xc8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x16, 0xc8, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x04, 0x28, 0x1a, 0xf0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1a, 0xf0, 0x05, 0x28, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x40, 0x1a, 0xf0, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1a, 0xf0, 0x07, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x28, 0x16, 0xc8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x16, 0xc8, 0x05, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x48, 0x12, 0xa8, 0x18, 0xe0, 0x1b, 0xf8, 0x1b, 0xf8, 0x18, 0xe0, 0x12, 0xa8, 0x08, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x08, 0xa0, 0x12, 0xe0, 0x18, 0xf8, 0x1b, 0xf8, 0x1b, 0xe0, 0x18, 0xa0, 0x12, 0x48, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x04, 0xc8, 0x16, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xc8, 0x16, 0x28, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x07, 0xf0, 0x1a, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf0, 0x1a, 0x40, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x28, 0x04, 0xf0, 0x1a, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf0, 0x1a, 0x28, 0x05, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc8, 0x16, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xc8, 0x16, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x48, 0x08, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0x48, 0x08, 0x00, 0x00, 
  0x00, 0x00, 0xa0, 0x12, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xa8, 0x12, 0x00, 0x00, 
  0x00, 0x00, 0xe0, 0x18, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xe0, 0x18, 0x00, 0x00, 
  0x00, 0x00, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0x00, 0x00, 
  0x00, 0x00, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0x00, 0x00, 
  0x00, 0x00, 0xe0, 0x18, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xe0, 0x18, 0x00, 0x00, 
  0x00, 0x00, 0xa0, 0x12, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xa8, 0x12, 0x00, 0x00, 
  0x00, 0x00, 0x48, 0x08, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0x48, 0x08, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xc8, 0x16, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xc8, 0x16, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x28, 0x04, 0xf0, 0x1a, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf0, 0x1a, 0x28, 0x05, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x07, 0xf0, 0x1a, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf0, 0x1a, 0x48, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x05, 0xc8, 0x16, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xf8, 0x1b, 0xc8, 0x16, 0x28, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x08, 0xa8, 0x12, 0xe0, 0x18, 0xf8, 0x1b, 0xf8, 0x1b, 0xe0, 0x18, 0xa8, 0x12, 0x48, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0x3f, 0x00, 0x49, 0xff, 0x8d, 0x00, 0xa3, 0xff, 0xc0, 0x00, 0xde, 0xff, 0xd9, 0x00, 0xfb, 0xff, 0xd9, 0x00, 0xfb, 0xff, 0xc0, 0x00, 0xdf, 0xff, 0x8d, 0x00, 0xa4, 0xff, 0x40, 0x00, 0x4a, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x23, 0x00, 0x29, 0xff, 0xad, 0x00, 0xc8, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xad, 0x00, 0xc9, 0xff, 0x24, 0x00, 0x2a, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x39, 0x00, 0x42, 0xff, 0xd1, 0x00, 0xf2, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd2, 0x00, 0xf3, 0xff, 0x3b, 0x00, 0x44, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x23, 0x00, 0x29, 0xff, 0xd1, 0x00, 0xf2, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd2, 0x00, 0xf3, 0xff, 0x25, 0x00, 0x2b, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0xad, 0x00, 0xc8, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xae, 0x00, 0xca, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x49, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0x41, 0x00, 0x4b, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x8d, 0x00, 0xa3, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0x8f, 0x00, 0xa6, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0xde, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xc1, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xd8, 0x00, 0xfa, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd9, 0x00, 0xfc, 0xff, 0x01, 0x00, 0x01, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xd8, 0x00, 0xfa, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd9, 0x00, 0xfc, 0xff, 0x01, 0x00, 0x01, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0xde, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xc1, 0x00, 0xe0, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x8d, 0x00, 0xa4, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0x90, 0x00, 0xa7, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x40, 0x00, 0x4a, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0x42, 0x00, 0x4c, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0xad, 0x00, 0xc9, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xaf, 0x00, 0xcb, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x24, 0x00, 0x2a, 0xff, 0xd2, 0x00, 0xf3, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd3, 0x00, 0xf4, 0xff, 0x26, 0x00, 0x2c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x3b, 0x00, 0x44, 0xff, 0xd2, 0x00, 0xf3, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xd3, 0x00, 0xf4, 0xff, 0x3c, 0x00, 0x45, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x25, 0x00, 0x2b, 0xff, 0xae, 0x00, 0xca, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xdc, 0x00, 0xff, 0xff, 0xaf, 0x00, 0xcb, 0xff, 0x26, 0x00, 0x2c, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0x41, 0x00, 0x4b, 0xff, 0x8f, 0x00, 0xa6, 0xff, 0xc1, 0x00, 0xe0, 0xff, 0xda, 0x00, 0xfd, 0xff, 0xda, 0x00, 0xfd, 0xff, 0xc1, 0x00, 0xe0, 0xff, 0x90, 0x00, 0xa7, 0xff, 0x42, 0x00, 0x4c, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t Corps10 = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = Corps10_map,
};
