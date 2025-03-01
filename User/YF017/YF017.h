#ifndef __YF017_H
#define __YF017_H
#include "stm32f10x.h"
#include "io_bit.h"

#define RST1  PBout(14)
#define DATA  PBout(13)

#define BUSY  PBin(12)

void YF017_init(void);
void Music(unsigned char z);
void BUSY_IN(void);
void yuyinbobao(unsigned int t);
void yuyinbobao_DJ(unsigned int d);
void yuyinbobao_JINE(unsigned long J);


#endif
