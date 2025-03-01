#include "YF017.h"
#include "delay.h"

unsigned char fmq_flag = 0, xsd_flag = 0;
unsigned char Yu_flag = 0;
void YF017_init(void) {
    GPIO_InitTypeDef GPIO_Init_Structure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init_Structure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_13;

    GPIO_Init_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init_Structure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOB, &GPIO_Init_Structure);
}

void BUSY_IN(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Music(unsigned char z) {
    RST1 = 1;
    // GPIO_SetBits(GPIOB,GPIO_Pin_14);
    delay_ms(2);
    RST1 = 0;
    // GPIO_ResetBits(GPIOB,GPIO_Pin_14);
    delay_ms(2);

    while (z > 0) {
        // GPIO_SetBits(GPIOB,GPIO_Pin_13);
        DATA = 1;
        delay_ms(1);
        DATA = 0;
        // GPIO_ResetBits(GPIOB,GPIO_Pin_13);
        delay_ms(1);
        z--;
    }

    while (!BUSY)
        ;
}
