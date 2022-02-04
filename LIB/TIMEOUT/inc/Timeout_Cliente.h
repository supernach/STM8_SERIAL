#ifndef TIMEOUT_CLIENTE_H
#define TIMEOUT_CLIENTE_H

#include <stm8s.h>
#include <stdlib.h>
#include <stdbool.h>

#define TIMEOUT_MAX_CLIENTS 4

typedef struct Timeout_Cliente_t Timeout_Cliente_t;
typedef Timeout_Cliente_t* Timeout_Cliente_ptr;

typedef union
{
	uint8_t fByte;
	struct flagBit
	{
		uint8_t stopped : 1;
		uint8_t running : 1;
		uint8_t overflow : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t Start : 1;
		uint8_t Stop : 1;
	}Bit;
}Timeout_Cliente_Flag_t;

struct Timeout_Cliente_Data
{
	uint16_t Setpoint;
	uint16_t Tick;
};

struct Timeout_Cliente_t
{
	Timeout_Cliente_Flag_t Status; 
	struct Timeout_Cliente_Data Data;
};



void Timeout_Client_Init( Timeout_Cliente_ptr mClient, const uint16_t mSetpoint );
void Timeout_Client_Stop( Timeout_Cliente_ptr mClient );



#endif