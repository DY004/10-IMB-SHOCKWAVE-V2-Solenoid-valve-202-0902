#include "PWR_ON_OFF.h"
#include "gpio.h"
#include "key.h"
#include "delay.h"

void PWR_ON_OFF(void)
{
	if(KEY0 == GPIO_PIN_RESET)
	{
		HAL_Delay(50);
		while(!KEY0);//�ȴ������ɿ�
		HAL_GPIO_WritePin(POWER_CTR_GPIO_Port,POWER_CTR_Pin, GPIO_PIN_RESET);
	
	}



}


