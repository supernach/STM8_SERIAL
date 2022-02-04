/****************************************************************************
* Title                 :   Gpio API
* Filename              :   Gpio.h
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
/** @file Gpio.h
 * @brief Este archivo contiene las operaciones basicas sobre los puertos
 *        gpio.
 */
/** @addtogroup API
  * @{
  */
/** @addtogroup N_HAL
  * @{
  */
/** @addtogroup GPIO
  * @{
  */
	
#ifndef GPIO_H
#define GPIO_H


/******************************************************************************
* Includes
*******************************************************************************/
#include <stm8s.h>
#include <stdbool.h>
#include <Gpio_Config.h>

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

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif


void IO_Init( Gpio_Config_t* gpio );
bool IO_Read( Gpio_Config_t* gpio );
void IO_Write( Gpio_Config_t* gpio, bool estado );

#ifdef __cplusplus
} // extern "C"
#endif 

#endif /*GPIO_H_*/

/**
  * @}
  */
/**
  * @}
	*/
/**
  * @}
*/