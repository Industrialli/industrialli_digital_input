#include "industrialli_hub.hpp"

/* Biblioteca que contém a função ENCODER_INTERRUPTION()
 * que calcula algumas informações do encoder.
 */
#include "digital_input/industrialli_digital_input_encoder.hpp"

industrialli_hub hub;

uint32_t last_update = 0;

void setup(){
    /* Inicializa a industrialli hub e algumas bibliotecas
     * padrões da Industrialli Hub, incluindo a biblioteca 
     * de leds.
     */
    hub.begin();

    /* Inicialização da biblioteca de entradas digitais.
     */
    digital_input.begin();

    /* Anexa uma função no pino I05 (encoder conectado em I05 e 
     * I06) para calcular a velocidade de rotação, sentido e 
     * quantidade de pulsos do encoder.
     */
    digital_input.attach_interrupt(I05, ENCODER_INTERRUPTION, PNP);
}

void loop(){
    /* Exibe a quantidade de pulsos, velocidade de rotação
     * e sentido do encoder a cada 500ms.
     */
    if(HAL_GetTick() - last_update >= 500){
        Serial.print(count); 
        Serial.println(" pulses");

        Serial.print(encoder_velocity); 
        Serial.println(" rpm");

        Serial.print(encoder_sense); 
        Serial.println(" sense");

        last_update = HAL_GetTick();
    }

    /* Atualiza os leds das entradas digitais.
     */
    digital_input.update_leds();

    /* Envia a configuração dos leds para o CI.
     */
    leds.update();
}