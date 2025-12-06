#include "my_display.h"

TFT_eSPI tft = TFT_eSPI();

void display_init() {
  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(1);
  tft.fillScreen(TFT_BLACK);
}

void display_camera(){
   camera_fb_t *fb = esp_camera_fb_get(); // 获取帧缓冲
  if (!fb) 
  {
    Serial.println("Camera capture failed");
    return;
  }
  tft.pushImage(0, 0, fb->width, fb->height, (uint16_t *)fb->buf);
  
  esp_camera_fb_return(fb); // 释放帧缓冲

}
