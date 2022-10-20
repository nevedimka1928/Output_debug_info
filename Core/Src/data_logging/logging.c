/**
  ******************************************************************************
  * @file    logging.c
  * @brief   Data logging Module.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 20, 2022
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "logging.h"


#ifdef SPRINTF
#include <stdio.h>
//#else
#endif
/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
static char RegularBuffer[REGULAR_BUFFER_SIZE];

/* Private function prototypes -----------------------------------------------*/


/* Private user code ---------------------------------------------------------*/


/* External variables --------------------------------------------------------*/


/* External functions --------------------------------------------------------*/

/**
  * @brief Initialization Function of Common Buffer Structure
  * @param Type: type of Buffer Structure
  * @param CommonBuffer: pointer to common buffer structure
  * @retval Status RB initialization
  */
StatusFunctionExecution_t initializeCommonBuffer(BufferType_t Type, CommonBuffer_t* CommonBuffer)
{
	if (Type == REGULAR_BUFFER)
	{
		CommonBuffer->RegularBuffer = &RegularBuffer;
	}
	else if (Type == RING_BUFFER_TX)
	{
		if (initializeRingBuffer(TX_BUFFER) == OK_STATUS)
		{
			CommonBuffer->RingBuffer = getTxRingBuffer();
		}
	}
	else if (Type == RING_BUFFER_RX)
	{
		if (initializeRingBuffer(RX_BUFFER) == OK_STATUS)
		{
			CommonBuffer->RingBuffer = getRxRingBuffer();
		}
	}
	else
	{
		return ERROR_STATUS;
	}

	CommonBuffer->BufferType = Type;

	return OK_STATUS;
}

/**
  * @brief Addition log message to buffer
  * @param Type: type of UART
  * @param RingBuffer: pointer to ring buffer structure
  * @retval Status RB initialization
  */
StatusFunctionExecution_t addLogMessage(RingBuffer_t* RingBuffer, const char *format, uint32_t Value)
{
	return OK_STATUS;
}










