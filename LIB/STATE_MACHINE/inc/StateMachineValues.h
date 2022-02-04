#ifndef STATEMACHINEVALUES_H
#define STATEMACHINEVALUES_H

/****************************************************************************
* Title                 :   State Machine Values
* Filename              :   StateMachineValues.h
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
/** @file StateMachineValues.h
 * @brief Proporciona valores internos de la maquina de estado
 *				necesarios para su control y ejecucion
 */
/******************************************************************************
* Includes
*******************************************************************************/

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
* @typedef enum  StatesPoint_t
* @brief Definicion de los 3 puntos de ejecucion de un estado
*
*/
typedef enum
{
	ENTRY, /**< Punto de entrada del estado */
	RUN, /**< Ejecucion acciones del estado */
	EXIT /**< Punto de salida del estado */
}StatesPoint_t;

/**
* @typedef struct  StateMachine_t
* @brief Valores actuales usados en la maquina de estado para
* 			 llevar el tracking de su estado. Tanto el estado actual
*				 como el punto de ejecucion donde se encuentra el estado
*
*/
typedef struct
{
	uint8_t CurrentState; /**< Estado actual de la maquina */
	uint8_t CurrentStatePoint; /**< Punto de ejecucion actual del estado */
	uint8_t ResultCode; 			 /**< Codigo devuelto tras la ejecucion de las acciones del estado, usado para transiciones */
	uint8_t InitState; /**< Estado inicial de la maquina */
}StateMachineValues_t;

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
