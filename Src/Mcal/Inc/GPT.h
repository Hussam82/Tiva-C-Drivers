/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPT.h
 *       Module:  General Purpose Timers
 *
 *  Description:  Header for GPT Module    
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "common_macros.h"
#include "GPT_Cfg.h"
#include "GPT_Types.h"

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initilizes the GPT Driver                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a constant array of structures                      
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)        
* \Description     : Disables the Notifications for GPT                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                      
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel);
/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)        
* \Description     : Enables the Notifications for GPT                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                      
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel);
/******************************************************************************
* \Syntax          : void Gpt_StartTimerPollingMode(Gpt_ChannelType Channel, Gpt_ValueType Value)        
* \Description     : Starts the timer in Polling Mode                                                                                                                
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port   
                     Value     The value at which the interrupt occurs                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_StartTimerPollingMode(Gpt_ChannelType Channel, Gpt_ValueType Value);
/******************************************************************************
* \Syntax          : void Gpt_StartTimerInterruptMode(Gpt_ChannelType Channel, Gpt_ValueType Value)        
* \Description     : Starts the timer in Interrupt Mode                                                                                                                
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port   
                     Value     The value at which the interrupt occurs                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_StartTimerInterruptMode(Gpt_ChannelType Channel, Gpt_ValueType Value);
/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)        
* \Description     : Stops the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel);
/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)        
* \Description     : Return the Elapsed Time of the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : ElapsedTime                              
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)        
* \Description     : Return the Remaining Time of the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : RemainingTime                              
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer0(void)        
* \Description     : The CallBack Function for Timer0                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer0(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer1(void)        
* \Description     : The CallBack Function for Timer1                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer1(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer2(void)        
* \Description     : The CallBack Function for Timer2                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer2(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer3(void)        
* \Description     : The CallBack Function for Timer3                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer3(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer4(void)        
* \Description     : The CallBack Function for Timer4                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer4(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer5(void)        
* \Description     : The CallBack Function for Timer5                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer5(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer0_Wide(void)        
* \Description     : The CallBack Function for Wide Timer0                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer0_Wide(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer1_Wide(void)        
* \Description     : The CallBack Function for Wide Timer1                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer1_Wide(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer2_Wide(void)        
* \Description     : The CallBack Function for Wide Timer2                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer2_Wide(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer3_Wide(void)        
* \Description     : The CallBack Function for Wide Timer3                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer3_Wide(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer4_Wide(void)        
* \Description     : The CallBack Function for Wide Timer4                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer4_Wide(void);
/******************************************************************************
* \Syntax          : void Gpt_Notification_Timer5_Wide(void)        
* \Description     : The CallBack Function for Wide Timer5                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_Notification_Timer5_Wide(void);

 
#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
