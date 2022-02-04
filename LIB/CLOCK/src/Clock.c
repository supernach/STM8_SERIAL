/****************************************************************************
* Title                 :   Clock API
* Filename              :   Clock.h
* Author                :   SuperNach
* Origin Date           :   20/02/2021
* Version               :   1.0.0
* Compiler              :   Cosmic C
* Target                :   STM8
* Copyright             :   
* All Rights Reserved
*
* AQUI VA DECLARACIONES DERECHOS
*
*******************************************************************************/
/****************************************************************************
* Doxygen C Template
* Copyright (c) 2013 - Jacob Beningo - All Rights Reserved
*
* Feel free to use this Doxygen Code Template at your own risk for your own
* purposes.  The latest license and updates for this Doxygen C template can be
* found at www.beningo.com or by contacting Jacob at jacob@beningo.com.
*
* For updates, free software, training and to stay up to date on the latest
* embedded software techniques sign-up for Jacobs newsletter at
* http://www.beningo.com/814-2/
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Template.
*
*****************************************************************************/
/*************** SOURCE REVISION LOG *****************************************
*
*    Date    Version   Author         Description
*  20/02/21   1.0.0   SuperNach       Initial Release.
*  
*
*******************************************************************************/
/** @file Clock.h
 *  @brief Proporciona un acceso basico a la configuracion y
 *				 usos del reloj interno del micro.
 */
 
/** @addtogroup API
  * @{
  */
/** @addtogroup N_HAL
  * @{
  */
/** @addtogroup CLOCK
  * @{
  */ 
/******************************************************************************
* Includes
*******************************************************************************/
#include <Clock.h>

/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
/******************************************************************************
* Function : Clock_HSI_Init
*//**
* \b Description:
*
* Inicializacion del reloj interno de alta velocidad
*
* PRE-CONDITION: Parametros del reloj elegidos
* 
*
* POST-CONDITION: El reloj esta habilitado a la frecuencia elegida
* 
* @param			Divisor para la frecuencia master
* @param			Divisor para la frecuencia de la cpu, esta va referida a la frecuencia master
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		Clock_HSI_Init(CLK_PRESCALER_HSIDIV1, CLK_PRESCALER_CPUDIV1);
* @endcode
*
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/02/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void Clock_HSI_Init(CLK_Prescaler_TypeDef fHsi, CLK_Prescaler_TypeDef fCpu)
{
	CLK_DeInit();
	
	CLK_HSECmd(DISABLE); //Desactivar oscilador externo
	CLK_LSICmd(DISABLE); //Desactivar oscilador lento interno 128khz
	
	CLK_HSICmd(ENABLE); // Activar oscilador interno 16mhz
	
	while(CLK_GetFlagStatus(CLK_FLAG_HSIRDY) == FALSE); // Espera hasta que el oscilador este preparado
	
	CLK_ClockSwitchCmd(ENABLE);
	
	CLK_HSIPrescalerConfig(fHsi); //fMaster 16mhz
	CLK_SYSCLKConfig(fCpu); // fCpu 
	
	CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_ENABLE);
                                
  DisableAllPeripherals();
}

/******************************************************************************
* Function : plantilla()
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void DisableAllPeripherals(void)
{
	CLK_PeripheralClockConfig(CLK_PERIPHERAL_I2C, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_AWU, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, DISABLE);
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, DISABLE);
}

/******************************************************************************
* Function : EnableClockMirror()
*//**
* \b Description:
*
* Habilita un pin del micro y saca la señal de reloj elegida
*
* PRE-CONDITION: Reloj configurado y habilitado
* PRE-CONDITION: IO parametrizada
* 
*
* POST-CONDITION: IO configurada como salida
* POST-CONDITION: Señal del reloj elegida es replicada en la IO
* 
* @param			Señal de reloj a replicar
* @param			Configuracion de la IO
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		EnableClockMirror(CLK_OUTPUT_CPU, &gpio)
* @endcode
*
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/02/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void EnableClockMirror(CLK_Output_TypeDef source, Gpio_Config_t* pin)
{
	IOConfig_SetType( pin, GPIO_MODE_OUT_PP_HIGH_FAST );
	IO_Init( pin ); //Tipo salida debe ser 10Mhz
	CLK_CCOConfig(source);
  CLK_CCOCmd(ENABLE);
}

/******************************************************************************
* Function : plantilla()
*//**
* \b Description:
*
* plantilla descripcion
*
* PRE-CONDITION: 
* PRE-CONDITION: 
* PRE-CONDITION: 
*
* POST-CONDITION: 
* 
* @param			
* @param			
*
* @return 		void
*
* \b Example Ejemplo:
* @code
*		
* @endcode
*
* @see 
* @see 
*
* <br><b> - CHANGELOG - </b>
*
* <table align="left" style="width:800px">
* <tr><td> Fecha       </td><td> Software Version </td><td> Creador </td><td> Descripcion </td></tr>
* <tr><td> 20/08/2021  </td><td> 1.0.0            </td><td> SN      </td><td> Primera edicion </td></tr>
* </table><br><br>
* <hr>
*
*******************************************************************************/
void HabilitarRelojPeriferico( CLK_Peripheral_TypeDef periferico )
{
	CLK_PeripheralClockConfig(periferico, ENABLE);
}

/**
  * @}
  */
/**
  * @}
	*/
/**
  * @}
*/