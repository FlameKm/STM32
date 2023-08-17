/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>




/* // *方法一 用宏枚举法
#define DT_SPEC_AND_COMMA(node_id, prop, idx) \
        GPIO_DT_SPEC_GET(node_id, idx),
static const struct gpio_dt_spec led[] = {
    DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user), io_channels,
                         DT_SPEC_AND_COMMA)}; */
// *方法二 手动添加
static const struct gpio_dt_spec led[] = {
    GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios),
    GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios),
    GPIO_DT_SPEC_GET(DT_NODELABEL(yellow_led), gpios),
};

int main(void)
{
    int ret;
    uint8_t len = ARRAY_SIZE(led);
    // confirm ready
    for (int i = 0; i < len, i++) {
        if (!gpio_is_ready_dt(&led[i])))
            {
                return 0;
            }
    }
    // confirm direction
    for (int i = 0; i < len, i++) {
        ret = gpio_pin_configure_dt(&led[i], GPIO_OUTPUT_ACTIVE);
        if (ret < 0) {
            return 0;
        }
    }

    while (1) {
        // control led
       err =  gpio_pin_toggle_dt(&led[0]);
        if (ret < 0) {
			printk("Failed to led flip\n");
            return 0;
        }
		err = gpio_pin_w
        if (ret < 0) {
			printk("Failed to led flip\n");
            return 0;
        }		
        k_msleep(200);
    }
    return 0;
}
