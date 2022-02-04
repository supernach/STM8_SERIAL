#ifndef SERIAL_CONFIG_H
#define SERIAL_CONFIG_H

/****************************************************************************
* Title                 :   plantilla
* Filename              :   plantilla.h
* Author                :   SuperNach
* Origin Date           :   20/08/2021
* Version               :   1.0.0
* Compiler              :   Cosmic C
* Target                :   STM8
* Copyright             :   
* All Rights Reserved
*
* AQUI VA DECLARACIONES DERECHOS
*
*******************************************************************************/
/****************************************************************************
* Doxygen C Template
* Copyright (c) 2013 - Jacob Beningo - All Rights Reserved
*
* Feel free to use this Doxygen Code Template at your own risk for your own
* purposes.  The latest license and updates for this Doxygen C template can be
* found at www.beningo.com or by contacting Jacob at jacob@beningo.com.
*
* For updates, free software, training and to stay up to date on the latest
* embedded software techniques sign-up for Jacobs newsletter at
* http://www.beningo.com/814-2/
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template.
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
*  20/08/21   1.0.0   SuperNach       Initial Release.
*  
*
*******************************************************************************/
/** @file plantilla.h
 *  @brief 
 */

/** @addtogroup PLANTILLA
  * @{
  */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stm8s.h>
#include <gpio.h>


/******************************************************************************
* Constants
*******************************************************************************/

/******************************************************************************
* Configuration
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
* @typedef UART_Config_t
* @brief <descripcion>
*
* @see UART_Config
*/
typedef struct Serial_Config Serial_Config_t;


/******************************************************************************
* Struct
*******************************************************************************/
struct Serial_Config_Hw_Gpio
{
	Gpio_Config_t RX; /**<  */
	Gpio_Config_t TX; /**<  */
};

struct Serial_Config_Hw
{
	 UART1_StopBits_TypeDef StopBit; /**<  */
	 UART1_Parity_TypeDef Paridad; /**<  */
	 UART1_WordLength_TypeDef Bits; /**<  */
	 uint32_t Baudios; /**<  */
};

/**
* @struct UART_Config
* @brief 
*
* @see
*/
struct Serial_Config
{
	struct Serial_Config_Hw HW; /**<  */
	struct Serial_Config_Hw_Gpio IO; /**<  */
	UART1_Mode_TypeDef Modo; /**<  */
};


/******************************************************************************
* Variables
*******************************************************************************/
/**
* @var 
* @brief 
*
* @see
*/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void Serial_Config_Init( Serial_Config_t* config, const uint16_t baudios );

#ifdef __cplusplus
} // extern "C"
#endif 

#endif

/**
  * @}
  */