#include "stm32f7xx.h"
#include "lvgl/lvgl.h"
#include "wrapper.h"

#include <stdlib.h>

void init_bsp(void);
void test_ui(void);
void test_ui2(void);
void test_malloc(void);
int test_panic(int val);
void enable_unpriviledged_mode(uint32_t base_user_stack_addr, uint32_t base_interrupt_stack_addr);

LV_EVENT_CB_DECLARE(slider_1_event_cb);
LV_EVENT_CB_DECLARE(button_event_cb);
LV_EVENT_CB_DECLARE(button_screen_event_cb);
void animate_progressbar(void);
void animate_pacman(void);

extern void* __interrupt_stack_end;
extern void* __stack_end;

static lv_obj_t * slider_label_1;
static lv_obj_t * progressbar_label_2;
static lv_obj_t * progressbar;
static volatile uint8_t flag=0;
static lv_obj_t *img[16];
static lv_obj_t *label_score;
static lv_obj_t *label_temps;

LV_IMG_DECLARE(pacman_haut);
LV_IMG_DECLARE(pacman_bas);
LV_IMG_DECLARE(pacman_gauche);
LV_IMG_DECLARE(pacman_droit);

LV_IMG_DECLARE(pacman_haut_2);
LV_IMG_DECLARE(pacman_bas_2);
LV_IMG_DECLARE(pacman_gauche_2);
LV_IMG_DECLARE(pacman_droit_2);

LV_IMG_DECLARE(fant_bleu);
LV_IMG_DECLARE(fant_rose);
LV_IMG_DECLARE(fant_jaune);
LV_IMG_DECLARE(fant_rouge);
LV_IMG_DECLARE(fant_vuln);

LV_IMG_DECLARE(pomme);
LV_IMG_DECLARE(cerise);
LV_IMG_DECLARE(ananas);
LV_IMG_DECLARE(melon);
LV_IMG_DECLARE(fraise);
LV_IMG_DECLARE(orange);

int main(void)
{
	//int val;

	init_bsp();
	//enable_unpriviledged_mode((uint32_t)((void *)&__stack_end), (uint32_t)((void *)&__interrupt_stack_end));

	//test_malloc();

	//val=test_panic(2);

	test_ui();

	while (1)
	{
		HAL_Delay(50);
		//animate_progressbar();
	}
}

void test_malloc(void)
{
	//uint32_t *p;
	uint32_t **array_of_pointer;
    uint32_t element_size = sizeof(*array_of_pointer);

	array_of_pointer = (uint32_t **)malloc(100*element_size);

	element_size = sizeof(**array_of_pointer);
	for (uint8_t i=0; i<100; i++) {
		array_of_pointer[i] = (uint32_t *)malloc(500*element_size);
	}

	array_of_pointer[0][0] = 0xDEADBEEF;

	for (uint8_t i=0; i<100; i++) {
			free(array_of_pointer[i]);
		}

	free (array_of_pointer);

}

void enable_unpriviledged_mode(uint32_t topOfProcStack, uint32_t topOfMainStack)
{
	__set_PSP(topOfProcStack);
	__set_MSP(topOfMainStack);

	uint32_t control= __get_CONTROL() + (1<<CONTROL_SPSEL_Pos) + (1<<CONTROL_nPRIV_Pos);
	__set_CONTROL(control);

	__ISB();
}

int test_panic(int val)
{
	if (val>100) return val;
	else return test_panic(val);
}

void test_ui_screen1(void)
{
	lv_obj_t * slider_1 = UI_SLIDER_Create(0, -70, -1, LV_ALIGN_CENTER, slider_1_event_cb);
	slider_label_1 = UI_SLIDER_AddLabel(slider_1, 0, 10, -1, LV_ALIGN_OUT_BOTTOM_MID);
	UI_LABEL_SetText(slider_label_1, "0%");

	progressbar = UI_PROGRESSBAR_Create(0, 10, -1, LV_ALIGN_CENTER);
	progressbar_label_2 = UI_PROGRESSBAR_AddLabel(progressbar, 0, 10, -1, LV_ALIGN_OUT_BOTTOM_MID);
	UI_LABEL_SetText(progressbar_label_2, "0%");

	lv_obj_t *button = UI_BUTTON_Create(75, 70, -1, LV_ALIGN_CENTER, button_event_cb);
	lv_obj_t *label = UI_BUTTON_AddLabel(button, 0, 0, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label, "Create fault");

	button = UI_BUTTON_Create(-75, 70, -1, LV_ALIGN_CENTER, button_screen_event_cb);
	label = UI_BUTTON_AddLabel(button, 0, 0, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label, "Screen 2");
}

