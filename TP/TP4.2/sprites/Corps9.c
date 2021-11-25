#include "lvgl/lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif
#ifndef LV_ATTRIBUTE_IMG_CORPS9
#define LV_ATTRIBUTE_IMG_CORPS9
#endif
const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_CORPS9 uint8_t Corps9_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x83, 0xa3, 0xa3, 0xa3, 0xa3, 0x83, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x21, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x21, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x21, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x21, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x21, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x21, 0x00, 0x00, 
  0x00, 0x00, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x00, 0x00, 
  0x00, 0x41, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x41, 0x00, 
  0x00, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x00, 
  0x00, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x00, 
  0x00, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x00, 
  0x00, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x00, 
  0x00, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x00, 
  0x00, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x00, 
  0x00, 0x41, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x41, 0x00, 
  0x00, 0x00, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x00, 0x00, 
  0x00, 0x00, 0x21, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x21, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x21, 0xa3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xa3, 0x21, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x21, 0x83, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x21, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x83, 0xa3, 0xc3, 0xc3, 0xa3, 0x83, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x30, 0x14, 0x70, 0x1c, 0x98, 0x1f, 0xb0, 0x1f, 0xb0, 0x1c, 0x98, 0x14, 0x70, 0x09, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x19, 0x88, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x19, 0x88, 0x05, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x1e, 0xa8, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1e, 0xa8, 0x08, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x1e, 0xa8, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1e, 0xa8, 0x05, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x19, 0x88, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x19, 0x90, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x09, 0x30, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x09, 0x30, 0x00, 0x00, 
  0x00, 0x00, 0x14, 0x70, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x15, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x98, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1c, 0x98, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x00, 0x00, 
  0x00, 0x00, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x98, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1c, 0x98, 0x00, 0x00, 
  0x00, 0x00, 0x14, 0x70, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x15, 0x78, 0x00, 0x00, 
  0x00, 0x00, 0x09, 0x30, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x09, 0x38, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x19, 0x88, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x19, 0x90, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x1e, 0xa8, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1e, 0xa8, 0x05, 0x20, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x1e, 0xa8, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1e, 0xa8, 0x09, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x20, 0x19, 0x90, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x19, 0x90, 0x05, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x30, 0x15, 0x70, 0x1c, 0x98, 0x1f, 0xb0, 0x1f, 0xb0, 0x1c, 0x98, 0x15, 0x78, 0x09, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x09, 0x70, 0x14, 0x98, 0x1c, 0xb0, 0x1f, 0xb0, 0x1f, 0x98, 0x1c, 0x70, 0x14, 0x30, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x05, 0x88, 0x19, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x88, 0x19, 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x08, 0xa8, 0x1e, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xa8, 0x1e, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x20, 0x05, 0xa8, 0x1e, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xa8, 0x1e, 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x88, 0x19, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x90, 0x19, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x30, 0x09, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x30, 0x09, 0x00, 0x00, 
  0x00, 0x00, 0x70, 0x14, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x70, 0x15, 0x00, 0x00, 
  0x00, 0x00, 0x98, 0x1c, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x98, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x00, 0x00, 
  0x00, 0x00, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x00, 0x00, 
  0x00, 0x00, 0x98, 0x1c, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x98, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x70, 0x14, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x78, 0x15, 0x00, 0x00, 
  0x00, 0x00, 0x30, 0x09, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x38, 0x09, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x88, 0x19, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x90, 0x19, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x20, 0x05, 0xa8, 0x1e, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xa8, 0x1e, 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x08, 0xa8, 0x1e, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xa8, 0x1e, 0x30, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x05, 0x90, 0x19, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0xb0, 0x1f, 0x90, 0x19, 0x20, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x09, 0x70, 0x15, 0x98, 0x1c, 0xb0, 0x1f, 0xb0, 0x1f, 0x98, 0x1c, 0x78, 0x15, 0x38, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0x49, 0x00, 0x33, 0xff, 0xa3, 0x00, 0x72, 0xff, 0xde, 0x00, 0x9b, 0xff, 0xfb, 0x00, 0xaf, 0xff, 0xfb, 0x00, 0xaf, 0xff, 0xdf, 0x00, 0x9c, 0xff, 0xa4, 0x00, 0x72, 0xff, 0x4a, 0x00, 0x34, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x29, 0x00, 0x1d, 0xff, 0xc8, 0x00, 0x8c, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xc9, 0x00, 0x8c, 0xff, 0x2a, 0x00, 0x1d, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x42, 0x00, 0x2e, 0xff, 0xf2, 0x00, 0xa9, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xf3, 0x00, 0xaa, 0xff, 0x44, 0x00, 0x2f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x29, 0x00, 0x1d, 0xff, 0xf2, 0x00, 0xa9, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xf3, 0x00, 0xaa, 0xff, 0x2b, 0x00, 0x1e, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0xc8, 0x00, 0x8c, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xca, 0x00, 0x8d, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x49, 0x00, 0x33, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0x4b, 0x00, 0x34, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xa3, 0x00, 0x72, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xa6, 0x00, 0x74, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0x00, 0x9b, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xe0, 0x00, 0x9c, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xfa, 0x00, 0xaf, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xfc, 0x00, 0xb0, 0xff, 0x01, 0x00, 0x01, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xfa, 0x00, 0xaf, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xfc, 0x00, 0xb0, 0xff, 0x01, 0x00, 0x01, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0x00, 0x9b, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xe0, 0x00, 0x9c, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xa4, 0x00, 0x72, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xa7, 0x00, 0x75, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x4a, 0x00, 0x34, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0x4c, 0x00, 0x35, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0xc9, 0x00, 0x8c, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xcb, 0x00, 0x8e, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x2a, 0x00, 0x1d, 0xff, 0xf3, 0x00, 0xaa, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xf4, 0x00, 0xaa, 0xff, 0x2c, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x44, 0x00, 0x2f, 0xff, 0xf3, 0x00, 0xaa, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xf4, 0x00, 0xaa, 0xff, 0x45, 0x00, 0x30, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x2b, 0x00, 0x1e, 0xff, 0xca, 0x00, 0x8d, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xff, 0x00, 0xb2, 0xff, 0xcb, 0x00, 0x8e, 0xff, 0x2c, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x01, 0x00, 0x01, 0xff, 0x4b, 0x00, 0x34, 0xff, 0xa6, 0x00, 0x74, 0xff, 0xe0, 0x00, 0x9c, 0xff, 0xfd, 0x00, 0xb1, 0xff, 0xfd, 0x00, 0xb1, 0xff, 0xe0, 0x00, 0x9c, 0xff, 0xa7, 0x00, 0x75, 0xff, 0x4c, 0x00, 0x35, 0xff, 0x01, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t Corps9 = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = Corps9_map,
};