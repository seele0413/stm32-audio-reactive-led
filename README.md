# STM32 Audio Reactive LED System

基于 STM32F103C8T6 的音频律动灯控制系统。系统通过 MAX9814 麦克风模块采集环境音频信号，使用 ADC + DMA 完成连续采样，并结合 FFT 分析音频幅值特征，最终驱动 WS2812B 灯带实现随音乐变化的动态灯效。

## Tech Stack

STM32F103C8T6 / MAX9814 / WS2812B / ADC / DMA / FFT / PWM / C

## Features

- 使用 MAX9814 采集环境音频信号，并适配 STM32 ADC 输入范围
- 基于 ADC + DMA 实现连续音频采样，减少 CPU 轮询开销
- 使用 FFT 分析音频频域特征，并提取音量和频谱变化信息
- 根据音频特征映射 WS2812B 灯带颜色、亮度和动态效果
- 完成硬件接线、模块联调、参数调试和实物验证

## System Architecture

```text
Audio Signal
    ↓
MAX9814 Microphone Module
    ↓
STM32F103C8T6 ADC + DMA Sampling
    ↓
FFT Analysis
    ↓
Lighting Effect Mapping
    ↓
WS2812B LED Strip
