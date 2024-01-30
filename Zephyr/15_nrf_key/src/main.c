#include "zephyr/devicetree.h"
#include "zephyr/sys/printk.h"
#include "zephyr/sys/util.h"
#include <stdint.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>


static const struct gpio_dt_spec btn[] = {
    GPIO_DT_SPEC_GET(DT_NODELABEL(button0), gpios),
    GPIO_DT_SPEC_GET(DT_NODELABEL(button1), gpios),
};
static const struct gpio_dt_spec led[] = {
    GPIO_DT_SPEC_GET(DT_NODELABEL(led0), gpios),
    GPIO_DT_SPEC_GET(DT_NODELABEL(led1), gpios),
};

int gpio_init()
{
    int err;
    for (int i = 0; i < ARRAY_SIZE(btn); i++) {
        if (!gpio_is_ready_dt(btn + i)) {
            return -1;
        }
        err = gpio_pin_configure_dt(btn + i, GPIO_INPUT);
        if (err < 0) {
            return -1;
        }
    }
    for (int i = 0; i < ARRAY_SIZE(led); i++) {
        if (!gpio_is_ready_dt(led + i)) {
            return -1;
        }
        err = gpio_pin_configure_dt(led + i, GPIO_OUTPUT);
        if (err < 0) {
            return -1;
        }
    }
    return 0;
}
int main(void)
{
    int err;
    int key[ARRAY_SIZE(btn)];
    uint32_t cnt = 0;
    err = gpio_init();
    if (err < 0) {
        printk("Faild to gpio init");
    }

    printk("hello world");
    while (1) {
        key[0] = gpio_pin_get_dt(&btn[0]);
        key[1] = gpio_pin_get_dt(&btn[1]);
        gpio_pin_set_dt(&led[0], key[0]);
        gpio_pin_set_dt(&led[1], key[1]);
        cnt++;
        if (cnt % 200) {
            printk("key is %d %d\n", key[0], key[1]);
        }
        k_msleep(5);
    }
    return 0;
}
