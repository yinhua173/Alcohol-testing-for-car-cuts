#ifndef __USART_H
#define __USART_H
//#include "sys.h" 
#include "stdio.h"
#include "string.h"
#define USART_REC_LEN  		200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	

//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(u32 bound);
void USART1_Send_Byte(unsigned char byte);//���ڷ���һ���ֽ�
void UART1_Send_Str(unsigned char *s);//�����ַ��� ����Ӧ��ָ�� ����

void uart2_init(u32 bound);
void USART2_Send_Byte(unsigned char byte);//���ڷ���һ���ֽ�
void UART2_Send_Str(unsigned char *s);//�����ַ��� ����Ӧ��ָ�� ����
typedef struct{
	u8 date[128];
	u8 flag;
	u16 index;
}usart_type;
extern usart_type usart1_date;
#endif
