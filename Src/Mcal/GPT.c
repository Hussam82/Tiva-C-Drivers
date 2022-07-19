/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "GPT_Regs.h"
#include "GPT.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (*Gpt_CallBackPtr[GPT_NUMBER_OF_TIMERS])(void) = {NULL_PTR};


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
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{   
    /* Initialize the timer */
    uint8 counter;
    for(counter = 0; counter < GPT_CONFIG_NUM_TIMERS; counter++)
    {

        /* Set the callback function */
        Gpt_CallBackPtr[ConfigPtr[counter].GptChannelId] = ConfigPtr[counter].GptNotification;

        /* Get the required to be set in the corressponding register whether it is in RCGCTIMER or in RCGCWTIMER */
        uint8 ReqBit = ConfigPtr[counter].GptChannelId < 6 ? (ConfigPtr[counter].GptChannelId):(ConfigPtr[counter].GptChannelId - 6);

        /* Enable Clock for the desired Timer Channel */
        SET_BIT(RCGC_TIMER(ConfigPtr[counter].GptChannelId), ReqBit);

        /* Disable the desired timer channel in GPTMCTL */
        CLEAR_BIT(GPTMCTL(ConfigPtr[counter].GptChannelId), GPTMCTL_TAEN_BIT);

        /* Write the GPTM Configuration Register (GPTMCFG) with a value of 0x00000000 */
        GPTMCFG(ConfigPtr[counter].GptChannelId) = 0x0;

        /* Insert the required mode in the first 3 bits of GPTMAMR Register */
        GPTMTAMR(ConfigPtr[counter].GptChannelId) |= ConfigPtr[counter].GptChannelMode;

        /* Enable the Timer Match Interrupt Mask */
        SET_BIT(GPTMTAMR(ConfigPtr[counter].GptChannelId), GPTMTAMR_TAMIE_BIT);

        /* Enable the Timer Time-Out Interrupt Mask */
        SET_BIT(GPTMTAMR(ConfigPtr[counter].GptChannelId), GPTMIMR_TATOIM_BIT);

        /* Select Count up Mode */
        SET_BIT(GPTMTAMR(ConfigPtr[counter].GptChannelId), GPTMTAMR_TACDIR_BIT);

        /* Enable the timer match interrupt */
        SET_BIT(GPTMIMR(ConfigPtr[counter].GptChannelId), GPTMIMR_TAMIM_BIT);
    
    }
}

void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* Disable the Timer interrupt */
    CLEAR_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);
}

void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* Enable the Timer interrupt */
    SET_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);    
}

void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAILR Register */
    GPTMTAILR(Channel) = Value;

    /* Start counting */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}

void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* Stop counting */
    CLEAR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}



void TIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_0])();
    }
}

void TIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_1])();
    }
}

void TIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_2])();
    }
}

void TIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_3])();
    }
}

void TIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_4])();
    }
}

void TIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_5])();
    }
}

void WTIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_0])();
    }
}

void WTIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_1])();
    }
}

void WTIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_2])();
    }
}

void WTIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_3])();
    }
}

void WTIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_4])();
    }
}

void WTIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_5])();
    }
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/