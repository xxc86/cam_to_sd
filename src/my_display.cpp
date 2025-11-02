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
  // Serial.println("Image captured. Sending to serial...");
  //   // 通过串口发送图像数据
  //   for (size_t i = 0; i < fb->len; i++) {
  //     Serial.write(fb->buf[i]);  // 发送单字节
  //   }
  //   Serial.println("\nImage sent!");
  // 直接显示RGB565图像
  tft.pushImage(0, 0, fb->width, fb->height, (uint16_t *)fb->buf);
  
  esp_camera_fb_return(fb); // 释放帧缓冲

}
