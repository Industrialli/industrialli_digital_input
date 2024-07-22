#include "industrialli_hub.hpp"

industrialli_hub hub;

volatile uint64_t counts_i03 = 0;
volatile uint64_t counts_i04 = 0;

void count_interruptions_i03(){
	__disable_irq();
	counts_i03++;
	__enable_irq();
}

void count_interruptions_i04(){
	__disable_irq();
	counts_i04++;
	__enable_irq();
}

int main(){
    hub.begin();

	digital_input.begin();
	digital_input.attach_interrupt(I03, count_interruptions_i03, GPIO_MODE_IT_FALLING);
	digital_input.attach_interrupt(I04, count_interruptions_i04, GPIO_MODE_IT_RISING);
	
	
    while(1){
		digital_input.update_leds();
		leds.update();

		HAL_Delay(1);
	}
}