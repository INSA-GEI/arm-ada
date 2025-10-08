/*
 * legacy.c
 *
 *  Created on: 19 juin 2019
 *      Author: dimercur
 */

#include <wrapper_ui.h>
#include "lvgl/lvgl.h"

#include <stdlib.h>

void UI_ClearScreen(void) {
	lv_obj_clean(lv_scr_act());
}

void UI_RemoveObject(lv_obj_t *obj) {
	lv_obj_clean(obj);
}

void UI_AlignObject(lv_obj_t *obj, lv_obj_t *parent, int off_x, int off_y, lv_align_t alignment) {
	lv_obj_align(obj, parent, alignment, off_x, off_y);
}

void UI_ResizeObject(lv_obj_t *obj, int width, int height) {
	if (width !=-1) lv_obj_set_width(obj, width);
	if (height != -1) lv_obj_set_height(obj, height);
}

lv_obj_t* UI_GetScreenId(void) {
	return lv_scr_act();
}

lv_obj_t* UI_LABEL_Create(int off_x, int off_y, int length, lv_align_t alignment) {
	lv_obj_t *obj = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_width(obj, length);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);

	return obj;
}

void UI_LABEL_SetText(lv_obj_t *label,  const char *text) {
	lv_label_set_text(label, text);
}

lv_obj_t* UI_SLIDER_Create(int off_x, int off_y, int length, lv_align_t alignment, lv_event_cb_t event_cb) {
	lv_obj_t *obj = lv_slider_create(lv_scr_act(),NULL);
	if (length != -1) lv_obj_set_width(obj, length);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);
	if (event_cb != NULL) lv_obj_set_event_cb(obj, event_cb);

	return obj;
}

lv_obj_t* UI_SLIDER_AddLabel(lv_obj_t* slider, int off_x, int off_y, int length, lv_align_t alignment) {
	lv_obj_t *obj = lv_label_create(lv_scr_act(),NULL);
	lv_obj_set_width(obj, length);
	lv_obj_align(obj, slider, alignment, off_x, off_y);

	return obj;
}

int16_t UI_SLIDER_GetValue(lv_obj_t* slider) {
	return lv_slider_get_value(slider);
}

lv_obj_t* UI_BUTTON_Create(int off_x, int off_y, int length, lv_align_t alignment, lv_event_cb_t event_cb) {
	lv_obj_t *obj= lv_btn_create(lv_scr_act(),NULL);
	if (length != -1) lv_obj_set_width(obj, length);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);
	if (event_cb != NULL) lv_obj_set_event_cb(obj, event_cb);

	return obj;
}

lv_obj_t* UI_BUTTON_AddLabel(lv_obj_t* btn, int off_x, int off_y, int length, lv_align_t alignment) {
	lv_obj_t *obj = lv_label_create(btn, NULL);
	lv_obj_set_width(obj, length);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);

	return obj;
}

lv_state_t UI_BUTTON_GetState(lv_obj_t* btn) {
	return lv_btn_get_state(btn);
}

lv_obj_t* UI_PROGRESSBAR_Create (int off_x, int off_y, int length, lv_align_t alignment) {
	lv_obj_t *obj = lv_bar_create(lv_scr_act(), NULL);
	lv_bar_set_range(obj, 0, 100);
	if (length != -1) lv_obj_set_width(obj, length);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);

	return obj;
}

lv_obj_t* UI_PROGRESSBAR_AddLabel(lv_obj_t* bar, int off_x, int off_y, int length, lv_align_t alignment) {
	lv_obj_t *obj = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_width(obj, length);
	lv_obj_align(obj, bar, alignment, off_x, off_y);

	return obj;
}

void UI_PROGRESSBAR_SetValue(lv_obj_t* bar, int16_t value) {
	lv_bar_set_value (bar, value, LV_ANIM_ON);
}

lv_obj_t* UI_MESSAGEBOX_Create (const char *text, const char *btns[], lv_event_cb_t event_cb) {
	lv_obj_t * obj = lv_msgbox_create(lv_scr_act(),NULL);
	lv_msgbox_add_btns(obj, btns);
	lv_msgbox_set_text_fmt(obj, text);
	lv_obj_set_event_cb(obj, event_cb);
	lv_obj_align(obj, NULL, LV_ALIGN_CENTER, 0, 0);

	return obj;
}

lv_obj_t* UI_IMAGE_Create(int off_x, int off_y, lv_align_t alignment) {
	lv_obj_t *obj = lv_img_create(lv_scr_act(),NULL);
	lv_obj_align(obj, NULL, alignment, off_x, off_y);

	return obj;
}

void UI_IMAGE_SetImage(lv_obj_t* img, const void *src_img) {
	lv_img_set_src(img, src_img);
}

lv_style_t *UI_GetEmptyStyle() {
	lv_style_t *tmp;

	tmp = (lv_style_t*)malloc(sizeof(lv_style_t));
	lv_style_init(tmp);
	
	return tmp;
}

lv_color_t* UI_CANVAS_AllocateBuffer(lv_coord_t w, lv_coord_t h, lv_color_t c) {
	lv_color_t *buf =(lv_color_t*)malloc(LV_CANVAS_BUF_SIZE_TRUE_COLOR(w, h));

	for (uint32_t i=0; i<(w*h); i++) {
		buf[i]=c;
	}

	return buf;
}

void UI_CANVAS_AddBuffer(lv_obj_t* canvas, lv_coord_t w, lv_coord_t h, lv_color_t c) {
	lv_color_t *buf =UI_CANVAS_AllocateBuffer(w, h, c);

	lv_canvas_set_buffer(canvas, (void*) buf, w, h, LV_IMG_CF_TRUE_COLOR);
}