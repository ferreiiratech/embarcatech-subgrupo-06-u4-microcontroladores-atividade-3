#ifndef KEYPAD_H
#define KEYPAD_H

#define LINHAS 4
#define COLS 4

extern const unsigned int gpio_linhas[LINHAS];
extern const unsigned int gpio_cols[COLS];

extern const char keymap[LINHAS][COLS];

void init_keypad(void);
char keypad_get_key(void);

#endif
