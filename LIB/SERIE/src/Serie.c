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
#include <serie.h>

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

@inline void Serial_Send_Break( void )
{
	UART1_SendBreak( ); // MANDA CARACTER BREAK: TODO CEROS
}

#ifdef SERIAL_CHECK_HW_ERROR
	@inline uint8_t Serial_Check_Error( Serial_Error_t* mError )
	{
		mError->fByte = 0;
	
		if( UART1_GetFlagStatus( UART1_FLAG_NF ) == SET )
		{
			mError->Bit.noise = true;
		}
		if( UART1_GetFlagStatus( UART1_FLAG_FE ) == SET )
		{
			mError->Bit.frameError = true;
		}
		if( UART1_GetFlagStatus( UART1_FLAG_PE ) == SET )
		{
			mError->Bit.parityError = true;
		}
		if( UART1_GetFlagStatus( UART1_FLAG_OR ) == SET )
		{
			mError->Bit.overrun = true;
		}
	
		if( mError->fByte != 0 )
		{
			UART1_ReceiveData8( );
			return 1;
		}
		else
		{
			return 0;
		}
	}

	@inline void Serial_Error_Init(  Serial_ptr uart )
	{
		uart->Error.fByte = 0;
		uart->ErrorCounter = 0;
	}
#endif
/******************************************************************************
* Function : Nhal_UART_Init
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
void Serial_Init( Serial_ptr uart,
									#ifdef SERIAL_WITH_TIMEOUT
										 const Timeout_ptr mTimeout, const uint16_t mTimeoutMs,
									#endif
									const uint16_t baudios )
{
	
	UART1_DeInit();
	
	Serial_Config_Init( &uart->Config, baudios );
	Serial_Buffer_Init( &uart->Buffer );
	
	
	#ifdef SERIAL_CHECK_HW_ERROR
		Serial_Error_Init( uart );
	#endif
	
	uart->RXBytes = 0;
	uart->TXBytes = 0;
	uart->TXCompleted = 0;
	
	#ifdef SERIAL_WITH_TIMEOUT
		Timeout_Client_Init( &uart->Timeout, mTimeoutMs );
		Timeout_Client_Add( mTimeout, &uart->Timeout );
	#endif
	
	Serial_Interrupt_Init( );
	
	HabilitarRelojPeriferico( CLK_PERIPHERAL_UART1 );
	UART1_Init( uart->Config.HW.Baudios, uart->Config.HW.Bits, uart->Config.HW.StopBit, uart->Config.HW.Paridad, UART1_SYNCMODE_CLOCK_DISABLE, uart->Config.Modo );
	
	Serial_Interrupt_Enable( RXNE, ITC_PRIORITYLEVEL_2 );
	
	UART1_Cmd(ENABLE);

	Serial_Interrupt_Clear( TXE );
	Serial_Interrupt_Clear( RXNE );
}

/******************************************************************************
* Function : Nhal_UART_Init
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
Serial_Return_Code_t Serial_Enviar( Serial_ptr uart )
{
	if( uart->TXBytes == 0 )
	{
		uart->TX_Status = SERIE_RC_STANDBY;
	}
	else
	{
		// SI ES EL PRIMER BYTE A ENVIAR
		if( uart->Buffer.LB_TX_Items == uart->TXBytes )
		{
			Serial_Interrupt_Clear( TXE );
			UART1_SendData8( Serial_Buffer_GetData( &uart->Buffer, SB_LOCAL_TX ) );
			
			if( uart->Buffer.LB_TX_Items > 1 )
			{
				Serial_Interrupt_Enable( TXE, ITC_PRIORITYLEVEL_2 );
				
				uart->TX_Status = SERIE_RC_EXECUTING;
			}
			else
			{
				uart->TXCompleted = 0;
				Serial_Interrupt_Clear( TXE );
				Serial_Interrupt_Disable( TXE );
				
				uart->TXBytes = 0;
				Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_TX );
				Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_RX );
				
				uart->TX_Status = SERIE_RC_FINISHED;
			}
			
		}
		else if( uart->Buffer.LB_TX_Items < uart->TXBytes && uart->Buffer.LB_TX_Items > 0  ) // HAY MAS DATOS A ENVIAR
		{
			if( uart->TXCompleted != 0 )
			{
				Serial_Interrupt_Clear( TXE );
				Serial_Interrupt_Enable( TXE, ITC_PRIORITYLEVEL_2 );
				uart->TXCompleted = 0;
			}
			uart->TX_Status = SERIE_RC_EXECUTING;
		}
		else if( uart->Buffer.LB_TX_Items == 0 )
		{
			Serial_Interrupt_Clear( TXE );
			Serial_Interrupt_Disable( TXE );
			uart->TXCompleted = 0;
			
			uart->TXBytes = 0;
			Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_TX );
			
			uart->TX_Status = SERIE_RC_FINISHED; 			
		}
	}

	return uart->TX_Status;
}

/******************************************************************************
* Function : Nhal_UART_Init
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
Serial_Return_Code_t Serial_Recibir( Serial_ptr uart, uint8_t length )
{
	#ifdef SERIAL_CHECK_HW_ERROR
		if( Serial_Check_Error( &uart->Error ) == 1 )
		{
			Serial_Interrupt_Disable( RXNE );
		
			if( uart->ErrorCounter >= 200 )
			{
				uart->ErrorCounter = 1;
			}
			else
			{
				uart->ErrorCounter++;
			}
		
			Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_RX ); // inicializar local buffer
			Serial_Buffer_Reset( &uart->Buffer, SB_RING ); // inicializar ring buffer
		
			uart->RXBytes = 0;
			
			#ifdef SERIAL_WITH_TIMEOUT
				Timeout_Client_Stop( &uart->Timeout );
			#endif
			
			Serial_Interrupt_Enable( RXNE, 2 );
		
			return SERIE_RC_ERROR;
		}
	#endif
	
	uart->RXBytes = length;
	
	#ifdef SERIAL_WITH_TIMEOUT
		if( uart->Timeout.Status.Bit.overflow == false )
		{
	#endif
	
		if( uart->RXBytes != 0 ) 
		{
			
			#ifdef SERIAL_WITH_TIMEOUT
				if( uart->Buffer.LB_RX_Index > 0 ) 
				{
					uart->Timeout.Status.Bit.running = true;
				}
			#endif
			
			if( Serial_Buffer_GetData( &uart->Buffer, SB_RING ) > 0 )
			{
				if( uart->Buffer.LB_RX_Index == uart->RXBytes ) // HAY EL NUMERO DE BYTES VALIDOS NECESARIOS
				{
					uart->RXBytes = 0;
					
					#ifdef SERIAL_WITH_TIMEOUT
						Timeout_Client_Stop( &uart->Timeout );
					#endif
					
					Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_RX );
					
					return SERIE_RC_FINISHED;
				}
				else
				{
					return SERIE_RC_EXECUTING;
				}
			}
			else
			{
				return SERIE_RC_EXECUTING;
			}
		}
		else
		{
			return SERIE_RC_STANDBY;
		}
		
	#ifdef SERIAL_WITH_TIMEOUT
	}
		else
		{
			Timeout_Client_Stop( &uart->Timeout );
		
			Serial_Buffer_Reset( &uart->Buffer, SB_LOCAL_RX );
		
			uart->RXBytes = 0;
			return SERIE_RC_TIMEOUT;
		}
	#endif
}

void Serial_PutData( Serial_ptr uart, char* message, uint8_t length )
{
	uint8_t index = 0;
	uart->TXBytes =length;
	
	while( index < length )
	{
		Serial_Buffer_PutData( &uart->Buffer, SB_LOCAL_TX, message[index] );
		index++;
	}
}
/**
  * @}
  */