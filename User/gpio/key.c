#include "key.h"
#include "delay.h"
// ������ʼ������
// PA15��PC5 ���ó�����
void KEY_Init(void) {

    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // ʹ��PORTAʱ��

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;     // PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ���ó���������
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // ��ʼ��GPIOA0

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;     // PA1
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ���ó���������
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // ��ʼ��GPIOA1

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;     // PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ���ó���������
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // ��ʼ��GPIOA.2

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;     // PA2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // ���ó���������
    GPIO_Init(GPIOA, &GPIO_InitStructure);        // ��ʼ��GPIOA.2
}
