/*
 * SPI.c
 *
 *  Created on: Oct 19, 2021
 *      Author: Firat
 */


#include "../Inc/SPI.h"


/**
  * @brief  SPI_Init configures the SPI Peripherals
  * @param  SPI_Handle = User Config Structure
  *
  * @retval Void
  */

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle)
{
	uint32_t tempValue = 0;

	tempValue = SPI_Handle->Instance->CR1;

	tempValue |= (SPI_Handle->Init.BaudRate) 	| \
			     (SPI_Handle->Init.CPHA)     	| \
			     (SPI_Handle->Init.CPOL)     	| \
				 (SPI_Handle->Init.DFF_Format)  | \
				 (SPI_Handle->Init.Mode) 		| \
				 (SPI_Handle->Init.FrameFormat) | \
				 (SPI_Handle->Init.BusConfig)	| \
				 (SPI_Handle->Init.SSM_Cmd);

	SPI_Handle->Instance->CR1 = tempValue;


}

/**
  * @brief  SPI_Init configures the SPI Peripherals
  * @param  SPI_Handle = User Config Structure
  *
  * @param stateOfSPI = ENABLE or DISABLE
  * @retval Void
  */

void SPI_PeriphCmd(SPI_HandleTypeDef_t *SPI_Handle, FunctionalState_t stateOfSPI)
{
	if(stateOfSPI == ENABLE)
	{
		SPI_Handle->Instance->CR1 |= (0x1U << SPI_CR1_SPE);
	}
	else
	{
		SPI_Handle->Instance->CR1 &= ~(0x1U << SPI_CR1_SPE);
	}

}

/**
  * @brief  SPI_TransmitData transmits the data to slave
  *
  * @param  SPI_Handle = User Config Structure
  *
  * @param pData = Address of data to be sent
  *
  * @param sizeOfData = Length of your data in bytes
  *
  * @retval Void
  */

void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *pData, uint16_t sizeOfData)
{
	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS)
	{
		while(sizeOfData > 0)
		{
			if( (SPI_GetFlagStatus(SPI_Handle, SPI_TXE_FLAG)))
			{
				SPI_Handle->Instance->DR = *((uint16_t*)pData);
				pData += sizeof(uint16_t);
				sizeOfData -= 2;
			}
		}
	}
	else
	{
		while(sizeOfData > 0)
		{
			if( (SPI_GetFlagStatus(SPI_Handle, SPI_TXE_FLAG)))
			{
				SPI_Handle->Instance->DR = *pData;
				pData++;
				sizeOfData--;
			}
		}
	}

	while(SPI_GetFlagStatus(SPI_Handle, SPI_Busy_FLAG)); //Wait for Busy Flag
}

/**
  * @brief  SPI_ReceiveData receive data from slave
  *
  * @param  SPI_Handle = User Config Structure
  *
  * @param pData = Address of data to store the values
  *
  * @param sizeOfData = Length of your data in bytes
  *
  * @retval Void
  */


void SPI_ReceiveData(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *pBuffer, uint16_t sizeOfData)
{

	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS)
	{
		while(sizeOfData > 0)
		{
			if( (SPI_GetFlagStatus(SPI_Handle, SPI_RXNE_FLAG)))
			{
				*((uint16_t*)pBuffer) = (uint16_t)SPI_Handle->Instance->DR;
				pBuffer += sizeof(uint16_t);
				sizeOfData -= 2;
			}
		}
	}
	else
	{
		while(sizeOfData > 0)
		{
			if( (SPI_GetFlagStatus(SPI_Handle, SPI_RXNE_FLAG)))
			{
				*(pBuffer) = *((__IO uint8_t*)&SPI_Handle->Instance->DR);
				pBuffer++;
				sizeOfData--;
			}
		}
	}
}

/**
  * @brief  SPI_GetFlagStatus configures the SPI Peripherals
  *
  * @param  SPI_Handle = User Config Structure
  *
  * @param SPI_Flag = Flag name of SR register
  *
  * @retval SPI_FlagStatus_t
  */
SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle, uint16_t SPI_Flag)
{
	return (SPI_Handle->Instance->SR & SPI_Flag) ? SPI_FLAG_SET : SPI_FLAG_RESET;
}
























