#include <serie_buffer.h>

static @inline void _initBufferData( uint8_t* mBuf, uint16_t size )
{
	uint8_t indice = 0;
	
	while( indice < size )
	{
		mBuf[indice] = 0;
		indice++;
	}
}

void Serial_Buffer_Init( Serial_Buffer_ptr mBuf )
{	
	mBuf->RB_Manager = RB_Manager_init( &mBuf->Ring_RX[0], SERIAL_RINGBUF_MAX); // ALOCAMIENTO DINAMICO
	mBuf->LB_RX_Index = 0;
	mBuf->LB_TX_Index = 0;
	mBuf->LB_TX_Items = 0;
	
	_initBufferData( &mBuf->Ring_RX[0], SERIAL_RINGBUF_MAX );
	_initBufferData( &mBuf->Local_RX[0], SERIAL_LOCAL_BUF_RX_MAX);
	_initBufferData( &mBuf->Local_TX[0], SERIAL_LOCAL_BUF_TX_MAX);
	
}

uint8_t Serial_Buffer_HaveData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type )
{
	switch ( type )
	{
		case SB_LOCAL_RX:
			return mBuf->LB_RX_Index;
		break;
		case SB_LOCAL_TX:
			return mBuf->LB_TX_Items;
		break;
		case SB_RING:
			return RB_Manager_empty( mBuf->RB_Manager );
		break;
		default:
			return mBuf->LB_TX_Index;
	}
	return 0;
}

uint8_t Serial_Buffer_GetData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type )
{
	switch ( type )
	{
		case SB_LOCAL_RX:
			return 0;
		break;
		case SB_LOCAL_TX:
			mBuf->LB_TX_Index++;
			mBuf->LB_TX_Items--;
			return mBuf->Local_TX[mBuf->LB_TX_Index - 1];
		break;
		case SB_RING:
			if( RB_Manager_get( mBuf->RB_Manager, &mBuf->Local_RX[mBuf->LB_RX_Index] ) >= 0 )
			{
				mBuf->LB_RX_Index++;
				return 1;
			}
			else
			{
				return 0;
			}
		break;
	}
	return 0;
}

void Serial_Buffer_PutData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type, uint8_t optData )
{
	switch ( type )
	{
		/*case SB_LOCAL_RX:

		break;*/
		case SB_LOCAL_TX:
			mBuf->Local_TX[mBuf->LB_TX_Items] = optData;
			mBuf->LB_TX_Items++;
		break;
		case SB_RING:
			RB_Manager_put(mBuf->RB_Manager, UART1_ReceiveData8( ) );
		break;
	}
}


void Serial_Buffer_Reset( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type )
{
	switch ( type )
	{
		case SB_LOCAL_RX:
			mBuf->LB_RX_Index = 0;
		break;
		case SB_LOCAL_TX:
			mBuf->LB_TX_Index = 0;
			mBuf->LB_TX_Items = 0;
		break;
		case SB_RING:
			_initBufferData( &mBuf->Ring_RX[0], SERIAL_RINGBUF_MAX );
			RB_Manager_reset( mBuf->RB_Manager );
		break;
	}
	
}

