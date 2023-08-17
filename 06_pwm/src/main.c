/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>


/* const struct pwm_dt_spec spec =
    PWM_DT_SPEC_GET_BY_NAME(DT_NODELABEL(motor), alpha); */
const struct pwm_dt_spec spec[] = {
    PWM_DT_SPEC_GET_BY_IDX(DT_NODELABEL(contrl), 0),
    PWM_DT_SPEC_GET_BY_IDX(DT_NODELABEL(contrl), 1),
};
/* static const struct pwm_dt_spec spec[] = {
    PWM_DT_SPEC_GET_BY_IDX(DT_ALIAS(acontrl), 0),
    PWM_DT_SPEC_GET_BY_IDX(DT_ALIAS(acontrl), 1),
}; */

int main(void)
{
    uint32_t max_period;
    // Print pwm information
    for (int i = 0; i < ARRAY_SIZE(spec); i++) {
        if (!device_is_ready(spec[i].dev)) {
            printk("Error: PWM device %s is not ready\n",
                   spec[i].dev->name);

            return 0;
        }
        printk("name:%s, ch:%d, period:%d, flags:%d\n",
               spec[i].dev->name,
               spec[i].channel,
               spec[i].period,
               spec[i].flags);
    }
    max_period = PWM_SEC(1U);
    while (pwm_set_dt(&spec[0], max_period, max_period / 2U)) {
        max_period /= 2U;
        if (max_period < (500)) {
            printk("Error: PWM device "
                   "does not support a period at least %lu\n",
                   500LU);
            return 0;
        }
    }
	printk("Done calibrating; maximum/minimum periods %u/%lu nsec\n",
	       max_period, 100LU);
    while (1) {
        pwm_set_dt(&spec[0], 2000, 1500);
        pwm_set_dt(&spec[1], 2000, 500);
        k_msleep(1000);
        pwm_set_dt(&spec[0], 2000, 500);
        pwm_set_dt(&spec[1], 2000, 1500);
        k_msleep(1000);
    }

    return 0;
}
// west build -p always hello_world