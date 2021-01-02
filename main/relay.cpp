//
// Created by Bill Bensing on 1/2/21.
//

#include "driver/gpio.h"
#include "relay.h"


class RelayDriver : public Relay {

    gpio_num_t _gpio;

public:
    RelayDriver(gpio_num_t gpio) : Relay() {
        _gpio = gpio;
        gpio_pad_select_gpio(_gpio);
        gpio_set_direction(_gpio, GPIO_MODE_OUTPUT);
        executeClose();
    }

protected:

    void executeClose() {
        gpio_set_level(_gpio, 1);
    }

    void executeOpen() {
        gpio_set_level(_gpio, 1);
    }

};