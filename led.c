#include "led.h"
#include "stm32f10x.h"

void LED_Init(){
  GPIO_InitTypeDef GPIO_Initstructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);     //RCC->APB2ENR|=1<<3;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
  GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
  GPIO_Initstructure.GPIO.Pin=GPIO_Pin_5;
  GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOB,&GPIO_Initstructure);             //GPIOB->CRL&=0xFF0FFFFF;GPIOB->CRL|=0x00300000;
  GPIO_Init(GPIOE,&GPIO_Initstructure);
}
int main(){
  GPIO_SetBits(GPIOB,GPIO_Pin_5);
  GPIO_ResetBits(GPIOE,GPIO_Pin_5);
  //GPIOB->ODR|=1<<5;
  return 0;
}
