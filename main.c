#include "delay.h"
#include "Usart.h"
#include "time.h"
#include "massage.h"
#include "KEY.h"

u8 USART2_RX[20];
u8 massage[20] ;
u8 i;
/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	
	UsartInit();  //	���ڳ�ʼ��
	massage_init();
	Timer0Init();  //��ʱ��0��ʼ��
	while(1)
	{
		KEY();
		switch (USART2_RX[2])
	{
		case 0X05:
				memset(USART2_RX,0,30);   //�������		
				Gashapon = ~Gashapon;
				led1 = ~led1;
			break;
		
		case 0X06:
			break;
	}		
	
	}		
}
