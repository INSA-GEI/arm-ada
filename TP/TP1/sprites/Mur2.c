#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_MUR2
#define LV_ATTRIBUTE_IMG_MUR2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_MUR2 uint8_t Mur2_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit*/
  0x17, 0x7b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 0x9b, 
  0x0f, 0x33, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x57, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 
  0x0a, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x33, 0x7b, 
  0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e, 0x13, 
  0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x7b, 0x77, 0x13, 0x13, 0x0f, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0e, 
  0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x7b, 0x0f, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
  0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x37, 0x9b, 0x0e, 0x13, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit*/
  0xbf, 0x04, 0xdf, 0x5d, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 
  0x15, 0x03, 0x9c, 0x1c, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x7f, 0x3d, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x5f, 0x86, 
  0x50, 0x02, 0xb9, 0x03, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x9d, 0x14, 0x1f, 0x6e, 
  0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x71, 0x02, 0x71, 0x02, 0x70, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0xd3, 0x02, 0x9f, 0x04, 
  0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0x9e, 0x5d, 0x5e, 0x04, 0x5e, 0x04, 0xf4, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x70, 0x02, 0xb2, 0x02, 
  0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x5f, 0x35, 0x9f, 0x55, 0x76, 0x0b, 0xb9, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
  0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xff, 0x1c, 0x1f, 0x7e, 0xd2, 0x12, 0xfb, 0x03, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit BUT the 2 bytes are swapped*/
  0x04, 0xbf, 0x5d, 0xdf, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 0x86, 0x5f, 
  0x03, 0x15, 0x1c, 0x9c, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x3d, 0x7f, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x86, 0x5f, 
  0x02, 0x50, 0x03, 0xb9, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x04, 0x3d, 0x14, 0x9d, 0x6e, 0x1f, 
  0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x0a, 0x91, 0x02, 0x71, 0x02, 0x71, 0x02, 0x70, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0xd3, 0x04, 0x9f, 
  0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x75, 0xde, 0x5d, 0x9e, 0x04, 0x5e, 0x04, 0x5e, 0x02, 0xf4, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x50, 0x02, 0x70, 0x02, 0xb2, 
  0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x2d, 0x3f, 0x35, 0x5f, 0x55, 0x9f, 0x0b, 0x76, 0x03, 0xb9, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 0x03, 0xfb, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
  0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x1c, 0xff, 0x7e, 0x1f, 0x12, 0xd2, 0x03, 0xfb, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 0x04, 0xbf, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Blue: 8 bit, Green: 8 bit, Red: 8 bit, Fix 0xFF: 8 bit, */
  0xff, 0x94, 0x00, 0xff, 0xff, 0xb8, 0x57, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0xa7, 0x61, 0x00, 0xff, 0xe3, 0x8f, 0x1b, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xab, 0x38, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xff, 0xc9, 0x7f, 0xff, 
  0x7f, 0x4a, 0x00, 0xff, 0xc6, 0x73, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xe7, 0x86, 0x00, 0xff, 0xeb, 0x90, 0x13, 0xff, 0xff, 0xbf, 0x67, 0xff, 
  0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x07, 0xff, 0x87, 0x51, 0x06, 0xff, 0x87, 0x4e, 0x00, 0xff, 0x87, 0x4e, 0x00, 0xff, 0x81, 0x4b, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x95, 0x57, 0x00, 0xff, 0xf7, 0x8f, 0x00, 0xff, 
  0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb9, 0x6f, 0xff, 0xef, 0xb0, 0x5a, 0xff, 0xef, 0x8a, 0x00, 0xff, 0xef, 0x8a, 0x00, 0xff, 0xa2, 0x5e, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x7f, 0x4a, 0x00, 0xff, 0x82, 0x4b, 0x00, 0xff, 0x8f, 0x53, 0x00, 0xff, 
  0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa4, 0x27, 0xff, 0xff, 0xa8, 0x30, 0xff, 0xf9, 0xb2, 0x51, 0xff, 0xb2, 0x6c, 0x0a, 0xff, 0xc8, 0x74, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xd7, 0x7c, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
  0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x9d, 0x17, 0xff, 0xf7, 0xc1, 0x77, 0xff, 0x8f, 0x59, 0x0f, 0xff, 0xd7, 0x7c, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 0xff, 0x94, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t Mur2 = {
  .header.always_zero = 0,
  .header.w = 24,
  .header.h = 24,
  .data_size = 576 * LV_COLOR_SIZE / 8,
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .data = Mur2_map,
};

