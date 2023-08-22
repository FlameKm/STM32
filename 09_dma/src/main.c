/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/dma.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>


#define DMA_CHANNEL 4

const struct device *dma_dev = DEVICE_DT_GET(DT_NODELABEL(dma1));

static void dma_callback(const struct device *dev, void *user_data, uint32_t channel, int status)
{
    printk("DMA transfer completed with status %d\n", status);
}

int main(void)
{
    int ret;

    ret = device_is_ready(dma_dev);
    if (ret < 0) {
       printk("Faild to dma device\n");
       return 0;
    }
    uint8_t src_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    uint8_t dst_data[ARRAY_SIZE(src_data)] = {0};

    struct dma_block_config block_cfg = {
        .block_size = sizeof(src_data),
        .source_address = (uint32_t)src_data,
        .dest_address = (uint32_t)dst_data,
    };
    struct dma_config cfg = {
        .channel_direction = MEMORY_TO_MEMORY,
        .source_data_size = 1,
        .dest_data_size = 1,
        .source_burst_length = 1,
        .dest_burst_length = 1,
        .dma_callback = dma_callback,
        .block_count = 1,
        .head_block = &block_cfg,
    };

    ret = dma_config(dma_dev, DMA_CHANNEL, &cfg);
    if (ret != 0) {
        printk("Failed to configure DMA channel\n");
        return 0;
    }
    ret = dma_start(dma_dev, DMA_CHANNEL);
    if (ret != 0) {
        printk("Failed to start DMA transfer\n");
        return 0;
    }
    for (int i = 0; i < ARRAY_SIZE(dst_data); i++) {
        printk("dst_data[%d] = %d\n", i, dst_data[i]);
    }
    while (1) {
        k_sleep(K_SECONDS(1));
    }
    return 0;
}
// west build -p always hello_world