#include <serie_config.h>


void Serial_Config_Init( Serial_Config_t* config, const uint16_t baudios )
{
	config->HW.StopBit = UART1_STOPBITS_1;
	config->HW.Paridad = UART1_PARITY_NO;
	config->HW.Bits = UART1_WORDLENGTH_8D;
	config->HW.Baudios = baudios;
	
	config->IO.RX.Puerto = GPIOD;
	config->IO.RX.Pin = GPIO_PIN_6;
	config->IO.RX.Tipo = GPIO_MODE_IN_PU_IT;
	config->IO.TX.Puerto = GPIOD;
	config->IO.TX.Pin = GPIO_PIN_5;
	config->IO.TX.Tipo = GPIO_MODE_OUT_PP_HIGH_FAST;
	
	config->Modo = UART1_MODE_TXRX_ENABLE;
	
	IO_Init( &config->IO.RX ); 
	IO_Init( &config->IO.TX );
}