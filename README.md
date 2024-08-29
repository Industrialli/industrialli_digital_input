[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli digital input

Biblioteca para manipulação das entradas digitais da Industrialli Hub para o framework Arduino com o uso da biblioteca [stm32ino](https://github.com/stm32duino/).

> [!IMPORTANT]  
> Consulte a biblioteca geral da Industrialli Hub [:link:](https://pages.github.com/).

## Exemplo
No exemplo abaixo, é anexado uma função para contagem de interrupções nas entradas digitais I01 e I02, em que a entrada I01 é um sensor NPN, e a entrada I02 é um sensor PNP.

```cpp
#include "industrialli_hub.hpp"

industrialli_hub hub;

int counts = 0;

void count_interruptions(){
  __disable_irq();
  counts++;
  __enable_irq();
}

int main(){
    hub.begin();

    digital_input.begin();
    digital_input.attach_interrupt(I01, count_interruptions, NPN);
    digital_input.attach_interrupt(I02, count_interruptions, PNP);
	
    while(1){
      digital_input.update_leds();
      leds.update();
    }
}
```

## Funções

Segue abaixo as funções disponíveis para a manipulação de interrupções das entradas digitais.

<details>
<summary>begin</summary>

Inicializa a biblioteca.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_input.begin();
```
</details>

<details>
<summary>attach_interrupt</summary>

Anexa uma função a uma entrada digital para ser executada a cada interrupção.

**Parâmetros:**
- uint8_t: entrada digital: I01, I02, ... , I08.
- void (*_callback)(): ponteiro para uma função que será anexada a entrada digital.
- uint32_t: modo de contagem: PNP ou NPN.

**Retorno:** void

**Exemplo**
```cpp
void setup(){
	hub.begin();

	digital_input.begin();
	digital_input.attach_interrupt(I02, count_interruptions, NPN);
}
```
</details>

<details>
<summary>read</summary>

Retorna o estado atual de uma entrada digital, sem precisar associar a entrada a uma função de interrupção.

**Parâmetros:**
- uint8_t: entrada digital: I01, I02, ... , I08.

**Retorno:**
- int: retorna o estado da entrada digital.

**Exemplo**
```cpp
void loop(){
	Serial.println(digital_input.read(I07));
}
```
</details>

<details>
<summary>enable_analog</summary>

Habilita uma entrada analógica para funcionar como uma entrada digital.

OBS.: Não é possivel anexar uma entrada analógica a uma função de interrupção.

**Parâmetros:**
- uint8_t: entrada digital: I01, I02, ... , I08.

**Retorno:** void

**Exemplo**
```cpp
void setup(){
	hub.begin();

	digital_input.begin();
	digital_input.enable_analog(A04);
}

void loop(){
	Serial.println(digital_input.read(A04));

	digital_input.update_leds();
	leds.update();
}
```
</details>

<details>
<summary>update_leds</summary>

Atualiza os leds das entradas digitais com base no tipo de contagem.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
void loop(){
	digital_input.update_leds();
	leds.update();
}
```
</details>
