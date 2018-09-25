#ifndef _MAIN_H
#define _MAIN_H
#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "string.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit led0=P2^0;		 //将单片机的P2.0端口定义为led0
sbit led1=P2^1;		 //将单片机的P2.1端口定义为led1

sbit key1=P3^1;		 //将单片机的P3.0端口定义为key1
sbit key2=P3^0;		 //将单片机的P3.1端口定义为key2
sbit key3=P3^2;		 //将单片机的P3.2端口定义为key3
sbit key4=P3^3;		 //将单片机的P3.3端口定义为key4

sbit white_key =P0^0;		
sbit red_key   =P0^1;		 
sbit yellow_key=P0^2;		  
sbit green_key =P0^3;		
sbit blue_key  =P0^4;		
sbit Gashapon  =P0^5;		
sbit out_Gashapon  =P0^6;		
sbit coin  =P0^7;		

extern u8 USART2_RX[20];	
#endif