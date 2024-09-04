#include "PWR_ON.h"
#include "gpio.h"
#include "key.h"
#include "delay.h"
#include "main.h"

void PWR_ON(void)
{
	
	HAL_GPIO_WritePin(POWER_CTR_GPIO_Port,POWER_CTR_Pin,GPIO_PIN_SET);//按键通电就开启控制12V的IO，进行开机
    HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_SET);//开机的蜂鸣器提示音
    HAL_Delay(500);
    HAL_GPIO_WritePin(BEEP_GPIO_Port,BEEP_Pin,GPIO_PIN_RESET);//延迟500ms后，关闭的蜂鸣器提示音

}


