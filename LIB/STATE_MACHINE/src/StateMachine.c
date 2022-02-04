/****************************************************************************
* Title                 :   State Machine
* Filename              :   StateMachine.c
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
/** @file StateMachine.c
 * @brief Implementacion de las diferentes rutinas para la ejecucion
 *				y utilizacion de la maquina de estados.
 */

/******************************************************************************
* Includes
*******************************************************************************/
#include <statemachine.h>


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
* Module Function Prototypes
*******************************************************************************/

void StateMachine_Init( StateMachine_ptr mFsm,  StateMachineConfig_ptr mConfig, uint8_t mInitState)
{
	mFsm->Config = mConfig;
	mFsm->Actual.CurrentState = mInitState;
	mFsm->Actual.ResultCode = 0;
	mFsm->Actual.InitState = mInitState;
	//mFsm->Run = &StateMachine_Run;
}


void StateMachine_Run( StateMachine_ptr mFsm )
{	
	switch ( mFsm->Actual.CurrentStatePoint )
	{
		case ENTRY:
		if( mFsm->Config[mFsm->Actual.CurrentState].EntryFunction != NULL )
			{
				mFsm->Config[mFsm->Actual.CurrentState].EntryFunction( NULL );
				mFsm->Actual.CurrentStatePoint = RUN;
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = RUN;
			}
		break;
		
		case RUN:
			if( mFsm->Config[mFsm->Actual.CurrentState].RunFunction != NULL )
			{
				mFsm->Actual.ResultCode = mFsm->Config[mFsm->Actual.CurrentState].RunFunction( NULL );
				
				if( mFsm->Actual.CurrentState != mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState )
				{
					mFsm->Actual.CurrentStatePoint = EXIT;
				}
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = EXIT;
			}
		break;
		
		case EXIT:
			if( mFsm->Config[mFsm->Actual.CurrentState].ExitFunction != NULL )
			{
				mFsm->Config[mFsm->Actual.CurrentState].ExitFunction( NULL );
				
				mFsm->Actual.CurrentStatePoint = ENTRY;
				mFsm->Actual.CurrentState = mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState;
				
				mFsm->Actual.ResultCode = 0;
			}
			else
			{
				mFsm->Actual.CurrentStatePoint = ENTRY;
				
				if( mFsm->Config[mFsm->Actual.CurrentState].RunFunction == NULL )
				{
					mFsm->Actual.CurrentState = mFsm->Actual.InitState; // Si hemos llegado aqui desde la funcion run null
					mFsm->Actual.ResultCode = 0;
				}
				else
				{
					mFsm->Actual.CurrentState = mFsm->Config[mFsm->Actual.CurrentState].TransitionRules[mFsm->Actual.ResultCode].NewState;
					mFsm->Actual.ResultCode = 0;
				}
			}
		break;
	}
}
