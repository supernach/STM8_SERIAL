#ifndef SERIAL_INTERRUPT_H
#define SERIAL_INTERRUPT_H

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


/**
* @struct UART_IT_FLAG_e
* @brief 
*
* @see
*/
typedef enum
{
	TXE,
	RXNE
}Serial_IT_FLAG_e;


/******************************************************************************
* Struct
*******************************************************************************/
/**
* @struct UART_Config
* @brief 
*
* @see
*/


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

void Serial_Interrupt_Init( void ); 
void Serial_Interrupt_Clear( const Serial_IT_FLAG_e flag );
void Serial_Interrupt_Enable( const Serial_IT_FLAG_e flag, const ITC_PriorityLevel_TypeDef prio );
void Serial_Interrupt_Disable( const Serial_IT_FLAG_e flag );

#ifdef __cplusplus
} // extern "C"
#endif 

#endif

/**
  * @}
  */