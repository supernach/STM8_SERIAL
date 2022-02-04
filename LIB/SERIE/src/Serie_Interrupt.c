/****************************************************************************
* Title                 :   plantilla
* Filename              :   plantilla.c
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
/** @file uart.c
 *  @brief 
 */
/** @addtogroup PLANTILLA
  * @{
  */
/******************************************************************************
* Includes
*******************************************************************************/
#include <serie_interrupt.h>

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
void Serial_Interrupt_Init( void )
{
	Serial_Interrupt_Disable( TXE );
	Serial_Interrupt_Disable( RXNE );
}
/******************************************************************************
* Function : UART_Limpiar_IT
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
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
void Serial_Interrupt_Clear( const Serial_IT_FLAG_e flag )
{
	switch( flag )
	{
		case TXE:
			UART1_ClearITPendingBit( UART1_IT_TXE );
			UART1_ClearFlag( UART1_FLAG_TXE );
		break;
		case RXNE:
			UART1_ClearITPendingBit( UART1_IT_RXNE );
			UART1_ClearFlag( UART1_FLAG_RXNE );
		break;
	}
}

/******************************************************************************
* Function : UART_Habilitar_IT
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
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
void Serial_Interrupt_Enable( const Serial_IT_FLAG_e flag, const ITC_PriorityLevel_TypeDef prio )
{
	switch( flag )
	{
		case TXE:
			UART1_ITConfig( UART1_IT_TXE, ENABLE );
			ITC_SetSoftwarePriority( ITC_IRQ_UART1_TX, prio );
		break;
		case RXNE:
			UART1_ITConfig( UART1_IT_RXNE, ENABLE );
			ITC_SetSoftwarePriority( ITC_IRQ_UART1_RX, prio );
		break;
	}
}

/******************************************************************************
* Function : UART_Deshabilitar_IT
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
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
void Serial_Interrupt_Disable( const Serial_IT_FLAG_e flag )
{
	switch( flag )
	{
		case TXE:
			UART1_ITConfig( UART1_IT_TXE, DISABLE );
		break;
		case RXNE:
			UART1_ITConfig( UART1_IT_RXNE, DISABLE );
		break;
	}
}
/**
  * @}
  */