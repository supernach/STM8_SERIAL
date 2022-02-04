#ifndef TIMEOUT_H
#define TIMEOUT_H

#include <stm8s.h>
#include <stdlib.h>
#include <stdbool.h>
#include <systick.h>
#include <timeout_cliente.h>

typedef struct Timeout_t Timeout_t;
typedef Timeout_t* Timeout_ptr;


struct Timeout_t
{
	Systick_ptr Systick;
	uint16_t SystemTick;
	uint16_t TimeoutTick;
	
	Timeout_Cliente_t* Clients[TIMEOUT_MAX_CLIENTS];
	uint8_t TotalClients;
};

void Timeout_Init( Timeout_ptr mTimeout, Systick_ptr mSystick );
void Timeout_Client_Add( Timeout_ptr mTimeout, Timeout_Cliente_t* mClient );
void Timeout_Run( Timeout_ptr mTimeout );

#endif