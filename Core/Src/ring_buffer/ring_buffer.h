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
#include "common.h"

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Ring Buffer Structure
  */
typedef struct
{
  int16_t Length;    /*!< size of Ring Buffer */
  uint8_t* Head;    /*!< pointer to array start */
  uint8_t* InputItem;    /*!< pointer to input item */
  uint16_t NumberOfItems;      /*!< number of items */
} RingBuffer_t;

/* Exported constants --------------------------------------------------------*/
#define MAX_SIZE_DMA_BUFFER    65535U	  /*!< maximum size of DMA Buffer */

/* Exported macro ------------------------------------------------------------*/


/* Exported functions prototypes ---------------------------------------------*/
StatusFunctionExecution_t initializeRingBuffer(InterfaceBuffer_t);
StatusFunctionExecution_t decreaseNumberItems(RingBuffer_t*, uint16_t);

RingBuffer_t* getRxRingBuffer(void);
RingBuffer_t* getTxRingBuffer(void);

/* Private defines -----------------------------------------------------------*/




#endif /* SRC_DRV_UART_RING_BUFFER_H_ */
