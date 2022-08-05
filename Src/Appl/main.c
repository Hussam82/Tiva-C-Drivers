#include "IntCtrl.h"
#include "GPT.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu_Hw.h"
#include "LED.h"
#include "Button.h"
/* Global Variable to hold the ticks as each tick is 1 second */
static volatile uint8 g_Ticks = 0;

/* Global Variable to hold the On Time for the LED */
static volatile uint8 g_OnTime = 1;

/* Global Variable to hold the Off Time for the LED */
static volatile uint8 g_OffTime = 2;

/* Global Variable to hold the Off Time for the LED */
static volatile uint8 g_BlinkCount = 0;

/* Callback function of Timer1A */
void Gpt_Notification_Timer1()
{
	if(g_Ticks == g_OnTime)
	{
		/* Turn off the Led */
		Led_Off();
	}
	else if(g_Ticks == g_OffTime + g_OnTime)
	{
		/* Turn on The Led */
		Led_On();
		
		/* Reset the counts to start over */
		g_Ticks = 0;
		g_BlinkCount++;
	}
	/* To change the values of on time and off time when the led blinks 2 times*/ 
	if(g_BlinkCount == 3)
	{
		//g_Ticks = 0;
		g_OnTime = 2;
		g_OffTime = 4;
	}
	/* Each tick is 1 second, increment the counts */
	g_Ticks++;
}



int main(void)
{
	/* Initialize the NVIC and open the Gate for Timer1A */
	IntCrtl_Init();

	/* Initialize the Gpt Timer1A */
	Gpt_Init(GptConfigArray);

	/* Initialize the Port with PIN_F1 as DIO */
	Port_Init(PortConfigArray);
	
	/* Enable the Notification for Timer1A */
	Gpt_EnableNotification(GPT_TIMER_1);

	/* Start the timer in periodic mode with an interrupt every 1 second */
	Gpt_StartTimerInterruptMode(GPT_TIMER_1, 64000 - 1);

	while(1)
	{
		 
	}
}
