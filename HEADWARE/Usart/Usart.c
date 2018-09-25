#include "Usart.h"

u8 USART2_RX_BUF[20];
u8 JS_FLAG = 0;
u8 he = 0;
/*******************************************************************************
* 函数名         :UsartInit()
* 函数功能		   :设置串口
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void UsartInit()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}


/*******************************************************************************
* 函数名         : Usart() interrupt 4
* 函数功能		  : 串口通信中断函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void Usart() interrupt 4
{
	u8 Res;
	u8 i;
	
	Res = SBUF;
	if(Res == 0x7A && JS_FLAG == 0)
		JS_FLAG = 1;
	if(JS_FLAG > 0)
	{
		JS_FLAG++;
		USART2_RX_BUF[JS_FLAG-2] = Res;

	}
	if(USART2_RX_BUF[JS_FLAG-2] == 0x55 && 
		 USART2_RX_BUF[1] == JS_FLAG-4)
	{
		for(i=1 ; i< JS_FLAG-3; i++)
		 he = (he + USART2_RX_BUF[i])%256;
		if(he == USART2_RX_BUF[JS_FLAG-3])
		for(i=0 ; i< JS_FLAG-1; i++)
		{
			USART2_RX[i] = USART2_RX_BUF[i];
			USART2_RX_BUF[i] = 0;
		}
		JS_FLAG = 0;
		he = 0;
	}
	RI = 0;//清除接收中断标志位
}