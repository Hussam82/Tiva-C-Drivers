/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
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
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 PortNum, PinNum, ChannelValue;

    /* Get the Port Number */
    PortNum = ChannelId / 8;

    /* Get the Pin Number */
    PinNum = ChannelId % 8;   

    /* Get the Channel Value */
    ChannelValue = (GPIODATA(PortNum) | (1<<PinNum)); 

    return ChannelValue;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8 PortNum, PinNum;

    /* Get the Port Number */
    PortNum = ChannelId / 8;

    /* Get the Pin Number */
    PinNum = ChannelId % 8;    

    if(Level == PIN_HIGH)
    {
        /* Set the PinNum */
        GPIODATA(PortNum) |= (1<<PinNum);
    }
    else if(Level == PIN_LOW)
    {
        /* Clear the PinNum */
        GPIODATA(PortNum) &= ~(1<<PinNum);
    }
    else
    {
        /* Do Nothing */
    }
}
Dio_PortLevelType Dio_ReadPort(Dio_ChannelType ChannelId)
{
    uint8 PortNum, PortValue;

    /* Get the Port Number */
    PortNum = ChannelId / 8;

    /* Get the value of GPIODATA */
    PortValue = GPIODATA(PortNum); 

    return PortValue;

}
void Dio_WritePort(Dio_ChannelType ChannelId, Dio_PortLevelType Level)
{
    uint8 PortNum, PinNum;

    /* Get the Port Number */
    PortNum = ChannelId / 8; 

    /* Write the value to the GPIODATA */
    GPIODATA(PortNum) = Level;

}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint8 PortNum, PinNum, ChannelValue;

    /* Get the Port Number */
    PortNum = ChannelId / 8;

    /* Get the Pin Number */
    PinNum = ChannelId % 8;    

    /* Toggle the Channel Value */
    GPIODATA(PortNum) ^= (1<<PinNum);

    /* Get the Channel Value after toggling */
    ChannelValue = GPIODATA(PortNum) | (1<<PinNum);

    return ChannelValue;
}






/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/