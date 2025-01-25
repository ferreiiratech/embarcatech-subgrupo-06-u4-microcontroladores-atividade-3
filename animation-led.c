//Bibliotecas
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino
#define TOTAL_LEDS 25
#define MATRIZ_LEDS 7

// Configuração do teclado matricial
#define LINHAS 4
#define COLS 4

const unsigned int gpio_linhas[LINHAS] = {16, 17, 18, 19}; // Pinos das 
const unsigned int gpio_cols[COLS] = {20, 8, 9, 28};   // Pinos das colunas

// Mapeamento de teclas do teclado matricial
const char keymap[LINHAS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Estrutura para LEDs NeoPixel
struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;
npLED_t leds[TOTAL_LEDS];

// Variáveis para configuração do PIO
PIO np_pio;
uint sm;


// Inicializa os pinos do teclado matricial.
void init_keypad() {
    // Configuração das  como saída
    for (int i = 0; i < LINHAS; i++) {
        gpio_init(gpio_linhas[i]);
        gpio_set_dir(gpio_linhas[i], GPIO_OUT);
        gpio_put(gpio_linhas[i], 1); // Estado inativo (alto)
    }

    // Configuração das colunas como entrada com resistor pull-up
    for (int j = 0; j < COLS; j++) {
        gpio_init(gpio_cols[j]);
        gpio_set_dir(gpio_cols[j], GPIO_IN);
        gpio_pull_up(gpio_cols[j]); // Habilita pull-up para evitar flutuação
    }
}

 // Lê o teclado matricial e retorna a tecla pressionada.
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

// Inicializa o controle dos LEDs NeoPixel.
void controle(uint pin) {
    uint offset = pio_add_program(pio0, &ws2818b_program);
    np_pio = pio0;
    sm = pio_claim_unused_sm(np_pio, true);
    ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        leds[i].R = leds[i].G = leds[i].B = 0;
    }
}

 //Define a cor de um LED específico.
void cor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
    leds[index].R = r;
    leds[index].G = g;
    leds[index].B = b;
}


// Limpa o buffer de LEDs, apagando todos.
void desliga() {
    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        cor(i, 0, 0, 0);
      //cor(i, vermelho, verde, azul)  
    }
}

//Envia os dados do buffer para os LEDs.
void buffer() {
    for (uint i = 0; i < TOTAL_LEDS; ++i) {
        pio_sm_put_blocking(np_pio, sm, leds[i].G);
        pio_sm_put_blocking(np_pio, sm, leds[i].R);
        pio_sm_put_blocking(np_pio, sm, leds[i].B);
    }
    sleep_us(100);
}

void animacao1() {
    int q = 3;
    while(q<=3, q--) {
    for (int linha = 0; linha < 5; linha++) {
        desliga();
        for (int i = linha * 5; i < (linha + 1) * 5; i++) {
            cor(i, 255, 0, 255); // Define os LEDs da linha atual como azul
        }
        buffer();
        sleep_ms(300); } // Pausa de 3 segundos entre as linhas
    }
    desliga();
    buffer();
}

// Desenha um padrão de LEDs baseado na tecla pressionada.
void funcoes(char key) {
    desliga();
    switch (key) {
        //Desliga os leds
        case 'A':
            printf("desligando todos os leds\n");
            desliga();
            break;
         //liga os leds azuis   
        case 'B':
            printf("Ligando os leds azuis\n");
            for (int i = 0; i < TOTAL_LEDS; i++) {
                cor(i, 0, 0, 255); }
            break;
        //liga os leds vermelhos
        case 'C':
            printf("Ligando os vermelhos\n");
            for (int i = 0; i < TOTAL_LEDS; i++) {
                cor(i, 255, 0, 0);
            }
            break;
        // Liga os leds verdes    
        case 'D':
            printf("Ligando os verdes\n");
            for (int i = 0; i < TOTAL_LEDS; i++) {
                cor(i, 0, 255, 0);}
            break;
         //lilás em impares   
        case '1':
            printf("Cor lilás em pares\n");
            for (int i = 0; i < TOTAL_LEDS; i++) {
                if (i % 2 != 0) cor(i, 255, 0, 255); }
            break;
        // amarelo em pares  
        case '2':
            printf("Amarelo em intervalo impar\n");
            for (int i = 0; i < TOTAL_LEDS; i++) {
                if (i % 2 == 0) cor(i, 255, 255, 0);}
            break;
         case '3':
            printf("Lilás em intervalo de linhas\n");
            animacao1();       
            break;
        default:
            break;
    }
    buffer();
}

 //Função principal do programa.
int main() {
    stdio_init_all();
    init_keypad();
    controle(MATRIZ_LEDS);

    printf("Sistema iniciado!\n");

    while (true) {
        char key = keypad_get_key(); // Lê a tecla pressionada
        if (key) {
            //Desativando a exibição da tecla pressionada
            //printf("Tecla pressionada: %c\n", key); // Exibe a tecla pressionada
            funcoes(key); // Desenha o padrão correspondente
        }
        sleep_ms(100);
    }

    return 0;
}
