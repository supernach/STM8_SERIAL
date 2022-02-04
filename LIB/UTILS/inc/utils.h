#ifndef UTILS_H
#define UTILS_H

/****************************************************************************
* Title                 :   Utils NHAL
* Filename              :   Utils.h
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
/** @file  Utils.h
 *  @brief Define distintas funciones, macros utiles
 */
/** @addtogroup API
  * @{
  */
/** @addtogroup N_HAL
  * @{
  */
/** @addtogroup UTILS
  * @{
  */
	
/******************************************************************************
* Includes
*******************************************************************************/
#ifndef USING_C_STANDARD 
#include <stm8s.h>
#else
#include <stdint.h>
#endif

/******************************************************************************
* Constants
*******************************************************************************/
/**
* @def FCLK
* @brief Definir en Hz la frecuencia de trabajo del reloj
*/
#define FCLK 16000000 /**< Velocidad frecuencia cpu(depende de la configuracion) */

/******************************************************************************
* Configuration
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
/**
* @def NULL
* @brief Macro Null para punteros
*/
//#define NULL (void*)0 /**< Definicion de puntero nulo */

/**
* @def IS_NULL(val)
* @brief Macro para comprobar punteros nulos
*/
//#define IS_NULL(val) ((val == NULL) ? true : false) /**< Chequeo puntero nulo */


#ifndef FCLK /**< Comprobacion que esta establecida la velocidad en Hz del reloj */
	#error FCLK is not defined! 
#endif
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


static @inline void _delay_cycl( unsigned short __ticks )
{
	#define T_COUNT(x) (( x * (FCLK / 1000000UL) )-3)/3)
	_asm("nop\n $N:\n decw X\n jrne $L\n nop\n ", __ticks);  
}

/******************************************************************************
* Function : _delay_us()
*//**
* \b Description:
*
* Bloquea el programa durante los microsegundos definidos
*
* PRE-CONDITION: Reloj inicializado
* PRE-CONDITION: FCLK definido
* 
*
* POST-CONDITION: Bloqueo durante el tiempo elegido
* 
* @param			tiempo de bloqueo
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		_delay_us( 10 );
* @endcode
*
* 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 9/09/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void _delay_us( const unsigned short __us )
{
	_delay_cycl( (unsigned short)( T_COUNT(__us) );
}

/******************************************************************************
* Function : _delay_ms()
*//**
* \b Description:
*
* Bloquea el programa durante los milisegundos definidos
*
* PRE-CONDITION: Reloj inicializado
* PRE-CONDITION: FCLK definido
* 
*
* POST-CONDITION: Bloqueo durante el tiempo elegido
* 
* @param			tiempo de bloqueo
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		_delay_ms( 10 );
* @endcode
*
* 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 9/09/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline void _delay_ms( unsigned short __ms )
{
	while ( __ms-- )
	{
		_delay_us( 1000 );
	}
}

/******************************************************************************
* Function : WordToInt
*//**
* \b Description:
*
* 
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* 
*
* POST-CONDITION: 
* 
* @param			
*
* @return 		uint8_t
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 30/09/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline uint8_t WordToInt( uint8_t decena, uint8_t unidad )
{
	return (uint8_t)( ( ( decena - 48 ) * 10 ) + ( unidad - 48 ) );
}

/******************************************************************************
* Function : ByteToInt
*//**
* \b Description:
*
* 
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* 
*
* POST-CONDITION: 
* 
* @param			
*
* @return 		uint8_t
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 30/09/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
static @inline uint8_t ByteToInt( uint8_t unidad )
{
	return (uint8_t)( unidad - 48 );
}

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