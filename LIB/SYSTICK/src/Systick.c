#include <systick.h>




void Systick_Init( Systick_ptr mTick )
{
	mTick->ResetValue = 60000;
	mTick->FlagCounter = 0;	
}

void Systick_Run( Systick_ptr mTick )
{
	if( mTick->FlagCounter >= mTick->ResetValue )
	{
		mTick->FlagCounter = 0;
	}
}

uint16_t Systick_GetValue( Systick_ptr mTick )
{
	return mTick->FlagCounter;
}