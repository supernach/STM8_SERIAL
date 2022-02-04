#include <timeout.h>

void Timeout_Init( Timeout_ptr mTimeout, Systick_ptr mSystick )
{
	mTimeout->Systick = mSystick;
	mTimeout->SystemTick = Systick_GetValue( mTimeout->Systick );
	mTimeout->TimeoutTick = mTimeout->SystemTick;
	mTimeout->TotalClients = 0;
}

void Timeout_Client_Add( Timeout_ptr mTimeout, Timeout_Cliente_t* mClient )
{
	
	if( mTimeout->TotalClients < TIMEOUT_MAX_CLIENTS )
	{
		mTimeout->Clients[mTimeout->TotalClients] = mClient;
		mTimeout->TotalClients++;
	}
}

void Timeout_Run( Timeout_ptr mTimeout )
{
	uint16_t tempTick = 0;
	
	mTimeout->SystemTick = Systick_GetValue( mTimeout->Systick );
	if( mTimeout->TimeoutTick != mTimeout->SystemTick ) // HA PASADO TIEMPO
	{
		if( mTimeout->SystemTick >= mTimeout->TimeoutTick ) // cuanto tiempo ha pasado
		{
			tempTick = mTimeout->SystemTick - mTimeout->TimeoutTick;
		}
		else
		{
			tempTick = ( mTimeout->Systick->ResetValue - mTimeout->TimeoutTick ) + mTimeout->SystemTick;
		}
		mTimeout->TimeoutTick = mTimeout->SystemTick; // ACTUALIZA NUECO TIEMPO SISTEMA
		
		mTimeout->SystemTick = 0;
		while( mTimeout->SystemTick < mTimeout->TotalClients ) // ACTUALIZO TIEMPO EN CLIENTES
		{
			if( mTimeout->Clients[mTimeout->SystemTick]->Status.Bit.running == true )
			{
				mTimeout->Clients[mTimeout->SystemTick]->Data.Tick = tempTick + mTimeout->Clients[mTimeout->SystemTick]->Data.Tick;
				
				if( mTimeout->Clients[mTimeout->SystemTick]->Data.Tick >= mTimeout->Clients[mTimeout->SystemTick]->Data.Setpoint ) // CHEQUEO EL OVERFLOW
				{
					mTimeout->Clients[mTimeout->SystemTick]->Status.Bit.running = false;
					mTimeout->Clients[mTimeout->SystemTick]->Status.Bit.overflow = true;
					mTimeout->Clients[mTimeout->SystemTick]->Data.Tick = 0;
				}
			}
			
			mTimeout->SystemTick++;
		}
		mTimeout->SystemTick = 0;
	}
	else
	{
		
	}
}
