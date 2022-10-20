/**
  ******************************************************************************
  * @file    int-char_converting.c
  * @brief   Data logging Module.
  ******************************************************************************
  *
  * Author: dmitriy
  * Created on: Oct 20, 2022
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <types_converting.h>



/* Private typedef -----------------------------------------------------------*/
/**
  * @brief  Degrees of ten
  */
typedef enum
{
	ONE_BILLION = 				1000000000U,
	ONE_HANDRED_MILLION =  		100000000U,
	TEN_MILLION =   			10000000U,
	ONE_MILLION = 	  			1000000U,
	ONE_HANDRED_THOUSAND = 		100000U,
	TEN_THOUSAND = 				10000U,
	ONE_THOUSAND = 				1000U,
	ONE_HANDRED = 				100U,
	TEN = 						10U,
	ONE = 						1U
} TenToDegree_t;

/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
static IntAsString_t    StringStructure;

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
IntAsString_t* convertIntToString(uint32_t Number)
{
	StringStructure.RealyStringSize = 0;

	for (uint8_t i = 0; i < 10; i++)
	{
		StringStructure.RegularBuffer[i] = '0';
	}

	uint8_t tempCount = 0;

	void addCharIfNotNone(TenToDegree_t TenToDegree)
	{
		uint32_t tempNumber = Number;

		tempNumber /= TenToDegree;

		if (StringStructure.RealyStringSize != 0)
		{
			tempNumber %= 10;
		}

		if (tempNumber != 0)
		{
			StringStructure.RegularBuffer[tempCount] = '0' + (char)tempNumber;
			StringStructure.RealyStringSize++;
		}

		tempCount++;
	}

	addCharIfNotNone(ONE_BILLION);
	addCharIfNotNone(ONE_HANDRED_MILLION);
	addCharIfNotNone(TEN_MILLION);
	addCharIfNotNone(ONE_MILLION);
	addCharIfNotNone(ONE_HANDRED_THOUSAND);
	addCharIfNotNone(TEN_THOUSAND);
	addCharIfNotNone(ONE_THOUSAND);
	addCharIfNotNone(ONE_HANDRED);
	addCharIfNotNone(TEN);
	addCharIfNotNone(ONE);


	return &StringStructure;
}










