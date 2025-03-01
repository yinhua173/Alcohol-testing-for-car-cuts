#ifndef __KEY_H
#define __KEY_H	 
#include "stm32f10x.h"
#include "io_bit.h"

#define key3  PAin(7)   	
#define key2  PAin(6)	 
#define key1  PAin(5)	 
#define RHW  PAin(8)

void KEY_Init(void);	//IO��ʼ��
u8 KEY_Scan(u8 mode);	//����ɨ�躯��		

#endif
