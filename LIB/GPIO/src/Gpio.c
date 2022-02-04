/****************************************************************************
* Title                 :   Gpio API
* Filename              :   Gpio.c
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
/** @file Gpio.c
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
/******************************************************************************
* Includes
*******************************************************************************/
#include <gpio.h>

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
* Function : NHALgpio_Init()
*//**
* \b Description:
*
* Esta funcion inicializa la IO segun su declaracion
*
* PRE-CONDITION: Clock habilitado
* PRE-CONDITION: Configuracion de la gpio creada
*
* POST-CONDITION: La gpio esta inicializada a los valores indicados
* 
* @param			Configuracion de la gpio
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		NHALgpio_Init( &gpio );
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
void IO_Init( Gpio_Config_t* gpio )
{
	GPIO_Init(gpio->Puerto, gpio->Pin, gpio->Tipo);
}

/******************************************************************************
* Function : NHALgpio_Read()
*//**
* \b Description:
*
* Esta funcion devuelve el estado de la gpio
*
* PRE-CONDITION: La gpio ha sido configurada
*
* POST-CONDITION: Obtenemos valor del estado de la gpio
* 
* @param			Configuracion de la gpio
*
* @return 		Estado de la gpio
*
* \b Example Ejemplo:
* @code
*		if( NHALgpio_Read( &gpio ) )
*		{
*			//Hacer algo
*		}
*		else
*		{
*			//Hacer algo
*		}
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
bool IO_Read( Gpio_Config_t* gpio )
{
	if(GPIO_ReadInputPin(gpio->Puerto, gpio->Pin)) return true;
	else return false;
}

/******************************************************************************
* Function : NHALgpio_Write()
*//**
* \b Description:
*
* Esta sobreescribe el estado logico de la gpio
*
* PRE-CONDITION: La gpio ha sido configurada
*
* POST-CONDITION: El estado logico de la gpio ha sido establecido
* 
* @param			Configuracion de la gpio
* @param			Valor logico de la gpio a establecer
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		NHALgpio_Write( &gpio, true );
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
void IO_Write( Gpio_Config_t* gpio, bool estado )
{
	if( estado )
	{
		GPIO_WriteHigh(gpio->Puerto, gpio->Pin);
	}
	else
	{
		GPIO_WriteLow(gpio->Puerto, gpio->Pin);
	}
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