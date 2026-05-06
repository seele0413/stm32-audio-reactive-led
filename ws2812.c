#include "ws2812.h"

#define WS2812_PIN GPIO_PIN_5
#define WS2812_GPIO_PORT GPIOA

static uint16_t num_leds;
static WS2812_Color led_buffer[WS2812_NUM_LEDS];

// ???? WS2812 ?????(???????)
void WS2812_Init(uint16_t num_leds) {
    // ???LED??
    this->num_leds = num_leds;

    // ???PA5???(????WS2812)
    GPIO_InitTypeDef GPIO_InitStruct;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = WS2812_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(WS2812_GPIO_PORT, &GPIO_InitStruct);
}

// ????LED???
void WS2812_SetColor(uint16_t index, uint8_t R, uint8_t G, uint8_t B) {
    if (index < num_leds) {
        led_buffer[index].R = R;
        led_buffer[index].G = G;
        led_buffer[index].B = B;
    }
}

// ???????????? WS2812 ??
void WS2812_Update(void) {
    uint16_t i, j;
    uint8_t byte;
    
    // ??? LED ????,?????
    for (i = 0; i < num_leds; i++) {
        for (j = 0; j < 8; j++) {
            byte = led_buffer[i].G;
            // ??????
            if ((byte & (1 << (7 - j))) != 0) {
                WS2812_SendBit(1); // ???????
            } else {
                WS2812_SendBit(0); // ???????
            }
        }
        for (j = 0; j < 8; j++) {
            byte = led_buffer[i].R;
            // ??????
            if ((byte & (1 << (7 - j))) != 0) {
                WS2812_SendBit(1); 
            } else {
                WS2812_SendBit(0);
            }
        }
        for (j = 0; j < 8; j++) {
            byte = led_buffer[i].B;
            // ??????
            if ((byte & (1 << (7 - j))) != 0) {
                WS2812_SendBit(1);
            } else {
                WS2812_SendBit(0);
            }
        }
    }
}

// ??????? WS2812
void WS2812_SendBit(uint8_t bit) {
    if (bit) {
        // ???????(? 800ns)
        HAL_GPIO_WritePin(WS2812_GPIO_PORT, WS2812_PIN, GPIO_PIN_SET);
        HAL_Delay(1);  // ????????????????
        HAL_GPIO_WritePin(WS2812_GPIO_PORT, WS2812_PIN, GPIO_PIN_RESET);
        HAL_Delay(1);  // ?????????????
