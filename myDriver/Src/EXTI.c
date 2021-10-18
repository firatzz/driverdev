/*
 * EXTI.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Firat
 */
#include "EXTI.h"


/**
  * @brief  EXTI_Init configures the port and line number
  * @param  EXTI_InitStruct = User Config Structure
  *
  * @retval Void
  */

void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct)
{
	uint32_t tempValue = 0;

	tempValue = (uint32_t)EXTI_BASE_ADDR;

	EXTI->IMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
	EXTI->EMR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	if (EXTI_InitStruct->EXTI_LineCmd != DISABLE)
	{
		tempValue += EXTI_InitStruct->EXTI_Mode;

		*(__IO uint32_t *)tempValue = (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue = (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		if (EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF)
		{
			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}
		else
		{
			tempValue += EXTI_InitStruct->TriggerSelection;
			*(__IO uint32_t *)tempValue = (0x1U << EXTI_InitStruct->EXTI_LineNumber);
		}
	}
	else
	{
		tempValue = (uint32_t)EXTI_BASE_ADDR;
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*(__IO uint32_t *)tempValue &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	}
}


/**
  * @brief  EXTI_LineConfig configures the port and the pin for SYSCFG
  * @param  PortSource = PORT Value A - I @def_group PORT_Values
  *
  * @param  EXTI_LineSource PIN numbers & Line numbers @def_group  EXTI_Line_Values
  *
  * @retval Void
  */

void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource)
{
	uint32_t tempValue;

	tempValue = SYSCFG->EXTI_CR[EXTI_LineSource >> 2];			/*Divide by 4 to find which EXTICR*/
	tempValue &= ~(0xFU << (EXTI_LineSource & 0x3U) * 4);		/*Clear bits*/
	tempValue = (PortSource << (EXTI_LineSource & 0x3U ) * 4);  /*Mode by 8 and find exact pin and write port source*/
	SYSCFG->EXTI_CR[EXTI_LineSource >> 2] = tempValue;
}


/**
  * @brief  NVIC_EnableInterrupt
  * @param  IRQNumber = IRQ Number of Line
  *
  * @retval Void
  */

void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber)
{
	uint32_t tempValue = 0;

	tempValue = *( (IRQNumber >> 5U) + NVIC_ISER0 );		//Get NVIC register
	tempValue &= ~(1U << (IRQNumber & 0x1FU)); 				//Mode(5) of IRQ and clear
	tempValue |= (1U << (IRQNumber & 0x1FU));				//set to enable
	*( (IRQNumber >> 5U) + NVIC_ISER0 ) = tempValue;
}





















