
#include <stm32f1xx_hal.h>
#include "zephyr/sys/printk.h"
#include <stdint.h>
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_hal_uart.h"
#include <stm32f1xx_hal_gpio.h>
#include <stm32f1xx_hal_cortex.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec key = GPIO_DT_SPEC_GET(DT_ALIAS(key0), gpios);

void uart_hal()
{

    UART_HandleTypeDef huart1;
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart1);
    HAL_UART_Transmit(&huart1, (uint8_t *)"hello uart\n", 12, 20);

/*     HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"hello dma\n", 9); // !很遗憾还是没有实现
    k_msleep(20); */
}
int main(void)
{
    int ret[3];
    int err;
    if (!gpio_is_ready_dt(&key)) {
        return 0;
    }

    err = gpio_pin_configure_dt(&key, GPIO_INPUT);
    if (ret < 0) {
        return 0;
    }

    printk("hello world\n");
    uart_hal();

    while (1) {
        ret[0] = gpio_pin_get_dt(&key); // *数值和实际电平相反是因为这个是考虑到活跃电平的
        ret[1] = (LL_GPIO_ReadInputPort(GPIOA) >> 3) & 0x1;
        ret[2] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
        printk("key input is dt:%d ll:%d hal:%d\n", ret[0], ret[1], ret[2]);

        k_msleep(5000);
    }
    return 0;
}
