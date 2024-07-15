#include "ir.h"
#include "delay.h"
#include "stm32g0xx_hal_tim.h"
#include "tim.h"


void IR_Send(u8 addr,u8 data)
{
	u8 iaddr,idata;
	u32 send_Code;

	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	delay_us(9000);
	HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
	delay_us(4500);
	
	iaddr=~addr;
	idata=~data;
	send_Code = addr<<24 | iaddr<<16 | data<<8 | idata;
	for(int i=31;i>=0;i--){
		HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
		delay_us(560);
		HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
		if((send_Code>>i) & 0x01)
			delay_us(1690);
		else
			delay_us(560);
	}
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	delay_us(560);
	HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
}

































