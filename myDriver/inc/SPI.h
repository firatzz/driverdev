/*
 * SPI.h
 *
 *  Created on: Oct 19, 2021
 *      Author: firat.sonmez
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stm32f407xx.h"

/*
 * @def_group SPI_BaudRates
 *
 * */

#define SPI_BAUDRATE_DIV2			( (uint32_t)(0x00000000) )
#define SPI_BAUDRATE_DIV4			( (uint32_t)(0x00000008) )
#define SPI_BAUDRATE_DIV8			( (uint32_t)(0x00000010) )
#define SPI_BAUDRATE_DIV16			( (uint32_t)(0x00000018) )
#define SPI_BAUDRATE_DIV32			( (uint32_t)(0x00000020) )
#define SPI_BAUDRATE_DIV64			( (uint32_t)(0x00000028) )
#define SPI_BAUDRATE_DIV128			( (uint32_t)(0x00000030) )
#define SPI_BAUDRATE_DIV256			( (uint32_t)(0x00000038) )

/*
 * @def_group CPHA_Values
 *
 * */

#define SPI_CPHA_FIRST				( (uint32_t)(0x00000000) )
#define SPI_CPHA_SECOND				( (uint32_t)(0x00000001) )

/*
 * @def_group CPOL_Values
 *
 * */

#define SPI_CPOL_LOW				( (uint32_t)(0x00000000) )
#define SPI_CPOL_HIGH				( (uint32_t)(0x00000002) )

/*
 * @def_group DFF_Values
 *
 * */

#define SPI_DFF_8BITS				( (uint32_t)(0x00000000) )
#define SPI_DFF_16BITS				( (uint32_t)(0x00000800) )

/*
 * @def_group Mode_Values
 *
 * */

#define SPI_MODE_MASTER				( (uint32_t)(0x00000004) )
#define SPI_MODE_SLAVE				( (uint32_t)(0x00000000) )

/*
 * @def_group FF_Values
 *
 * */

#define SPI_FRAMEFORMAT_MSB			( (uint32_t)(0x00000000) )
#define SPI_FRAMEFORMAT_LSB			( (uint32_t)(0x00000080) )

/*
 * @def_group BusConfig_Values
 *
 * */

#define SPI_BUS_FULLDUPLEX			( (uint32_t)(0x00000000) )
#define SPI_BUS_RECEIVEONLY			( (uint32_t)(0x00000400) )
#define SPI_BUS_HALFDUPLEX_T		( (uint32_t)(0x0000C000) )
#define SPI_BUS_HALFDUPLEX_R		( (uint32_t)(0x00008000) )

/*
 * @def_group SSM_Values
 *
 * */

#define SPI_SSM_DISABLE			( (uint32_t)(0x00000000) )
#define SPI_SSM_ENABLE			( (uint32_t)(0x00000300) )


typedef enum
{
	SPI_FLAG_RESET 	= 0x0U,
	SPI_FLAG_SET	= !SPI_FLAG_RESET
}SPI_FlagStatus_t;

typedef struct
{
	uint32_t Mode;					/*!< Mode values for SPI @def_group Mode_Values	*/
	uint32_t CPHA;					/*!< CPHA values for SPI @def_group CPHA_Values	*/
	uint32_t CPOL;					/*!< CPOL values for SPI @def_group CPOL_Values	*/
	uint32_t BaudRate;				/*!< BaudRate values for SPI @def_group SPI_BaudRates	*/
	uint32_t SSM_Cmd;				/*!< SSM Values for SPI @def_group SSM_Values	*/
    uint32_t DFF_Format;			/*!< DFF Values for SPI @def_group DFF_Values	*/
    uint32_t BusConfig;  			/*!< BusConfig values for SPI @def_group BusConfig_Values	*/
    uint32_t FrameFormat;			/*!< Frame FormatValues for SPI @def_group FF_Values	*/
}SPI_InitTypeDef_t;

typedef struct
{

	SPI_TypeDef_t *Instance;
	SPI_InitTypeDef_t Init;



}SPI_HandleTypeDef_t;


void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle);
void SPI_PeriphCmd(SPI_HandleTypeDef_t *SPI_Handle, FunctionalState_t stateOfSPI);
void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle, uint8_t *pData, uint16_t sizeOfData);
SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle, uint16_t SPI_Flag);
#endif /* INC_SPI_H_ */
