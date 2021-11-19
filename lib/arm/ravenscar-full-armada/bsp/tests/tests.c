/*
 * tests.c
 *
 *  Created on: 24 juin 2021
 *      Author: dimercur
 */

#include "stm32f7xx.h"
#include "lvgl/lvgl.h"

#include "system.h"

static lv_obj_t * tv;
static lv_obj_t * tbutton;
static lv_obj_t * tsensors;
static lv_obj_t * taudio_out;
static lv_obj_t * taudio_in;

static uint16_t tab_id_audio_in;
static uint16_t tab_id_audio_out;
static uint8_t entering_audio_in_tab;
static uint8_t entering_audio_out_tab;

static lv_obj_t *button_a;
static lv_obj_t *button_b;
static lv_obj_t *button_x;
static lv_obj_t *button_y;
static lv_obj_t *button_up;
static lv_obj_t *button_down;
static lv_obj_t *button_left;
static lv_obj_t *button_right;

lv_obj_t * chart_acc;
lv_chart_series_t * s_acc_x;
lv_chart_series_t * s_acc_y;
lv_chart_series_t * s_acc_z;

lv_obj_t * chart_gyr;
lv_chart_series_t * s_gyr_x;
lv_chart_series_t * s_gyr_y;
lv_chart_series_t * s_gyr_z;

lv_obj_t * chart_mag;
lv_chart_series_t * s_mag_x;
lv_chart_series_t * s_mag_y;
lv_chart_series_t * s_mag_z;

lv_obj_t * chart_pres;
lv_chart_series_t * s_pres;

lv_obj_t * chart_audio_in;
lv_chart_series_t * s_audio_in_left;
lv_chart_series_t * s_audio_in_right;
static void TEST_AUDIO_IN_EventCallback(int buffer_nbr);

lv_obj_t * chart_audio_out;
lv_chart_series_t * s_audio_out;
static void TEST_AUDIO_OUT_EventCallback(int buffer_nbr);

static char buf[40];
static int16_t buffer_audio_in[AUDIO_IN_BUFFER_SIZE*2];
static uint8_t buffer_in_data_received;
static int16_t buffer_audio_out[AUDIO_OUT_BUFFER_SIZE*2];

void tab_button_create(lv_obj_t * parent);
void tab_sensors_create(lv_obj_t * parent);
void tab_audio_out_create(lv_obj_t * parent);
void tab_audio_in_create(lv_obj_t * parent);
static lv_style_t style_box;

static void animate_data_cb(lv_task_t * task);

#define CHART_COLOR_X_AXIS lv_color_hex(0x1644AA)
#define CHART_COLOR_Y_AXIS lv_color_hex(0x258808)
#define CHART_COLOR_Z_AXIS lv_color_hex(0x880825)

void tests(void) {
	tv = lv_tabview_create(lv_scr_act(), NULL);
	tbutton = lv_tabview_add_tab(tv, "Buttons");
	tsensors = lv_tabview_add_tab(tv, "Sensors");
	taudio_in = lv_tabview_add_tab(tv, "Audio in");
	taudio_out = lv_tabview_add_tab(tv, "Audio out");
	tab_id_audio_in=2;
	tab_id_audio_out=3;

	lv_style_init(&style_box);
	lv_style_set_value_align(&style_box, LV_STATE_DEFAULT, LV_ALIGN_OUT_TOP_LEFT);
	lv_style_set_value_ofs_y(&style_box, LV_STATE_DEFAULT, - LV_DPX(10));
	lv_style_set_margin_top(&style_box, LV_STATE_DEFAULT, LV_DPX(30));

	tab_button_create(tbutton);
	tab_sensors_create(tsensors);
	tab_audio_in_create(taudio_in);
	tab_audio_out_create(taudio_out);

	lv_task_create(animate_data_cb, 100, LV_TASK_PRIO_LOW, NULL);

	while (1) { // never get out tests
	}
}

