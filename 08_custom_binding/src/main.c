/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>

static const struct pwm_dt_spec my_custom = PWM_DT_SPEC_GET(DT_NODELABEL(my_custom));
static const uint32_t min_pulse = DT_PROP(DT_NODELABEL(my_custom), min_pulse);
static const uint32_t max_pulse = DT_PROP(DT_NODELABEL(my_custom), max_pulse);

int main(void)
{
    int ret;

    if (!device_is_ready(my_custom.dev)) {
        printk("Error: PWM device %s is not ready\n", my_custom.dev->name);
        return 0;
    }
    ret = pwm_set_dt(&my_custom, max_pulse, max_pulse);
    if (ret < 0) {
        return 0;
    }

    while (1) {
        ret = pwm_set_pulse_dt(&my_custom, 500);
        if (ret < 0) {
            goto err;
        }
        k_sleep(K_SECONDS(1));
        ret = pwm_set_pulse_dt(&my_custom, 1500);
        if (ret < 0) {
            goto err;
        }
        
        k_sleep(K_SECONDS(1));
    }
err:
    if (ret < 0) {
        printk("Error %d: failed to set pulse width\n", ret);
        return 0;
    }
    return 0;
}
// west build -p always hello_world