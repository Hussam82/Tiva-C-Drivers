/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_REGS_H
#define GPT_REGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_types.h"
#include "Platform_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
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


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
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
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* GPT_REGS_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_Regs.h
 *********************************************************************************************************************/
