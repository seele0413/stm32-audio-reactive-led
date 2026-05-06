# Firmware / 固件说明

This folder is reserved for the STM32 firmware of the audio-reactive LED system.  
本目录用于存放音频律动灯系统的 STM32 固件代码。

## Planned Modules / 计划模块

- `audio_sampling`: ADC + DMA audio sampling from MAX9814  
  `audio_sampling`：基于 ADC + DMA 采集 MAX9814 输出的音频信号

- `fft_processing`: FFT-based audio feature extraction  
  `fft_processing`：基于 FFT 的音频特征提取

- `led_effects`: WS2812B color and brightness mapping  
  `led_effects`：WS2812B 灯带颜色与亮度映射

- `board_config`: GPIO, timer, ADC and DMA configuration  
  `board_config`：GPIO、定时器、ADC 和 DMA 初始化配置

## Notes / 说明

The original prototype was built around STM32F103C8T6, MAX9814 and WS2812B.  
本项目原型基于 STM32F103C8T6、MAX9814 和 WS2812B 搭建。

Source files will be organized here after cleaning generated files, board-specific paths and third-party driver references.  
后续会在清理编译生成文件、板级路径和第三方驱动引用后，将源码整理到本目录中。
