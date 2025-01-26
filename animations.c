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
