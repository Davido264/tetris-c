#include "../include/data_structures.h"
#include "../include/tetromino.h"
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

char characters[] = {
  '#',
  '$',
  '%',
  '&',
  '*',
  '+',
  '=',
  '0',
  '3',
  '8',
  '9',
  '?',
  '@',
  '\0'
};

char characters_length = 14;
char letters_length = 26;

char get_rnd_char() {
  srand(time(NULL));
  int value = rand() % characters_length;

  if (value != 13) {
    return characters[value];
  }

  return (char) (rand() % letters_length) + 65;
}

void render_tetromino(int x, int y, Tetromino *pfig, WINDOW *w) {
  wrefresh(w);
  char blockch = get_rnd_char();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Pixel pix = (*pfig)[i][j];

      if (pix.value == 1) {
        if (has_colors()) {
          wattron(w,COLOR_PAIR(pix.color));
        }
        mvwaddch(w, y + i, x + j, blockch);
        if (has_colors()) {
          wattroff(w,COLOR_PAIR(pix.color));
        }
      } else {
        mvwaddch(w, y + i, x + j, ' ');
      }

    }
  }
  wrefresh(w);
}
