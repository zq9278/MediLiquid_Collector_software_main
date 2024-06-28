/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32g070xx.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CURRENT_OUT_Pin GPIO_PIN_0
#define CURRENT_OUT_GPIO_Port GPIOA
#define IRMA381_Pin GPIO_PIN_3
#define IRMA381_GPIO_Port GPIOA
#define BEE_Pin GPIO_PIN_4
#define BEE_GPIO_Port GPIOA
#define SV_AIR_SOURCE_Pin GPIO_PIN_7
#define SV_AIR_SOURCE_GPIO_Port GPIOA
#define SV_MAIN_PUSH_Pin GPIO_PIN_0
#define SV_MAIN_PUSH_GPIO_Port GPIOB
#define SV_DETERGENT_Pin GPIO_PIN_1
#define SV_DETERGENT_GPIO_Port GPIOB
#define SV_TAP_WATER_Pin GPIO_PIN_2
#define SV_TAP_WATER_GPIO_Port GPIOB
#define AIR_MOTOR_Pin GPIO_PIN_10
#define AIR_MOTOR_GPIO_Port GPIOB
#define CHARGE_Pin GPIO_PIN_11
#define CHARGE_GPIO_Port GPIOB
#define WATER_MOTOR_Pin GPIO_PIN_12
#define WATER_MOTOR_GPIO_Port GPIOB
#define MAGNET_Pin GPIO_PIN_13
#define MAGNET_GPIO_Port GPIOB
#define PSVHOTOELECTRIC12_Pin GPIO_PIN_14
#define PSVHOTOELECTRIC12_GPIO_Port GPIOB
#define PHOTOELECTRIC11_Pin GPIO_PIN_15
#define PHOTOELECTRIC11_GPIO_Port GPIOB
#define PHOTOELECTRIC22_Pin GPIO_PIN_6
#define PHOTOELECTRIC22_GPIO_Port GPIOC
#define PHOTOELECTRIC21_Pin GPIO_PIN_7
#define PHOTOELECTRIC21_GPIO_Port GPIOC
#define PRESURE_Pin GPIO_PIN_3
#define PRESURE_GPIO_Port GPIOD
#define RED_Pin GPIO_PIN_3
#define RED_GPIO_Port GPIOB
#define ORANGE_Pin GPIO_PIN_4
#define ORANGE_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
