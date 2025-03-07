#include "LED.h"

void Init_LEDpin(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE); // 使能PF端口时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;        // 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);            // 根据设定参数初始化GPIOC

    GPIO_SetBits(GPIOC, GPIO_Pin_13); // 初始化设置为0

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;         // 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO口速度为50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);            // 根据设定参数初始化GPIOC

    GPIO_SetBits(GPIOB, GPIO_Pin_9);
}
