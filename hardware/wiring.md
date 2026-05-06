# Hardware Wiring / 硬件接线说明

## Main Modules / 主要模块

| Module / 模块 | Connection / 连接方式 | Description / 说明 |
| --- | --- | --- |
| MAX9814 OUT | STM32 PA0 | Audio analog signal input / 音频模拟信号输入 |
| MAX9814 VCC | 3.3V / 5V | Power input, depends on module configuration / 电源输入，具体电压取决于模块配置 |
| MAX9814 GND | GND | Common ground / 共地 |
| WS2812B DIN | STM32 PB7 | LED strip data input / 灯带数据输入 |
| WS2812B VCC | 5V | LED strip power input / 灯带电源输入 |
| WS2812B GND | GND | Common ground / 共地 |

## Notes / 注意事项

- STM32、MAX9814 和 WS2812B 需要共地，否则信号可能无法稳定识别。
- WS2812B 灯带在高亮度或多灯珠同时点亮时电流较大，建议使用稳定的 5V 电源供电。
- MAX9814 输出的音频模拟信号应控制在 STM32 ADC 可接受的输入电压范围内。
- WS2812B 对时序要求较高，数据线建议尽量缩短，减少干扰。
- 调试时建议先降低灯带亮度，确认信号正常后再逐步提高亮度。
