/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "zephyr/sys/printk.h"
#include "zephyr/sys/util.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec led[] = {
    GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios),
    GPIO_DT_SPEC_GET_BY_IDX(DT_PATH(gpio, led_2), gpios, 0),
    GPIO_DT_SPEC_GET_BY_IDX(DT_ALIAS(led12), gpios, 1),
};
/* 
 */
int main(void)
{
    int ret;
    int len = ARRAY_SIZE(led);
    // confirm ready
    for (int i = 0; i < len; i++) {
        if (!gpio_is_ready_dt(&led[i])) {
            return 0;
        }
    }
    // confirm direction
    for (int i = 0; i < len; i++) {
        ret = gpio_pin_configure_dt(&led[i], GPIO_OUTPUT_ACTIVE);
        if (ret < 0) {
            return 0;
        }
    }

    while (1) {
        // control led
        ret = gpio_pin_toggle_dt(&led[1]);
        if (ret < 0) {
            printk("Failed to led flip\n");
            return 0;
        }
        // keep the opposite of led0
        ret = gpio_pin_set_dt(&led[2], !gpio_pin_get_dt(&led[1]));
        if (ret < 0) {
            printk("Failed to led flip\n");
            return 0;
        }

        k_msleep(1000);
    }
    return 0;
}
