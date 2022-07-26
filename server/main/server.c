#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

//for GPIO
#include "driver/gpio.h"

#define BLINK_LED 2

void app_main(void)
{
    char * ourTaskname = pcTaskGetName(NULL);
    ESP_LOGI(ourTaskname,"Hello, starting up!... testing for win git\n");

    //flush config info for pin
    gpio_reset_pin(BLINK_LED);
    gpio_set_direction(BLINK_LED,GPIO_MODE_OUTPUT);

    while(1){
        //yielding priority back to RTOS
        // vTaskDelay(1000);

        //vtask delay delays for number of sys ticks
        
        gpio_set_level(BLINK_LED,1);
        vTaskDelay(1000/portTICK_PERIOD_MS);
        gpio_set_level(BLINK_LED,0);
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }

}
