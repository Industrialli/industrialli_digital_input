#include "industrialli_hub.hpp"

industrialli_hub hub;

void my_function(){
    Serial.println("Hello industrialli!");
}

void setup(){
    hub.begin();

    /* Inicializa a biblioteca de entradas digitais.
     */
    digital_input.begin();

    /* Anexa a função my_function na entrada digital
     * A01 para ser executada a cada interrupção de um
     * sensor PNP.
     */
    digital_input.attach_interrupt(I01, my_function, PNP);
}

void loop(){
    digital_input.update_leds();
    leds.update();
    delay(10);
}