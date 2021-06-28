#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_FANT_BLEU
#define LV_ATTRIBUTE_IMG_FANT_BLEU
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_FANT_BLEU uint8_t fant_bleu_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x27, 0x27, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x27, 0x27, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x27, 0x27, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x27, 0x27, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 
  0x00, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0x1f, 0x21, 0x1f, 0x21, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0x1f, 0x21, 0x1f, 0x21, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfc, 0xde, 0x1f, 0x21, 0x1f, 0x21, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfc, 0xde, 0x1f, 0x21, 0x1f, 0x21, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfb, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0xe6, 0x1c, 0xe7, 0xfb, 0xe6, 0x1c, 0xe7, 0xfc, 0xe6, 0x1c, 0xe7, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfc, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0xe7, 0xfc, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0xe7, 0xfb, 0xde, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x06, 0x1c, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfc, 0x06, 0x1b, 0x07, 0xfc, 0x06, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x07, 0xfb, 0x06, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x21, 0x1f, 0x21, 0x1f, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x21, 0x1f, 0x21, 0x1f, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfc, 0x21, 0x1f, 0x21, 0x1f, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfc, 0x21, 0x1f, 0x21, 0x1f, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfb, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0xe6, 0xfb, 0xe7, 0x1c, 0xe6, 0xfc, 0xe7, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfc, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0xe7, 0x1c, 0xde, 0xfc, 0xe7, 0x1c, 0xde, 0xfb, 0xe7, 0x1c, 0xde, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xfc, 0x07, 0x1c, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfc, 0x07, 0x1b, 0x06, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0x06, 0xfb, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xff, 0x21, 0x21, 0xff, 0xff, 0x21, 0x21, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xff, 0x21, 0x21, 0xff, 0xff, 0x21, 0x21, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xff, 0x21, 0x21, 0xff, 0xff, 0x21, 0x21, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xff, 0x21, 0x21, 0xff, 0xff, 0x21, 0x21, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0xde, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0xde, 0xde, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t fant_bleu = {
  .header.always_zero = 0,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = fant_bleu_map,
};

