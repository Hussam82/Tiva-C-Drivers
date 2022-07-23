/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  NVIC Registers Definitions
 *********************************************************************************************************************/
typedef struct{
    volatile uint32 ENx[5];
    volatile uint32 DISx[5];
    volatile uint32 PENDx[5];
    volatile uint32 UNPENDx[5];
    volatile uint32 ACTIVEx[5];
    volatile uint32 PRIx[35];
}INTCTRL_Regs;
#define INTCTRL_BASE_ADDRESS   0xE000E100
#define INTCTRL_SWTRIG_REG     *((volatile uint32*)0xE000EF00)
#define INTCTRL_PERIPH         ((volatile INTCTRL_Regs*)INTCTRL_BASE_ADDRESS)



/**********************************************************************************************************************
 *  SCB Registers Definitions
 *********************************************************************************************************************/
typedef struct{
    volatile uint32 CPUID;
    volatile uint32 INTCTRL;
    volatile uint32 VTABLE;
    volatile uint32 APINT;
    volatile uint32 SYSCTRL;
    volatile uint32 CFGCTRL;
    volatile uint32 SYSPRI1;
    volatile uint32 SYSPRI2;
    volatile uint32 SYSPRI3;
    volatile uint32 SYSHNDCTRL;
    volatile uint32 FAULTSTAT;\
    volatile uint32 HFAULTSTAT;
    volatile uint32 RESERVED;
    volatile uint32 MMADDR;
    volatile uint32 FAULTADDR;
}SCB_Regs;
#define SCB_BASE_ADDRESS    0xE000ED00
#define SCB_PERIPH          ((volatile SCB_Regs*)SCB_BASE_ADDRESS)


/**********************************************************************************************************************
 *  General Purpose Timer Registers Definitions
 *********************************************************************************************************************/
/* Base Addresses */
#define TIMER_0_BASE_ADDRESS            0x40030000
#define TIMER_1_BASE_ADDRESS            0x40031000
#define TIMER_2_BASE_ADDRESS            0x40032000
#define TIMER_3_BASE_ADDRESS            0x40033000
#define TIMER_4_BASE_ADDRESS            0x40034000
#define TIMER_5_BASE_ADDRESS            0x40035000
#define WIDE_TIMER_0_BASE_ADDRESS       0x40036000
#define WIDE_TIMER_1_BASE_ADDRESS       0x40037000
#define WIDE_TIMER_2_BASE_ADDRESS       0x4004C000
#define WIDE_TIMER_3_BASE_ADDRESS       0x4004D000
#define WIDE_TIMER_4_BASE_ADDRESS       0x4004E000
#define WIDE_TIMER_5_BASE_ADDRESS       0x4004F000
#define SYSCTL_RCGCTIMER_ADDRESS        0x400FE604
#define SYSCTL_RCGCWTIMER_ADDRESS       0x400FE65C

/* Bit fields in GPTMCTL Register */
#define GPTMCTL_TAEN_BIT                   0
/* Bit fields in GPTMTnMR Register */
#define GPTMTAMR_TAMIE_BIT                 5
#define GPTMTAMR_TACDIR_BIT                4
/* Bit fields in GPTMICR Register */
#define GPTMICR_TAMCINT_BIT                  4
/* Bit fields in GPTMIMR Register */
#define GPTMIMR_TAMIM_BIT                  4
#define GPTMIMR_TATOIM_BIT                 0


/* General-Purpose Timer Registers */
#define GPT_OFFSET(x)		    (x<8? ((TIMER_0_BASE_ADDRESS) + ((x)*0x1000)):((WIDE_TIMER_2_BASE_ADDRESS) + ((x-8)*0x1000)))
#define GPTMCFG(x)              *((volatile uint32*)GPT_OFFSET(x))
#define GPTMTAMR(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x004))
#define GPTMTBMR(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x008))
#define GPTMCTL(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x00C))
#define GPTMSYNC(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x010))
#define GPTMIMR(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x018))
#define GPTMRIS(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x01C))
#define GPTMMIS(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x020))
#define GPTMICR(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x024))
#define GPTMTAILR(x)            *((volatile uint32*)(GPT_OFFSET(x) + 0x028))
#define GPTMBILR(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x02C))
#define GPTMTAMATCHR(x)         *((volatile uint32*)(GPT_OFFSET(x) + 0x030))        
#define GPTMTBMATCHR(x)         *((volatile uint32*)(GPT_OFFSET(x) + 0x034))
#define GPTMTAPR(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x038))
#define GPTMTBPR(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x03C))
#define GPTMTAPMR(x)            *((volatile uint32*)(GPT_OFFSET(x) + 0x040))
#define GPTMTBPMR(x)            *((volatile uint32*)(GPT_OFFSET(x) + 0x044))
#define GPTMTAR(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x048))
#define GPTMTBR(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x04C))
#define GPTMTAV(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x050))
#define GPTMTBV(x)              *((volatile uint32*)(GPT_OFFSET(x) + 0x054))
#define GPTMRTCPD(x)            *((volatile uint32*)(GPT_OFFSET(x) + 0x058))
#define GPTMTAPS(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x05C))
#define GPTMTBPS(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x060))
#define GPTMTAPV(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x064))
#define GPTMTBPV(x)             *((volatile uint32*)(GPT_OFFSET(x) + 0x068))
#define GPTMPP(x)               *((volatile uint32*)(GPT_OFFSET(x) + 0xFC0))
/* General-Purpose Timer Run Mode Clock Gating Control */
#define SYSCTL_RCGC_TIMER(x)           *(volatile uint32*)(x<6? SYSCTL_RCGCTIMER_ADDRESS:SYSCTL_RCGCWTIMER_ADDRESS)




/**********************************************************************************************************************
 *  Port Registers Definitions
 *********************************************************************************************************************/
#if GPIO_MODE == GPIO_APB
#define GPIO_PORT_A_OFFSET      0x40004000   
#define GPIO_PORT_B_OFFSET      0x40005000
#define GPIO_PORT_C_OFFSET      0x40006000
#define GPIO_PORT_D_OFFSET      0x40007000
#define GPIO_PORT_E_OFFSET      0x40024000
#define GPIO_PORT_F_OFFSET      0x40025000
#define GPIO_OFFSET(x)		    (x<4? ((GPIO_PORT_A_OFFSET) + ((x)*0x1000)):((GPIO_PORT_E_OFFSET) + ((x-4)*0x1000)))
#elif GPIO_MODE == GPIO_AHB
#define GPIO_PORT_A_OFFSET      0x40058000
#define GPIO_PORT_B_OFFSET      0x40059000
#define GPIO_PORT_C_OFFSET      0x4005A000
#define GPIO_PORT_D_OFFSET      0x4005B000
#define GPIO_PORT_E_OFFSET      0x4005C000
#define GPIO_PORT_F_OFFSET      0x4005D000
#define GPIO_OFFSET(x)		    (GPIO_PORT_A_OFFSET) + ((x)*0x1000)
#else
#error "Choose a valid GPIO bus"
#endif
#define SYSCTL_RCGCGPIO_ADDRESS  0x400FE608   
#define SYSCTL_GPIOHBCTL_ADDRESS 0x400FE06C

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
#define SYSCTL_RCGCGPIO_REG         *((volatile uint32 *)SYSCTL_RCGCGPIO_ADDRESS)
#define SYSCTL_GPIOHBCTL_REG        *((volatile uint32 *)SYSCTL_GPIOHBCTL_ADDRESS)



 

 
#endif  /* MCU_HW_H */