void tab_button_create(lv_obj_t * parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);
	lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);
	lv_coord_t grid_w = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_SMALL ? 1 : 2, 1);

	lv_obj_t * h1 = lv_cont_create(parent, NULL);
	lv_cont_set_layout(h1, LV_LAYOUT_PRETTY_MID);
	lv_obj_add_style(h1, LV_CONT_PART_MAIN, &style_box);
	lv_obj_set_drag_parent(h1, true);

	lv_obj_set_style_local_value_str(h1, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Direction");
	lv_cont_set_fit2(h1, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(h1, grid_w);

	button_up = lv_btn_create(h1, NULL);
	lv_obj_t * label = lv_label_create(button_up, NULL);
	lv_label_set_text(label ,"Up");

	//button_left = lv_btn_create(h, button_up);
	button_left = lv_btn_create(h1, NULL);
	lv_btn_set_fit2(button_left, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_left, lv_obj_get_width_grid(h1, 2,1));
	label = lv_label_create(button_left, NULL);
	lv_label_set_text(label ,"Left");

	button_right = lv_btn_create(h1, NULL);
	lv_btn_set_fit2(button_right, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_right, lv_obj_get_width_grid(h1, 2,1));
	label = lv_label_create(button_right, NULL);
	lv_label_set_text(label ,"Right");

	button_down = lv_btn_create(h1, NULL);
	label = lv_label_create(button_down, NULL);
	lv_label_set_text(label ,"Down");

	lv_obj_t *h2 = lv_cont_create(parent, h1);
	lv_cont_set_fit(h2, LV_FIT_NONE);
	lv_obj_set_style_local_value_str(h2, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Buttons");
	lv_cont_set_fit2(h2,  LV_FIT_NONE, LV_FIT_NONE);
	lv_obj_set_width(h2, grid_w);
	lv_obj_set_height(h2, lv_obj_get_height(h1)),
			lv_cont_set_layout(h2, LV_LAYOUT_GRID);

	button_x = lv_btn_create(h2, NULL);
	//lv_btn_set_fit2(button_x, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_x, lv_obj_get_width_grid(h2, 2,1));
	label = lv_label_create(button_x, NULL);
	lv_label_set_text(label ,"X");

	button_y = lv_btn_create(h2, NULL);
	//lv_btn_set_fit2(button_y, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_y, lv_obj_get_width_grid(h2, 2,1));
	label = lv_label_create(button_y, NULL);
	lv_label_set_text(label ,"Y");

	button_a = lv_btn_create(h2, NULL);
	//lv_btn_set_fit2(button_a, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_a, lv_obj_get_width_grid(h2, 2,1));
	label = lv_label_create(button_a, NULL);
	lv_label_set_text(label ,"A");

	button_b = lv_btn_create(h2, NULL);
	//lv_btn_set_fit2(button_b, LV_FIT_NONE, LV_FIT_TIGHT);
	lv_obj_set_width(button_b, lv_obj_get_width_grid(h2, 2,1));
	label = lv_label_create(button_b, NULL);
	lv_label_set_text(label ,"B");
}

void tab_sensors_create(lv_obj_t * parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);

	lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);

	lv_coord_t grid_h_chart = lv_page_get_height_grid(parent, 1, 1);
	lv_coord_t grid_w_chart = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_LARGE ? 1 : 2, 1);

	chart_acc = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_acc, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_acc, true);
	lv_obj_set_style_local_value_str(chart_acc, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Accelerometer");
	lv_obj_set_width_margin(chart_acc, grid_w_chart);
	lv_obj_set_height_margin(chart_acc, grid_h_chart);
	lv_chart_set_div_line_count(chart_acc, 3, 0);
	lv_chart_set_point_count(chart_acc, 30);
	lv_chart_set_type(chart_acc, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_acc,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_acc,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_acc,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_acc,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_acc, 0, 0);
		lv_chart_set_x_tick_length(chart_acc, 0, 0);
		lv_chart_set_y_tick_texts(chart_acc, "2 G\n1 G\n0 G\n-1 G\n-2 G", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_acc_x = lv_chart_add_series(chart_acc, CHART_COLOR_X_AXIS);
	s_acc_y = lv_chart_add_series(chart_acc, CHART_COLOR_Y_AXIS);
	s_acc_z = lv_chart_add_series(chart_acc, CHART_COLOR_Z_AXIS);

	chart_gyr = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_gyr, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_gyr, true);
	lv_obj_set_style_local_value_str(chart_gyr, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Gyroscope");
	lv_obj_set_width_margin(chart_gyr, grid_w_chart);
	lv_obj_set_height_margin(chart_gyr, grid_h_chart);
	lv_chart_set_div_line_count(chart_gyr, 3, 0);
	lv_chart_set_point_count(chart_gyr, 30);
	lv_chart_set_type(chart_gyr, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_gyr,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_gyr,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_gyr,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_gyr,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_gyr, 0, 0);
		lv_chart_set_x_tick_length(chart_gyr, 0, 0);
		lv_chart_set_y_tick_texts(chart_gyr, "50 dps\n25 dps\n0 dps\n-25 dps\n-50 dps", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_gyr_x = lv_chart_add_series(chart_gyr, CHART_COLOR_X_AXIS);
	s_gyr_y = lv_chart_add_series(chart_gyr, CHART_COLOR_Y_AXIS);
	s_gyr_z = lv_chart_add_series(chart_gyr, CHART_COLOR_Z_AXIS);

	chart_mag = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_mag, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_mag, true);
	lv_obj_set_style_local_value_str(chart_mag, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Magnetometer");
	lv_obj_set_width_margin(chart_mag, grid_w_chart);
	lv_obj_set_height_margin(chart_mag, grid_h_chart);
	lv_chart_set_div_line_count(chart_mag, 3, 0);
	lv_chart_set_point_count(chart_mag, 30);
	lv_chart_set_type(chart_mag, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_mag,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_mag,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_mag,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_mag,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_mag, 0, 0);
		lv_chart_set_x_tick_length(chart_mag, 0, 0);
		lv_chart_set_y_tick_texts(chart_mag, "1000 mg\n500 mg\n0 mg\n-500 mg\n-1000 mg", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_mag_x = lv_chart_add_series(chart_mag, CHART_COLOR_X_AXIS);
	s_mag_y = lv_chart_add_series(chart_mag, CHART_COLOR_Y_AXIS);
	s_mag_z = lv_chart_add_series(chart_mag, CHART_COLOR_Z_AXIS);

	chart_pres = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_pres, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_pres, true);
	lv_obj_set_style_local_value_str(chart_pres, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Pressure");
	lv_obj_set_width_margin(chart_pres, grid_w_chart);
	lv_obj_set_height_margin(chart_pres, grid_h_chart);
	lv_chart_set_div_line_count(chart_pres, 3, 0);
	lv_chart_set_point_count(chart_pres, 30);
	lv_chart_set_type(chart_pres, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_pres,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_pres,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_pres,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_pres,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_pres, 0, 0);
		lv_chart_set_x_tick_length(chart_pres, 0, 0);
		lv_chart_set_y_tick_texts(chart_pres, "1005\n1002\n1000\n998\n995", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_pres = lv_chart_add_series(chart_pres, LV_THEME_DEFAULT_COLOR_PRIMARY);
}

void tab_audio_out_create(lv_obj_t * parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);

	lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);

	lv_coord_t grid_h_chart = lv_page_get_height_grid(parent, 1, 1);
	lv_coord_t grid_w_chart = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_LARGE ? 1 : 2, 1);

	chart_audio_out = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_audio_out, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_audio_out, true);
	lv_obj_set_style_local_value_str(chart_audio_out, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Loudspeakers");
	lv_obj_set_width_margin(chart_audio_out, grid_w_chart);
	lv_obj_set_height_margin(chart_audio_out, grid_h_chart);
	lv_chart_set_div_line_count(chart_audio_out, 3, 0);
	lv_chart_set_point_count(chart_audio_out, AUDIO_IN_BUFFER_SIZE);
	lv_chart_set_type(chart_audio_out, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_audio_out,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_audio_out,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_audio_out,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_audio_out,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_audio_out, 0, 0);
		lv_chart_set_x_tick_length(chart_audio_out, 0, 0);
		lv_chart_set_y_tick_texts(chart_audio_out, "10 db\n0 db\n-10 db", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_audio_out = lv_chart_add_series(chart_audio_out, CHART_COLOR_X_AXIS);

	AUDIO_OUT_SetEventCallback(TEST_AUDIO_OUT_EventCallback);
	entering_audio_out_tab=1;
}

void tab_audio_in_create(lv_obj_t * parent) {
	lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY_TOP);

	lv_disp_size_t disp_size = lv_disp_get_size_category(NULL);

	lv_coord_t grid_h_chart = lv_page_get_height_grid(parent, 1, 1);
	lv_coord_t grid_w_chart = lv_page_get_width_grid(parent, disp_size <= LV_DISP_SIZE_LARGE ? 1 : 2, 1);

	chart_audio_in = lv_chart_create(parent, NULL);
	lv_obj_add_style(chart_audio_in, LV_CHART_PART_BG, &style_box);
	lv_obj_set_drag_parent(chart_audio_in, true);
	lv_obj_set_style_local_value_str(chart_audio_in, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Microphones");
	lv_obj_set_width_margin(chart_audio_in, grid_w_chart);
	lv_obj_set_height_margin(chart_audio_in, grid_h_chart);
	lv_chart_set_div_line_count(chart_audio_in, 3, 0);
	lv_chart_set_point_count(chart_audio_in, AUDIO_IN_BUFFER_SIZE);
	lv_chart_set_type(chart_audio_in, LV_CHART_TYPE_LINE);
	if(disp_size > LV_DISP_SIZE_SMALL) {
		lv_obj_set_style_local_pad_left(chart_audio_in,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 4 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_bottom(chart_audio_in,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 3 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_right(chart_audio_in,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_obj_set_style_local_pad_top(chart_audio_in,  LV_CHART_PART_BG, LV_STATE_DEFAULT, 2 * (LV_DPI / 10));
		lv_chart_set_y_tick_length(chart_audio_in, 0, 0);
		lv_chart_set_x_tick_length(chart_audio_in, 0, 0);
		lv_chart_set_y_tick_texts(chart_audio_in, "10 db\n0 db\n-10 db", 0, LV_CHART_AXIS_DRAW_LAST_TICK);
	}

	s_audio_in_left = lv_chart_add_series(chart_audio_in, CHART_COLOR_X_AXIS);
	s_audio_in_right = lv_chart_add_series(chart_audio_in, CHART_COLOR_Y_AXIS);

	AUDIO_IN_SetEventCallback(TEST_AUDIO_IN_EventCallback);
	buffer_in_data_received=0;
	entering_audio_in_tab=1;
}

static void TEST_AUDIO_IN_EventCallback(int buffer_nbr) {
	AUDIO_IN_GetBuffer16(buffer_nbr, buffer_audio_in);

	buffer_in_data_received=1;
}

static void TEST_AUDIO_OUT_EventCallback(int buffer_nbr) {
	for (int i=0; i<AUDIO_OUT_BUFFER_SIZE; i++) {
		buffer_audio_out[i]=8192;
	}

	for (int i=AUDIO_OUT_BUFFER_SIZE; i<AUDIO_OUT_BUFFER_SIZE*2; i++) {
		buffer_audio_out[i]=-8192;
	}

	AUDIO_OUT_FillBuffer16(buffer_nbr, buffer_audio_out);
}

static void animate_data_cb(lv_task_t * task) {
	acceleration_t acceleration;
	angularRate_t angular_rate;
	magnetic_t magnetic;
	float pressure;
	float temperature;
	uint16_t tab_id;

	if (BSP_PB_GetState(BUTTON_A)) lv_btn_set_state(button_a, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_a, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_B)) lv_btn_set_state(button_b, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_b, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_X)) lv_btn_set_state(button_x, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_x, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_Y)) lv_btn_set_state(button_y, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_y, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_UP)) lv_btn_set_state(button_up, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_up, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_DOWN)) lv_btn_set_state(button_down, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_down, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_LEFT)) lv_btn_set_state(button_left, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_left, LV_BTN_STATE_RELEASED);

	if (BSP_PB_GetState(BUTTON_RIGHT)) lv_btn_set_state(button_right, LV_BTN_STATE_PRESSED);
	else lv_btn_set_state(button_right, LV_BTN_STATE_RELEASED);

	if (BSP_ACC_ReadValues(&acceleration)== ACC_OK) {
		if (acceleration.x>2000.0) acceleration.x=2000.0;
		else if (acceleration.x<-2000.0) acceleration.x=-2000.0;
		lv_chart_set_next(chart_acc, s_acc_x,50 + (int)(acceleration.x*50.0/2000.0));

		if (acceleration.y>2000.0) acceleration.y=2000.0;
		else if (acceleration.y<-2000.0) acceleration.y=-2000.0;
		lv_chart_set_next(chart_acc, s_acc_y,50 + (int)(acceleration.y*50.0/2000.0));

		if (acceleration.z>2000.0) acceleration.z=2000.0;
		else if (acceleration.z<-2000.0) acceleration.z=-2000.0;
		lv_chart_set_next(chart_acc, s_acc_z,50 + (int)(acceleration.z*50.0/2000.0));
	} else {
		lv_obj_set_style_local_value_str(chart_acc, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Accelerometer (Not present)");
	}

	if (BSP_GYRO_ReadValues(&angular_rate)== ACC_OK) {
		if (angular_rate.x>50000.0) angular_rate.x=50000.0;
		else if (angular_rate.x<-50000.0) angular_rate.x=-50000.0;
		lv_chart_set_next(chart_gyr, s_gyr_x,50 + (int)(angular_rate.x*50.0/50000.0));

		if (angular_rate.y>50000.0) angular_rate.y=50000.0;
		else if (angular_rate.y<-50000.0) angular_rate.y=-50000.0;
		lv_chart_set_next(chart_gyr, s_gyr_y,50 + (int)(angular_rate.y*50.0/50000.0));

		if (angular_rate.z>50000.0) angular_rate.z=50000.0;
		else if (angular_rate.z<-50000.0) angular_rate.z=-50000.0;
		lv_chart_set_next(chart_gyr, s_gyr_z,50 + (int)(angular_rate.z*50.0/50000.0));
	} else {
		lv_obj_set_style_local_value_str(chart_acc, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Gyroscope (Not present)");
	}

	if (BSP_MAG_ReadValues(&magnetic)== MAG_OK) {
		if (magnetic.x>1000.0) magnetic.x=1000.0;
		else if (magnetic.x<-1000.0) magnetic.x=-1000.0;
		lv_chart_set_next(chart_mag, s_mag_x,50 + (int)(magnetic.x*50.0/1000.0));

		if (magnetic.y>1000.0) magnetic.y=1000.0;
		else if (magnetic.y<-1000.0) magnetic.y=-1000.0;
		lv_chart_set_next(chart_mag, s_mag_y,50 + (int)(magnetic.y*50.0/1000.0));

		if (magnetic.z>1000.0) magnetic.z=1000.0;
		else if (magnetic.z<-1000.0) magnetic.z=-1000.0;
		lv_chart_set_next(chart_mag, s_mag_z,50 + (int)(magnetic.z*50.0/1000.0));
	} else {
		lv_obj_set_style_local_value_str(chart_acc, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Magnetometer (Not present)");
	}

	if (BSP_PRESSURE_ReadCompensatedValues(&pressure, &temperature)==PRESSURE_OK) {
		/*
		 * Value are in Pascal, normally atmospheric value are in Hp (hectoPascal), so we must
		 * divide by 100 value given by sensor
		 */

		lv_snprintf(buf, sizeof(buf), "Pressure [T°= %d C]", (int)(temperature));
		lv_obj_set_style_local_value_str(chart_pres, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, buf);

		pressure = pressure-100000.0;
		if (pressure > 500.0) pressure = 500.0;
		else if (pressure < -500.0) pressure = -500.0;
		lv_chart_set_next(chart_pres, s_pres,50 + (int)(pressure*50.0/500.0));
	} else {
		lv_obj_set_style_local_value_str(chart_acc, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, "Pressure (Not present)");
	}

	tab_id = lv_tabview_get_tab_act(tv);
	if (tab_id==tab_id_audio_in) {
		if (entering_audio_in_tab!=0) {
			AUDIO_IN_Start();
			entering_audio_in_tab=0;
		}

		if (buffer_in_data_received!=0) {
			lv_chart_clear_serie(chart_audio_in, s_audio_in_left);
			lv_chart_clear_serie(chart_audio_in, s_audio_in_right);

			for (int i=0; i<AUDIO_IN_BUFFER_SIZE*2; i+=2) {
				lv_chart_set_next(chart_audio_in, s_audio_in_left,50 + (int)(buffer_audio_in[i]*100/8192));
				lv_chart_set_next(chart_audio_in, s_audio_in_right,50 + (int)(buffer_audio_in[i+1]*100/8192));
			}

			buffer_in_data_received=0;
		}
	} else {
		AUDIO_IN_Stop();
		entering_audio_in_tab=1;
	}

	//	if (tab_id==tab_id_audio_out) {
	//		if (entering_audio_out_tab!=0) {
	//			AUDIO_OUT_Start();
	//			entering_audio_out_tab=0;
	//		}
	//	} else {
	//		AUDIO_OUT_Stop();
	//		entering_audio_out_tab=1;
	//	}
}
