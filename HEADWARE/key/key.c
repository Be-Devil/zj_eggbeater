#include "key.h"
#include "delay.h"
#include "massage.h"

#define yellow 1
#define green 2
#define white 3
#define blue 4
#define red 5

#define press 1
#define lift 2
void KEY()
{	 	 
	if(yellow_key==0)		  
	{	
		delay_ms(10);  
		if(yellow_key==0)	 
		{
			key_control(yellow,press);
				Gashapon = ~Gashapon;
		while(!yellow_key);	 
			key_control(yellow,lift);
		}
	}	
		
	if(green_key==0)		 
	{	
		delay_ms(10);  
		if(green_key==0)	
		{
			key_control(green,press);
				Gashapon = ~Gashapon;
		while(!green_key);	 
			key_control(green,lift);
		}
	}	
	
	if(white_key==0)		 
	{	
		delay_ms(10);  
		if(white_key==0)	 
		{
			key_control(white,press);
			Gashapon = ~Gashapon;
		while(!white_key);	
		key_control(white,lift);
		}
	}	
		
	if(blue_key==0)		
	{	
		delay_ms(10);  
		if(blue_key==0)	
		{
			key_control(blue,press);
				Gashapon = ~Gashapon;
		while(!blue_key);	 
			key_control(blue,lift);
		}
	}		
		
	if(red_key==0)		 
	{	
		delay_ms(10);  
		if(red_key==0)	
		{
			key_control(red,press);
				Gashapon = ~Gashapon;
		while(!red_key);	 
			key_control(red,lift);
		}
	}	
		
} 