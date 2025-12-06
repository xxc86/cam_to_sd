#include <Arduino.h>
#include "my_display.h"
#include "my_camera.h"
#include "my_SD.h"
#include "my_key.h"
#include "my_ml.h"


void setup() {
  Serial.begin(9600);
  display_init();
  psramFound();
  my_camera_init();
  // my_sd_init();
}

void loop() {

  ml_run();
  // if(Key_Scan()==1)
  // {
  //   save_photo();
  // }
  display_camera();
  display_result();
  delay(10);
}
