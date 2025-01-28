#include "animations.h"
#include "led_control.h"

void animacaoPurpleLineInterval() {
    int q = 3;
    while (q <= 3, q--) {
        for (int linha = 0; linha < 5; linha++) {
            desliga();
            for (int i = linha * 5; i < (linha + 1) * 5; i++) {
                cor(i, 255, 0, 255);
            }
            buffer();
            sleep_ms(300);
        }
    }
    desliga();
    buffer();
}

void animationAllLedsYellowPairs(){
    for (int i = 0; i < TOTAL_LEDS; i++) {
        if (i % 2 == 0) cor(i, 255, 255, 0);
    }
}

void animationAllOddLedsPink(){
    for (int i = 0; i < TOTAL_LEDS; i++) {
        if (i % 2 != 0) cor(i, 255, 0, 255);
    }
}

void animationAllGreenLeds(){
    for (int i = 0; i < TOTAL_LEDS; i++) cor(i, 0, 128, 0);
}

void animationAllRedLeds(){
    for (int i = 0; i < TOTAL_LEDS; i++) cor(i, 204, 0, 0);
}

void animationAllBlueLeds(){
    for (int i = 0; i < TOTAL_LEDS; i++) cor(i, 0, 0, 255);
}

// Animação C E P E D I - Tecla 7
void animationCEPEDI(){
    // Definição do tempo entre os frames
    const int timeFrame  = 1000;

    // FRAME 1 (C)
    int frame1[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame1[coluna][linha][0], frame1[coluna][linha][1], frame1[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 2 (E)
    int frame2[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},      
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},        
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame2[coluna][linha][0], frame2[coluna][linha][1], frame2[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 3 (P)
    int frame3[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame3[coluna][linha][0], frame3[coluna][linha][1], frame3[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 4 (E)
    int frame4[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},      
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},        
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame4[coluna][linha][0], frame4[coluna][linha][1], frame4[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 5 (D)
    int frame5[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame5[coluna][linha][0], frame5[coluna][linha][1], frame5[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 6 (I)
    int frame6[5][5][3] = {
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame6[coluna][linha][0], frame6[coluna][linha][1], frame6[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(timeFrame);
    desliga();

    // FRAME 7 ( )
    int frame7[5][5][3] = {
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame7[coluna][linha][0], frame7[coluna][linha][1], frame7[coluna][linha][2]);
      }
    };
    buffer();
    sleep_ms(2000);
}

void animationSEQUENCE() {
    //acende e apaga sete cores em sequência
    // Cores para a animação (Laranja, Ciano, Lilás, Vermelho, Azul, Verde, Branco)
    const int cores[7][3] = {
        {255, 165,  0 },  // Laranja
        { 0 , 255, 255},  // Ciano
        {200,  0 , 255},  // Lilás
        {255,  0 ,  0 },  // Vermelho
        { 0 ,  0 , 255},  // Azul
        { 0 , 255,  0 },  // Verde
        {255, 255, 255} };// Branco
    
    for (int c = 0; c < 7; c++) { // Itera sobre as cores
        // Acende os LEDs na sequência
        for (int i = 0; i < TOTAL_LEDS; i++) {
            cor(i, cores[c][0], cores[c][1], cores[c][2]); // Define a cor atual
            buffer(); // Atualiza os LEDs
            sleep_ms(100); }// Aguarda 100 ms

        // Apaga os LEDs na sequência inversa
        for (int i = TOTAL_LEDS - 1; i >= 0; i--) {
            cor(i, 0, 0, 0); // Desliga o LED atual
            buffer(); // Atualiza os LEDs
            sleep_ms(100); }} // Aguarda 100 ms

                desliga(); // Garante que todos os LEDs fiquem apagados no final
                buffer(); } // Atualiza os LEDs para o estado desligado

void animacaoRelogio( ) {
    int frame01[5][5][3] = {
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},  
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},
        {{ 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}},
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame01[linha][coluna][0], frame01[linha][coluna][1], frame01[linha][coluna][2]);
      }
    };
    buffer();
    sleep_ms(2000);
    desliga();

    int frame02[5][5][3] = {
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},  
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}},
        {{ 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}, { 0, 255,  0}},
        {{  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}, {  0,  0,  0}}
    };
    for(int linha = 0; linha < 5; linha++){
      for(int coluna = 0; coluna < 5; coluna++){
        int posicao = getIndex(linha, coluna);
        cor(posicao, frame02[linha][coluna][0], frame02[linha][coluna][1], frame02[linha][coluna][2]);
      }
    };
    buffer();
    sleep_ms(2000);
    desliga();
}