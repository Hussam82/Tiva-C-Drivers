#include "IntCtrl.h"
#include "GPT.h"
#include "Port.h"
#include "Dio.h"
uint8 x = 0;
void Gpt_Notification_Timer1()
{
	x++;	
}



int main(void)
{
	
	IntCrtl_Init();
	Gpt_Init(GptConfigArray);
	Port_Init(PortConfigArray);
	Dio_WriteChannel(PIN_A0, PIN_HIGH);
	Dio_WriteChannel(PIN_A1, PIN_HIGH);
	Dio_WriteChannel(PIN_B2, PIN_HIGH);
	Dio_WriteChannel(PIN_B3, PIN_HIGH);
	
	Gpt_EnableNotification(GPT_TIMER_1);
	Gpt_StartTimerInterruptMode(GPT_TIMER_1, 64000 - 1);
	while(1)
	{
		 
	}
}
