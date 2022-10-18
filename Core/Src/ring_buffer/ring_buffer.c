/**
  ******************************************************************************
  * @file    ring_buffer.c
  * @brief   Ring Buffer Module.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 18, 2022
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ring_buffer.h"
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/

#define UART_RX_BUFFER_SIZE    256	  /*!< size of RX Ring Buffer */
#define UART_TX_BUFFER_SIZE    256	  /*!< size of TX Ring Buffer */

/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
static uint8_t RxRingBuffer[UART_RX_BUFFER_SIZE];
static uint8_t TxRingBuffer[UART_TX_BUFFER_SIZE];

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


/* External functions --------------------------------------------------------*/

/**
  * @brief Initialization Function of Ring Buffer Structure
  * @param Type: type of UART
  * @param RingBuffer: pointer to ring buffer structure
  * @retval Status RB initialization
  */
StatusFunctionExecution_t initializeRingBuffer(UartBuffer_t Type, RingBuffer_t* NewRingBuffer)
{
	if((UART_RX_BUFFER_SIZE > MAX_SIZE_DMA_BUFFER) || (UART_RX_BUFFER_SIZE < 1) || (NewRingBuffer == NULL))
	{
		return INVALID_PARAMS;
	}

	if (Type == RX_BUFFER)
	{
		NewRingBuffer->Length = UART_RX_BUFFER_SIZE;
		NewRingBuffer->Head = RxRingBuffer;
		NewRingBuffer->InputItem = RxRingBuffer;
		NewRingBuffer->NumberOfItems = 0;
	}
	else if (Type == TX_BUFFER)
	{
		NewRingBuffer->Length = UART_TX_BUFFER_SIZE;
		NewRingBuffer->Head = TxRingBuffer;
		NewRingBuffer->InputItem = TxRingBuffer;
		NewRingBuffer->NumberOfItems = 0;
	}
	else
	{
		return ERROR_STATUS;
	}

	return OK_STATUS;
}

/**
  * @brief Decrease Number of Items of Ring Buffer
  * @param RingBuffer: pointer to ring buffer structure
  * @param Number: Number of items
  * @retval Status function
  */
StatusFunctionExecution_t decreaseNumberItems(RingBuffer_t* RingBuffer, uint16_t Number)
{
	if (RingBuffer == NULL)
	{
		return INVALID_PARAMS;
	}

	if (Number > RingBuffer->NumberOfItems)
	{
		return ERROR_STATUS;
	}

	RingBuffer->NumberOfItems -= Number;

	return OK_STATUS;
}

/**
  * @brief Decrease Number of Items of Ring Buffer
  * @param RingBuffer: pointer to ring buffer structure
  * @param Number: Number of items
  * @retval Status function
  */
StatusFunctionExecution_t putRBValue(RingBuffer_t* RingBuffer, uint8_t val)
{

    if(RingBuffer == NULL)
    {
    	return INVALID_PARAMS;
    }

    *(RingBuffer->InputItem) = val;  // запись нового значения в КБ
    RingBuffer->InputItem++;  // инкремент позиции
    if (RingBuffer->InputItem >= (RingBuffer->Head + RingBuffer->Length))
    {
    	RingBuffer->InputItem = RingBuffer->Head;  // установка позиции в 0, при выходе за пределы
    }
    if (RingBuffer->NumberOfItems < RingBuffer->Length)
    {
    	RingBuffer->NumberOfItems++;  // инкремент кол-ва эл-тов
    }

    return OK_STATUS;
}




