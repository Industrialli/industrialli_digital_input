#include "industrialli_hub.hpp"
#include <cmath>

using namespace std;

industrialli_hub hub;

volatile uint32_t encoder_last_update = 0;
volatile uint32_t encoder_last_count  = 0;
volatile int count                    = 0;
volatile double encoder_velocity      = 0;
volatile bool encoder_sense = true;
volatile int encoder_a;
volatile int encoder_b;

void count_encoder_interruption();

int main(){
    hub.begin();

	digital_input.begin();
	digital_input.attach_interrupt(I01, count_encoder_interruption, GPIO_MODE_IT_RISING);
	
	
    while(1){
		digital_input.update_leds();
		leds.update();

		HAL_Delay(1);
	}
}

void count_encoder_interruption(){
	__disable_irq();
   
	encoder_a = HAL_GPIO_ReadPin(EXTI_01_PE15_GPIO_Port, EXTI_01_PE15_Pin);
	encoder_b = HAL_GPIO_ReadPin(EXTI_02_PE14_GPIO_Port, EXTI_02_PE14_Pin);

	if(encoder_last_update - HAL_GetTick() >= 150){
		encoder_velocity    = (60000.0 * abs((int32_t)encoder_last_count - count)) / (400.0 * abs((int32_t)encoder_last_update - (int32_t)HAL_GetTick()));
		encoder_last_update = HAL_GetTick();
		encoder_last_count  = count;
	}

	if (encoder_a != encoder_b){
		count++;
		encoder_sense = true;

	}else{
		count--;
		encoder_sense = false;
	}
        
    __enable_irq();
}