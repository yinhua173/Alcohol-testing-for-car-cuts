#include "adc.h"
#include "delay.h"
#include "stm32f10x_adc.h"

// 初始化ADC
// 这里我们仅以规则通道为例
// 我们默认将开启通道0~3
void Adc_Init(void) {
    ADC_InitTypeDef ADC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE); // 使能ADC1通道时钟
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);                                           // 设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M
    // PA0 作为模拟通道输入引脚
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; // 模拟输入引脚
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_DeInit(ADC1); // 复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值

    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                 // 连续转化模式设置
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;              // 数据左对齐
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // 软件触发
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                  // 独立模式
    ADC_InitStructure.ADC_NbrOfChannel = 1;                             // 通道数
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;                       // 扫描模式设置
    ADC_Init(ADC1, &ADC_InitStructure);

    ADC_Cmd(ADC1, ENABLE); // 使能指定ADC外设

    ADC_ResetCalibration(ADC1); // 使能复位校准

    while (ADC_GetResetCalibrationStatus(ADC1))
        ;                           // 等待复位校准结束

    ADC_StartCalibration(ADC1);     // 开启AD校准
    ADC_GetCalibrationStatus(ADC1); // 等待AD校准结束
}

float temp_avrg = 0;
int temp_LL = 40;
int shidu;
u16 Get_Adc(u8 ch) {

    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5);

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);

    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC))
        ;

    return ADC_GetConversionValue(ADC1);
}

u16 Get_Adc_Average(u8 ch, u8 times) {
    u32 temp_val = 0;
    u8 t;

    for (t = 0; t < times; t++) {
        temp_val += Get_Adc(ch);
        delay_ms(1);
    }

    temp_avrg = temp_val / times;
    return temp_avrg;
}
