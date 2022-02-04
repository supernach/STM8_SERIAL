#ifndef SERIAL_BUFFER_H
#define SERIAL_BUFFER_H

#include <stm8s.h>
#include <ringbuffer.h>


#define SERIAL_LOCAL_BUF_TX_MAX 10
#define SERIAL_LOCAL_BUF_RX_MAX 10
#define SERIAL_RINGBUF_MAX 10

typedef struct Serial_Buffer_t Serial_Buffer_t;
typedef Serial_Buffer_t* Serial_Buffer_ptr;

typedef enum
{
	SB_LOCAL_RX,
	SB_LOCAL_TX,
	SB_RING
}Serial_Buffer_Types_t;

struct Serial_Buffer_t
{
	uint8_t LB_RX_Index;
	char Local_RX[SERIAL_LOCAL_BUF_RX_MAX];
	
	uint8_t Ring_RX[SERIAL_RINGBUF_MAX];
	Ring_Buffer_ptr RB_Manager;
	
	volatile uint8_t LB_TX_Index; // items extraidos del buffer
	volatile uint8_t LB_TX_Items; // items añadidos al buffer
	uint8_t Local_TX[SERIAL_LOCAL_BUF_TX_MAX];
};


void Serial_Buffer_Init( Serial_Buffer_ptr mBuf );
uint8_t Serial_Buffer_HaveData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type );
uint8_t Serial_Buffer_GetData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type );
void Serial_Buffer_PutData( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type, uint8_t optData  );
void Serial_Buffer_Reset( Serial_Buffer_ptr mBuf, Serial_Buffer_Types_t type );



#endif