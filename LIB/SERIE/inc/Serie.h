#ifndef SERIAL_H
#define SERIAL_H

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
#include <stdbool.h>
#include <clock.h>
#include <gpio.h>



#include <serie_config.h>
#include <serie_interrupt.h>
#include <serie_buffer.h>

/******************************************************************************
* Constants
*******************************************************************************/
//#define SERIAL_CHECK_HW_ERROR 1

#define SERIAL_WITH_TIMEOUT 1
#ifdef SERIAL_WITH_TIMEOUT
	#include <timeout.h>
#endif
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
typedef struct Serial_t Serial_t;
typedef Serial_t* Serial_ptr;

/**
* @typedef UART_Config_t
* @brief <descripcion>
*
* @see UART_Config
*/
typedef enum
{
	SERIE_RC_STANDBY,
	SERIE_RC_EXECUTING,
	
	
	#ifdef SERIAL_WITH_TIMEOUT
		SERIE_RC_TIMEOUT,
	#endif
	
	#ifdef SERIAL_CHECK_HW_ERROR
		SERIE_RC_ERROR,
	#endif
	
	SERIE_RC_FINISHED
}Serial_Return_Code_t;

/**
* @typedef UART_Config_t
* @brief <descripcion>
*
* @see UART_Config
*/

#ifdef SERIAL_CHECK_HW_ERROR
	typedef enum
	{
		SERIE_EC_FRAMEERROR,
		SERIE_EC_NOISE,
		SERIE_EC_OVERRUN,
		ERIE_EC_PARITYERROR
	}Serial_Error_Code_t;

	typedef union
	{
		uint8_t fByte;
		struct fBit
		{
			uint8_t frameError : 1;
			uint8_t noise : 1;
			uint8_t overrun : 1;
			uint8_t parityError : 1;
			uint8_t bit4 : 1;
			uint8_t bit5 : 1;
			uint8_t bit6 : 1;
			uint8_t bit7 : 1;
		}Bit;
	}Serial_Error_t;
#endif

/******************************************************************************
* Struct
*******************************************************************************/

/**
* @struct UART_Config
* @brief 
*
* @see
*/
struct Serial_t
{
	Serial_Config_t Config;
	Serial_Buffer_t Buffer;
	Serial_Return_Code_t TX_Status;
	
	
	#ifdef SERIAL_CHECK_HW_ERROR
		Serial_Error_t Error;
		uint8_t ErrorCounter;
	#endif
	
	#ifdef SERIAL_WITH_TIMEOUT
		Timeout_Cliente_t Timeout;
	#endif
	
	uint8_t RXBytes;
	uint8_t TXBytes;
	volatile uint8_t TXCompleted;
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

void Serial_Init( Serial_ptr uart,
									#ifdef SERIAL_WITH_TIMEOUT
										 const Timeout_ptr mTimeout, const uint16_t mTimeoutMs,
									#endif
									const uint16_t baudios );
Serial_Return_Code_t Serial_Enviar( Serial_ptr uart );
Serial_Return_Code_t Serial_Recibir( Serial_ptr uart, uint8_t length );

void Serial_PutData( Serial_ptr uart, char* message, uint8_t length );


#ifdef __cplusplus
} // extern "C"
#endif 

#endif

/**
  * @}
  */