#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "drivers/relayDriver.h"

extern "C" void app_main(void)
{

    RelayDriver relayDriver(GPIO_NUM_12);
    while(1) {

        relayDriver.Open();
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        relayDriver.Close();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
