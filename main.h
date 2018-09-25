#ifndef _MAIN_H
#define _MAIN_H
#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "string.h"

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit led0=P2^0;		 //����Ƭ����P2.0�˿ڶ���Ϊled0
sbit led1=P2^1;		 //����Ƭ����P2.1�˿ڶ���Ϊled1

sbit key1=P3^1;		 //����Ƭ����P3.0�˿ڶ���Ϊkey1
sbit key2=P3^0;		 //����Ƭ����P3.1�˿ڶ���Ϊkey2
sbit key3=P3^2;		 //����Ƭ����P3.2�˿ڶ���Ϊkey3
sbit key4=P3^3;		 //����Ƭ����P3.3�˿ڶ���Ϊkey4

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