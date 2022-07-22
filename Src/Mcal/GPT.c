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
static void (*Gpt_CallBackPtr[GPT_NUMBER_OF_TIMERS])(void) = {NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR,
                                                              NULL_PTR, NULL_PTR, NULL_PTR};
                                                                
                                                                


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
    for(counter = 0; counter < GPT_CONFIGURED_TIMERS; counter++)
    {
        /* Give an error if the user chose a max tick value higher than the chosen timer */
        //ASSERT(ConfigPtr[counter].GptChannelId < 6 && ConfigPtr[counter].GptChannelTickValueMax > 65536);

        /* Give an error if the user chose the normal timers and chose prescaler higher than 256 */
        //ASSERT(ConfigPtr[counter].GptChannelId < 6 && ConfigPtr[counter].GptChannelId >= 8);

        /* Set the callback function */
        Gpt_CallBackPtr[ConfigPtr[counter].GptChannelId] = ConfigPtr[counter].GptNotification;

        /* Get the required to be set in the corressponding register whether it is in RCGCTIMER or in RCGCWTIMER */
        uint8 ReqBit = ConfigPtr[counter].GptChannelId < 6 ? (ConfigPtr[counter].GptChannelId):(ConfigPtr[counter].GptChannelId - 6);

        /* Enable Clock for the desired Timer Channel */
        SET_BIT(SYSCTL_RCGC_TIMER(ConfigPtr[counter].GptChannelId), ReqBit);

        /* Disable the desired timer channel in GPTMCTL */
        CLEAR_BIT(GPTMCTL(ConfigPtr[counter].GptChannelId), GPTMCTL_TAEN_BIT);

        /* For a 16/32-bit timer, this value selects the 16-bit timer configuration */
        GPTMCFG(ConfigPtr[counter].GptChannelId) = 0x4;

        /* Insert the required mode in the first 2 bits of GPTMAMR Register */
        GPTMTAMR(ConfigPtr[counter].GptChannelId) |= ConfigPtr[counter].GptChannelMode;

        /* Select Count up Mode */
        SET_BIT(GPTMTAMR(ConfigPtr[counter].GptChannelId), GPTMTAMR_TACDIR_BIT);

        /* Insert the required prescaler in the GPTMAPTR */
        GPTMTAPR(ConfigPtr[counter].GptChannelId) = ConfigPtr[counter].GptChannelTickFrequency;
    }
}

void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    /* Disable the Timer interrupt */
    CLEAR_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);

    /* Disable the Timer match interrupt */
    CLEAR_BIT(GPTMIMR(Channel), GPTMIMR_TAMIM_BIT);
}

void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    /* Enable the Timer interrupt */
    SET_BIT(GPTMTAMR(Channel), GPTMTAMR_TAMIE_BIT);  

    /* Enable the timer match interrupt */
    SET_BIT(GPTMIMR(Channel), GPTMIMR_TAMIM_BIT);
    
    /* Enable the timer match interrupt */
//    SET_BIT(GPTMIMR(Channel), 2);
//    /* Enable the timer match interrupt */
//    SET_BIT(GPTMIMR(Channel), 1);
//    /* Enable the timer match interrupt */
//    SET_BIT(GPTMIMR(Channel), 0);
}

void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    /* Load the value in GPTMTAMATCHR Register */
    GPTMTAMATCHR(Channel) = Value;

    /* Start counting */
    SET_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}

void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    /* Stop counting */
    CLEAR_BIT(GPTMCTL(Channel), GPTMCTL_TAEN_BIT);
}

/**************************************************************************/
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
/***************************************************************************/


void TIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_0])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_0), GPTMICR_TAMCINT_BIT);
    }
}

void TIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_1])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_1), GPTMICR_TAMCINT_BIT);
    }
}

void TIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_2])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_2), GPTMICR_TAMCINT_BIT);
    }
}

void TIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_3])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_3), GPTMICR_TAMCINT_BIT);
    }
}

void TIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_4])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_4), GPTMICR_TAMCINT_BIT);
    }
}

void TIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_TIMER_5])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_TIMER_5), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER0A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_0]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_0])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_0), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER1A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_1]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_1])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_1), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER2A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_2]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_2])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_2), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER3A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_3]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_3])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_3), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER4A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_4]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_4])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_4), GPTMICR_TAMCINT_BIT);
    }
}

void WTIMER5A_Handler(void)
{
    if(Gpt_CallBackPtr[GPT_WIDE_TIMER_5]!= NULL_PTR)
    {
        (*Gpt_CallBackPtr[GPT_WIDE_TIMER_5])();
        /* Clear the TAMCINT flag */
        SET_BIT(GPTMICR(GPT_WIDE_TIMER_5), GPTMICR_TAMCINT_BIT);
    }
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/