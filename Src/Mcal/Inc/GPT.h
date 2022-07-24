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
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel);
void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
void Gpt_Notification_Timer0(void);
void Gpt_Notification_Timer1(void);
void Gpt_Notification_Timer2(void);
void Gpt_Notification_Timer3(void);
void Gpt_Notification_Timer4(void);
void Gpt_Notification_Timer5(void);
void Gpt_Notification_Timer0_Wide(void);
void Gpt_Notification_Timer1_Wide(void);
void Gpt_Notification_Timer2_Wide(void);
void Gpt_Notification_Timer3_Wide(void);
void Gpt_Notification_Timer4_Wide(void);
void Gpt_Notification_Timer5_Wide(void);
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

 
#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT.h
 *********************************************************************************************************************/
