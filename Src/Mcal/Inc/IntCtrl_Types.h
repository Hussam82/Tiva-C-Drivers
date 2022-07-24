/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  Contains all the Types for IntCtrl Module     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define		INTCTRL_GROUP_3_SUB_0		0x05FA0400		/* 3 bits for Group and 0 bits for sub group */
#define		INTCTRL_GROUP_2_SUB_1		0x05FA0500		/* 2 bits for Group and 1 bits for sub group */
#define		INTCTRL_GROUP_1_SUB_2		0x05FA0600		/* 1 bits for Group and 2 bits for sub group */
#define		INTCTRL_GROUP_0_SUB_3		0x05FA0700		/* 0 bits for Group and 3 bits for sub group */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if INTCTRL_GROUP_SUB_DIST == INTCTRL_GROUP_3_SUB_0
    typedef enum{
        GROUP_0_SUB_0,
        GROUP_1_SUB_0,
        GROUP_2_SUB_0,
        GROUP_3_SUB_0,
        GROUP_4_SUB_0,
        GROUP_5_SUB_0,
        GROUP_6_SUB_0,
        GROUP_7_SUB_0
    }IntCtrl_Group_Sub_Dist;
#elif INTCTRL_GROUP_SUB_DIST == INTCTRL_GROUP_2_SUB_1
    typedef enum{
        GROUP_0_SUB_0,
        GROUP_0_SUB_1,
        GROUP_1_SUB_0,
        GROUP_1_SUB_1,
        GROUP_2_SUB_0,
        GROUP_2_SUB_1,
        GROUP_3_SUB_0,
        GROUP_3_SUB_1
    }IntCtrl_Group_Sub_Dist;
#elif INTCTRL_GROUP_SUB_DIST == INTCTRL_GROUP_1_SUB_2
    typedef enum{
        GROUP_0_SUB_0,
        GROUP_0_SUB_1,
        GROUP_0_SUB_2,
        GROUP_0_SUB_3,
        GROUP_1_SUB_0,
        GROUP_1_SUB_1,
        GROUP_1_SUB_2,
        GROUP_1_SUB_3
    }IntCtrl_Group_Sub_Dist;
#elif INTCTRL_GROUP_SUB_DIST == INTCTRL_GROUP_0_SUB_3
    typedef enum{
        GROUP_0_SUB_0,
        GROUP_0_SUB_1,
        GROUP_0_SUB_2,
        GROUP_0_SUB_3,
        GROUP_0_SUB_4,
        GROUP_0_SUB_5,
        GROUP_0_SUB_6,
        GROUP_0_SUB_7
    }IntCtrl_Group_Sub_Dist;
#endif


typedef enum
{
    GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_FAULT,
    PWM0_GENERATOR_0,
    PWM0_GENERATOR_1,
	PWM0_GENERATOR_2,
	QEI0,
	ADC0_SEQUENCE_0,
	ADC0_SEQUENCE_1,
	ADC0_SEQUENCE_2,
	ADC0_SEQUENCE_3,
	WATCHDOG_TIMER_0_1,
	TIMER_0A_16_32,
	TIMER_0B_16_32,
	TIMER_1A_16_32,
	TIMER_1B_16_32,
	TIMER_2A_16_32,
	TIMER_2B_16_32,
	Analog_Comparator_0,
	Analog_Comparator_1,
	SYSTEM_CONTROL = 28,
    FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL,
    GPIO_PORTF,
    UART2 = 33,
    SSI1,
    TIMER_3A_16_32,
    TIMER_3B_16_32,
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    HIBERNATION_MODULE = 43,
    USB,
    PWM_GENERATOR_3,
    uDMA_SOFTWARE,
    uDMA_ERROR,
    ADC1_SEQUENCE_0,
    ADC1_SEQUENCE_1,
    ADC1_SEQUENCE_2,
    ADC1_SEQUENCE_3,
    SSI2 = 57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    I2C2 = 68,
    I2C3,
    TIMER_4A_16_32,
    TIMER_4B_16_32,
    TIMER_5A_16_32 = 92,
    TIMER_5B_16_32,
    TIMER_0A_32_64,
    TIMER_0B_32_64,
    TIMER_1A_32_64,
    TIMER_1B_32_64,
    TIMER_2A_32_64,
    TIMER_2B_32_64,
    TIMER_3A_32_64,
    TIMER_3B_32_64,
    TIMER_4A_32_64,
    TIMER_4B_32_64,
    TIMER_5A_32_64,
    TIMER_5B_32_64,
    SYSTEM_EXCEPTION,
    PWM1_GENERATOR_0 = 134,
    PWM1_GENERATOR_1,
    PWM1_GENERATOR_2,
    PWM1_GENERATOR_3,
    PWM1_Fault
}IntCtrl_InterruptType;

typedef enum
{
    DISABLED,
    ENABLED
}IntCtrl_State;


typedef struct{
    IntCtrl_InterruptType InterrupPeripheralGates;
    IntCtrl_State InterruptPeripheralState;
    IntCtrl_Group_Sub_Dist InterruptPeripheralPriority;
}IntCtrl_ConfigStruct;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const IntCtrl_ConfigStruct InterruptsConfigArray[INTCTRL_CONFIGURED_INTERRUPTS];

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
