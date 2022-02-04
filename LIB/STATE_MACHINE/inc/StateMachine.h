#ifndef STATEMACHINE_H
#define STATEMACHINE_H

/****************************************************************************
* Title                 :   State Machine
* Filename              :   StateMachine.h
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
/** @file StateMachine.h
 * @brief Proporciona una maquina de estados previamente configurada
 *				lista para inicializar y usar a traves de sus metodos.
 */
/******************************************************************************
* Includes
*******************************************************************************/

//#define USING_C_STANDARD 0

#ifndef USING_C_STANDARD 
#include <stm8s.h>
#else
#include <stdint.h>
#endif

#include <stdlib.h>
#include <utils.h>


#include <statemachineconfig.h>
#include <statemachinevalues.h>

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
/** Tipo publico para crear la maquina */
typedef struct StateMachine_t StateMachine_t;
typedef StateMachine_t* StateMachine_ptr;

/**	Tipo de la funcion que gestiona la maquina */
//typedef void ( *Run_fPtr )( StateMachine_t* );


/******************************************************************************
* Struct
*******************************************************************************/
/**
* @struct StateMachine
*
* @brief Proporciona el tipo que da acceso a una maquina de estados tipica 	
*
* @see StateMachineConfig_t		
* @see StateMachineValues_t	
* @see Run_fPtr		
*/

struct StateMachine_t
{
	StateMachineConfig_ptr Config; /**< Configuracion de estados y transiciones */
	StateMachineValues_t Actual; /**< Valores actuales de la ejecucion de la maquina */
	//Run_fPtr Run; /**< Funcion que gestiona la maquina. Inicializada por defecto */
};

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/******************************************************************************
* Function : StateMachine_Init()
*//**
* \b Description:
*					Inicializa la maquina. Se asignan los estados y transiciones
*					previamente definidos, se asigna el estado inicial y se define
*					la funcion que gestiona la maquina.
* 
*
* PRE-CONDITION: Configuracion de la maquina creada
* PRE-CONDITION: Estado inicial decidido
*
* POST-CONDITION: La maquina queda lista para ejecutar la funcion Run
* 
* @param StateMachine_t Puntero hacia la maquina a inicializar
*
* @param StateMachineConfig_t Puntero hacia la configuracion de esa maquina
*
* @param uint8_t Estado incial para la maquina
*
* @return void 		
*
* \b Example Ejemplo:
* @code
*				StateMachine_t fsm;
*
*				const enum StateNames
*				{
*					INIT,
*					STATE1,
*					STATE2,
*					STATE3
*				};
*
*				const enum ResultCodes
*				{
*					CODE_EXECUTING,
*					CODE_OK,
*					CODE_FAIL,
*					CODE_TIMEOUT
*				};
*
*				const StateMachineTransitionRule_t FSM_Transiciones_INIT[] = {
*																																					{ TR_CODE_EXECUTING },
*																																					{ TR_CODE_OK },
*																																					{ TR_CODE_FAIL },
*																																					{ TR_CODE_TIMEOUT }
*																																				};
*
*				const StateMachineTransitionRule_t FSM_Transiciones_STATE1[] = {
*																																					{ TR_CODE_EXECUTING },
*																																					{ TR_CODE_OK },
*																																					{ TR_CODE_FAIL },
*																																					{ TR_CODE_TIMEOUT }
*																																				};
*
*				const StateMachineTransitionRule_t FSM_Transiciones_STATE2[] = {
*																																					{ TR_CODE_EXECUTING },
*																																					{ TR_CODE_OK },
*																																					{ TR_CODE_FAIL },
*																																					{ TR_CODE_TIMEOUT }
*																																				};
*
*				const StateMachineTransitionRule_t FSM_Transiciones_STATE3[] = {
*																																					{ TR_CODE_EXECUTING },
*																																					{ TR_CODE_OK },
*																																					{ TR_CODE_FAIL },
*																																					{ TR_CODE_TIMEOUT }
*																																				};
*
*				const StateMachineConfig_t FSM_Estados[] = {
*																											{ INIT, &FSM_Transiciones_INIT[0], &ENTRY_FUNCTION, &RUN_FUNCTION, &EXIT_FUNCTION },
*																											{ STATE1, &FSM_Transiciones_STATE1[0], &ENTRY_FUNCTION, &RUN_FUNCTION, &EXIT_FUNCTION },
*																											{ STATE2, &FSM_Transiciones_STATE2[0], &ENTRY_FUNCTION, &RUN_FUNCTION, &EXIT_FUNCTION },
*																											{ STATE3, &FSM_Transiciones_STATE3[0], &ENTRY_FUNCTION, &RUN_FUNCTION, &EXIT_FUNCTION }
*																										};
*
*				StateMachine_Init( &fsm, &FSM_Estados[0], INIT );
*		
* @endcode
*
* @see StateMachine_t
* @see StateMachineConfig_t
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
void StateMachine_Init( StateMachine_ptr mFsm,  StateMachineConfig_ptr mConfig, uint8_t mInitState );

/******************************************************************************
* Function : StateMachine_Run()
*//**
* \b Description:
*				Gestion de la maquina de estados. Se encarga de llamar
*				a los metodos necesarios dependiendo del estado y el punto de ejecucion
*				del estado donde se encuentre. Una vez procesado define el nuevo estado
*				dependiendo de la transicion que haya que ejecutar.
* 
*
* PRE-CONDITION: La maquina ha sido inciailizada con el metodo StateMachine_Init( ) 
*
* POST-CONDITION: La maquina empieza a ejecutar su ciclo
* 
* @param StateMachine_t Puntero a la maquina de estados a ejecutar			
*
* @return void 		
*
* \b Example Ejemplo:
* @code
*
*				// La maquina ha sido inicializada
*				fsm.Run( &fsm );
*
* @endcode
*
* @see StateMachine_t
* @see Run_fPtr
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
void StateMachine_Run( StateMachine_ptr mFsm );




#endif