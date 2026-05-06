#ifndef __STM32F4XX_CONF_H
#define __STM32F4XX_CONF_H

/* ?????????? */
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"

/* ??????(??????) */
#define assert_param(expr) ((void)0)

#endif /* __STM32F4XX_CONF_H */
#ifdef USE_FULL_ASSERT
#define assert_param(expr) ((void)0)
#endif
