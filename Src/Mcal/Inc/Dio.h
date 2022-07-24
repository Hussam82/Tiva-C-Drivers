/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  Header for DIO Module     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "common_macros.h"
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_ChannelType ChannelId)       
* \Description     : Reads the Port Value                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The Port number of a certain port                     
* \Parameters (out): None                                                      
* \Return value:   : PortValue                             
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_ChannelType ChannelId);
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
void Dio_WritePort(Dio_ChannelType ChannelId, Dio_PortLevelType Level);
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)       
* \Description     : Flips the value of a certain pin                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId   The Pin number to be flipped                
* \Parameters (out): None                                                      
* \Return value:   : None                             
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/