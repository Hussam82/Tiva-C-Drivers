/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port Driver 
 *
 *      \details  Initializes the Port Driver with the given Configurations
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)        
* \Description     : Initializes the Port Driver                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr      Pointer to an array of structures                     
* \Parameters (out): None                                                      
* \Return value:   : None                                                                      
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    uint8 Counter;
    uint8 PortNum;
    uint8 PinNum;
	uint8 temp;
    for(Counter = 0; Counter < PORT_CONFIGURED_PINS; Counter++)
    {
        /* Get the Port Number */
        PortNum = ConfigPtr[Counter].PortPin / 8;

        /* Get the Pin Number */
        PinNum = ConfigPtr[Counter].PortPin % 8;

        /* Enable the clock for the Pin */
        SET_BIT(SYSCTL_RCGCGPIO_REG, PortNum);

		/* Delay after setting the clock */
		temp = 0;
				
        /* Enable the AHB Bus for GPIO */
        #if GPIO_MODE == GPIO_AHB
        SET_BIT(SYSCTL_GPIOHBCTL_REG, PortNum);
        #endif

        /* Handling the special Registers PC0 - PC3 */
        /* Warning: Skip JTAG pins PC0:3 of Tiva-C as they can not be operated as a gpio pins to avoid locking the mcu */
        if((ConfigPtr[Counter].PortPin == PORT_C0) || (ConfigPtr[Counter].PortPin == PORT_C1) 
            || (ConfigPtr[Counter].PortPin == PORT_C2) || (ConfigPtr[Counter].PortPin == PORT_C3))
        {
            continue;
        }
        else if(ConfigPtr[Counter].PortPin == PORT_D7 || ConfigPtr[Counter].PortPin == PORT_F0)
        {
            /* Before using these pins as GPIO, they have to be unlocked first */
            /* Write 0x4C4F434B to GPIOLOCK Register to unlock writing to GPIOCR Register */
            GPIOLOCK(PortNum) = 0x4C4F434B;
            /* Write one to the corressponding pin in GPIOCR Register */
            SET_BIT(GPIOCR(PortNum), PinNum);
        }


        /* Select the pin mode as DIO or Alternative Function */
        if(ConfigPtr[Counter].PortPinMode == PORT_DIO_MODE)
        {
            /* Disable Alternative Function Mode for this pin */
            CLEAR_BIT(GPIOAFSEL(PortNum), PinNum);

            /* Enable Digital Mode for this pin*/
            SET_BIT(GPIODEN(PortNum), PinNum);

            /* Disable the Analog Mode for this pin */
            CLEAR_BIT(GPIOAMSEL(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinMode == PORT_ADC_MODE) 
        {
            /* Disable Alternative Function for this pin */
            CLEAR_BIT(GPIOAFSEL(PortNum), PinNum);

            /* Disable Digital Mode for this pin */
            CLEAR_BIT(GPIODEN(PortNum), PinNum);

            /* Enable the Analog Mode for this pin */
            SET_BIT(GPIOAMSEL(PortNum), PinNum);
        }
        else
        {
            /* Enable Alternive Function for this pin */
            SET_BIT(GPIOAFSEL(PortNum), PinNum);

            /* Select the exact Alternative Function for this pin */
            GPIOPCTL(PortNum)  &= ~((0x0000000F)<<(PinNum * 4));
			GPIOPCTL(PortNum)  |=  ((ConfigPtr[Counter].PortPinMode)<<(PinNum * 4));
        }

        /* Select the Current Strength */
        if(ConfigPtr[Counter].PortPinOutputCurrent == PORT_2MA_OUTPUT_CURRENT)
        {
            /* Enable the 2mA Output Current for this pin */
            SET_BIT(GPIODR2R(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinOutputCurrent == PORT_4MA_OUTPUT_CURRENT)
        {
            /* Enable the 4mA Output Current for this pin */
            SET_BIT(GPIODR4R(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinOutputCurrent == PORT_8MA_OUTPUT_CURRENT)
        {
            /* Enable the 8mA Output Current for this pin */
            SET_BIT(GPIODR8R(PortNum), PinNum);
        }
        else
        {
            /* Do Nothing */
        }
				
				/* Select the pin direction */
        if(ConfigPtr[Counter].PortPinDirection == PORT_PIN_OUTPUT)
        {
            /* Set the pin as Output */
            SET_BIT(GPIODIR(PortNum), PinNum);
            if(ConfigPtr[Counter].PortPinLevel == PORT_PIN_HIGH_LEVEL)
            {
                /* Write one to PinNum in PortNum */
                GPIODATA(PortNum) |= (1<<PinNum);
            }
            else if(ConfigPtr[Counter].PortPinLevel == PORT_PIN_LOW_LEVEL)
            {
                /* Write zero to PinNum in PortNum */
                GPIODATA(PortNum) &= ~(1<<PinNum);
            }
            else
            {
                /* Nothing to do */
            }
        }
        else if(ConfigPtr[Counter].PortPinDirection == PORT_PIN_INPUT)
        {
            /* Set the pin as input */
            CLEAR_BIT(GPIODIR(PortNum), PinNum);
        }
        else
        {
            /* Do Nothing */
        }

        /* Select the Internal Attach Resistor */
        if(ConfigPtr[Counter].PortPinInternalAttach == PORT_INTERNAL_RESISTOR_OFF)
        {
            /* Disable the Internal Pull Up Resistor for this pin */
            CLEAR_BIT(GPIOPUR(PortNum), PinNum);

            /* Disable the Internal Pull Down Resistor for this pin */
            CLEAR_BIT(GPIOPDR(PortNum), PinNum);

            /* Disable the Open Drain for this pin */
            CLEAR_BIT(GPIOODR(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinInternalAttach == PORT_INTERNAL_PULL_DOWN_MODE)
        {
            /* Enable the Internal Pull Up Resistor for this pin */
            SET_BIT(GPIOPDR(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinInternalAttach == PORT_INTERNAL_PULL_UP_MODE)
        {
            /* Enable the Internal Pull Up Resistor for this pin */
            SET_BIT(GPIOPUR(PortNum), PinNum);
        }
        else if(ConfigPtr[Counter].PortPinInternalAttach == PORT_OPEN_DRAIN_MODE)
        {
            /* Enable the 8mA Output Current for this pin */
            SET_BIT(GPIOODR(PortNum), PinNum);
        }
        else
        {
            /* Do Nothing */
        }     

    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/