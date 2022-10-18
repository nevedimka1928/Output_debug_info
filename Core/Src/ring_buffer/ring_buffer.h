/**
  ******************************************************************************
  * @file           : ring_buffer.h
  * @brief          : Header for ring_buffer.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 18, 2022
  *
  ******************************************************************************
  */

#ifndef SRC_DRV_UART_RING_BUFFER_H_
#define SRC_DRV_UART_RING_BUFFER_H_


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>

#include "common.h"

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Ring Buffer Structure
  */
typedef struct
{
  int16_t Length;    /*!< size of Ring Buffer */
  uint32_t* Head;    /*!< pointer to array start */
  uint32_t* InputItem;    /*!< pointer to input item */
  uint16_t NumberOfItems;      /*!< number of items */
} RingBuffer_t;

/* Exported constants --------------------------------------------------------*/
#define MAX_SIZE_DMA_BUFFER    65535U	  /*!< maximum size of DMA Buffer */

/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/
StatusFunctionExecution_t initializeRingBuffer(UartBuffer_t, RingBuffer_t*);


/* Private defines -----------------------------------------------------------*/




#endif /* SRC_DRV_UART_RING_BUFFER_H_ */