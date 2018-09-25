#include "massage.h"
unsigned char UID[8];
u8 ID_massage[13] = {0x7a,0x0a,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8 key_instructions[8] = {0x7a,0x05,0x03,0x03,0x01,0x01,0x07,0x55};

/*******************************************************************************
* 函 数 名       : send_massage
* 函数功能		   : 发送指令
*******************************************************************************/
void send_massage(u8 *s, u8 z)
{
	u8 i,sum;
	
	for(i=0,sum=0; i<z ; i++,s++)
	{
			if(i == z-1)
				*s = 0x55;
			if(i == z-2)
				*s = sum;
			if(i > 0)
				sum = sum + *s;
		SBUF=*s;				 //将接收到的数据放入到发送寄存器
		while(!TI);			 //等待发送数据完成
		TI=0;						 //清除发送完成标志位
	}
	
}

void key_control(u8 key_type,u8 key_state)
{
	key_instructions[4] = key_type;
	key_instructions[5] = key_state;
	send_massage(key_instructions,8);
}

u8 massage_init()
{
	u8 i;
	GetMCUID(0);
	for(i = 0; i<7 ; i++)
	{
	ID_massage[i+4] = UID[i];
	ID_massage[11] = (ID_massage[11] +  UID[i])%256;
	}	
	send_massage(ID_massage,13);
	return 0;
}

char GetMCUID(unsigned char nType)
{
    unsigned char idata *iptr;
    unsigned char code *cptr;
    unsigned char i;
    
    if (nType == RAMID) {
        iptr = ID_ADDR_RAM;        
        for (i=0; i<7; i++) {      
            UID[i] =*iptr++;   
        }
    }
    else {
        cptr = ID_ADDR_ROM;         
        for (i=0; i<7; i++) {      
            UID[i] =*cptr++;  
        }
    }
    UID[7]=0;
    
    return 0;
}