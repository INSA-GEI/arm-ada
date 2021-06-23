/*
 * wrapper_ui.h
 *
 *  Created on: 19 juin 2019
 *      Author: dimercur
 */

#ifndef _WRAPPER_UI_H_
#define _WRAPPER_UI_H_

#include "lvgl/lvgl.h"

void UI_ClearScreen(void);
void UI_RemoveObject(lv_obj_t *obj);
void UI_AlignObject(lv_obj_t *obj, lv_obj_t *parent, int off_x, int off_y, lv_align_t alignment);
void UI_ResizeObject(lv_obj_t *obj, int width, int height);
lv_obj_t* UI_LABEL_Create(int off_x, int off_y, int length, lv_align_t alignment);
void UI_LABEL_SetText(lv_obj_t *label,  const char *text);
lv_obj_t* UI_SLIDER_Create(int off_x, int off_y, int length, lv_align_t alignment, lv_event_cb_t event_cb);
lv_obj_t* UI_SLIDER_AddLabel(lv_obj_t* slider, int off_x, int off_y, int length, lv_align_t alignment);
int16_t UI_SLIDER_GetValue(lv_obj_t* slider) ;
lv_obj_t* UI_BUTTON_Create(int off_x, int off_y, int length, lv_align_t alignment, lv_event_cb_t event_cb);
lv_obj_t* UI_BUTTON_AddLabel(lv_obj_t* btn, int off_x, int off_y, int length, lv_align_t alignment);
lv_state_t UI_BUTTON_GetState(lv_obj_t* btn);
lv_obj_t* UI_PROGRESSBAR_Create (int off_x, int off_y, int length, lv_align_t alignment);
lv_obj_t* UI_PROGRESSBAR_AddLabel(lv_obj_t* bar, int off_x, int off_y, int length, lv_align_t alignment);
void UI_PROGRESSBAR_SetValue(lv_obj_t* bar, int16_t value);
lv_obj_t* UI_MESSAGEBOX_Create (const char *text, const char *btns[], lv_event_cb_t event_cb);

#endif /* _WRAPPER_UI_H_ */
