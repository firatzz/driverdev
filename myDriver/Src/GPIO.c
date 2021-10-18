/*
 * GPIO.c
 *
 *  Created on: Sep 14, 2021
 *      Author: Firat
 */

#include "GPIO.h"


/**
  * @brief  GPIO_Init configures the port and the pin
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  GPIO_ConfigStruct user configuration
  *
  * @retval Void
  */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_ConfigStruct)
{

	uint32_t position;
	uint32_t fakePosition = 0;
	uint32_t lastPosition = 0;

	for ( position = 0; position < 16; position++ )
	{
		fakePosition = ( 0x1U << position );
		lastPosition = (uint32_t)GPIO_ConfigStruct->pinNumber & fakePosition;

		if(fakePosition == lastPosition)
		{
				/*	MODE CONFIG	*/
				uint32_t temp = GPIOx->MODER;
				temp &= ~( 0x3U << (position *2) );
				temp |= (GPIO_ConfigStruct->Mode << (position *2));
				GPIOx->MODER = temp;

				if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF )
				{
					/*	OUTPUT TYPE CONFIG	*/
					temp = GPIOx->OTYPER;
					temp &= ~( 0x1U << position );
					temp |= (GPIO_ConfigStruct->Otype << position);
					GPIOx->OTYPER = temp;

					/*	OSPEED CONFIG	*/
					temp = GPIOx->OSPEEDR;
					temp &= ~( 0x3U << (position *2) );
					temp |= (GPIO_ConfigStruct->Speed << (position *2));
					GPIOx->OSPEEDR = temp;

				}
				/*	PUSH PULL CONFIG	*/
				temp = GPIOx->PUPDR;
				temp &= ~( 0x3U << (position *2) );
				temp |= (GPIO_ConfigStruct->PuPd << (position *2));
				GPIOx->PUPDR = temp;

		}

	}





}




/**
  * @brief  GPIO_Write_Pin sets pin high or low
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Numbers 0 - 15
  *
  * @param	pinState = GPIO_Pin_Set or GPIO_Pin_Reset
  *         the configuration information for the specified GPIO peripheral.
  * @retval Void
  */


void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState)
{
//	GPIOx->BSRR = (pinNumber | (pinNumber << 16U)) & pinState;
	if( pinState == GPIO_Pin_Set )
	{
		GPIOx->BSRR = pinNumber;
	}
	else
	{
		GPIOx->BSRR = (pinNumber << 16U );
	}

}

/**
  * @brief  GPIO_ReadPin gets pin state
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Numbers 0 - 15
  *
  * @retval GPIO_PinState_t bitStatus
  */

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if( (GPIOx->IDR & pinNumber) != GPIO_Pin_Reset)
	{
		bitStatus = GPIO_Pin_Set;
	}

	return bitStatus;
}


/**
  * @brief  GPIO_LockPin locks the pin of the GPIOx port
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Numbers 0 - 15
  *
  * @retval Void
  */

void GPIO_LockPin( GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t tempValue = (0x1U << 16U ) | pinNumber;

	GPIOx->LCKR = tempValue;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = tempValue;
	tempValue = GPIOx->LCKR;

}


/**
  * @brief  GPIO_TogglePin locks the pin of the GPIOx port
  * @param  GPIOx = GPIO Port Base Address
  *
  * @param  pinNumber = GPIO Pin Numbers 0 - 15
  *
  * @retval Void
  */

void GPIO_TogglePin( GPIO_TypeDef_t *GPIOx, uint16_t pinNumber )
{
	uint32_t tempODRRegister = GPIOx->ODR;

	GPIOx->BSRR = (tempODRRegister & pinNumber) << 16U | (~tempODRRegister & pinNumber);
}


