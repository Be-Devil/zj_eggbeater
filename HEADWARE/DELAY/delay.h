#ifndef __DELAY_H
#define __DELAY_H 		
#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "string.h"
#include "main.h"

void delay_ms(u16 nms);
void delay();

#endif