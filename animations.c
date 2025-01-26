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
    for (int i = 0; i < TOTAL_LEDS; i++) cor(i, 0, 255, 0);
}

void animationAllRedLeds(){
    for (int i = 0; i < TOTAL_LEDS; i++) cor(i, 255, 0, 0);
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