#include "my_key.h"
void Key_Init(uint8_t num)
{
    pinMode(boot_pin,INPUT);
}
int Key_Scan()
{
    if(digitalRead(boot_pin)==LOW){
        delay(5);
        if (digitalRead(boot_pin)==LOW)
        {
            while (digitalRead(boot_pin)==LOW);
            return 1;
        }
    }
    return 0;
}