#include "IntCtrl.h"
#include "GPT.h"
#include "Port.h"
#include "Dio.h"
#include "Mcu_Hw.h"
/* Global Variable to hold the ticks as each tick is 1 second */
static volatile uint8 g_Ticks = 0;

/* Global Variable to hold the On Time for the LED */
static volatile uint8 g_OnTime = 4;

/* Global Variable to hold the Off Time for the LED */
static volatile uint8 g_OffTime = 6;

/* Callback function of Timer1A */
void Gpt_Notification_Timer1()
{
	/* Each tick is 1 second, increment the counts */
	g_Ticks++;

	if(g_Ticks == g_OnTime)
	{
		/* Turn off the Led */
		Dio_WriteChannel(PORT_F1, PIN_LOW);
	}
	else if(g_Ticks == g_OffTime + g_OnTime)
	{
		/* Turn on The Led */
		Dio_WriteChannel(PORT_F1, PIN_HIGH);
		
		/* Reset the counts to start over */
		g_Ticks = 0;
	}
}



int main(void)
{
	/* Initialize the NVIC and open the Gate for Timer1A */
	IntCrtl_Init();

	/* Initialize the Gpt Timer1A */
	Gpt_Init(GptConfigArray);

	/* Initialize the Port with PIN_F1 as DIO */
	Port_Init(PortConfigArray);
	
	Dio_WritePort(PORT_F1, PIN_HIGH);
	
	/* Enable the Notification for Timer1A */
	Gpt_EnableNotification(GPT_TIMER_1);

	/* Start the timer in periodic mode with an interrupt every 1 second */
	Gpt_StartTimerInterruptMode(GPT_TIMER_1, 64000 - 1);

	while(1)
	{
		 
	}
}
