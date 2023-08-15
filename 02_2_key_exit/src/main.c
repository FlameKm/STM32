#include "zephyr/sys/printk.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec key = GPIO_DT_SPEC_GET(DT_ALIAS(key0), gpios);
static struct gpio_callback callback;


void press_button(const struct device *port, struct gpio_callback *cb, gpio_port_pins_t pins)
{
    /*     if (key.port == port) {
        printk("key is press\n");
    } */
    if (&callback == cb) {
        printk("key is press\n");
    }
}
int main(void)
{
    int ret;

    if (!gpio_is_ready_dt(&key)) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&key, GPIO_INPUT);
    if (ret < 0) {
        return 0;
    }

    ret = gpio_pin_get_dt(&key);
    if (ret < 0) {
        printk("Failed to read pin");
    }

    gpio_init_callback(&callback, press_button, BIT(key.pin));
    ret = gpio_add_callback_dt(&key, &callback);
    if (ret < 0) {
        printk("Faild to add callback");
    }

    ret = gpio_pin_interrupt_configure_dt(&key, GPIO_INT_EDGE_TO_ACTIVE);
    if (ret < 0) {
        printk("Faild to configure pin int");
    }

    printk("config surrceful");
    while (1) {
        ret = gpio_pin_get_dt(&key);
        printk("key is %d\n", ret);
        k_msleep(1000);
    }
    return 0;
}
