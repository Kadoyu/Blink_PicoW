/**
 * 30回Lチカしたらメモリリセットします。
 * 不揮発メモリに設定値を保存するため切断してもその前の数字から始まります。
 * メモリはBlock31 先頭セクタ(1F0000)の4kByteを使用します。
 */
#include <iostream>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FlashPROM.h"

int size = 512;
int addr = 0;
uint count;

int main()
{
    stdio_init_all();
    if (cyw43_arch_init())
    {
        printf("Wi-Fi init failed");
        return -1;
    }

    EEPROM.begin(size);
    count = EEPROM.read(0);
    std::cout << "Read Data " << count << std::endl;

    while (true)
    {
        EEPROM.write(addr, count);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
        std::cout << "Blink Count: " << count << std::endl;

        if (EEPROM.commit())
        {
            printf("EEPROM successfully comitted\n");
        }
        else
        {
            printf("ERROR! EEPROM commit failed\n");
        }

        if (count >= 30)
        {
            if (EEPROM.reset())
            {
                printf("EEPROM successfully reset\n");
            }
            else
            {
                printf("ERROR! EEPROM reset failed\n");
            }
        }
        count = EEPROM.read(0);
        count++;
    }

    return 0;
}
