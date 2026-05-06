#ifndef __WS2812_H
#define __WS2812_H

#include "stm32f4xx.h"

// WS2812 LED?????
#define WS2812_NUM_LEDS 50

// WS2812 LED ?????
typedef struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
} WS2812_Color;

// WS2812 ????
void WS2812_Init(uint16_t num_leds);
void WS2812_SetColor(uint16_t index, uint8_t R, uint8_t G, uint8_t B);
void WS2812_Update(void);

#endif
