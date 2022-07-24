/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT_Lcfg.c
 *        \brief  General Purpose Timers Link Configurations
 *
 *      \details  Link Stage Configurations for GPT Driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPT_Types.h"
#include "GPT.h"


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* Note: You have to configure the number of Timers used in Cfg.h */
/*  Options for Timer ID
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
*/

/*  Options for Timer Prescaler:
    GPT_NO_PS, GPT_PS_2, GPT_PS_4, GPT_PS_8, GPT_PS_16, GPT_PS_32, GPT_PS_64
    GPT_PS_128, GPT_PS_256, GPT_PS_512, GPT_PS_1024, GPT_PS_2048, GPT_PS_4096
    GPT_PS_8192, GPT_PS_16384, GPT_PS_32768, GPT_PS_65536
*/

/* Options for Timer Mode:
    GPT_MODE_SLEEP, GPT_MODE_NORMAL
*/


const Gpt_ConfigType GptConfigArray[GPT_CONFIGURED_TIMERS] = 
{
    {GPT_TIMER_1,      65536, GPT_PS_256, GPT_MODE_NORMAL, Gpt_Notification_Timer1}
};




/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
