/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
 *        \brief  Port Link Configurations
 *
 *      \details  The Link stage configurations for the Port Driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/* Note: You have to configure the number of Port Pin in Cfg.h */
/*  Options for Channel ID:
    PORT_A0, PORT_A1, PORT_A2, PORT_A3, PORT_A4, PORT_A5, PORT_A6, PORT_A7,
    PORT_B0, PORT_B1, PORT_B2, PORT_B3, PORT_B4, PORT_B5, PORT_B6, PORT_B7,
    PORT_C0, PORT_C1, PORT_C2, PORT_C3, PORT_C4, PORT_C5, PORT_C6, PORT_C7,
    PORT_D0, PORT_D1, PORT_D2, PORT_D3, PORT_D4, PORT_D5, PORT_D6, PORT_D7,
    PORT_E0, PORT_E1, PORT_E2, PORT_E3, PORT_E4, PORT_E5, PORT_E6, PORT_E7,
    PORT_F0, PORT_F1, PORT_F2, PORT_F3, PORT_F4, PORT_F5, PORT_F6, PORT_F7
*/

/*  Options for Channel Direction:
    PORT_PIN_INPUT, PORT_PIN_OUTPUT
*/

/*  Options for Default Channel Value in case of Output Direction:
    PORT_PIN_LOW_LEVEL, PORT_PIN_HIGH_LEVEL
*/

/*  Options for Channel Mode:
    PORT_DIO_MODE, PORT_AF_1_MODE, PORT_AF_2_MODE, PORT_AF_3_MODE, PORT_AF_4_MODE,
    PORT_AF_5_MODE, PORT_AF_6_MODE, PORT_AF_7_MODE, PORT_AF_8_MODE, PORT_AF_9_MODE,
    PORT_AF_10_MODE, PORT_AF_11_MODE, PORT_AF_12_MODE, PORT_AF_13_MODE,PORT_AF_14_MODE,
    PORT_ADC_MODE
*/

/*  Options for Internal Attach Mode:
    PORT_INTERNAL_RESISTOR_OFF, PORT_INTERNAL_PULL_UP_MODE,
    PORT_INTERNAL_PULL_DOWN_MODE, PORT_OPEN_DRAIN_MODE
*/

/*  Options for Channel Drive Strength 
    PORT_2MA_OUTPUT_CURRENT, PORT_4MA_OUTPUT_CURRENT, PORT_8MA_OUTPUT_CURRENT
*/
const Port_ConfigType PortConfigArray[PORT_CONFIGURED_PINS] = 
{
    {PORT_A0, PORT_PIN_OUTPUT, PORT_PIN_LOW_LEVEL, PORT_DIO_MODE, PORT_INTERNAL_PULL_DOWN_MODE, PORT_2MA_OUTPUT_CURRENT},
    {PORT_A1, PORT_PIN_OUTPUT, PORT_PIN_LOW_LEVEL, PORT_DIO_MODE, PORT_INTERNAL_PULL_DOWN_MODE, PORT_2MA_OUTPUT_CURRENT},
    {PORT_B2, PORT_PIN_OUTPUT, PORT_PIN_LOW_LEVEL, PORT_DIO_MODE, PORT_INTERNAL_PULL_DOWN_MODE, PORT_2MA_OUTPUT_CURRENT},
    {PORT_B3, PORT_PIN_OUTPUT, PORT_PIN_LOW_LEVEL, PORT_DIO_MODE, PORT_INTERNAL_PULL_DOWN_MODE, PORT_2MA_OUTPUT_CURRENT}
};


/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 ***************************/