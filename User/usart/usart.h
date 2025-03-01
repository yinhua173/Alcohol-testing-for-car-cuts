#ifndef __USART_H
#define __USART_H
//#include "sys.h" 
#include "stdio.h"
#include "string.h"
#define USART_REC_LEN  		200  	//定义最大接收字节数 200
#define EN_USART1_RX 			1		//使能（1）/禁止（0）串口1接收
	  	

//如果想串口中断接收，请不要注释以下宏定义
void uart_init(u32 bound);
void USART1_Send_Byte(unsigned char byte);//串口发送一个字节
void UART1_Send_Str(unsigned char *s);//发送字符串 函数应用指针 方法

void uart2_init(u32 bound);
void USART2_Send_Byte(unsigned char byte);//串口发送一个字节
void UART2_Send_Str(unsigned char *s);//发送字符串 函数应用指针 方法
typedef struct{
	u8 date[128];
	u8 flag;
	u16 index;
}usart_type;
extern usart_type usart1_date;
#endif
