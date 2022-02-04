/****************************************************************************
* Title                 :   Gpio_Config API
* Filename              :   Gpio_config.h
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
/** @file Gpio_Config.h
 * @brief Este archivo define los datos necesarios de configuracion gpio
 *        
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
/** @addtogroup GPIO_CONFIG
  * @{
  */	
	
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

/******************************************************************************
* Includes
*******************************************************************************/
#include <stm8s.h>

/******************************************************************************
* Constants
*******************************************************************************/
/**
* @var   <tipo>  <nombre>
* @brief 
*/

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
* @typedef struct  Gpio_Config_t
* @brief	
*					
*/
typedef struct Gpio_Config Gpio_Config_t;
/******************************************************************************
* Struct
*******************************************************************************/
/**
* @struct Gpio_Config
* @brief 	
*
* @see		GPIO_TypeDef
* @see		GPIO_Pin_TypeDef
* @see		GPIO_Mode_TypeDef
*/
struct Gpio_Config
{
	GPIO_TypeDef* Puerto;
	GPIO_Pin_TypeDef Pin;
	GPIO_Mode_TypeDef Tipo;
};
/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**<TODO: Mejorar abstraccion del parametro tipo */
void IOConfig_SetType( Gpio_Config_t* gpio, GPIO_Mode_TypeDef tipo );

#ifdef __cplusplus
} // extern "C"
#endif 

#endif

/**
  * @}
  */
/**
  * @}
	*/
/**
  * @}
*/
/**
  * @}
*/