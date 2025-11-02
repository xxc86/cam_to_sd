#ifndef _MY_KEY_H_
#define _MY_KEY_H_
#include <Arduino.h>

#define boot_pin        0


void Key_Init(uint8_t num);
int Key_Scan();
#endif