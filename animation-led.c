#include <stdio.h>
#include "keypad.h"
#include "led_control.h"
#include "animations.h"

#define MATRIZ_LEDS 7

int main() {
    stdio_init_all();
    init_keypad(); // Inicializa o teclado matricial
    controle(MATRIZ_LEDS); // Inicializa o controle dos LEDs
    printf("Sistema iniciado!\n");
    animacaoRelogio();
    buffer();

    // Loop principal
    while (true) {
        char key = keypad_get_key(); // Lê a tecla pressionada
        if (key) {
            printf("Tecla pressionada: %c\n", key);
            animationFunctions(key); // Executa a função correspondente à tecla pressionada
        }
        sleep_ms(100);
    }

    return 0;
}
