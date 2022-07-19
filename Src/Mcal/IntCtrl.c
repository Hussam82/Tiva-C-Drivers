/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "IntCtrl_Regs.h"
#include "SCB_Regs.h"
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
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    SCB_PERIPH->APINT = INTCTRL_GROUP_SUB_DIST;
    uint8 intNumber,intPosition,intPriNumber;
    /* Loop to cover all the interrupts in the config struct array */
    for(intNumber = 0; intNumber < NUM_INTERRUPTS; intNumber++)
    {
        IntCtrl_ConfigStruct currentInt = InterruptsConfigArray.InterruptStruct[intNumber];
		if(intNumber == 25 || intNumber == 26 || intNumber == 27)
			continue;
        intPriNumber = currentInt.InterrupPeripheralGates / 4;       /* Get the correct PRI register number */ 
        intPosition = currentInt.InterrupPeripheralGates % 4;        /* Get the position of the interrupt inside PRI register */
        /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/ 
        /* Setting the Priority of the interrupt */
        switch (intPosition)
        {
            case 0:
                INTCTRL_PERIPH->PRIx[intPriNumber] |= (currentInt.InterruptPeripheralPriority << 5); /* Insert the the priority in the corresponding 3 bits in PRI register */
                break;
            case 1:
                INTCTRL_PERIPH->PRIx[intPriNumber] |= (currentInt.InterruptPeripheralPriority << 13); /* Insert the the priority in the corresponding 3 bits in PRI register */
                break;
            case 2:
                INTCTRL_PERIPH->PRIx[intPriNumber] |= (currentInt.InterruptPeripheralPriority << 21); /* Insert the the priority in the corresponding 3 bits in PRI register */
                break;
            case 3:
                INTCTRL_PERIPH->PRIx[intPriNumber] |= (currentInt.InterruptPeripheralPriority << 29); /* Insert the the priority in the corresponding 3 bits in PRI register */
                break;
            default:
                break;
        }
        /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        /* Enabling the Interrupt */
        if(currentInt.InterruptPeripheralState == ENABLED)
        {
            if(currentInt.InterrupPeripheralGates >= 0 && currentInt.InterrupPeripheralGates <= 31)
            {
                SET_BIT(INTCTRL_PERIPH->ENx[0], currentInt.InterrupPeripheralGates);
            }
            else if(currentInt.InterrupPeripheralGates >= 32 && currentInt.InterrupPeripheralGates <= 63)
            {
                SET_BIT(INTCTRL_PERIPH->ENx[1], currentInt.InterrupPeripheralGates - 32);
            }
            else if(currentInt.InterrupPeripheralGates >= 64 && currentInt.InterrupPeripheralGates <= 95)
            {
                SET_BIT(INTCTRL_PERIPH->ENx[2], currentInt.InterrupPeripheralGates - 64);
            }
            else if(currentInt.InterrupPeripheralGates >= 96 && currentInt.InterrupPeripheralGates < 127)
            {
                SET_BIT(INTCTRL_PERIPH->ENx[3], currentInt.InterrupPeripheralGates - 96);
            }
            else
            {
                SET_BIT(INTCTRL_PERIPH->ENx[4], currentInt.InterrupPeripheralGates - 128);
            }
				}
        else if(currentInt.InterruptPeripheralState == DISABLED)
        {
            if(currentInt.InterrupPeripheralGates >= 0 && currentInt.InterrupPeripheralGates <= 31)
            {
                SET_BIT(INTCTRL_PERIPH->DISx[0], currentInt.InterrupPeripheralGates);
            }
            else if(currentInt.InterrupPeripheralGates >= 32 && currentInt.InterrupPeripheralGates <= 63)
            {
                SET_BIT(INTCTRL_PERIPH->DISx[1], currentInt.InterrupPeripheralGates - 32);
            }
            else if(currentInt.InterrupPeripheralGates >= 64 && currentInt.InterrupPeripheralGates <= 95)
            {
                SET_BIT(INTCTRL_PERIPH->DISx[2], currentInt.InterrupPeripheralGates - 64);
            }
            else if(currentInt.InterrupPeripheralGates >= 96 && currentInt.InterrupPeripheralGates < 127)
            {
                SET_BIT(INTCTRL_PERIPH->DISx[3], currentInt.InterrupPeripheralGates - 96);
            }
            else
            {
                SET_BIT(INTCTRL_PERIPH->DISx[4], currentInt.InterrupPeripheralGates - 128);
            }
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
