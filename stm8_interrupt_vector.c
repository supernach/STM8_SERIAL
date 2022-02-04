/*	BASIC INTERRUPT VECTOR TABLE FOR STM8 devices
 *	Copyright (c) 2007 STMicroelectronics
 */

#include <stm8s.h>

#include <serie.h>
#include <systick.h>
extern Serial_t Serial;
extern Systick_t Systick;


@svlreg @far @interrupt void UART_TXE_IRQHandler( void )
{
	UART1_SendData8( Serial_Buffer_GetData( &Serial.Buffer, SB_LOCAL_TX ) );
	Serial.TXCompleted = 1;
	UART1_ClearITPendingBit( UART1_IT_TXE );
	UART1_ClearFlag( UART1_FLAG_TXE );
	UART1_ITConfig( UART1_IT_TXE, DISABLE );
}


@svlreg @far @interrupt void UART_RXNE_IRQHandler( void ) // @svlreg agregado por norma de ST
{
	
	Serial_Buffer_PutData( &Serial.Buffer, SB_RING, '' );
	
	UART1_ClearITPendingBit( UART1_IT_RXNE );
	UART1_ClearFlag( UART1_FLAG_RXNE );
}


@svlreg @far @interrupt void TIM2_OV_IRQHandler( void )
{
	Systick.FlagCounter++;

	TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
	TIM2_ClearFlag(TIM2_FLAG_UPDATE);
}
 
typedef void @far (*interrupt_handler_t)(void);

struct interrupt_vector {
	unsigned char interrupt_instruction;
	interrupt_handler_t interrupt_handler;
};

@far @interrupt void NonHandledInterrupt (void)
{
	/* in order to detect unexpected events during development, 
	   it is recommended to set a breakpoint on the following instruction
	*/
	return;
}

extern void _stext();     /* startup routine */

struct interrupt_vector const _vectab[] = {
	{0x82, (interrupt_handler_t)_stext}, /* reset */
	{0x82, NonHandledInterrupt}, /* trap  */
	{0x82, NonHandledInterrupt}, /* irq0  */
	{0x82, NonHandledInterrupt}, /* irq1  */
	{0x82, NonHandledInterrupt}, /* irq2  */
	{0x82, NonHandledInterrupt}, /* irq3  */
	{0x82, NonHandledInterrupt}, /* irq4  */
	{0x82, NonHandledInterrupt}, /* irq5  */
	{0x82, NonHandledInterrupt}, /* irq6  */
	{0x82, NonHandledInterrupt}, /* irq7  */
	{0x82, NonHandledInterrupt}, /* irq8  */
	{0x82, NonHandledInterrupt}, /* irq9  */
	{0x82, NonHandledInterrupt}, /* irq10 */
	{0x82, NonHandledInterrupt}, /* irq11 */
	{0x82, NonHandledInterrupt}, /* irq12 */
	{0x82, (interrupt_handler_t)TIM2_OV_IRQHandler}, /* irq13 */
	{0x82, NonHandledInterrupt}, /* irq14 */
	{0x82, NonHandledInterrupt}, /* irq15 */
	{0x82, NonHandledInterrupt}, /* irq16 */
	{0x82, (interrupt_handler_t)UART_TXE_IRQHandler}, /* irq17 */
	{0x82, (interrupt_handler_t)UART_RXNE_IRQHandler}, /* irq18 */
	{0x82, NonHandledInterrupt}, /* irq19 */
	{0x82, NonHandledInterrupt}, /* irq20 */
	{0x82, NonHandledInterrupt}, /* irq21 */
	{0x82, NonHandledInterrupt}, /* irq22 */
	{0x82, NonHandledInterrupt}, /* irq23 */
	{0x82, NonHandledInterrupt}, /* irq24 */
	{0x82, NonHandledInterrupt}, /* irq25 */
	{0x82, NonHandledInterrupt}, /* irq26 */
	{0x82, NonHandledInterrupt}, /* irq27 */
	{0x82, NonHandledInterrupt}, /* irq28 */
	{0x82, NonHandledInterrupt}, /* irq29 */
};
