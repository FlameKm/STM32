

/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

/* 
    输入什么就返回什么
 */

/** 
* *这个的操作不是通过API操作，而是直接操作设备，这个和别的区别就是没有封装成DT（比如LED_GPIO）
* *操作似乎比较底层，但是又不是特别底层，是最基础的API实现的
*/

int main(void)
{
    int err;
    char ret;
    // const struct device *uart = DEVICE_DT_GET(DT_PATH(soc, serial_40013800));
    const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(usart1));

    // 检查设备
    err = device_is_ready(uart_dev);
    if (err < 0) {
        return -1;
    }

    while (1) {
        // POLL
        err = uart_poll_in(uart_dev, &ret);
        if (err >= 0) {
            uart_poll_out(uart_dev, ret);
        }
    }

    return 0;
}
// west build -p always hello_world