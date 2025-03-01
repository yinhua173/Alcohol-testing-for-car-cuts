#include "adc.h"
#include "delay.h"
#include "stm32f10x_adc.h"

// ��ʼ��ADC
// �������ǽ��Թ���ͨ��Ϊ��
// ����Ĭ�Ͻ�����ͨ��0~3
void Adc_Init(void) {
    ADC_InitTypeDef ADC_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE); // ʹ��ADC1ͨ��ʱ��
    RCC_ADCCLKConfig(RCC_PCLK2_Div6);                                           // ����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M
    // PA0 ��Ϊģ��ͨ����������
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; // ģ����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    ADC_DeInit(ADC1); // ��λADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ

    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                 // ����ת��ģʽ����
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;              // ���������
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // �������
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                  // ����ģʽ
    ADC_InitStructure.ADC_NbrOfChannel = 1;                             // ͨ����
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;                       // ɨ��ģʽ����
    ADC_Init(ADC1, &ADC_InitStructure);

    ADC_Cmd(ADC1, ENABLE); // ʹ��ָ��ADC����

    ADC_ResetCalibration(ADC1); // ʹ�ܸ�λУ׼

    while (ADC_GetResetCalibrationStatus(ADC1))
        ;                           // �ȴ���λУ׼����

    ADC_StartCalibration(ADC1);     // ����ADУ׼
    ADC_GetCalibrationStatus(ADC1); // �ȴ�ADУ׼����
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
