/**
  ******************************************************************************
  * @file           : common.h
  * @brief          : Header for project files.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  *
  * Created on: Oct 18, 2022
  * Author: dmitriy
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef INC_COMMON_H_
#define INC_COMMON_H_


/* Includes ------------------------------------------------------------------*/


/* Private includes ----------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Result value update
  */
typedef enum
{
    OK_STATUS = 0U,
    INVALID_PARAMS = 1U,
    ERROR_STATUS = 2U
} StatusFunctionExecution_t;

/**
  * @brief  Buffer Type
  */
typedef enum
{
    RX_BUFFER = 0U,
    TX_BUFFER = 1U
} UartBuffer_t;

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/

/****************** Function State : check Function OK state ****************************/
#define IS_RESULT_OK(FUNCTION_STATE)    ((FUNCTION_STATE) == OK_STATUS)

/* Exported functions prototypes ---------------------------------------------*/


/* Private defines -----------------------------------------------------------*/

#endif /* INC_COMMON_H_ */
