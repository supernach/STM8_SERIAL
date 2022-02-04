#ifndef STATEMACHINECONFIG_H
#define STATEMACHINECONFIG_H

/****************************************************************************
* Title                 :   State Machine Config
* Filename              :   StateMachineConfig.h
* Author                :   SuperNach
* Origin Date           :   15/01/2022
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
*  15/01/2022   1.0.0   SuperNach       Initial Release.
*  
*
*******************************************************************************/
/** @file StateMachineConfig.h
 * @brief Proporciona el tipo necesario para crear diferentes estados
 *				y diferentes transiciones.
 *				Las transiciones deben ser declaradas en el mismo orden
 *				que la declaracion de los codigos de resultado devueltos
 *				al ejecutar las acciones del estado.
 */
/******************************************************************************
* Includes
*******************************************************************************/

#ifndef USING_C_STANDARD 
#include <stm8s.h>
#else
#include <stdint.h>
#endif

//#include <stdint.h>

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
/**
* @def 
* @brief 
*/

/******************************************************************************
* Typedefs
*******************************************************************************/
/**
* @typedef struct  StateMachineTransitionRule_t
*
* @brief	Proporciona las regla para transicionar a otro estado.
*					
*/
typedef struct
{
	uint8_t NewState; /**< Nuevo estado al que transicionar */
}StateMachineTransitionRule_t;
typedef StateMachineTransitionRule_t* StateMachineTransitionRule_ptr;

/**
* @typedef struct  StateMachineConfig_t
*
* @brief Estructura que tiene cada estado. Se define el
*				 nombre del estado( definido por la maquina de estados ),
*				 y los 3 puntos de ejecucion del estado.
*
*/
typedef struct
{
	const uint8_t State; /**< Nombre del estado */
	
	const StateMachineTransitionRule_ptr TransitionRules; /**< Distintas transiciones que pueden producirse en este estado */
	
	void ( *EntryFunction )( void* data ); /**< Ordenes a ejecutar al entrar en el estado */
	uint8_t ( *RunFunction )( void* data ); /**< Acciones a realizar en el estado */
	void ( *ExitFunction )( void* data ); /**< Ordenes a ejecutar al salir del estado */
}StateMachineConfig_t;
typedef StateMachineConfig_t* StateMachineConfig_ptr;

/******************************************************************************
* Struct
*******************************************************************************/
/**
* @struct 
* @brief 	
*
* @see		
* @see		
* @see		
*/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/******************************************************************************
* Function : ()
*//**
* \b Description:
*
* 
*
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
*
* @return 		
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 15/01/2022  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/





#endif