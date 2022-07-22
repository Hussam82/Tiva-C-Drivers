/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_REGS_H
#define PORT_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/* General-Purpose Timer Registers */

#if  GPIO_MODE == GPIO_APB
#define GPIO_PORT_A_OFFSET      0x40004000   
#define GPIO_PORT_B_OFFSET      0x40005000
#define GPIO_PORT_C_OFFSET      0x40006000
#define GPIO_PORT_D_OFFSET      0x40007000
#define GPIO_PORT_E_OFFSET      0x40024000
#define GPIO_PORT_F_OFFSET      0x40025000
#define GPIO_OFFSET(x)		    (x<4? ((GPIO_PORT_A_OFFSET) + ((x)*0x1000)):((GPIO_PORT_E_OFFSET) + ((x-4)*0x1000)))
#elif  GPIO_MODE == GPIO_AHB
#define GPIO_PORT_A_OFFSET      0x40058000
#define GPIO_PORT_B_OFFSET      0x40059000
#define GPIO_PORT_C_OFFSET      0x4005A000
#define GPIO_PORT_D_OFFSET      0x4005A000
#define GPIO_PORT_E_OFFSET      0x4005C000
#define GPIO_PORT_F_OFFSET      0x4005D000
#define GPIO_OFFSET(x)		    (x<4? ((GPIO_PORT_A_OFFSET) + ((x)*0x1000)):((GPIO_PORT_E_OFFSET) + ((x-4)*0x1000)))
#else
#error "Choose a valid GPIO bus"
#endif

/* By using Bit Specific addressing to access the GPIODATA register for each port */
#define GPIODATA_PORT_PIN(x,y)      *((volatile uint32*)(GPIO_OFFSET(x) + (1<<(2 + y))))    /* This macro to be able to write to a pin y in port x */
#define GPIODATA(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x3FC))           /* If written to this register, it will write to the whole port */

#define GPIODIR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x400))
#define GPIOIS(x)                   *((volatile uint32*)(GPIO_OFFSET(x) + 0x404))
#define GPIOIBE(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x408))
#define GPIOIEV(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x40C))
#define GPIOIM(x)                   *((volatile uint32*)(GPIO_OFFSET(x) + 0x410))
#define GPIORIS(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x414))
#define GPIOMIS(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x418))
#define GPIOICR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x41C))
#define GPIOAFSEL(x)                *((volatile uint32*)(GPIO_OFFSET(x) + 0x420))
#define GPIODR2R(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x500))
#define GPIODR4R(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x504))        
#define GPIODR8R(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x508))
#define GPIOODR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x50C))
#define GPIOPUR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x510))
#define GPIOPDR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x514))
#define GPIOSLR(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x518))
#define GPIODEN(x)                  *((volatile uint32*)(GPIO_OFFSET(x) + 0x51C))
#define GPIOLOCK(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x520))
#define GPIOCR(x)                   *((volatile uint32*)(GPIO_OFFSET(x) + 0x524))
#define GPIOAMSEL(x)                *((volatile uint32*)(GPIO_OFFSET(x) + 0x528))
#define GPIOPCTL(x)                 *((volatile uint32*)(GPIO_OFFSET(x) + 0x52C))
#define GPIOADCCTL(x)               *((volatile uint32*)(GPIO_OFFSET(x) + 0x530))
#define GPIODMACTL(x)               *((volatile uint32*)(GPIO_OFFSET(x) + 0x534))
#define GPIOPeriphID4(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFD0))
#define GPIOPeriphID5(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFD4))
#define GPIOPeriphID6(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFD8))
#define GPIOPeriphID7(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFDC))
#define GPIOPeriphID0(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFE0))
#define GPIOPeriphID1(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFE4))
#define GPIOPeriphID2(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFE8))
#define GPIOPeriphID3(x)            *((volatile uint32*)(GPIO_OFFSET(x) + 0xFEC))
#define GPIOPCellID0(x)             *((volatile uint32*)(GPIO_OFFSET(x) + 0xFF0))
#define GPIOPCellID1(x)             *((volatile uint32*)(GPIO_OFFSET(x) + 0xFF4))
#define GPIOPCellID2(x)             *((volatile uint32*)(GPIO_OFFSET(x) + 0xFF8))
#define GPIOPCellID3(x)             *((volatile uint32*)(GPIO_OFFSET(x) + 0xFFC))

/* General-Purpose Timer Run Mode Clock Gating Control */
#define SYSCTL_RCGCGPIO_ADDRESS     0x400FE608   
#define SYSCTL_RCGCGPIO_REG         *((volatile uint32 *)SYSCTL_RCGCGPIO_ADDRESS)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_REGS_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Regs.h
 *********************************************************************************************************************/