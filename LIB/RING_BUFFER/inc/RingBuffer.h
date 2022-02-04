#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stm8s.h>
#include <stdbool.h>
#include <stdlib.h>

//#define SERIE_FILL_CHAR 0x23

typedef struct Ring_Buffer_t Ring_Buffer_t;
typedef Ring_Buffer_t* Ring_Buffer_ptr;




/// Pass in a storage buffer and size 
/// Returns a circular buffer handle
Ring_Buffer_ptr RB_Manager_init( uint8_t* buffer, uint8_t size );

/// Free a circular buffer structure.
/// Does not free data buffer; owner is responsible for that
void RB_Manager_free( Ring_Buffer_ptr rbuf );

/// Reset the circular buffer to empty, head == tail
void RB_Manager_reset( Ring_Buffer_ptr rbuf );

/// Put version 1 continues to add data if the buffer is full
/// Old data is overwritten
void RB_Manager_put( Ring_Buffer_ptr rbuf, uint8_t data );

/// Put Version 2 rejects new data if the buffer is full
/// Returns 0 on success, -1 if buffer is full
//int16_t circular_buf_put2(pRing_Buffer_t cbuf, uint8_t data);

/// Retrieve a value from the buffer
/// Returns 0 on success, -1 if the buffer is empty
int16_t RB_Manager_get( Ring_Buffer_ptr rbuf, uint8_t * data );

/// Returns true if the buffer is empty
bool RB_Manager_empty( Ring_Buffer_ptr rbuf );

/// Returns true if the buffer is full
bool RB_Manager_full( Ring_Buffer_ptr rbuf );

/// Returns the maximum capacity of the buffer
uint16_t RB_Manager_capacity( Ring_Buffer_ptr rbuf );

/// Returns the current number of elements in the buffer
uint16_t RB_Manager_size( Ring_Buffer_ptr rbuf );

//uint8_t Ring_Buffer_ActualData( pRing_Buffer_t cbuf );


#endif