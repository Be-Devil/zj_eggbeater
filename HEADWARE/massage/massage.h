#ifndef __MASSAGE_H
#define __MASSAGE_H 		
#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "string.h"
#include "main.h"

void send_massage(u16 *receiveData,u8 num);
void key_control(u8 key_type,u8 key_state);
char GetMCUID(unsigned char nType);
u8 massage_init();

#define ID_ADDR_RAM 0xF1       
#define ID_ADDR_ROM 0x0FF9  
#define RAMID 0
#define ROMID 1  

#endif