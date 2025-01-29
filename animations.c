#include "animations.h"
#include "led_control.h"
#include "pico/stdlib.h"

// Declare Buzzer_A
#define Buzzer_A 21 
#define Buzzer_B 10 

void animacaoPurpleLineInterval()
{
  int q = 3;
  while (q <= 3, q--)
  {
    for (int linha = 0; linha < 5; linha++)
    {
      desliga();
      for (int i = linha * 5; i < (linha + 1) * 5; i++)
      {
        cor(i, 255, 0, 255);
      }
      buffer();
      sleep_ms(300);
    }
  }
  desliga();
  buffer();
}

void animationAllLedsYellowPairs()
{
  for (int i = 0; i < TOTAL_LEDS; i++)
  {
    if (i % 2 == 0)
      cor(i, 255, 255, 0);
  }
}

void animationEspiral()
{
    const int timeFrame = 200;
    const int rows = 5;
    const int cols = 5;

    // Coordenadas para seguir o padrão em espiral
    int spiralOrder[25][2] = {
      {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0},
      {4, 1}, {4, 2}, {4, 3}, {4, 4},
      {3, 4}, {2, 4}, {1, 4}, {0, 4},
      {0, 3}, {0, 2}, {0, 1},
      {1, 1}, {2, 1}, {3, 1},
      {3, 2}, {3, 3},
      {2, 3}, {1, 3},
      {1, 2}, {2, 2}
    };

    // Percorre cada LED na ordem espiral
    for (int i = 0; i < TOTAL_LEDS; i++)
    {
        // Acende todos os LEDs anteriores para manter o efeito
      for (int j = 0; j <= i; j++)
      {
        int linha = spiralOrder[j][0];
        int coluna = spiralOrder[j][1];
        int posicao = getIndex(linha, coluna);
        cor(posicao, 50, 0, 100);

        if(i == TOTAL_LEDS - 1){
          cor(posicao, 100, 0, 0);
        }
      }
      buffer();
      sleep_ms(timeFrame);
    }

    desliga();

    // Loop reverso do centro para as bordas
    for (int i = TOTAL_LEDS - 1; i >= 0; i--)
    {
      // Acende todos os LEDs a partir do centro
      for (int j = TOTAL_LEDS - 1; j >= i; j--)
      {
          int linha = spiralOrder[j][0];
          int coluna = spiralOrder[j][1];
          int posicao = getIndex(linha, coluna);
          cor(posicao, 100, 0, 0);

          if(i == 0){
            cor(posicao, 0, 0, 100);
          }
      }

      buffer();
      sleep_ms(timeFrame);
    }
    desliga();
}

void animationAllGreenLeds()
{
  for (int i = 0; i < TOTAL_LEDS; i++)
    cor(i, 0, 128, 0);
}

void animationAllRedLeds()
{
  for (int i = 0; i < TOTAL_LEDS; i++)
    cor(i, 204, 0, 0);
}

void animationAllBlueLeds()
{
  for (int i = 0; i < TOTAL_LEDS; i++)
    cor(i, 0, 0, 255);
}

//Animação Coração - Tecla 6

