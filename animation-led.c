#include <stdio.h>
#include "keypad.h"
#include "led_control.h"
#include "animations.h"
#include "pico/stdlib.h"

#define MATRIZ_LEDS 7
#define Buzzer_A 21
#define Buzzer_B 10


int main() {
    stdio_init_all();
    init_keypad(); // Inicializa o teclado matricial
    controle(MATRIZ_LEDS); // Inicializa o controle dos LEDs
    gpio_init(Buzzer_A);
    gpio_init(Buzzer_B);
    gpio_set_dir(Buzzer_A, GPIO_OUT);
    gpio_set_dir(Buzzer_B, GPIO_OUT);
    printf("Sistema iniciado!\n");

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
