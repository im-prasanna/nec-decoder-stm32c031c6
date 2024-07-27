#include <stdint.h>
#include <stdlib.h>

#include "gpio.h"
#include "rcc.h"
#include "nvic.h"
#include "exti.h"
#include "systick.h"
#include "lcd.h"

uint32_t timer = 0;
uint32_t count = 0;
int start = 0;
uint32_t data;

void nec_init();

int main(void){
	nec_init();
	lcd_init();
	lcd_entryModeSet(1,0);
	lcd_displayControl(1,1,1);
	lcd_clear();
	lcd_print("--NEC DECODER--");

	for(;;);
}
void nec_init(){
	RCC->IOPENR |= (1<<0);								//Enable Port A

	GPIOA->MODER &= ~((0b11));							// PA0 as INPUT
	GPIOA->PUPDR &= ~((0b11) );							// No PULL Up/Down for PA0

	EXTI->EXTICR[0] &= ~(0xFF);
	EXTI->IMR1 |= 0b1;
	EXTI->FTSR1 |= 0b1;									// Set interrupt for rising edge
	EXTI->RTSR1 |= 0b1;									// Set interrupt for Falling edge
	NVIC_EnableIRQ(EXTI0_1_IRQn);

}
void nec_decoder(){
	char buff[10];
	if(count==2 && timer>15){
		start = 1;
	}
	if((count>2 && count < 35) && start == 1){
		data <<= 1;
		if(timer>=4) data |= 0b1;
	}
	if(count==34){
		itoa(((data>>8)&0xFF), buff, 10);
		lcd_clear();
		lcd_print("Command: ");
		lcd_print(buff);
		count=0;
	}
}
void SysTick_timer_start(){
	timer = 0;

	SYSTICK->CSR |= (1<<2) | (1<<1);	 //clock source - processor, TICKINT
	SYSTICK->CSR &= ~1;  				//Disable counter

//	SYSTICK->RVR |= 0xBB80; 			//Reload value = 48000
//	SYSTICK->RVR &= ~(0xFF447F);

	SYSTICK->RVR &= ~(0xFFFFFF);
	SYSTICK->RVR |= 0x2EE0; 			//Reload value = 12000


	SYSTICK->CVR &= ~(0xFFFFFF);

	SYSTICK->CSR |= 0b1; 				//Enable timer
}

void SysTick_timer_stop(){
	SYSTICK->CSR &= ~0b1; 					//Stop timer
}
void SysTick_Handler(void)
{
	timer++;
}
void EXTI0_1_IRQHandler(void){
	if ((EXTI->RPR1 & (0x01)) != 0U){
		EXTI->RPR1 |= 0x01;
		SysTick_timer_start();
	}
	if ((EXTI->FPR1 & (0x01)) != 0U){
		EXTI->FPR1 |= 0x01;
		SysTick_timer_stop();
		count++;
		nec_decoder();
	}
}
