/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "PWR_ON_OFF.h"
#include "tim.h"
#include "Solenoid_adj_Hz.h"
#include "string.h"
#include "stdio.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId PWR_TaskHandle;
osThreadId KEY_TaskHandle;
osThreadId LED_TaskHandle;
osThreadId FAN_TaskHandle;
osThreadId NTC_B3950_TaskHandle;
osThreadId heater_TaskHandle;
osThreadId Solenoid_adj_HzHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Start_PWR_Task(void const * argument);
void Start_KEY_Task(void const * argument);
void Start_LED_Task(void const * argument);
void Start_FAN_Task(void const * argument);
void Start_NTC_B3950_Task(void const * argument);
void Start_heater_Task(void const * argument);
void Start_Solenoid_adj_Hz(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of PWR_Task */
  osThreadDef(PWR_Task, Start_PWR_Task, osPriorityNormal, 0, 128);
  PWR_TaskHandle = osThreadCreate(osThread(PWR_Task), NULL);

  /* definition and creation of KEY_Task */
  osThreadDef(KEY_Task, Start_KEY_Task, osPriorityIdle, 0, 128);
  KEY_TaskHandle = osThreadCreate(osThread(KEY_Task), NULL);

  /* definition and creation of LED_Task */
  osThreadDef(LED_Task, Start_LED_Task, osPriorityIdle, 0, 128);
  LED_TaskHandle = osThreadCreate(osThread(LED_Task), NULL);

  /* definition and creation of FAN_Task */
  osThreadDef(FAN_Task, Start_FAN_Task, osPriorityIdle, 0, 128);
  FAN_TaskHandle = osThreadCreate(osThread(FAN_Task), NULL);

  /* definition and creation of NTC_B3950_Task */
  osThreadDef(NTC_B3950_Task, Start_NTC_B3950_Task, osPriorityIdle, 0, 128);
  NTC_B3950_TaskHandle = osThreadCreate(osThread(NTC_B3950_Task), NULL);

  /* definition and creation of heater_Task */
  osThreadDef(heater_Task, Start_heater_Task, osPriorityIdle, 0, 128);
  heater_TaskHandle = osThreadCreate(osThread(heater_Task), NULL);

  /* definition and creation of Solenoid_adj_Hz */
  osThreadDef(Solenoid_adj_Hz, Start_Solenoid_adj_Hz, osPriorityIdle, 0, 128);
  Solenoid_adj_HzHandle = osThreadCreate(osThread(Solenoid_adj_Hz), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Start_PWR_Task */
/**
  * @brief  Function implementing the PWR_Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Start_PWR_Task */
void Start_PWR_Task(void const * argument)
{
  /* USER CODE BEGIN Start_PWR_Task */
  /* Infinite loop */
  for(;;)
  {
	  PWR_ON_OFF();//关机操作
      osDelay(20);
  }
  /* USER CODE END Start_PWR_Task */
}

/* USER CODE BEGIN Header_Start_KEY_Task */
/**
* @brief Function implementing the KEY_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_KEY_Task */
void Start_KEY_Task(void const * argument)
{
  /* USER CODE BEGIN Start_KEY_Task */
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
      osDelay(500);
  }
  /* USER CODE END Start_KEY_Task */
}

/* USER CODE BEGIN Header_Start_LED_Task */
/**
* @brief Function implementing the LED_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_LED_Task */
void Start_LED_Task(void const * argument)
{
  /* USER CODE BEGIN Start_LED_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Start_LED_Task */
}

/* USER CODE BEGIN Header_Start_FAN_Task */
/**
* @brief Function implementing the FAN_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_FAN_Task */
void Start_FAN_Task(void const * argument)
{
  /* USER CODE BEGIN Start_FAN_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Start_FAN_Task */
}

/* USER CODE BEGIN Header_Start_NTC_B3950_Task */
/**
* @brief Function implementing the NTC_B3950_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_NTC_B3950_Task */
void Start_NTC_B3950_Task(void const * argument)
{
  /* USER CODE BEGIN Start_NTC_B3950_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Start_NTC_B3950_Task */
}

/* USER CODE BEGIN Header_Start_heater_Task */
/**
* @brief Function implementing the heater_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_heater_Task */
void Start_heater_Task(void const * argument)
{
  /* USER CODE BEGIN Start_heater_Task */
  /* Infinite loop */
  for(;;)
  {
	printf("n的值是：%d\r\n",n);
    osDelay(500);
  }
  /* USER CODE END Start_heater_Task */
}

/* USER CODE BEGIN Header_Start_Solenoid_adj_Hz */
/**
* @brief Function implementing the Solenoid_adj_Hz thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Solenoid_adj_Hz */
void Start_Solenoid_adj_Hz(void const * argument)
{
  /* USER CODE BEGIN Start_Solenoid_adj_Hz */
  /* Infinite loop */
  for(;;)
  {
    Solenoid_adj_Hz();
  }
  /* USER CODE END Start_Solenoid_adj_Hz */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
