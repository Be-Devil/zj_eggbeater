#include "delay.h"
#include "Usart.h"
#include "time.h"
#include "massage.h"
#include "KEY.h"

u8 USART2_RX[20];
u8 massage[20] ;
u8 i;
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	UsartInit();  //	串口初始化
	massage_init();
	Timer0Init();  //定时器0初始化
	while(1)
	{
		KEY();
		switch (USART2_RX[2])
	{
		case 0X05:
				memset(USART2_RX,0,30);   //清空数组		
				Gashapon = ~Gashapon;
				led1 = ~led1;
			break;
		
		case 0X06:
			break;
	}		
	
	}		
}
