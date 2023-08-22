/* 
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/* !!!!!!
*   This demo is not available
*
 */
#include "stm32f103xb.h"
#include "zephyr/sys/util.h"
#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/dma.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define DMA_CHANNEL 4

const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(usart1));
const struct device *dma_dev = DEVICE_DT_GET(DT_NODELABEL(dma1));

static void dma_callback(const struct device *dev, void *user_data, uint32_t channel, int status)
{
    printk("%s %d transfer completed with status %d\n", dev->name, channel, status);
}

int main(void)
{
    int ret;

    ret = device_is_ready(dma_dev);
    if (ret < 0) {
        printk("Faild to dma device\n");
        return 0;
    }
    ret = device_is_ready(uart_dev);
    if (ret < 0) {
        printk("Faild to uart device\n");
        return 0;
    }
    uint8_t src_data[] = "12345\n";
    uint8_t dst_data[ARRAY_SIZE(src_data)] = {0};
    struct dma_block_config block_cfg = {
        .block_size = sizeof(src_data),
        .source_address = (uint32_t)src_data,
        .source_addr_adj = DMA_ADDR_ADJ_INCREMENT,
        .dest_address = (uint32_t)&USART1->DR,
        .dest_addr_adj = DMA_ADDR_ADJ_NO_CHANGE,
    };
    struct dma_config cfg = {
        .dma_slot = 5,
        .channel_direction = MEMORY_TO_PERIPHERAL,
        .dest_handshake = 0,
        .source_handshake = 0,
        .cyclic = 0,
        .source_data_size = 1,
        .dest_data_size = 1,
        .source_burst_length = 1,
        .dest_burst_length = 1,
        .user_data = NULL,
        .dma_callback = dma_callback,
        .block_count = 1,
        .head_block = &block_cfg,
        .complete_callback_en = 0,
    };
    
    ret = dma_config(dma_dev, DMA_CHANNEL, &cfg);
    if (ret < 0) {
        printk("Failed to configure DMA channel\n");
        return 0;
    }
    ret = dma_start(dma_dev, DMA_CHANNEL);
    if (ret < 0) {
        printk("Failed to start DMA transfer\n");
        return 0;
    }

    while (1) {
        dma_config(dma_dev, DMA_CHANNEL, &cfg);
        dma_start(dma_dev, DMA_CHANNEL);
        k_sleep(K_SECONDS(1));
    }
    return 0;
}
