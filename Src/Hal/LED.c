/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LED.c
 *        \brief  LED Driver
 *
 *      \details  Turns on/off the chosen LED
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "LED.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Led_On(void)        
* \Description     : Turns on the LED                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Led_On(void)
{
	/* Write 1 to the pin connected to the LED */
	Dio_WriteChannel(LED_CHANNEL, LED_ON);
}

/******************************************************************************
* \Syntax          : void Led_Off(void)        
* \Description     : Turns off the LED                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Led_Off(void)
{
	/* Write 0 to the pin connected to the LED */
	Dio_WriteChannel(LED_CHANNEL, LED_OFF);
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/