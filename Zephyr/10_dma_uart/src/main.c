

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <stdint.h>
#include <string.h>

// 参考 https://github.com/intel/zephyr/blob/main/tests/drivers/uart/uart_async_api

const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(usart1));
K_SEM_DEFINE(sem_rdy, 0, 1);
K_SEM_DEFINE(sem_rel, 0, 1);
static void test_single_read_callback(const struct device *dev, struct uart_event *evt, void *user_data)
{
    ARG_UNUSED(dev);

    switch (evt->type) {
        case UART_TX_DONE:
            printk("UART_TX_DONE\n");
            break;
        case UART_TX_ABORTED:
            break;
        case UART_RX_RDY: // !类似空闲中断
            k_sem_give(&sem_rdy);
            break;
        case UART_RX_BUF_RELEASED: // !结束数据完成
            k_sem_give(&sem_rel);
            break;
        case UART_RX_DISABLED:
            break;
        default:
            break;
    }
}

volatile uint32_t tx_aborted_count;
int main()
{
    uint8_t rx_buf[11] = {0};
    uint8_t tx_buf[] = "test\r\n";

    if (!device_is_ready(uart_dev)) {
        printk("Failed to device ready!\n");
    }

    uart_callback_set(uart_dev,
                      test_single_read_callback,
                      NULL);

    uart_tx(uart_dev, tx_buf, sizeof(tx_buf), 100 * USEC_PER_MSEC);//右边是超时时间
    k_msleep(20);                                                  // wait transmit
    uart_tx(uart_dev, tx_buf, sizeof(tx_buf), 0);
    k_msleep(20);// wait transmit
    uart_rx_enable(uart_dev, rx_buf, 10, 0);
    while (1) {
        k_sem_take(&sem_rdy, K_FOREVER);
        printk("%s\n", rx_buf);
        if (0 == k_sem_take(&sem_rel, K_MSEC(0))) {
            rx_buf[10] = 0;
            printk("\nrx buf: %s\n", rx_buf);
            uart_rx_disable(uart_dev);
            uart_rx_enable(uart_dev, rx_buf, 10, 0);
            memset(rx_buf, 0, 11);
        }
    }
    return 0;
}