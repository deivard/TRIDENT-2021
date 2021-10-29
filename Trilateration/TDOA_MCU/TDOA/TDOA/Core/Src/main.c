/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//Possible states of the system
enum State{S1_Estimation, S2_Estimation, S3_Estimation, PairPhase, Transmit};
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
//Current state of the system
enum State state = S1_Estimation;

//Timestamp datastructures for the sensors
Timestamps ts1;
Timestamps ts2;
Timestamps ts3;

//Current sensor that is sampling
uint8_t samplingSensor = 0;

//Period in samples of one wavelength
double period = 6263;
double periodS[3];

//Middle points of rising and falling edge for sensors
uint32_t midPoints1[SAMPLE_SIZE-1];
uint32_t midPoints2[SAMPLE_SIZE-1];
uint32_t midPoints3[SAMPLE_SIZE-1];

//Shift of middle points
double midPointShift[SAMPLE_SIZE-1];

//Midpoint smart selection variables
uint16_t cntRising = 0;
uint16_t cntFalling = 0;
uint16_t midPointCount = 0;
uint16_t dist;

//Average shift of the different sensors
double meanShiftS1;
double meanShiftS2;
double meanShiftS3;

//Time difference of arrival
double TDOA12;
double TDOA13;

double TDOA12mean;
double TDOA13mean;
uint16_t TDOACount;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
void Get_Mid_Points(Timestamps* t, uint32_t* midpoints);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	ts = &ts1;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  HAL_NVIC_DisableIRQ(EXTI0_IRQn);
  HAL_NVIC_DisableIRQ(EXTI3_IRQn);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  __HAL_TIM_ENABLE(&htim2);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  switch(state){
	  	  case S1_Estimation:
	  		  if(ts1.riseCount == SAMPLE_SIZE && ts1.fallCount == SAMPLE_SIZE){

	  			  Get_Mid_Points(&ts1, midPoints1);
	  			  for(int i = 0; i < midPointCount-1; i++){
	  				  periodS[0] = periodS[0] + midPoints1[i+1] - midPoints1[i];
	  			  }
	  			  periodS[0] = periodS[0]/(midPointCount-1);
	  			  for(int i = 0; i < midPointCount;i++){
	  				  midPointShift[i] = fmod(midPoints1[i]+period/2,period)-period/2;
	  				  meanShiftS1 = meanShiftS1 + midPointShift[i] / midPointCount;
	  			  }

	  			  state = S2_Estimation;
	  		  }
	  		  break;
	  	  case S2_Estimation:
	  		  if(ts2.riseCount == SAMPLE_SIZE && ts2.fallCount == SAMPLE_SIZE){
	  			  Get_Mid_Points(&ts2,midPoints2);

	  			  for(int i = 0; i < midPointCount-1; i++){
	  				  periodS[1] = periodS[1] + midPoints2[i+1] - midPoints2[i];
	  			  }
	  			  periodS[1] = periodS[1]/(midPointCount-1);

	  			  for(int i = 0; i < midPointCount;i++){
	  				  midPointShift[i] = fmod(midPoints2[i]+period/2,period)-period/2;
	  				  meanShiftS2 = meanShiftS2 + midPointShift[i] / midPointCount;
	  			  }

	  			  state = S3_Estimation;
	  		  }
	  		  break;

	  	  case S3_Estimation:
	  		  if(ts3.riseCount == SAMPLE_SIZE && ts3.fallCount == SAMPLE_SIZE){

	  			  Get_Mid_Points(&ts3,midPoints3);

	  			  for(int i = 0; i < midPointCount-1; i++){
	  				  periodS[2] = periodS[2] + midPoints3[i+1] - midPoints3[i];
				  }
				  periodS[2] = periodS[2]/(midPointCount-1);

	  			  for(int i = 0; i < midPointCount;i++){
	  				  midPointShift[i] = fmod(midPoints3[i]+period/2,period)-period/2;
	  				  meanShiftS3 = meanShiftS3 + midPointShift[i] / midPointCount;
	  			  }
	  			  state = PairPhase;
	  		  }
	  		  break;
	  	  case PairPhase:
	  		  TDOA12 = fmod(meanShiftS2-meanShiftS1+period/2,period) - period/2;
	  		  TDOA13 = fmod(meanShiftS3-meanShiftS1+period/2,period) - period/2;
	  		  TDOA12mean = TDOA12mean + TDOA12;
	  		  TDOA13mean = TDOA13mean + TDOA13;
	  		  TDOACount = TDOACount + 1;
	  		  if(TDOACount == 3){
	  			  TDOA12mean = TDOA12mean/3;
	  			  TDOA13mean = TDOA13mean/3;
	  			  TDOACount = 0;
	  			  TDOA12mean = 0;
	  			  TDOA13mean = 0;
	  		  }
	  		  state = Transmit;
	  		  break;
	  	  case Transmit:

	  		  state = S1_Estimation;
	  		  meanShiftS1 = 0;
	  		  meanShiftS2 = 0;
	  		  meanShiftS3 = 0;
	  		  ts1.riseCount = 0;
	  		  ts1.fallCount = 0;
	  		  ts2.riseCount = 0;
	  		  ts2.fallCount = 0;
			  ts3.riseCount = 0;
			  ts3.fallCount = 0;
//			  __HAL_RCC_TIM2_FORCE_RESET();
//			  MX_TIM2_Init();
//			  __HAL_TIM_ENABLE(&htim2);
	  		  //Turn on interrupts
	  		  break;
  	  }


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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 60;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : S1Rise_Pin */
  GPIO_InitStruct.Pin = S1Rise_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(S1Rise_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : S1Fall_Pin */
  GPIO_InitStruct.Pin = S1Fall_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(S1Fall_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_USART1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_UART4;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

}

/* USER CODE BEGIN 4 */
void Sensor_Multiplex_Control(void){
	if(ts->fallCount == SAMPLE_SIZE && ts->riseCount == SAMPLE_SIZE)
	{
		switch(samplingSensor){
		case 0:
			samplingSensor = 1;
			//Switch Multiplexer
			ts = &ts2;
			//HAL_NVIC_EnableIRQ(EXTI0_IRQn);
			//HAL_NVIC_EnableIRQ(EXTI3_IRQn);
			break;
		case 1:
			samplingSensor = 2;
			//Switch Multiplexer
			ts = &ts3;
			//HAL_NVIC_EnableIRQ(EXTI0_IRQn);
			//HAL_NVIC_EnableIRQ(EXTI3_IRQn);
			break;
		case 2:
			samplingSensor = 0;
			ts = &ts1;
			//Switch Multiplexer
			break;
		}
	}
}

void Get_Mid_Points(Timestamps* t, uint32_t* midpoints){
	cntRising = 1;
	cntFalling = 1;
	midPointCount = 0;
	while(cntRising <= SAMPLE_SIZE-1 && cntFalling < SAMPLE_SIZE-1){
		dist = t->fallStamps[cntFalling] - t->riseStamps[cntRising];
		while(dist < 0 && t->fallStamps[cntFalling] < SAMPLE_SIZE-1){
			cntFalling = cntFalling + 1;
			dist = t->fallStamps[cntFalling] - t->riseStamps[cntRising];
		}

		while(cntFalling < SAMPLE_SIZE-1 && t->fallStamps[cntFalling+1] - t->riseStamps[cntRising] <= dist){
			cntFalling = cntFalling + 1;
			dist = t->fallStamps[cntFalling] - t->riseStamps[cntRising];
		}
		if(dist >= 0){
			midpoints[midPointCount] = t->riseStamps[cntRising] + dist/2;
			if(cntRising < SAMPLE_SIZE-1 && cntFalling < SAMPLE_SIZE-1){
				cntRising = cntRising + 1;
				midPointCount = midPointCount + 1;
			}
		}

	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
