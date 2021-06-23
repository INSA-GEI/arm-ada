#include "stm32f7xx.h"
#include "lvgl/lvgl.h"

void init_bsp(void);
void test_ui(void);

LV_EVENT_CB_DECLARE(slider_1_event_cb);
LV_EVENT_CB_DECLARE(slider_2_event_cb);
LV_EVENT_CB_DECLARE(button_event_cb);
static lv_obj_t * slider_label_1;
static lv_obj_t * slider_label_2;

int main(void)
{
	/* Turn on the processor cache */
	SCB_EnableDCache();
	SCB_EnableICache();

	init_bsp();

	test_ui();

	while (1)
	{
		HAL_Delay(5);
	}
}

void test_ui(void)
{
	lv_obj_t * slider_1 = lv_slider_create(lv_scr_act(),NULL);
	lv_obj_align(slider_1, NULL, LV_ALIGN_CENTER, 0, -70);
	lv_obj_set_event_cb(slider_1, slider_1_event_cb);

	/*Create a label below the slider*/
	slider_label_1 = lv_label_create(lv_scr_act(),NULL);
	lv_label_set_text(slider_label_1, "0%");

	lv_obj_align(slider_label_1, slider_1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

	lv_obj_t * slider_2 = lv_slider_create(lv_scr_act(),NULL);
	lv_obj_align(slider_2, NULL, LV_ALIGN_CENTER, 0, +10);
	lv_obj_set_event_cb(slider_2, slider_2_event_cb);

	/*Create a label below the slider*/
	slider_label_2 = lv_label_create(lv_scr_act(),NULL);
	lv_label_set_text(slider_label_2, "0%");

	lv_obj_align(slider_label_2, slider_2, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

	lv_obj_t *button= lv_btn_create(lv_scr_act(),NULL);
	lv_obj_set_event_cb(button, button_event_cb);

	lv_obj_align(button, NULL, LV_ALIGN_CENTER, 0, 70);
	lv_obj_t *label = lv_label_create(button, NULL);
    lv_label_set_text(label, "Button");
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
}

LV_EVENT_CB_DECLARE(slider_1_event_cb)
{
	if (e == LV_EVENT_VALUE_CHANGED)
	{
		lv_obj_t *slider = obj;

		char buf[8];

		lv_snprintf(buf, sizeof(buf), "%d%%", lv_slider_get_value(slider));
		lv_label_set_text(slider_label_1, buf);
		lv_obj_align(slider_label_1, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	}
}

LV_EVENT_CB_DECLARE(slider_2_event_cb)
{
	if (e == LV_EVENT_VALUE_CHANGED)
	{
		lv_obj_t *slider = obj;

		char buf[8];

		lv_snprintf(buf, sizeof(buf), "%d%%", lv_slider_get_value(slider));
		lv_label_set_text(slider_label_2, buf);
		lv_obj_align(slider_label_2, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
	}
}

LV_EVENT_CB_DECLARE(button_event_cb)
{
	if (e == LV_EVENT_CLICKED)
	{
		__IO uint32_t *p=0x30000001;
		*p=0x1;
	}
}
