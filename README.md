[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# industrialli digital input

Biblioteca para manipulação das entradas digitais da Industrialli Hub com a utilização da biblioteca Hardware Abstraction Layer (HAL).

> [!IMPORTANT]  
> Consulte a biblioteca geral da Industrialli Hub [:link:](https://pages.github.com/).
> 
> Consulte a biblioteca de contador de interrupções [:link:](https://pages.github.com/).
> 
> Consulte a biblioteca de encoder [:link:](https://pages.github.com/).

## Exemplo
No exemplo abaixo, é anexado uma função para contagem de interrupções nas entradas digitais I03 e I04, em que a entrada I03 é um sensor NPN, e a entrada I04 é um sensor PNP. 

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
    digital_input.attach_interrupt(I03, count_interruptions, GPIO_MODE_IT_FALLING);
    digital_input.attach_interrupt(I04, count_interruptions, GPIO_MODE_IT_RISING);
	
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
- DIGITAL_INPUT_PIN: entrada digital: I01, I02, ... , I08.
- void (*_callback)(): ponteiro para uma função que será anexada a entrada digital.
- uint32_t: modo de contagem: GPIO_MODE_IT_RISING ou GPIO_MODE_IT_FALLING.

**Retorno:** void

**Exemplo**
```cpp
digital_input.attach_interrupt(I03, count_interruptions, GPIO_MODE_IT_FALLING);
```
</details>


<details>
<summary>update_leds</summary>

Atualiza os leds das entradas digitais com base no tipo de contagem.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
digital_input.update_leds();
leds.update();
```
</details>
