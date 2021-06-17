#include "stm32f7xx.h"
#include "wrapper.h"

void GLCD_Clear (COLOR color) {

}

void GLCD_SetTextColor (COLOR color) {

}

void GLCD_SetBackColor (COLOR color) {

}

void GLCD_PutPixel (uint32_t x, uint32_t y, COLOR color) {

}

void GLCD_DrawChar (uint32_t x,  uint32_t y, uint8_t c) {

}

void GLCD_DrawString (uint32_t x,  uint32_t y, const char *str) {

}

void GLCD_DrawADAString (uint32_t x, uint32_t y, uint32_t len, const char *str) {

}

void GLCD_DrawLine (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {

}

void GLCD_DrawRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {

}

void GLCD_DrawFillRectangle (uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {

}

void GLCD_DrawCircle (uint32_t x, uint32_t y, uint32_t radius) {

}

void GLCD_DrawFillCircle (uint32_t x, uint32_t y, uint32_t radius) {

}

void GLCD_DrawImage (COLOR* data, uint32_t x, uint32_t y, uint32_t w, int32_t h) {

}

// Second set of function for GLCD
void GLCD_DrawImagefromSRAM (uint32_t SRAM_Ptr, uint32_t x, uint32_t y, uint32_t w, int32_t h) {

}

void GLCD_LayerScrollMode(uint8_t mode) {

}

void GLCD_SetScrollWindow (uint32_t x, uint32_t y, uint32_t w, uint32_t h) {

}

void GLCD_ScrollVertical (uint32_t dy) {

}

void GLCD_ScrollHorizontal (uint32_t dy) {

}

void GLCD_LayerDisplayMode(uint8_t mode) {

}

void GLCD_LayerTransparency(uint8_t layer1_trans, uint8_t layer2_trans) {

}

void GLCD_SetLayer(uint8_t layerNbr) {

}

void GLCD_BTESetSource(uint32_t X, uint32_t Y, uint8_t layer) {

}

void GLCD_BTESetDestination(uint32_t X, uint32_t Y, uint8_t layer) {

}

void GLCD_BTESetSize(uint32_t width, uint32_t height) {

}

void GLCD_BTESetBackgroundColor(uint32_t red, uint32_t green, uint32_t blue) {

}

void GLCD_BTESetForegroundColor(uint32_t red, uint32_t green, uint32_t blue) {

}

void GLCD_BTESetPatternNumber(uint8_t pattern) {

}

void GLCD_SetTransparentColor(COLOR color) {

}

void GLCD_BTEStart (uint8_t source_mode, uint8_t dest_mode, uint8_t ROP, uint8_t operation) {

}

void GLCD_BTEStartAndFillFromSRAM(uint8_t dest_mode, uint8_t ROP, uint8_t operation, uint32_t SRAM_Ptr, uint32_t size) {

}
