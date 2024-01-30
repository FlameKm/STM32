/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "zephyr/sys/printk.h"
#include "zephyr/sys/util.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

// 通过某个绑定结构获取，但是没有使用led0的库，直接操作系统提供的api——gpio
static const struct gpio_dt_spec led[] = {
    GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios),
    GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios),
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
            return -1;
        }
    }
    // confirm direction
    for (int i = 0; i < len; i++) {
        ret = gpio_pin_configure_dt(&led[i], GPIO_OUTPUT_ACTIVE);
        if (ret < 0) {
            return -1;
        }
    }
    printk("hello world\n");
    while (1) {
        // control led
        ret = 0;
        ret |= gpio_pin_toggle_dt(&led[0]);
        ret |= gpio_pin_toggle_dt(&led[1]);
        if (ret < 0) {
            printk("Failed to led flip\n");
            return -1;
        }
        // keep the opposite of led0


        k_msleep(1000);
    }
    return 0;
}
