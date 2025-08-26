/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-05-24                  the first version
 */

#include <rtthread.h>
#include "main.h"
#include "iwdg.h"
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/**
 * This function will initial your board.
 */
void rt_hw_board_init(void) {
    HAL_Init();
    SystemClock_Config();
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);
    MX_RTC_Init();
    MX_USART1_UART_Init();
    MX_GPIO_Init();
    MX_IWDG_Init();

    /* Call components board initial (use INIT_BOARD_EXPORT()) */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
    extern char _rt_heap_start;
    rt_system_heap_init((void *)&_rt_heap_start, (void *)(0x20000000 + 64 * 1024));
#    ifdef RT_DEBUG
    rt_kprintf("heap start: 0x%08x\n", &_rt_heap_start);
#    endif
#endif
}

#ifdef RT_USING_CONSOLE

void rt_hw_console_output(const char * str) {
    HAL_UART_Transmit(&huart1, (uint8_t *)str, rt_strlen(str), 100);
}

#endif
