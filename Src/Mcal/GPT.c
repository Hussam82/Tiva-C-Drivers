/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPT.c
 *        \brief  General Purpose Timers Driver
 *
 *      \details  Initializes the GPT Driver with the given Configurations
 *                Disables the Notifications
 *                Enables the Notifications
 *                Starts Timer in Polling/Interrupt Mode
 *                Stops the timer
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "GPT.h"
#include "assert.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* Global pointers to functions to hold the address of the call back function */
static void (*Gpt_CallBackPtr[GPT_NUMBER_OF_TIMERS])(void) = {NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR};
                                                                
                                                                
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{   
    /* Initialize the timer */
    uint8 counter;
    for(counter = 0; counter < GPT_CONFIGURED_TIMERS; counter++)
    {

        /* Set the callback function */
        Gpt_CallBackPtr[ConfigPtr[counter].GptChannelId] = ConfigPtr[counter].GptNotification;

        /* Enable Clock for the desired Timer Channel */
        if(ConfigPtr[counter].GptChannelId < 6)
        {
            SET_BIT(SYSCTL_RCGC_TIMER(ConfigPtr[counter].GptChannelId), ConfigPtr[counter].GptChannelId);
        }
        else
        {
            SET_BIT(SYSCTL_RCGC_TIMER(ConfigPtr[counter].GptChannelId), ConfigPtr[counter].GptChannelId - 6);
        }

        /* Disable the desired timer channel in GPTMCTL */
        GPTMCTL(ConfigPtr[counter].GptChannelId) = 0x00000000;

        /* For a 16/32-bit timer, this value selects the 16-bit timer configuration */
        GPTMCFG(ConfigPtr[counter].GptChannelId) = 0x0;

        /* For a 16/32-bit timer, this value selects the 16-bit timer configuration */
        GPTMCFG(ConfigPtr[counter].GptChannelId) = 0x4;

        /* Insert the required mode in the first 2 bits of GPTMAMR Register */
        GPTMTAMR(ConfigPtr[counter].GptChannelId) |= ConfigPtr[counter].GptChannelMode;

        /* Insert the required prescaler in the GPTMAPTR */
        if(ConfigPtr[counter].GptChannelId < 6 && ConfigPtr[counter].GptChannelTickFrequency >= 8)
        {
            GPTMTAPR(ConfigPtr[counter].GptChannelId) = GPT_PS_256;
        }
        else
        {
            GPTMTAPR(ConfigPtr[counter].GptChannelId) = ConfigPtr[counter].GptChannelTickFrequency;
        }
        
        /* Select Count up Mode */
        SET_BIT(GPTMTAMR(ConfigPtr[counter].GptChannelId), GPTMTAMR_TACDIR_BIT);
    }
}

/******************************************************************************
* \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType Channel)        
* \Description     : Disables the Notifications for GPT                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                      
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* Disable the Timer match interrupt */
    CLEAR_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_BIT);
}

/******************************************************************************
* \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType Channel)        
* \Description     : Enables the Notifications for GPT                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                      
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* Enable the timer time-out interrupt */
    SET_BIT(GPTMIMR(Channel), GPTMIMR_TATOIM_BIT);
}

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
void Gpt_StartTimerPollingMode(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAILR Register */
    GPTMTAILR(Channel) = Value;
    
    /* Start counting */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);

    /* Wait untill the flag is 1 */
    while(BIT_IS_CLEAR(GPTMRIS(Channel),GPTMRIS_TATORIS_BIT)){}

    /* Clear the TimeOut Interrupt Flag */
    SET_BIT(GPTMICR(Channel),GPTMICR_TATOCINT_BIT);
}

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
void Gpt_StartTimerInterruptMode(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAILR Register */
    GPTMTAILR(Channel) = Value;
    
    /* Start counting */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}


/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel)        
* \Description     : Stops the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* Stop counting */
    CLEAR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)        
* \Description     : Return the Elapsed Time of the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : ElapsedTime                              
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    uint8 Counter, Prescaler_Bits;
    uint32 ElapsedCounts = 0x0;
    float32 ElapsedTime = 0x0;
    for(Counter = 0; Counter < GPT_CONFIGURED_TIMERS; Counter++)
    {
        if(GptConfigArray[Counter].GptChannelId == Channel)
        {
            Prescaler_Bits = GptConfigArray[Counter].GptChannelTickFrequency;
            /* We want to move the 16 bits right to get the required time including the prescaler used */
            ElapsedCounts = (GPTMTAV(Channel) & (0x0000FFFF << Prescaler_Bits)) >> Prescaler_Bits;
            ElapsedTime = (1.0 / 16000000UL) * ElapsedCounts;
            break;
        }
    }
    return ElapsedTime;
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)        
* \Description     : Return the Remaining Time of the timer                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Pin number of a certain port                   
* \Parameters (out): None                                                      
* \Return value:   : RemainingTime                              
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    uint8 Counter, Prescaler_Bits;
    uint32 ElapsedCounts = 0x0;
    uint32 RemainingCounts = 0x0;
    float32 RemainingTime = 0x0;
    for(Counter = 0; Counter < GPT_CONFIGURED_TIMERS; Counter++)
    {
        if(GptConfigArray[Counter].GptChannelId == Channel)
        {
            Prescaler_Bits = GptConfigArray[Counter].GptChannelTickFrequency;
            /* We want to move the 16 bits right to get the required time including the prescaler used */
            ElapsedCounts = (GPTMTAV(Channel) & (0x0000FFFF << Prescaler_Bits)) >> Prescaler_Bits;
            break;
        }
    }
    RemainingCounts = (GPTMTAMATCHR(Channel) - RemainingCounts);
    RemainingTime = (1.0 / 16000000UL) * RemainingCounts;
    return RemainingTime;
}

/******************************************************************************
* \Syntax          : void TIMER0A_Handler(void)        
* \Description     : Handler of Timer0A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_0])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_0), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void TIMER1A_Handler(void)        
* \Description     : Handler of Timer1A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_1])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_1), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void TIMER2A_Handler(void)        
* \Description     : Handler of Timer2A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_2])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_2), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void TIMER3A_Handler(void)        
* \Description     : Handler of Timer3A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_3])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_3), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void TIMER4A_Handler(void)        
* \Description     : Handler of Timer4A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_4])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_4), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void TIMER5A_Handler(void)        
* \Description     : Handler of Timer5A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void TIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_5])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_TIMER_5), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER0A_Handler(void)        
* \Description     : Handler of Wide Timer0A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_0])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_0), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER1A_Handler(void)        
* \Description     : Handler of Wide Timer1A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_1])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_1), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER2A_Handler(void)        
* \Description     : Handler of Wide Timer2A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_2])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_2), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER3A_Handler(void)        
* \Description     : Handler of Wide Timer3A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_3])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_3), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER4A_Handler(void)        
* \Description     : Handler of Wide Timer4A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_4])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_4), GPTMICR_TATOCINT_BIT);
    }
}

/******************************************************************************
* \Syntax          : void WTIMER5A_Handler(void)        
* \Description     : Handler of Wide Timer5A                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                  
* \Parameters (out): None                                                      
* \Return value:   : None                              
*******************************************************************************/
void WTIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_5])();
        /* Clear the TimeOut Interrupt Flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_5), GPTMICR_TATOCINT_BIT);
    }
}


/**********************************************************************************************************************
 *  END OF FILE: GPT.c
 *********************************************************************************************************************/