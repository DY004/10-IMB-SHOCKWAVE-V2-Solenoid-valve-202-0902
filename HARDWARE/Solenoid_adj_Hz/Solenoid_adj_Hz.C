#include "Solenoid_adj_Hz.h"
#include "gpio.h"
#include "key.h"
#include "delay.h"
#include "main.h"
#include "tim.h"
#include "string.h"
#include "stdio.h"


uint16_t key_value = 0;
uint16_t n = 0;
void Solenoid_adj_Hz(void)
{
	key_value = KEY_Scan(0);
	if(key_value == 2)//减小频率,速度变慢
	{
		n++;
		if(n ==1)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,10000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,3500);
		}
		if(n ==2)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,5000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,70000);
		}
		
		if(n ==3)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,3330-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,2400);
		}
		if(n ==4)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,2500-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1750);
		}
		
		if(n ==5)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,2000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1400);
		}
		
		if(n ==6)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1667-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1120);
		}
		
		if(n ==7)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1428-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1120);
		}
		
		if(n ==8)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1250-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,850);
		}
		
		if(n ==9)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1111-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,770);
		}
		if(n ==10)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,700);
		}
		if(n >= 10)
		{
			n = 10;	
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,700);
		}
	}
			
	if(key_value == 3)//增加频率，速度变快	
	{
		
		n--;
		if(n ==1)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,10000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,3500);
		}
		if(n ==2)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,5000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,70000);
		}
		
		if(n ==3)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,3330-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,2400);
		}
		if(n ==4)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,2500-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1750);
		}
		
		if(n ==5)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,2000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1400);
		}
		
		if(n ==6)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1667-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1120);
		}
		
		if(n ==7)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1428-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,1120);
		}
		
		if(n ==8)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1250-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,850);
		}
		
		if(n ==9)
		{
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,1111-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,770);
		}
		
		if(n ==65535 ||n ==0)
		{
			n =0;
			__HAL_TIM_SET_PRESCALER(&htim4,7200-1);
			__HAL_TIM_SET_AUTORELOAD(&htim4,10000-1);
			__HAL_TIM_SetCompare(&htim4,TIM_CHANNEL_4,0);
		
		
		}
	
	
	}
	HAL_Delay(10);
}

u8 KEY_Scan(u8 mode)
{
    static u8 key_up=1;     //按键松开标志
    if(mode==1)key_up=1;    //支持连按
    if(key_up&&(KEY1==0||KEY2==0))
    {
        delay_ms(20);
        key_up=0;
        if(KEY1==0)       	   return KEY1_PRES;
		else if(KEY2==0)       return KEY2_PRES;
		     
    }else if(KEY1==1&&KEY2 == 1)key_up=1;
    return 0;   //无按键按下
}


