#ifndef _MY_DISPLAY_H__
#define _MY_DISPLAY_H__

#include "TFT_eSPI.h"
#include "my_camera.h"
#include "my_ml.h"

extern TFT_eSPI tft;

void display_init();
void display_demo();
void display_camera();
void display_result();

#endif