#include "systicks.h"
#include "stm32f10x.h"

static u16 fac_ms;
void DELAY_Init(){
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_ms = SystemCoreClock/8000;
}

void DELAY_ms(int ms){
	u32 temp;
	SysTick->LOAD = (u32)ms*fac_ms;
	SysTick->VAL = 0x00;
	SysTick->CTRL|=1<<0; //使能
	do{
		temp=SysTick->CTRL;
	}while(!(temp&1<<16)&&(temp&1<<0)); //16：到0
	SysTick->CTRL&=0<<0;
	SysTick->VAL=0x00;


}
