#include <timer2.h>


void Timer2_Start( const uint16_t ms )
{
	CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, ENABLE);
	TIM2_ITConfig( TIM2_IT_UPDATE, DISABLE );
	TIM2_Cmd( DISABLE );
	TIM2_TimeBaseInit( TIM2_PRESCALER_16, ms);
	TIM2_ITConfig( TIM2_IT_UPDATE, ENABLE );
	ITC_SetSoftwarePriority( ITC_IRQ_TIM2_OVF, ITC_PRIORITYLEVEL_1 );
	TIM2_Cmd( ENABLE );
}

void Timer2_Stop( void )
{
	TIM2_ClearITPendingBit( TIM2_IT_UPDATE );
	TIM2_ClearFlag( TIM2_FLAG_UPDATE );
	TIM2_SetCounter( 0 );
	TIM2_ITConfig( TIM2_IT_UPDATE, DISABLE );
	TIM2_Cmd( DISABLE );
}