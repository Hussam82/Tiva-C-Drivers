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
#define RCGCTIMER_ADDRESS               0x400FE604
#define RCGCWTIMER_ADDRESS              0x400FE65C
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


/* Pointers to the same structure as each timer has the same registers */
/* #define GPT_TIMER_0_PERIPH                         ((volatile GPT_Regs*)TIMER_0_BASE_ADDRESS)        
#define GPT_TIMER_1_PERIPH                         ((volatile GPT_Regs*)TIMER_1_BASE_ADDRESS)      
#define GPT_TIMER_2_PERIPH                         ((volatile GPT_Regs*)TIMER_2_BASE_ADDRESS)      
#define GPT_TIMER_3_PERIPH                         ((volatile GPT_Regs*)TIMER_3_BASE_ADDRESS)      
#define GPT_TIMER_4_PERIPH                         ((volatile GPT_Regs*)TIMER_4_BASE_ADDRESS)      
#define GPT_TIMER_5_PERIPH                         ((volatile GPT_Regs*)TIMER_5_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_0_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_0_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_1_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_1_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_2_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_2_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_3_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_3_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_4_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_4_BASE_ADDRESS)      
#define GPT_WIDE_TIMER_5_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_5_BASE_ADDRESS)    */

/* The last register has its own offset outside the structure */
/* #define GPT_TIMER_0_GPTPP                         ((volatile uint32)TIMER_0_BASE_ADDRESS + GPTPP_OFFSET)        
#define GPT_TIMER_1_GPTPP                         ((volatile uint32)TIMER_1_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_2_GPTPP                         ((volatile uint32)TIMER_2_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_3_GPTPP                         ((volatile uint32)TIMER_3_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_4_GPTPP                         ((volatile uint32)TIMER_4_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_5_GPTPP                         ((volatile uint32)TIMER_5_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_0_GPTPP                    ((volatile uint32)WIDE_TIMER_0_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_1_GPTPP                    ((volatile uint32)WIDE_TIMER_1_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_2_GPTPP                    ((volatile uint32)WIDE_TIMER_2_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_3_GPTPP                    ((volatile uint32)WIDE_TIMER_3_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_4_GPTPP                    ((volatile uint32)WIDE_TIMER_4_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_5_GPTPP                    ((volatile uint32)WIDE_TIMER_5_BASE_ADDRESS + GPTPP_OFFSET)    */

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
#define RCGCTIMER               RCGCTIMER_ADDRESS
#define RCGCWTIMER              RCGCWTIMER_ADDRESS
#define RCGC_TIMER(x)           *(volatile uint32*)(x<6? RCGCTIMER:RCGCWTIMER)



/* typedef struct{
    volatile uint32 GPTMCFG;
    volatile uint32 GPTMTAMR;
    volatile uint32 GPTMTBMR;
    volatile uint32 GPTMCTL;
    volatile uint32 GPTMSYNC;
    volatile uint32 GPTMIMR;
    volatile uint32 GPTMRIS;
    volatile uint32 GPTMMIS;
    volatile uint32 GPTMICR;
    volatile uint32 GPTMTAILR;
    volatile uint32 GPTMBILR;
    volatile uint32 GPTMTAMATCHR;
    volatile uint32 GPTMTBMATCHR;
    volatile uint32 GPTMTAPR;
    volatile uint32 GPTMTBPR;
    volatile uint32 GPTMTAPMR;
    volatile uint32 GPTMTBPMR;
    volatile uint32 GPTMTAR;
    volatile uint32 GPTMTBR;
    volatile uint32 GPTMTAV;
    volatile uint32 GPTMTBV;
    volatile uint32 GPTMRTCPD;
    volatile uint32 GPTMTAPS;
    volatile uint32 GPTMTBPS;
    volatile uint32 GPTMTAPV;
    volatile uint32 GPTMTBPV;
}GPT_Regs; */

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
