#include "LED.h"

void Init_LEDpin(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE); // ʹ��PF�˿�ʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;        // �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  // �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);            // �����趨������ʼ��GPIOC

    GPIO_SetBits(GPIOC, GPIO_Pin_13); // ��ʼ������Ϊ0

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;         // �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  // �������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);            // �����趨������ʼ��GPIOC

    GPIO_SetBits(GPIOB, GPIO_Pin_9);
}
