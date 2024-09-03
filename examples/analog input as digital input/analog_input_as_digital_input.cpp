#include "industrialli_hub.hpp"

industrialli_hub hub;

void setup(){
    hub.begin();

    /* Inicializa a biblioteca de entradas digitais.
     */
    digital_input.begin();

    /* Habilita a entrada analógica A03 para funcionar 
     * como uma entrada digital.
     */
    digital_input.enable_analog(A03);
}

void loop(){

    /* Exibe uma mesagem caso a entrada analógica A03
     * esteja ativada.
     */
    if(digital_input.read(A03)){
        Serial.println("Hello Industrialli!");
    }

    /* Atualiza os leds das entradas digitais.
     */
    digital_input.update_leds();

    /* Envia a configuração dos leds para o CI.
     */
    leds.update();
    delay(10);
}
