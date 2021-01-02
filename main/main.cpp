#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "relayDriver.h"

extern "C" void app_main(void)
{

    RelayDriver relayDriver(GPIO_NUM_12);

    while(1) {

        printf("Relay Open - No current is running to the load.\n");
        relayDriver.Open();
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        printf("Relay Close - Current is running to the load.\n");
        relayDriver.Close();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
