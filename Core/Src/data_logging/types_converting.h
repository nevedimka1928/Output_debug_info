/**
  ******************************************************************************
  * @file           : types_converting.h
  * @brief          : Header for types_converting.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 18, 2022
  *
  ******************************************************************************
  */
#ifndef SRC_DATA_LOGGING_TYPES_CONVERTING_H_
#define SRC_DATA_LOGGING_TYPES_CONVERTING_H_


/* Includes ------------------------------------------------------------------*/
#include "common.h"

//#include "ring_buffer.h"

/* Private defines -----------------------------------------------------------*/
#define MAX_STRING_SIZE	  10

/* Exported types ------------------------------------------------------------*/


/**
  * @brief  Common Buffer Structure - wrap for buffer type
  */
typedef struct
{
	uint8_t RealyStringSize;
	char RegularBuffer[MAX_STRING_SIZE];

} IntAsString_t;

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/



#endif /* SRC_DATA_LOGGING_TYPES_CONVERTING_H_ */
