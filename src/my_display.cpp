#include "my_display.h"
#include "esp_camera.h"
TFT_eSPI tft = TFT_eSPI();

void display_init() {
  tft.init();
  tft.setRotation(1);
  tft.invertDisplay(1);
  tft.fillScreen(TFT_BLACK);
}

void display_camera(){
  camera_fb_t *fb = esp_camera_fb_get(); // 获取帧缓冲  // s->set_pixformat(s,PIXFORMAT_JPEG);

  if (!fb) 
  {
    Serial.println("Camera capture failed");
    return;
  }
  tft.pushImage(0, 0, fb->width, fb->height, (uint16_t *)fb->buf);
  
  esp_camera_fb_return(fb); // 释放帧缓冲
}

void display_result(){
  tft.setTextSize(3);
  if(object)
  tft.drawString("cup",20,20);
  else
  tft.drawString("pen",20,20);

}
