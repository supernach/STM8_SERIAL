#ifndef SYSTICK_H
#define SYSTICK_H

#include <stm8s.h>
#include <stdbool.h>


typedef struct Systick_t Systick_t;
typedef Systick_t* Systick_ptr;

struct Systick_t
{
	volatile uint16_t FlagCounter;
	uint16_t ResetValue; // 60000 = 1min
};


void Systick_Init( Systick_ptr mTick );

void Systick_Run( Systick_ptr mTick );
uint16_t Systick_GetValue( Systick_ptr mTick );



#endif