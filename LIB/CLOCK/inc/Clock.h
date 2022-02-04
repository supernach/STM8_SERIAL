#ifndef CLOCK_H
#define CLOCK_H

/****************************************************************************
* Title                 :   Clock API
* Filename              :   Clock.h
* Author                :   SuperNach
* Origin Date           :   20/02/2021
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
*  20/02/21   1.0.0   SuperNach       Initial Release.
*  
*
*******************************************************************************/
/** @file Clock.h
 *  @brief Proporciona un acceso basico a la configuracion y
 *				 usos del reloj interno del micro.
 */

/** @addtogroup API
  * @{
  */
/** @addtogroup N_HAL
  * @{
  */
/** @addtogroup CLOCK
  * @{
  */	
/******************************************************************************
* Includes
*******************************************************************************/
#include <stm8s.h>
#include <Gpio.h>

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

/**
@brief Deshabilita el uso del reloj en todos los perifericos			 

*/
void DisableAllPeripherals(void);

/**
@brief Inicializa el reloj de alta velocidad interno del
			 micro. A su vez deshabilita el reloj externo y el
			 reloj lento interno. Configura la frecuencia Master
			 y la frecuencia de la cpu. Por ultimo deshabilita
			 el uso del reloj para todos los perifericos.
			 
@param Prescaler para la frecuencia Master. 1,2,4,8
@param Prescaler para la frecuencia de la cpu. Esta 
			 la marca la frecuencia Master. 1,2,4,8,16,32,64,128
*/			 
void Clock_HSI_Init(CLK_Prescaler_TypeDef fHsi, CLK_Prescaler_TypeDef fCpu);

/**
@brief Habilita el uso de la funcion CCO en el pin por 
			 defecto del micro. En ese pin tendremos un espejo
			 de la frecuencia del reloj que elijamos.
@param Señal de reloj a usar
@param Configuracion fisica del pin
*/
void EnableClockMirror(CLK_Output_TypeDef source, Gpio_Config_t* pin);

void HabilitarRelojPeriferico( CLK_Peripheral_TypeDef periferico );


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