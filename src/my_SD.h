#ifndef _MY_SD_H__
#define _MY_SD_H__

#include "Arduino.h"
#include "SD.h"
#include "SD_MMC.h"
#include "FS.h"
#include "my_camera.h"
#include <EEPROM.h>

#define SD_DATA_PIN 40       //D0
#define SD_CLK_PIN 39        //CLK
#define SD_CMD_PIN 38        //DI

#define EEPROM_SIZE 1


void my_sd_init();

void save_photo();

#endif // _MY_SD_H__