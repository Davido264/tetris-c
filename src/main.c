#include "../include/data_structures.h"
#include "../include/render.h"
#include "../include/tetromino.h"
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() { 
  setlocale(LC_ALL, "");
  srand(time(NULL));

  WINDOW *master = initscr();
  noecho();
  cbreak();
  keypad(master, 1);

  if (has_colors()) {
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
  }

  // Draw the board
  int sizex = (int)(getcurx(master) * 0.8);
  int sizey = (int)(getcury(master) * 0.8);
  WINDOW *w = newwin(sizey, sizex, (int)(getcury(master) * 0.1),
                     (int)(getcurx(master) * 0.1));
  box(w, 0, 0);
  refresh();

  // keep the last 3 to show
  Tetromino *figs[3];
  for (int i = 0; i < 3; i++) {
    figs[i] = get_rnd_tetromino();
  }

  char next_value = 1;
  char repeat = 1;
  while (repeat) {
    Tetromino *current = figs[0];
    render_tetromino(10, 10, current, w);

    switch (wgetch(w)) {
    case ' ':
      lrotate_tetromino(current);
      next_value = 0;
      break;
    case 'q':
      repeat = 0;
      break;
    default:
      free(current);
      next_value = 1;
      break;
    }


    if (next_value) {
      // shift and generate new
      for (int i = 0; i < 2; i++) {
        figs[i] = figs[i + 1];
      }
      figs[2] = get_rnd_tetromino();
    }
  }

  endwin();
  delwin(w);
  delwin(master);
  return 0;
}
