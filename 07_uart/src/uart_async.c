

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <stdint.h>
#include <string.h>

// 参考 https://github.com/intel/zephyr/blob/main/tests/drivers/uart/uart_async_api

const struct device *uart_dev = DEVICE_DT_GET(DT_NODELABEL(usart1));

static void test_single_read_callback(const struct device *dev, struct uart_event *evt, void *user_data)
{
    ARG_UNUSED(dev);

    switch (evt->type) {
        case UART_TX_DONE:
            printk("UART_TX_DONE\n");
            break;
        case UART_TX_ABORTED:
            (*(uint32_t *)user_data)++;
            break;
        case UART_RX_RDY:
            printk("UART_RX_RDY\n");
            break;
        case UART_RX_BUF_RELEASED:
            printk("UART_RX_BUF_RELEASED\n");
            break;
        case UART_RX_DISABLED:
            printk("UART_RX_DISABLED\n");
            break;
        default:
            break;
    }
}

volatile uint32_t tx_aborted_count;
int main()
{
    uint8_t rx_buf[10] = {0};
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
    while (1) {
        uart_rx_enable(uart_dev, rx_buf, 1, 1);
        k_sleep(K_FOREVER);
    }
    return 0;
}