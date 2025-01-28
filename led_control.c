#include "led_control.h"
#include "ws2818b.pio.h"
#include "animations.h"

npLED_t leds[TOTAL_LEDS]; // Array que representa os LEDs
PIO np_pio; // Objeto representando o periférico PIO usado para controlar os LEDs
uint sm; // Representa o estado da máquina de estados do PIO

// Função para inicializar o controle dos LEDs
void controle(uint pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

// Função para definir a cor de um LED específico
void cor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}

// Função para desligar todos os LEDs
void desliga() {
    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        cor(i, 0, 0, 0);
    }
}

// Função para enviar o estado atual dos LEDs ao hardware  - buffer de saída
void buffer() {
    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100);
}

int getIndex(int x, int y) {
        // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
        // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
        if (y % 2 == 0) {
            return 24-(y * 5 + x); // Linha par (esquerda para direita).
        } else {
            return 24-(y * 5 + (4 - x)); // Linha ímpar (direita para esquerda).
        }
    }

// Função para executar a animação correspondente à tecla pressionada
void animationFunctions(char key) {
    desliga();
    switch (key) {
        case 'A':
            desliga();
            break;
        case 'B':
            animationAllBlueLeds();
            break;
        case 'C':
            animationAllRedLeds();
            break;
        case 'D':
            animationAllGreenLeds();
            break;
        case '1':
            animationAllOddLedsPink();
            break;
        case '2':
            animationAllLedsYellowPairs();
            break;
        case '3':
            animacaoPurpleLineInterval();
            break;
        case '4':
            animationSEQUENCE();
            break;
        case '7':
            animationCEPEDI();
            break;
        case '8':
            animacaoRelogio();
            break;
        case '#':
            animationWhiteLedsLowIntensity();
            break;
        default:
            break;

    }
    buffer();
}
