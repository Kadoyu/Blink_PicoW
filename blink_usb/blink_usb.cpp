/**
 * シリアルリードした数だけLチカスルコード
 * ちなみにPicoのSerialSpeedはデフォルトで115200bps
 */
#include <iostream>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
int main()
{
    int interval = 0;

    stdio_init_all();

    if (cyw43_arch_init())
    {
        printf("Wi-Fi init failed");
        return -1;
    }

    while (true)
    {
        //scanf("%d", &interval);
        std::cout << "Enter a number: " << std::endl;
        std::cin >> interval;

        while (interval != 0)
        {
            //printf("Burn: %d\n", interval);
            std::cout << "Burn: " << interval << std::endl;
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
            sleep_ms(500);
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
            sleep_ms(500);
            interval--;
        }
    }
}