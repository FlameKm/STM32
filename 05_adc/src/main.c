/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define DT_SPEC_AND_COMMA(node_id, prop, idx) \
    ADC_DT_SPEC_GET_BY_IDX(node_id, idx),


/* Data of ADC io-channels specified in devicetree. */
// !方法一 用宏枚举法
/* static const struct adc_dt_spec adc_channels[] = {
    DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user), io_channels,
                         DT_SPEC_AND_COMMA)}; */

// !方法二 手动处理
static const struct adc_dt_spec adc_channels[] = {
    ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 0),
    ADC_DT_SPEC_GET_BY_IDX(DT_PATH(zephyr_user), 1),
};


int main(void)
{
    uint32_t count = 0;
    int err;
    uint16_t buf;
    struct adc_sequence sequence = {
        .buffer = &buf,
        /* buffer size in bytes, not number of samples */
        .buffer_size = sizeof(buf),
    };
    uint8_t len = ARRAY_SIZE(adc_channels);
    // *init to adc
    for (int i = 0; i < len; i++) {
        err = adc_is_ready_dt(&adc_channels[i]);
        if (err < 0) {
            printk("ADC controller device %s not ready\n", adc_channels[i].dev->name);
        }
        err = adc_channel_setup_dt(&adc_channels[i]);
        if (err < 0) {
            printk("Could not setup channel #%d (%d)\n", 0, err);
        }
    }

    while (1) {
        int32_t val_mv;
        printk("ADC reading[%02u]: ", count++);
        for (int i = 0; i < len; i++) {
            printk("- ch%d: ", adc_channels[i].channel_id);
            adc_sequence_init_dt(&adc_channels[i], &sequence);
            // *adc read
            err = adc_read(adc_channels[i].dev, &sequence);
            if (err < 0) {
                printk("Could not read (%d)\n", err);
            }
            if (adc_channels[i].channel_cfg.differential) {
                val_mv = (int32_t)((int16_t)buf);
            }
            else {
                val_mv = (int32_t)buf;
            }
            printk("%d", val_mv);
            err = adc_raw_to_millivolts_dt(&adc_channels[i], &val_mv);
            if (err < 0) {
                printk(" (value in mV not available)\n");
            }
            else {
                printk("=%dmV", val_mv);
            }
        }
        printk("\n");
        k_msleep(500);
    }

    return 0;
}
// west build -p always hello_world