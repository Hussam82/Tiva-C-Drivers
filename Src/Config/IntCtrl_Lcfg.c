/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  Nested Vectored Interrupt Controller Link Configurations
 *
 *      \details  Link Stage Configrations for NVIC
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* Note: You have to configure the number of Port Pin in Cfg.h */
/* 	Options:
	GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD,
	GPIO_PORTE, UART0, UART1, SSI0, I2C0,
	PWM0_FAULT, PWM0_GENERATOR_0, PWM0_GENERATOR_1, PWM0_GENERATOR_2, QEI0,
	ADC0_SEQUENCE_0, ADC0_SEQUENCE_1, ADC0_SEQUENCE_2, ADC0_SEQUENCE_3, WATCHDOG_TIMER_0_1,
	TIMER_0A_16_32, TIMER_0B_16_32, TIMER_1A_16_32, TIMER_1B_16_32, TIMER_2A_16_32,
	TIMER_2B_16_32, Analog_Comparator_0, Analog_Comparator_1, SYSTEM_CONTROL = 28, FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL,
    GPIO_PORTF, UART2 = 33, SSI1, TIMER_3A_16_32, TIMER_3B_16_32,
    I2C1, QEI1, CAN0, CAN1, HIBERNATION_MODULE = 43,
    USB, PWM_GENERATOR_3, uDMA_SOFTWARE, uDMA_ERROR, ADC1_SEQUENCE_0,
    ADC1_SEQUENCE_1, ADC1_SEQUENCE_2, ADC1_SEQUENCE_3, SSI2 = 57, SSI3,
    UART3, UART4, UART5, UART6, UART7,
    I2C2 = 68, I2C3, TIMER_4A_16_32, TIMER_4B_16_32, TIMER_5A_16_32 = 92,
    TIMER_5B_16_32, TIMER_0A_32_64, TIMER_0B_32_64, TIMER_1A_32_64, TIMER_1B_32_64,
    TIMER_2A_32_64, TIMER_2B_32_64, TIMER_3A_32_64, TIMER_3B_32_64, TIMER_4A_32_64,
    TIMER_4B_32_64, TIMER_5A_32_64, TIMER_5B_32_64, SYSTEM_EXCEPTION, PWM1_GENERATOR_0 = 134,
    PWM1_GENERATOR_1, PWM1_GENERATOR_2, PWM1_GENERATOR_3, PWM1_Fault
*/


/* You have to change the Number of interrupts required in cfg.h for this to work */
const IntCtrl_ConfigStruct InterruptsConfigArray[INTCTRL_CONFIGURED_INTERRUPTS] =
{
	{TIMER_1A_16_32,						          ENABLED, GROUP_0_SUB_0}
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
