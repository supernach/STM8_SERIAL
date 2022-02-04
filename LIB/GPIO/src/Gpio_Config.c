/****************************************************************************
* Title                 :   Gpio_Config API
* Filename              :   Gpio_Config.c
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
/** @file Gpio_Config.c
 * @brief Este archivo contiene operaciones de configuracion
 *				 gpio
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
/******************************************************************************
* Includes
*******************************************************************************/
#include <Gpio_Config.h>

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/******************************************************************************
* Function : NHALgpioConfig_SetType()
*//**
* \b Description:
*
* Esta funcion cambia el tipo de la gpio
*
* PRE-CONDITION: Configuracion gpio creada
* PRE-CONDITION: Nuevo tipo asignado
*
* POST-CONDITION: La gpio ha cambiado de tipo
* 
* @param			Configuracion de la gpio
* @param			Nuevo tipo de la gpio
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		NHALgpioConfig_SetType( &gpio, GPIO_MODE_IN_FL_NO_IT );
* @endcode
*
* @see Gpio_Config_t
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void IOConfig_SetType( Gpio_Config_t* gpio, GPIO_Mode_TypeDef nuevoTipo )
{
	gpio->Tipo = nuevoTipo;
}

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
