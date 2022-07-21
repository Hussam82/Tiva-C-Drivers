#include "IntCtrl.h"
#include "GPT.h"
uint8 x = 0;
void Gpt_Notification_Timer1()
{
	x++;	
}



int main(void)
{
	
	IntCrtl_Init();
	Gpt_Init(GptConfigArray);
	Gpt_EnableNotification(GPT_TIMER_1);
	Gpt_StartTimer(GPT_TIMER_1, 1000);
	while(1)
	{
		 
	}
	
}
