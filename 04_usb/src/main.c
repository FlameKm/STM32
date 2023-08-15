/*
 * Copyright (c) 2016-2018 Intel Corporation.
 * Copyright (c) 2018-2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/usb/class/usb_hid.h>
#include <zephyr/usb/usb_device.h>

#define LOG_LEVEL LOG_LEVEL_INF
LOG_MODULE_REGISTER(main);

static const uint8_t hid_report_desc[] = HID_MOUSE_REPORT_DESC(2);
static enum usb_dc_status_code usb_status;
static K_SEM_DEFINE(sem, 0, 1);
static const struct gpio_dt_spec key = GPIO_DT_SPEC_GET(DT_ALIAS(key0), gpios);
static struct gpio_callback callback;
static uint8_t report[4] = {0x00};
static void status_cb(enum usb_dc_status_code status, const uint8_t *param)
{
    usb_status = status;
}

static void press_button(const struct device *gpio, struct gpio_callback *cb, uint32_t pins)
{
    // 如果设备挂起，则唤醒
    if (IS_ENABLED(CONFIG_USB_DEVICE_REMOTE_WAKEUP)) {
        if (usb_status == USB_DC_SUSPEND) {
            usb_wakeup_request();
            return;
        }
    }
    if(gpio_pin_get_dt(&key) == 0){
        report[2] = (uint8_t)(int8_t)-10;
    }
    if(gpio_pin_get_dt(&key) == 1){
        report[2] = 10;
    }
    LOG_INF("press_button");
    k_sem_give(&sem);
}

int main(void)
{
    int ret;
    const struct device *hid_dev;

    LOG_INF("init begin\n");
    // *KEY-GPIO
    if (!device_is_ready(key.port)) {
        LOG_ERR("GPIO port %s is not ready", key.port->name);
        return -ENODEV;
    }
    gpio_pin_configure_dt(&key, GPIO_INPUT);
    gpio_init_callback(&callback, press_button, BIT(key.pin));
    gpio_add_callback_dt(&key, &callback);
    gpio_pin_interrupt_configure_dt(&key, GPIO_INT_EDGE_BOTH);

    // *USB
    hid_dev = device_get_binding("HID_0");
    usb_hid_register_device(hid_dev,
                            hid_report_desc, sizeof(hid_report_desc),
                            NULL);
    usb_hid_init(hid_dev);
    ret = usb_enable(status_cb);
    if (ret != 0) {
        LOG_ERR("Failed to enable USB");
        return 0;
    }

    while (true) {
        k_sem_take(&sem, K_FOREVER);
        ret = hid_int_ep_write(hid_dev, report, sizeof(report), NULL);
        if (ret) {
            LOG_ERR("HID write error, %d", ret);
        }
    }
}
