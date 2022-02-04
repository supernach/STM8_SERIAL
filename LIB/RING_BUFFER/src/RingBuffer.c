#include <ringbuffer.h>



struct Ring_Buffer_t {
	uint8_t * buffer;
	volatile uint8_t head;
	volatile uint8_t tail;
	uint16_t max; 
	bool full;
};


static void advance_pointer( Ring_Buffer_ptr rbuf )
{
	if( rbuf->full )
	{
		if ( ++( rbuf->tail ) == rbuf->max ) 
		{ 
			rbuf->tail = 0;
		}
	}

	if ( ++( rbuf->head ) == rbuf->max ) 
	{ 
		rbuf->head = 0;
	}
	rbuf->full = ( rbuf->head == rbuf->tail );
}

static void retreat_pointer( Ring_Buffer_ptr rbuf )
{
	rbuf->full = false;
	if ( ++( rbuf->tail ) == rbuf->max ) 
	{ 
		rbuf->tail = 0;
	}
}


Ring_Buffer_ptr RB_Manager_init( uint8_t* buffer, uint8_t size )
{
	Ring_Buffer_ptr rbuf = malloc( sizeof( Ring_Buffer_t ) );
	rbuf->buffer = buffer;
	rbuf->max = size;
	RB_Manager_reset( rbuf );

	return rbuf;
}

void RB_Manager_reset( Ring_Buffer_ptr rbuf )
{
    rbuf->head = 0;
    rbuf->tail = 0;
    rbuf->full = false;
}

void RB_Manager_free( Ring_Buffer_ptr rbuf )
{
	free( rbuf );
}

bool RB_Manager_full( Ring_Buffer_ptr rbuf )
{
	return rbuf->full;
}

bool RB_Manager_empty( Ring_Buffer_ptr rbuf )
{
	return ( !rbuf->full && ( rbuf->head == rbuf->tail ) );
}

uint16_t RB_Manager_capacity( Ring_Buffer_ptr rbuf )
{
	return rbuf->max;
}

uint16_t RB_Manager_size( Ring_Buffer_ptr rbuf )
{
	uint16_t size = rbuf->max;

	if( !rbuf->full )
	{
		if( rbuf->head >= rbuf->tail )
		{
			size = ( rbuf->head - rbuf->tail );
		}
		else
		{
			size = ( rbuf->max + rbuf->head - rbuf->tail );
		}
	}

	return size;
}

void RB_Manager_put( Ring_Buffer_ptr rbuf, uint8_t data )
{
    rbuf->buffer[rbuf->head] = data;
    advance_pointer( rbuf );
}

int16_t RB_Manager_get( Ring_Buffer_ptr rbuf, uint8_t * data )
{
	int8_t r = -1;

	if(!RB_Manager_empty( rbuf ))
	{
		*data = rbuf->buffer[rbuf->tail];
		retreat_pointer( rbuf );

		r = 0;
	}
	return r;
}


