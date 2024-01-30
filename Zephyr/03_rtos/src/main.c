#include "stm32f1xx_hal.h"
#include "stm32f1xx_ll_gpio.h"
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

K_THREAD_STACK_DEFINE(threadA_stack_area, 1024);
static struct k_thread threadA_data;
K_THREAD_STACK_DEFINE(threadB_stack_area, 1024);
static struct k_thread threadB_data;


void threadA(void *dummy1, void *dummy2, void *dummy3)
{
    ARG_UNUSED(dummy1);
    ARG_UNUSED(dummy2);
    ARG_UNUSED(dummy3);
    // *获取线程句柄从而获取名字
    const char *tname;
    struct k_thread *current_thread;
    current_thread = k_current_get();
    tname = k_thread_name_get(current_thread);
    while (1) {
        printk("%s: Hello World!\n", tname);
        k_msleep(500);
    }
}
void threadB(void *dummy1, void *dummy2, void *dummy3)
{
    ARG_UNUSED(dummy1);
    ARG_UNUSED(dummy2);
    ARG_UNUSED(dummy3);
    // *获取线程句柄从而获取名字
    const char *tname;
    struct k_thread *current_thread;
    current_thread = k_current_get();
    tname = k_thread_name_get(current_thread);
    while (1) {
        printk("%s: Hello hyc!\n", tname);
        k_msleep(1000);
    }
}

int main()
{
    LL_GPIO_AF_Remap_SWJ_NOJTAG();
    k_thread_create(&threadA_data, threadA_stack_area,
                    K_THREAD_STACK_SIZEOF(threadA_stack_area),
                    threadA,
                    NULL,
                    NULL,
                    NULL,
                    7,
                    0,
                    K_FOREVER);
    k_thread_create(&threadB_data,
                    threadB_stack_area,
                    K_THREAD_STACK_SIZEOF(threadB_stack_area),
                    threadB,
                    NULL,
                    NULL,
                    NULL,
                    7,
                    0,
                    K_FOREVER);
    // *设置线程名字
    k_thread_name_set(&threadA_data, "name_a");
    k_thread_name_set(&threadB_data, "name_b");
    // *启动线程
    k_thread_start(&threadA_data);
    k_thread_start(&threadB_data);
    return 0;
}