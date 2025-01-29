#include "keypad.h"
#include "pico/stdlib.h"

// Pinos do teclado matricial
const unsigned int gpio_linhas[LINHAS] = {16, 17, 18, 19};
const unsigned int gpio_cols[COLS] = {20, 8, 9, 28};

// Mapeamento de teclas
const char keymap[LINHAS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void init_keypad() {
    // Configuração das linhas como saída
    for (int i = 0; i < LINHAS; i++) {
        gpio_init(gpio_linhas[i]);
        gpio_set_dir(gpio_linhas[i], GPIO_OUT);
        gpio_put(gpio_linhas[i], 1); // Estado inativo (alto)
    }

    // Configuração das colunas como entrada com resistor pull-up
    for (int j = 0; j < COLS; j++) {
        gpio_init(gpio_cols[j]);
        gpio_set_dir(gpio_cols[j], GPIO_IN);
        gpio_pull_up(gpio_cols[j]);
    }
}

char keypad_get_key() {
    for (int row = 0; row < LINHAS; row++) {
        gpio_put(gpio_linhas[row], 0); // Ativa a linha atual

        for (int col = 0; col < COLS; col++) {
            if (!gpio_get(gpio_cols[col])) { // Detecta tecla pressionada
                sleep_ms(50); // Debounce simples
                while (!gpio_get(gpio_cols[col])); // Aguarda tecla ser liberada
                gpio_put(gpio_linhas[row], 1); // Desativa a linha
                return keymap[row][col]; // Retorna a tecla correspondente
            }
        }

        gpio_put(gpio_linhas[row], 1); // Desativa a linha
    }
    return '\0'; // Nenhuma tecla pressionada
}
