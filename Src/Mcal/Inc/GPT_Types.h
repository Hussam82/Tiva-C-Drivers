/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define NUM_TIMERS  12
   
          

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 Gpt_ValueType;

typedef void (*Gpt_CallBackType)(void);

typedef enum{
    GPT_TIMER_0,
    GPT_TIMER_1,
    GPT_TIMER_2,
    GPT_TIMER_3,
    GPT_TIMER_4,
    GPT_TIMER_5,
    GPT_WIDE_TIMER_0,
    GPT_WIDE_TIMER_1,
    GPT_WIDE_TIMER_2,
    GPT_WIDE_TIMER_3,
    GPT_WIDE_TIMER_4,
    GPT_WIDE_TIMER_5
}Gpt_ChannelType;

typedef enum{
    GPT_NO_PS,
    GPT_PS_2,
    GPT_PS_4,
    GPT_PS_8,
    GPT_PS_16,
    GPT_PS_32,
    GPT_PS_64,
    GPT_PS_128,
    GPT_PS_256,
    GPT_PS_512,
    GPT_PS_1024,
    GPT_PS_2048,
    GPT_PS_4096,
    GPT_PS_8192,
    GPT_PS_16384,
    GPT_PS_32768,
    GPT_PS_65536
}Gpt_PrescalerType;

typedef enum{
    GPT_MODE_SLEEP = 1,
    GPT_MODE_NORMAL
}Gpt_ModeType;

typedef enum{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PreDefTimerType;

typedef struct{
    Gpt_ChannelType         GptChannelId;
    Gpt_ValueType           GptChannelTickValueMax;
    Gpt_PrescalerType       GptChannelTickFrequency;
    Gpt_ModeType            GptChannelMode;   
    Gpt_CallBackType            GptNotification;
}Gpt_OneConfigType;

typedef struct{
    Gpt_OneConfigType ConfigArray[NUM_TIMERS];
}Gpt_ConfigType;


 
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Types.h
 *********************************************************************************************************************/
