
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
//osThreadId defaultTaskHandle;
TaskHandle_t Task1Handle, Task2Handle, Task3Handle, Task4Handle, Task5Handle;
SemaphoreHandle_t xSemaphore1, xSemaphore2, xSemaphore3, xSemaphore4, xSemaphore5 = NULL;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
//void StartDefaultTask(void const * argument);
void Task_1(void * argument);
void Task_2(void * argument);
void Task_3(void * argument);
void Task_4(void * argument);
void Task_5(void * argument);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
		//========================
		/* Attempt to create a semaphore. */     
		vSemaphoreCreateBinary(xSemaphore1);		
		if( xSemaphore1 == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to         be created successfully. */
				 while (1);    
		}     
		xSemaphoreGive( xSemaphore1 );

		/* Attempt to create a semaphore. */     
		vSemaphoreCreateBinary(xSemaphore2);		
		if( xSemaphore2 == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to         be created successfully. */
				 while (1);    
		}
		xSemaphoreGive( xSemaphore2 );

		/* Attempt to create a semaphore. */     
		vSemaphoreCreateBinary(xSemaphore3);		
		if( xSemaphore3 == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to         be created successfully. */
				 while (1);    
		}
		xSemaphoreGive( xSemaphore3 );
		
		/* Attempt to create a semaphore. */     
		vSemaphoreCreateBinary(xSemaphore4);		
		if( xSemaphore4 == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to         be created successfully. */
				 while (1);    
		}
		xSemaphoreGive( xSemaphore4 );

		/* Attempt to create a semaphore. */     
		vSemaphoreCreateBinary(xSemaphore5);		
		if( xSemaphore5 == NULL ) 
		{    /* There was insufficient FreeRTOS heap available for the semaphore to         be created successfully. */
				 while (1);    
		}
		xSemaphoreGive( xSemaphore5 );
		/* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
//  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
//  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

      xTaskCreate(Task_1, "Task 1", 64, 0, osPriorityNormal, &Task1Handle);
      xTaskCreate(Task_2, "Task 2", 64, 0, osPriorityNormal, &Task2Handle);
      xTaskCreate(Task_3, "Task 3", 64, 0, osPriorityNormal, &Task3Handle);
      xTaskCreate(Task_4, "Task 4", 64, 0, osPriorityNormal, &Task4Handle);
      xTaskCreate(Task_5, "Task 5", 64, 0, osPriorityNormal, &Task5Handle);


  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
      vTaskStartScheduler();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}

/* USER CODE BEGIN 4 */

#define SIZE_BUF 100
volatile static unsigned char buf [SIZE_BUF];

//=================================================================
void fill_buf (unsigned char v)
{ 
  volatile int i, c;
  
      for (i = 0; i < SIZE_BUF; i++)
      {
        c = 500;
        buf [i] = v;
        while (c--);
      }
}

//=================================================================

/* USER CODE END 4 */

/* USER CODE BEGIN */
/**
  * @brief  Function implementing the task1.
  * @param  argument: Not used 
  * @retval None
  */
//=================================================================
void Task_1(void * argument)
{
  volatile int i;
	
  /* Infinite loop */
  for(;;)
  {
		if( xSemaphoreTake( xSemaphore1, 10 ) == pdTRUE)
		{
			vTaskDelay(2);
			if( xSemaphoreTake( xSemaphore2, 10 ) == pdTRUE)
			{
				//do someting
				xSemaphoreGive( xSemaphore2 );
			}
			xSemaphoreGive( xSemaphore1 );
		}
		else
		{
			xSemaphoreGive( xSemaphore2 );
		}
  }
}

//=================================================================

/* USER CODE BEGIN */
/**
  * @brief  Function implementing the task2.
  * @param  argument: Not used 
  * @retval None
  */
//=================================================================
void Task_2(void * argument)
{
  volatile int i;
	
  /* Infinite loop */
  for(;;)
  {
		if( xSemaphoreTake( xSemaphore2, 10 ) == pdTRUE)
		{
			vTaskDelay(2);
			if( xSemaphoreTake( xSemaphore3, 10 ) == pdTRUE)
			{
				//do someting
				xSemaphoreGive( xSemaphore3 );
			}
			xSemaphoreGive( xSemaphore2 );
		}
		else
		{
			xSemaphoreGive( xSemaphore3 );
		}
  }
}

//=================================================================
/* USER CODE BEGIN */
/**
  * @brief  Function implementing the task3.
  * @param  argument: Not used 
  * @retval None
  */
//=================================================================
void Task_3(void * argument)
{
  volatile int i;
	
  /* Infinite loop */
  for(;;)
  {
		if( xSemaphoreTake( xSemaphore3, 10 ) == pdTRUE)
		{
			vTaskDelay(2);
			if( xSemaphoreTake( xSemaphore4, 10 ) == pdTRUE)
			{
				//do someting
				xSemaphoreGive( xSemaphore4 );
			}
			xSemaphoreGive( xSemaphore3 );
		}
		else
		{
			xSemaphoreGive( xSemaphore4 );
		}
  }
}

//=================================================================
/* USER CODE BEGIN */
/**
  * @brief  Function implementing the task4.
  * @param  argument: Not used 
  * @retval None
  */
//=================================================================
void Task_4(void * argument)
{
  volatile int i;
	
  /* Infinite loop */
  for(;;)
  {
		if( xSemaphoreTake( xSemaphore4, 10 ) == pdTRUE)
		{
			vTaskDelay(2);
			if( xSemaphoreTake( xSemaphore5, 10 ) == pdTRUE)
			{
				//do someting
				xSemaphoreGive( xSemaphore5 );
			}
			xSemaphoreGive( xSemaphore4 );
		}
		else
		{
			xSemaphoreGive( xSemaphore5 );
		}
  }
}

//=================================================================
/* USER CODE BEGIN */
/**
  * @brief  Function implementing the task5.
  * @param  argument: Not used 
  * @retval None
  */
//=================================================================
void Task_5(void * argument)
{
  volatile int i;
	
  /* Infinite loop */
  for(;;)
  {
		if( xSemaphoreTake( xSemaphore5, 10 ) == pdTRUE)
		{
			vTaskDelay(2);
			if( xSemaphoreTake( xSemaphore1, 10 ) == pdTRUE)
			{
				//do someting
				xSemaphoreGive( xSemaphore1 );
			}
			xSemaphoreGive( xSemaphore5 );
		}
		else
		{
			xSemaphoreGive( xSemaphore1 );
		}
  }
}

//=================================================================
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
