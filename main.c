/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
 
#include <stdlib.h>
 
#include <stm8s.h>
#include <clock.h>
#include <gpio.h>
#include <utils.h>
#include <timer2.h>

#include <systick.h>
#include <timeout.h>
#include <serie.h>


#define BAUDIOS 9600
#define SERIAL_TIMEOUT_MS 500


Serial_t Serial;
Systick_t Systick;

int main()
{		


	static Timeout_t Timeout;
	static Gpio_Config_t Led;
	static Timeout_Cliente_t LedCliente;
	static Timeout_Cliente_t Cliente1;
	static Timeout_Cliente_t Cliente2;
	
	static Serial_Return_Code_t rc = SERIE_RC_STANDBY;
	
	

	static uint8_t Paso = 0;
	
	static uint8_t LedTracking = 0;
	
	
	Led.Puerto = GPIOD;
	Led.Pin = GPIO_PIN_3;
	Led.Tipo = GPIO_MODE_OUT_PP_LOW_SLOW;
	
	
	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOC);
	GPIO_DeInit(GPIOD);
	
	Clock_HSI_Init(CLK_PRESCALER_HSIDIV1, CLK_PRESCALER_CPUDIV1); // Reloj Interno. 16Mhz
	
	IO_Init( &Led );

	Systick_Init( &Systick  );
	Timeout_Init( &Timeout, &Systick );
	Serial_Init( &Serial, &Timeout, SERIAL_TIMEOUT_MS, BAUDIOS );
	
	Timeout_Client_Init( &LedCliente, 1000 );
	Timeout_Client_Add( &Timeout, &LedCliente );
	LedCliente.Status.Bit.running = true;
	
	Timeout_Client_Init( &Cliente1, 2000 );
	Timeout_Client_Add( &Timeout, &Cliente1 );
	Cliente1.Status.Bit.running = true;
	
	Timeout_Client_Init( &Cliente2, 6000 );
	Timeout_Client_Add( &Timeout, &Cliente2 );
	Cliente2.Status.Bit.running = true;
	
	Timer2_Start( 1000 );
	
	enableInterrupts( );
	while (1)
	{
		Systick_Run( &Systick );
		Timeout_Run( &Timeout );
		
		if( Cliente1.Status.Bit.stopped == true )
		{
			Cliente1.Status.Bit.running = true;
			Cliente1.Status.Bit.stopped = false;
		}
		
		if( Cliente2.Status.Bit.stopped == true )
		{
			Cliente2.Status.Bit.running = true;
			Cliente2.Status.Bit.stopped = false;
		}
		
		if( LedCliente.Status.Bit.stopped == true )
		{
			LedCliente.Status.Bit.running = true;
			LedCliente.Status.Bit.stopped = false;
		}
		
		
		
		switch (Paso)
		{
			case 0:
				rc = Serial_Recibir( &Serial, 2 );
				
				switch ( rc )
				{
					case SERIE_RC_FINISHED:
					Serial_PutData( &Serial, &Serial.Buffer.Local_RX[0], 1 );
					Paso = 1;
					break;
					
					case SERIE_RC_TIMEOUT:
					Serial_PutData( &Serial, "TIMEOUT", 7 );
					Paso = 2;
					break;
				}
				
			break;
			
			case 1:
				rc = Serial_Enviar( &Serial );
				if( rc == SERIE_RC_FINISHED )
				{
					Paso = 0;
				}
			break;
			
			case 2:
				rc = Serial_Enviar( &Serial );
				if( rc == SERIE_RC_FINISHED )
				{
					Paso = 0;
				}
			break;
			
			case 3:
			break;
		}
		
		if( Cliente1.Status.Bit.overflow == true )
		{
	
			Timeout_Client_Stop( &Cliente1 );
		}
		
		
		
		if(Cliente2.Status.Bit.overflow == true  )
		{
		
			Timeout_Client_Stop( &Cliente2 );
		}
		
		if( LedCliente.Status.Bit.overflow == true  )
		{
			if( LedTracking == 0 )
			{
				IO_Write( &Led, 1);
				LedTracking = 1;
	
				Timeout_Client_Stop( &LedCliente );
			}
			else
			{
				IO_Write( &Led, 0);
				LedTracking = 0;

				Timeout_Client_Stop( &LedCliente );
			}
		}
	}
}