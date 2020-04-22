#include "stm32f10x.h"
#include "delay.h"
#include "key.h"

void Key_Init(void){
  GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPU; //上拉
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
  GPIO_Init(GPIOE,&GPIO_Initstructure)
  
  GPIO_Initstructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IPD; //下拉
  GPIO_Init(GPIOA,&GPIO_Initstructure);
}

int KEY_Scan (int mode){
  static u8 key_up = 1;//1为没按，0为按下
  if(mode) key_up = 1;
  if(key_up&&KEY==0||KEY1==0||KEY2==0||WK_UP==1)){
	
	key_up=0;
	delay_ms(20);
	if(KEY0==0)return 1;
	else if(KEY1==0)return 2;
	else if(KEY2==0)return 3;
	else if(WK_UP==1)return 4;
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0){
	key_up=1;
  return 0;
}
