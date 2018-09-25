#include "time.h"
#include "massage.h"

u8 heart_massage[6] = {0x7a,0x03,0x02,0x03,0x08,0x55};
u8 coin_massage[6] = {0x7a,0x03,0x04,0x04,0x0b,0x55};
u8 out_Gashapon_massage[6] = {0x7a,0x03,0x05,0x02,0x0b,0x55};
/*******************************************************************************
* 函 数 名         : void Timer0() interrupt 1
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0() interrupt 1
{
	static u16 i;
	u16 x;
	TH0=(65536-300)/256;	//给定时器赋初值，定时0.3ms
	TL0=(65536-300)/256;
	i++;
	if(i==10000)
	{
		i=0;
		led0=~led0;	
//		send_massage(heart_massage,6);
	}	
		if(out_Gashapon==0&&Gashapon == 0)		
		{	
			Gashapon = 1;
		  send_massage(out_Gashapon_massage,6);
		}	
		if(coin==0&&Gashapon == 1)		
		{	
			Gashapon = 0;
		  send_massage(coin_massage,6);
		}			
}

/*******************************************************************************
* 函 数 名         : Timer0Init
* 函数功能		   : 定时器0初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0Init()
{
	TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。

	TH0=0XFC;	//给定时器赋初值，定时1ms
	TL0=0X18;	
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器			
}
