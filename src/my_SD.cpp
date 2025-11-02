#include "my_SD.h"


int pictureNumber = 0;


void my_sd_init(){
  // 正确传入：CLK, CMD, D0（可选再传 D1, D2, D3）
  SD_MMC.setPins(SD_CLK_PIN, SD_CMD_PIN, SD_DATA_PIN);
if (!SD_MMC.begin("/sdcard", true)) { // true enables 1-bit mode to free up GPIOs
    Serial.println("SD Card Mount Failed");
    //return;
  }
uint8_t cardType = SD_MMC.cardType();

  if (cardType == CARD_NONE)
  {
    Serial.println("未连接存储卡");
    return;
  }
  else if (cardType == CARD_MMC)
  {
    Serial.println("挂载了MMC卡");
  }
  else if (cardType == CARD_SD)
  {
    Serial.println("挂载了SDSC卡");
  }
  else if (cardType == CARD_SDHC)
  {
    Serial.println("挂载了SDHC卡");
  }
  else
  {
    Serial.println("挂载了未知存储卡");
  }

}


void save_photo()
{
  camera_fb_t * fb = NULL;
 
  // Take Picture with Camera
  fb = esp_camera_fb_get();  
  if(!fb) {
    Serial.println("Camera capture failed");
    return;
  }
  // initialize EEPROM with predefined size
  EEPROM.begin(EEPROM_SIZE);
  pictureNumber = EEPROM.read(0) + 1;
 
  // Path where new picture will be saved in SD Card
  String path = "/picture" + String(pictureNumber) +".jpg";
 
  fs::FS &fs = SD_MMC;
  Serial.printf("Picture file name: %s\n", path.c_str());
 
  File file = fs.open(path.c_str(), FILE_WRITE);
  if(!file){
    Serial.println("Failed to open file in writing mode");
  }
  else {
    file.write(fb->buf, fb->len); // payload (image), payload length
    Serial.printf("Saved file to path: %s\n", path.c_str());
    EEPROM.write(0, pictureNumber);
    EEPROM.commit();
  }
  file.close();
  esp_camera_fb_return(fb);
}