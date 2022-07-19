/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const IntCtrl_InterruptsConfigStruct InterruptsConfigArray =
{
	GPIO_PORTA,						                			ENABLED, GROUP_0_SUB_0,
	GPIO_PORTB,						                			ENABLED, GROUP_0_SUB_0,
	GPIO_PORTC,						                			ENABLED, GROUP_0_SUB_0,
	GPIO_PORTD,						                			DISABLED, GROUP_0_SUB_0,
	GPIO_PORTE,						                			DISABLED, GROUP_0_SUB_0,
	UART0,								            					DISABLED, GROUP_0_SUB_0,
	UART1,								            					DISABLED, GROUP_0_SUB_0,
	SSI0,								            						DISABLED, GROUP_0_SUB_0,
	I2C0,								            						DISABLED, GROUP_0_SUB_0,
	PWM0_FAULT,							           					DISABLED, GROUP_0_SUB_0,
	PWM0_GENERATOR_2,					            			DISABLED, GROUP_0_SUB_0,
	QEI0,								            						DISABLED, GROUP_0_SUB_0,
	ADC0_SEQUENCE_0,					            			DISABLED, GROUP_0_SUB_0,
	ADC0_SEQUENCE_1,					            			DISABLED, GROUP_0_SUB_0,
	ADC0_SEQUENCE_2,					            			DISABLED, GROUP_0_SUB_0,
	ADC0_SEQUENCE_3,					            			DISABLED, GROUP_0_SUB_0,
	WATCHDOG_TIMER_0_1,				            			DISABLED, GROUP_0_SUB_0,
	TIMER_0A_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_0B_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_1A_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_1B_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_2A_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_2B_16_32,						            			DISABLED, GROUP_0_SUB_0,
	Analog_Comparator_0,				            		DISABLED, GROUP_0_SUB_0,
	Analog_Comparator_1,				            		DISABLED, GROUP_0_SUB_0,
	System_Control,						            			DISABLED, GROUP_0_SUB_0,
	FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL,		DISABLED, GROUP_0_SUB_0,
	GPIO_PORTF,						                			DISABLED, GROUP_0_SUB_0,
	UART2,							                				DISABLED, GROUP_0_SUB_0,
	SSI1,								            						DISABLED, GROUP_0_SUB_0,
	TIMER_3A_16_32,							        				DISABLED, GROUP_0_SUB_0,
	TIMER_3B_16_32,							        				DISABLED, GROUP_0_SUB_0,
	I2C1,								            						DISABLED, GROUP_0_SUB_0,
	QEI1,								            						DISABLED, GROUP_0_SUB_0,
	CAN0,								            						DISABLED, GROUP_0_SUB_0,
	CAN1,								            						DISABLED, GROUP_0_SUB_0,
	HIBERNATION_MODULE,					            		DISABLED, GROUP_0_SUB_0,
	USB,								            						DISABLED, GROUP_0_SUB_0,
	PWM_GENERATOR_3,					            			DISABLED, GROUP_0_SUB_0,
	uDMA_SOFTWARE,						            			DISABLED, GROUP_0_SUB_0,
	uDMA_ERROR,							            				DISABLED, GROUP_0_SUB_0,
	ADC1_SEQUENCE_0,					           				DISABLED, GROUP_0_SUB_0,
	ADC1_SEQUENCE_1,					            			DISABLED, GROUP_0_SUB_0,
	ADC1_SEQUENCE_2,					            			DISABLED, GROUP_0_SUB_0,
	ADC1_SEQUENCE_3,					            			DISABLED, GROUP_0_SUB_0,
	SSI2,								            						DISABLED, GROUP_0_SUB_0,
	SSI3,								            						DISABLED, GROUP_0_SUB_0,
	UART3,								            					DISABLED, GROUP_0_SUB_0,
	UART4,								            					DISABLED, GROUP_0_SUB_0,
	UART5,								            					DISABLED, GROUP_0_SUB_0,
	UART6,								            					DISABLED, GROUP_0_SUB_0,
	UART7,								            					DISABLED, GROUP_0_SUB_0,
	I2C2,								            						DISABLED, GROUP_0_SUB_0,
	I2C3,								            						DISABLED, GROUP_0_SUB_0,
	TIMER_4A_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_4B_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_5A_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_5B_16_32,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_0A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_0B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_1A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_1B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_2A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_2B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_3A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_3B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_3A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_4A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_4B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_5A_32_64,						            			DISABLED, GROUP_0_SUB_0,
	TIMER_5B_32_64,						            			DISABLED, GROUP_0_SUB_0,
	SYSTEM_EXCEPTION,					            			DISABLED, GROUP_0_SUB_0,
	PWM1_GENERATOR_0,					            			DISABLED, GROUP_0_SUB_0,
	PWM1_GENERATOR_1,					            			DISABLED, GROUP_0_SUB_0,
	PWM1_GENERATOR_2,					            			DISABLED, GROUP_0_SUB_0,
	PWM1_GENERATOR_3,					            			DISABLED, GROUP_0_SUB_0,
	PWM1_Fault,							            				DISABLED, GROUP_0_SUB_0
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
