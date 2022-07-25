/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Button.c
 *        \brief  Button Driver
 *
 *      \details  Gets the button value
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Button.h"
#include "Dio.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : uint8 Button_readStatus(uint8 Channel)        
* \Description     : Reads the state of the button                                                                                                                
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel                    
* \Parameters (out): None                                                      
* \Return value:   : button_state                             
*******************************************************************************/
uint8 Button_ReadStatus(uint8 Channel)
{
	/* Variable to hold the state of the button */
	uint8 button_state;

	/* To enable the internal pull up configuration
	 * write 1 to the pin while it is in i/p mode
	 */
    #if(BUTTON_INTERNAL_PULL_UP)
	Dio_writeChannel(Channel, LOGIC_HIGH);
    #endif
	/* Check whether the button is pressed or not */
	if(Dio_ReadChannel(Channel))
	{
		button_state = BUTTON_PRESSED;
	}
	else
	{
		button_state = BUTTON_RELEASED;
	}
	return button_state;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/