void animationHeartbeat()
{
    const int timeFrame = 300; // Tempo entre os frames em milissegundos

    // Definição dos 6 frames do coração
    int frames[6][5][5][3] = {
        // Frame 1 - Menor
        {
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        },
        // Frame 2 - Crescendo
        {
            {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        },
        // Frame 3 - Maior
        {
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
        },
        // Frame 4 - Diminuindo
        {
            {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        },
        // Frame 5 - Menor novamente
        {
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}},
            {{0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        },
        // Frame 6 - Apagado
        {
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
            {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        },
    };

    // Reproduzir os frames do coração
    for (int frame = 0; frame < 6; frame++)
    {
        for (int linha = 0; linha < 5; linha++)
        {
            for (int coluna = 0; coluna < 5; coluna++)
            {
                int posicao = getIndex(4 - coluna, linha);
                cor(posicao, frames[frame][linha][coluna][0], frames[frame][linha][coluna][1], frames[frame][linha][coluna][2]);
            }
        }
        buffer();            // Atualiza os LEDs
        sleep_ms(timeFrame); // Espera entre os frames
    }
    desliga(); // Garante que os LEDs fiquem apagados após a animação
}

// Animação C E P E D I - Tecla 7
void animationCEPEDI()
{
  // Definição do tempo entre os frames
  const int timeFrame = 1000;

  // FRAME 1 (C)
  int frame1[5][5][3] = {
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{127, 0, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{127, 0, 255}, {127, 0, 255}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{0, 0, 0}, {0, 0, 0}, {127, 0, 255}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
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
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame7[coluna][linha][0], frame7[coluna][linha][1], frame7[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(2000);
}

void animationSEQUENCE()
{
  // acende e apaga sete cores em sequência
  //  Cores para a animação (Laranja, Ciano, Lilás, Vermelho, Azul, Verde, Branco)
  const int cores[7][3] = {
      {255, 165, 0},    // Laranja
      {0, 255, 255},    // Ciano
      {200, 0, 255},    // Lilás
      {255, 0, 0},      // Vermelho
      {0, 0, 255},      // Azul
      {0, 255, 0},      // Verde
      {255, 255, 255}}; // Branco

  for (int c = 0; c < 7; c++)
  { // Itera sobre as cores
    // Acende os LEDs na sequência
    for (int i = 0; i < TOTAL_LEDS; i++)
    {
      cor(i, cores[c][0], cores[c][1], cores[c][2]); // Define a cor atual
      buffer();                                      // Atualiza os LEDs
      sleep_ms(100);
    } // Aguarda 100 ms

    // Apaga os LEDs na sequência inversa
    for (int i = TOTAL_LEDS - 1; i >= 0; i--)
    {
      cor(i, 0, 0, 0); // Desliga o LED atual
      buffer();        // Atualiza os LEDs
      sleep_ms(100);
    }
  } // Aguarda 100 ms

  desliga(); // Garante que todos os LEDs fiquem apagados no final
  buffer();
} // Atualiza os LEDs para o estado desligado

void animacaoRelogio()
{                            // Animação do Relógio
  int tempo_do_frame = 1000; // Tempo do frame
  int matriz[5][5] = {       // Matriz de LEDs
      {24, 23, 22, 21, 20},
      {15, 16, 17, 18, 19},
      {14, 13, 12, 11, 10},
      {5, 6, 7, 8, 9},
      {4, 3, 2, 1, 0}};

  // FRAME 01
  gpio_put(Buzzer_A, 1);
  int frame01[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {255, 0, 0}, {255, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame01[linha][coluna][0], frame01[linha][coluna][1], frame01[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 02
  gpio_put(Buzzer_A, 0);
  gpio_put(Buzzer_B, 1);
  int frame02[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {255, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame02[linha][coluna][0], frame02[linha][coluna][1], frame02[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 03 
  gpio_put(Buzzer_B, 0);
  gpio_put(Buzzer_A, 1);
  int frame03[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {255, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame03[linha][coluna][0], frame03[linha][coluna][1], frame03[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 04
  gpio_put(Buzzer_A, 0);
  gpio_put(Buzzer_B, 1);
  int frame04[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{255, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame04[linha][coluna][0], frame04[linha][coluna][1], frame04[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 05
  gpio_put(Buzzer_A, 1);
  gpio_put(Buzzer_B, 0);
  int frame05[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{255, 0, 0}, {255, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame05[linha][coluna][0], frame05[linha][coluna][1], frame05[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 06
  gpio_put(Buzzer_A, 0);
  gpio_put(Buzzer_B, 1);
  int frame06[5][5][3] = {
      {{255, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {255, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame06[linha][coluna][0], frame06[linha][coluna][1], frame06[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 07
  gpio_put(Buzzer_A, 1);
  gpio_put(Buzzer_B, 0);
  int frame07[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {255, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 255}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame07[linha][coluna][0], frame07[linha][coluna][1], frame07[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 08
  gpio_put(Buzzer_A, 0);
  gpio_put(Buzzer_B, 1);
  int frame08[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {255, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255},{255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {0, 0, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame08[linha][coluna][0], frame08[linha][coluna][1], frame08[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();

  // FRAME 09
  gpio_put(Buzzer_A, 1);
  gpio_put(Buzzer_B, 0);
  int frame09[5][5][3] = {
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 255}, {255, 255, 0}},
      {{0, 0, 0}, {0, 0, 0}, {255, 255, 255}, {255, 0, 0}, {255, 0, 0}},
      {{255, 255, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 255, 0}},
      {{0, 0, 0}, {255, 255, 0}, {0, 0, 0}, {255, 255, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      cor(matriz[linha][coluna], frame09[linha][coluna][0], frame09[linha][coluna][1], frame09[linha][coluna][2]);
    }
  };
  buffer();
  sleep_ms(tempo_do_frame);
  desliga();
}

// Função para animação das leds brancas com baixa intensidade (20%)
void animationWhiteLedsLowIntensity() {
    for (int i = 0; i < TOTAL_LEDS; i++) {
        cor(i, 51, 51, 51); // Branco com 20% de intensidade
    }
    buffer(); // Atualiza o estado dos LEDs
}

void animacaoCountdown(){
    // Definição do tempo entre os frames
  const int timeFrame = 2000;

  // FRAME 1 (4)
  int frame1[5][5][3] = {
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame1[coluna][linha][0], frame1[coluna][linha][1], frame1[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(timeFrame);
  desliga();

  // FRAME 2 (3)
  int frame2[5][5][3] = {
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}},
      {{0, 191, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}},
      {{0, 191, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}},
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame2[coluna][linha][0], frame2[coluna][linha][1], frame2[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(timeFrame);
  desliga();

  // FRAME 3 (2)
  int frame3[5][5][3] = {
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}},
      {{0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}},
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame3[coluna][linha][0], frame3[coluna][linha][1], frame3[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(timeFrame);
  desliga();

  // FRAME 4 (1)
  int frame4[5][5][3] = {
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}},
      {{0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}}
};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame4[coluna][linha][0], frame4[coluna][linha][1], frame4[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(timeFrame);
  desliga();

  // FRAME 5 (0)
  int frame5[5][5][3] = {
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}},
      {{0, 191, 255}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}, {0, 191, 255}},
      {{0, 191, 255}, {0, 0, 0}, {0, 191, 255}, {0, 0, 0}, {0, 191, 255}},
      {{0, 191, 255}, {0, 191, 255}, {0, 0, 0}, {0, 0, 0}, {0, 191, 255}},
      {{0, 0, 0}, {0, 191, 255}, {0, 191, 255}, {0, 191, 255}, {0, 0, 0}}
};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame5[coluna][linha][0], frame5[coluna][linha][1], frame5[coluna][linha][2]);
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
      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
  for (int linha = 0; linha < 5; linha++)
  {
    for (int coluna = 0; coluna < 5; coluna++)
    {
      int posicao = getIndex(linha, coluna);
      cor(posicao, frame7[coluna][linha][0], frame7[coluna][linha][1], frame7[coluna][linha][2]);
    }
  };
  buffer();
  sleep_ms(2000);
}