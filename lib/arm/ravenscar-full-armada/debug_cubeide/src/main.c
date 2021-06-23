#include "stm32f7xx.h"
#include "lvgl/lvgl.h"
#include "wrapper.h"

void init_bsp(void);
void test_ui(void);
void test_ui2(void);

LV_EVENT_CB_DECLARE(slider_1_event_cb);
LV_EVENT_CB_DECLARE(button_event_cb);
void animate_progressbar(void);

static lv_obj_t * slider_label_1;
static lv_obj_t * progressbar_label_2;
static lv_obj_t * progressbar;

int main(void)
{
	init_bsp();

	test_ui2();

	while (1)
	{
		HAL_Delay(50);
		animate_progressbar();
	}
}

void test_ui2(void)
{
	lv_obj_t * slider_1 = UI_SLIDER_Create(0, -70, -1, LV_ALIGN_CENTER, slider_1_event_cb);
	slider_label_1 = UI_SLIDER_AddLabel(slider_1, 0, 10, -1, LV_ALIGN_OUT_BOTTOM_MID);
	UI_LABEL_SetText(slider_label_1, "0%");

	progressbar = UI_PROGRESSBAR_Create(0, 10, -1, LV_ALIGN_CENTER);
	progressbar_label_2 = UI_PROGRESSBAR_AddLabel(progressbar, 0, 10, -1, LV_ALIGN_OUT_BOTTOM_MID);
	UI_LABEL_SetText(progressbar_label_2, "0%");

	lv_obj_t *button = UI_BUTTON_Create(0, 70, -1, LV_ALIGN_CENTER, button_event_cb);
	lv_obj_t *label = UI_BUTTON_AddLabel(button, 0, 0, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label, "Create fault");
}

LV_EVENT_CB_DECLARE(slider_1_event_cb)
{
	if (e == LV_EVENT_VALUE_CHANGED)
	{
		lv_obj_t *slider = obj;

		char buf[8];

		lv_snprintf(buf, sizeof(buf), "%d%%", lv_slider_get_value(slider));
		UI_LABEL_SetText(slider_label_1, buf);
		UI_AlignObject(slider_label_1,slider,0, 10,LV_ALIGN_OUT_BOTTOM_MID);
	}
}

void animate_progressbar(void)
{
	static uint16_t cnt =0;
	char buf[8];

	cnt++;
	if (cnt>100) cnt=0;

	lv_snprintf(buf, sizeof(buf), "%d%%", cnt);
	UI_LABEL_SetText(progressbar_label_2, buf);
	UI_AlignObject(progressbar_label_2,progressbar,0, 10,LV_ALIGN_OUT_BOTTOM_MID);
	UI_PROGRESSBAR_SetValue(progressbar,cnt);
}

LV_EVENT_CB_DECLARE(button_event_cb)
{
	if (e == LV_EVENT_CLICKED)
	{
		__IO uint32_t *p=0x30000001;
		*p=0x1;
	}
}
