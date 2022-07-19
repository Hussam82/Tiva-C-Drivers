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
#define WIDE_TIMER_2_BASE_ADDRESS       0x4003C000
#define WIDE_TIMER_3_BASE_ADDRESS       0x4003D000
#define WIDE_TIMER_4_BASE_ADDRESS       0x4003E000
#define WIDE_TIMER_5_BASE_ADDRESS       0x4003F000
#define GPTPP_OFFSET                    0x00000FC0

/* Pointers to the same structure as each timer has the same registers */
#define GPT_TIMER_0_PERIPH                         ((volatile GPT_Regs*)TIMER_0_BASE_ADDRESS)        
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
#define GPT_WIDE_TIMER_5_PERIPH                    ((volatile GPT_Regs*)WIDE_TIMER_5_BASE_ADDRESS)   

/* The last register has its own offset outside the structure */
#define GPT_TIMER_0_GPTPP                         ((volatile GPT_Regs*)TIMER_0_BASE_ADDRESS + GPTPP_OFFSET)        
#define GPT_TIMER_1_GPTPP                         ((volatile GPT_Regs*)TIMER_1_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_2_GPTPP                         ((volatile GPT_Regs*)TIMER_2_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_3_GPTPP                         ((volatile GPT_Regs*)TIMER_3_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_4_GPTPP                         ((volatile GPT_Regs*)TIMER_4_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_TIMER_5_GPTPP                         ((volatile GPT_Regs*)TIMER_5_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_0_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_0_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_1_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_1_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_2_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_2_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_3_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_3_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_4_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_4_BASE_ADDRESS + GPTPP_OFFSET)      
#define GPT_WIDE_TIMER_5_GPTPP                    ((volatile GPT_Regs*)WIDE_TIMER_5_BASE_ADDRESS + GPTPP_OFFSET)   

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
typedef struct{
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
}GPT_Regs;

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
