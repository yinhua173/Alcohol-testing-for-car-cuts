#include "key.h"
#include "delay.h"
// 按键初始化函数
// PA15和PC5 设置成输入
void KEY_Init(void) {

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // 使能PORTA时钟

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;     // PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 设置成上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // 初始化GPIOA0

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;     // PA1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 设置成上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // 初始化GPIOA1

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;     // PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 设置成上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // 初始化GPIOA.2

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;     // PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 设置成上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // 初始化GPIOA.2
}
