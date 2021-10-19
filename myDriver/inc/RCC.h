/*
 * RCC.H
 *
 *  Created on: Sep 14, 2021
 *      Author: Firat
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"

/*
 * RCC AHB1 Peripherals Clock Control Macro Definitions
 * */


#define RCC_GPIOA_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_GPIOB_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_GPIOC_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_GPIOD_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_GPIOF_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOFEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_GPIOG_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);					\
												tempValue = READ_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOGEN);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_SYSCFG_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);					\
												tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);	\
												UNUSED(tempValue);											\
												}while(0)



#define RCC_GPIOA_CLK_DISABLE()					CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);
#define RCC_GPIOB_CLK_DISABLE()					CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOBEN);
#define RCC_GPIOC_CLK_DISABLE()					CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOCEN);
#define RCC_GPIOD_CLK_DISABLE()					CLEAR_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIODEN);


/*
 * RCC APB1 Peripherals Clock Control Macro Definitions
 * */

#define RCC_SP2_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);						\
												tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_SP3_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3);						\
												tempValue = READ_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3);	    \
												UNUSED(tempValue);											\
												}while(0)

#define RCC_SPI2_CLK_DISABLE()					CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2);
#define RCC_SPI3_CLK_DISABLE()					CLEAR_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI3);

/*
 * RCC APB2 Peripherals Clock Control Macro Definitions
 * */

#define RCC_SP1_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);						\
												tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);		\
												UNUSED(tempValue);											\
												}while(0)

#define RCC_SP4_CLK_ENABLE()				do{ uint32_t tempValue = 0;										\
												SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4);						\
												tempValue = READ_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4);		\
												UNUSED(tempValue);											\
												}while(0)


#define RCC_SPI1_CLK_DISABLE()					CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1);
#define RCC_SPI4_CLK_DISABLE()					CLEAR_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI4);

#endif /* INC_RCC_H_ */
