#include "industrialli_hub.hpp"

/* Biblioteca para contagem de interrupções das entradas digitais.
*/
#include "digital_input/industrialli_digital_input_counter.hpp"

industrialli_hub hub;

void setup(){
    hub.begin();

    /* Inicialização da biblioteca de entradas digitais.
     */
    digital_input.begin();

    /* Anexa uma função no pino I01 para contagem de interrupções
     * de um sensor PNP.
     */
    digital_input.attach_interrupt(I01, I01_COUNTING_UP_CALLBACK, PNP);

    /* Anexa uma função no pino I02 para contagem de interrupções
     * de um sensor NPN.
     */
    digital_input.attach_interrupt(I02, I02_COUNTING_DOWN_CALLBACK, NPN);
}

void loop(){

    /* Exibe a soma entre os contadores de interrupção dos pinos
     * I01 e I02.
     */
    Serial.println(i01_count + i02_count);

    digital_input.update_leds();
    leds.update();
    delay(10);
}