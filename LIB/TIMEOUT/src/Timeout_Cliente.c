#include <timeout_cliente.h>



void Timeout_Client_Init( Timeout_Cliente_t* mClient, const uint16_t mSetpoint )
{
	mClient->Status.fByte = 0;
	mClient->Data.Setpoint = mSetpoint;
	mClient->Data.Tick = 0;
}

void Timeout_Client_Stop( Timeout_Cliente_ptr mClient )
{
	mClient->Status.Bit.running = false;
	mClient->Status.Bit.overflow = false;
	mClient->Status.Bit.stopped = true;
}