#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1 PCout(13)
#define JDQ PBout(9)

extern void Init_LEDpin(void);

#endif

