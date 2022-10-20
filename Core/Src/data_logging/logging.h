/**
  ******************************************************************************
  * @file           : logging.h
  * @brief          : Header for logging.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 18, 2022
  *
  ******************************************************************************
  */

#ifndef SRC_DATA_LOGGING_LOGGING_H_
#define SRC_DATA_LOGGING_LOGGING_H_

/* Includes ------------------------------------------------------------------*/
//#include <stdint.h>
//#include <stddef.h>

#include "ring_buffer.h"

/* Private defines -----------------------------------------------------------*/
#define REGULAR_BUFFER_SIZE	  256

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Buffer Type
  */
typedef enum
{
    REGULAR_BUFFER = 0U,
    RING_BUFFER_RX = 1U,
	RING_BUFFER_TX = 2U
} BufferType_t;

/**
  * @brief  Common Buffer Structure - wrap for buffer type
  */
typedef struct
{
	RingBuffer_t* RingBuffer;
	char (*RegularBuffer)[REGULAR_BUFFER_SIZE];
	BufferType_t BufferType;

} CommonBuffer_t;

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/



#endif /* SRC_DATA_LOGGING_LOGGING_H_ */