void test_ui_screen2(void)
{
	lv_obj_t *button = UI_BUTTON_Create(0, 70, -1, LV_ALIGN_CENTER, button_screen_event_cb);
	lv_obj_t *label = UI_BUTTON_AddLabel(button, 0, 0, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label, "Screen 1");

	img[0] = UI_IMAGE_Create(-12+0, -80, LV_ALIGN_CENTER);
	img[1] = UI_IMAGE_Create(-12+24, -80, LV_ALIGN_CENTER);
	img[2] = UI_IMAGE_Create(-12+24+24, -80, LV_ALIGN_CENTER);
	img[3] = UI_IMAGE_Create(-12+24+24+24, -80, LV_ALIGN_CENTER);
	img[4] = UI_IMAGE_Create(-12+0, -80+24, LV_ALIGN_CENTER);
	img[5] = UI_IMAGE_Create(-12+24, -80+24, LV_ALIGN_CENTER);
	img[6] = UI_IMAGE_Create(-12+24+24, -80+24, LV_ALIGN_CENTER);
	img[7] = UI_IMAGE_Create(-12+24+24+24, -80+24, LV_ALIGN_CENTER);
	img[8] = UI_IMAGE_Create(-12+0, -80+24+24, LV_ALIGN_CENTER);
	img[9] = UI_IMAGE_Create(-12+24, -80+24+24, LV_ALIGN_CENTER);
	img[10] = UI_IMAGE_Create(-12+24+24, -80+24+24, LV_ALIGN_CENTER);
	img[11] = UI_IMAGE_Create(-12+24+24+24, -80+24+24, LV_ALIGN_CENTER);
	img[12] = UI_IMAGE_Create(-12, -80+24+24+24, LV_ALIGN_CENTER);
	img[13] = UI_IMAGE_Create(-12+24, -80+24+24+24, LV_ALIGN_CENTER);
	img[14] = UI_IMAGE_Create(-12+24+24, -80+24+24+24, LV_ALIGN_CENTER);
	img[15] = UI_IMAGE_Create(-12+24+24+24, -80+24+24+24, LV_ALIGN_CENTER);

	UI_IMAGE_SetImage(img[0], &pacman_haut);
	UI_IMAGE_SetImage(img[1], &pacman_bas);
	UI_IMAGE_SetImage(img[2], &pacman_gauche);
	UI_IMAGE_SetImage(img[3], &pacman_droit);
	UI_IMAGE_SetImage(img[4], &fant_bleu);
	UI_IMAGE_SetImage(img[5], &fant_jaune);
	UI_IMAGE_SetImage(img[6], &fant_rose);
	UI_IMAGE_SetImage(img[7], &fant_rouge);
	UI_IMAGE_SetImage(img[8], &fant_vuln);
	UI_IMAGE_SetImage(img[9], &ananas);
	UI_IMAGE_SetImage(img[10], &pomme);
	UI_IMAGE_SetImage(img[11], &orange);
	UI_IMAGE_SetImage(img[12], &pomme);
	UI_IMAGE_SetImage(img[13], &cerise);
	UI_IMAGE_SetImage(img[14], &fraise);
	UI_IMAGE_SetImage(img[15], &fant_rose);

	lv_obj_t *label1 = UI_LABEL_Create(120, -85, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label1, "Temps: ");
	label_temps = UI_LABEL_Create(0, 15, 150, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label_temps, "0");
	UI_AlignObject(label_temps, label1, 0, 15, LV_ALIGN_IN_BOTTOM_LEFT);

	label1 = UI_LABEL_Create(120, -35, -1, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label1, "Score: ");
	label_score = UI_LABEL_Create(0, 15, 150, LV_ALIGN_CENTER);
	UI_LABEL_SetText(label_score, "0");
	UI_AlignObject(label_score, label1, 0, 15, LV_ALIGN_IN_BOTTOM_LEFT);
}

void test_ui(void) {

	while (1) {
		test_ui_screen2();
		flag=0;
		while (flag==0) {
			HAL_Delay(150);
			animate_pacman();
		}

		UI_ClearScreen();
		HAL_Delay(100);

		test_ui_screen1();
		flag=0;
		while (flag!=1) {
			HAL_Delay(50);
			animate_progressbar();
		}

		flag=0;
		UI_ClearScreen();
		HAL_Delay(100);
	}
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

void animate_pacman(void) {
	static char flipflop=1;
	static uint16_t temps=0;
	static uint16_t score=0;
	char buf[16];

	temps++;

	if (flipflop==1) {
		flipflop=0;

		UI_IMAGE_SetImage(img[0], &pacman_haut_2);
		UI_IMAGE_SetImage(img[1], &pacman_bas_2);
		UI_IMAGE_SetImage(img[2], &pacman_gauche_2);
		UI_IMAGE_SetImage(img[3], &pacman_droit_2);
		score=score+temps/3;
	}
	else {
		flipflop=1;

		UI_IMAGE_SetImage(img[0], &pacman_haut);
		UI_IMAGE_SetImage(img[1], &pacman_bas);
		UI_IMAGE_SetImage(img[2], &pacman_gauche);
		UI_IMAGE_SetImage(img[3], &pacman_droit);
	}

	lv_snprintf(buf, sizeof(buf), "%d", temps);
	UI_LABEL_SetText(label_temps, buf);

	lv_snprintf(buf, sizeof(buf), "%d", score);
	UI_LABEL_SetText(label_score, buf);
}

LV_EVENT_CB_DECLARE(button_event_cb)
{
	if (e == LV_EVENT_CLICKED)
	{
		__IO uint32_t *p=(__IO uint32_t *)0x30000001UL;
		*p=0x1;
	}
}

LV_EVENT_CB_DECLARE(button_screen_event_cb)
{
	flag=1;
}
