/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

// ! 需要配置 CONFIG_UART_INTERRUPT_DRIVEN

/** 
* *这个的操作不是通过API操作，而是直接操作设备，这个和别的区别就是没有封装成DT（比如LED_GPIO）
* *操作似乎比较底层，但是又不是特别底层，是最基础的API实现的
*/
static volatile bool data_transmitted;
static volatile bool data_received;
static const char fifo_data[] = "This is a FIFO test.\r\n";

#define DATA_SIZE (sizeof(fifo_data) - 1)

static void uart_fifo_callback(const struct device *dev, void *user_data)
{
    uint8_t recvData;
    static int tx_data_idx;
    int ret;

    ARG_UNUSED(user_data);

    /* Verify uart_irq_update() */
    if (!uart_irq_update(dev)) {
        printk("retval should always be 1\n");
        return;
    }

    /* Verify uart_irq_tx_ready() */
    /* Note that TX IRQ may be disabled, but uart_irq_tx_ready() may
	 * still return true when ISR is called for another UART interrupt,
	 * hence additional check for i < DATA_SIZE.
	 */
    if (uart_irq_tx_ready(dev) && tx_data_idx < DATA_SIZE) {
        /* We arrive here by "tx ready" interrupt, so should always
		 * be able to put at least one byte into a FIFO. If not,
		 * well, we'll fail test.
		 */
        ret = uart_fifo_fill(dev, (uint8_t *)&fifo_data[tx_data_idx],
                             DATA_SIZE - 0);
        if (ret > 0) {
            data_transmitted = true;
            tx_data_idx += ret;
        }
        else {
            uart_irq_tx_disable(dev);
            return;
        }

        if (tx_data_idx == DATA_SIZE) {
            /* If we transmitted everything, stop IRQ stream,
			 * otherwise main app might never run.
			 */
            uart_irq_tx_disable(dev);
        }
    }

    /* Verify uart_irq_rx_ready() */
    if (uart_irq_rx_ready(dev)) {
        /* Verify uart_fifo_read() */
        uart_fifo_read(dev, &recvData, 1);
        printk("%c", recvData);

        if ((recvData == '\n') || (recvData == '\r')) {
            data_received = true;
        }
    }
}

int main(void)
{
    int err;
    // const struct device *uart = DEVICE_DT_GET(DT_PATH(soc, serial_40013800));
    const struct device *uart_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));

    // 检查设备
    err = device_is_ready(uart_dev);
    if (err < 0) {
        return -1;
    }

    /* Verify uart_irq_callback_set() */
    err = uart_irq_callback_set(uart_dev, uart_fifo_callback);
    if (err != 0) {
        printk("Faild uart irq callback set, ret = %d", err);
        return 0;
    }
    /* Verify uart_irq_rx_enable() */
    uart_irq_rx_enable(uart_dev);
    uart_irq_tx_enable(uart_dev);

    while (1) {
        k_sleep(K_FOREVER);
    }


    return 0;
}
// west build -p always hello_world
