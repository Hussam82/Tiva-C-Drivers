/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital Input Output Driver
 *
 *      \details  Read/Write the value of a given Pin
 *                Read/Write the value of a given Port
 *                Flips a given Pin
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)        
* \Description     : Reads the Channel Value                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The pin number of a certain port                     
* \Parameters (out): None                                                      
* \Return value:   : ChannelValue                             
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

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)       
* \Description     : Writes a value to a certain Channel                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The pin number of a certain port
                     Level       The value at which the channel is set                     
* \Parameters (out): None                                                      
* \Return value:   : None                             
*******************************************************************************/
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
        //GPIODATA_PORT_PIN(PortNum,PinNum) = 0xFF;

    }
    else if(Level == PIN_LOW)
    {
        /* Clear the PinNum */
        GPIODATA(PortNum) &= ~(1<<PinNum);
        //GPIODATA_PORT_PIN(PortNum,PinNum) = 0x00;
    }
    else
    {
        /* Do Nothing */
    }
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_ChannelType ChannelId)       
* \Description     : Reads the Port Value                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The Port number of a certain port                     
* \Parameters (out): None                                                      
* \Return value:   : PortValue                             
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_ChannelType ChannelId)
{
    uint8 PortNum, PortValue;

    /* Get the Port Number */
    PortNum = ChannelId / 8;

    /* Get the value of GPIODATA */
    PortValue = GPIODATA(PortNum); 

    return PortValue;

}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_ChannelType ChannelId, Dio_PortLevelType Level)       
* \Description     : Writes a value to a certain Port                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The Port number
                     Level       The value at which the Port is set                     
* \Parameters (out): None                                                      
* \Return value:   : None                             
*******************************************************************************/
void Dio_WritePort(Dio_ChannelType ChannelId, Dio_PortLevelType Level)
{
    uint8 PortNum, PinNum;

    /* Get the Port Number */
    PortNum = ChannelId / 8; 

    /* Write the value to the GPIODATA */
    if(Level = PIN_HIGH)
    {
        GPIODATA(PortNum) = 0xFF;
    }
    else if(Level = PIN_HIGH)
    {
        GPIODATA(PortNum) = 0x00;
    }
    

}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)       
* \Description     : Flips the value of a certain pin                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The Pin number to be flipped                
* \Parameters (out): None                                                      
* \Return value:   : None                             
*******************************************************************************/
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