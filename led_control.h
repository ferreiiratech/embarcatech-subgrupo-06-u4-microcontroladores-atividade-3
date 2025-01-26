#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#define TOTAL_LEDS 25

struct pixel_t {
    uint8_t G, R, B;
};
typedef struct pixel_t npLED_t;

void controle(uint pin);
void cor(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);
void desliga(void);
void buffer(void);
void animationFunctions(char key);

#endif
