#include "../include/data_structures.h"
#include "../include/render.h"
#include "../include/tetromino.h"
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  setlocale(LC_ALL, "");

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

  Tetromino *figs[3];
  char last_genetared_type[3];

  int color = rand() % MAX_COLOR_COUNT;
  int tetromino_type = rand() % MAX_TETROMINO_TYPE_COUNT;

  // to lazy to do a function that checks this with a cycle xd
  // TODO: do the thing I just said I'm too lazy to
  // TODO: Implement a queue with a has function
  while (tetromino_type == last_genetared_type[0] ||
         tetromino_type == last_genetared_type[1] ||
         tetromino_type == last_genetared_type[2]) {
    tetromino_type = rand() % MAX_TETROMINO_TYPE_COUNT;
  }

  figs[0] = get_tetromino(L, RED);
  figs[1] = get_tetromino(J, BLUE);
  figs[2] = get_tetromino(O, RED);
  figs[3] = get_tetromino(I, YELLOW);
  figs[4] = get_tetromino(S, RED);
  figs[5] = get_tetromino(Z, GREEN);
  figs[6] = get_tetromino(T, WHITE);

  int i = 0;
  while (i < 7) {
    render_tetromino(10, 10, figs[i], w);
    switch (wgetch(w)) {
    case ' ':
      lrotate_tetromino(figs[i]);
      break;
    case KEY_ENTER:
    default:
      free(figs[i]);
      i++;
      break;
    }
  }

  endwin();
  delwin(w);
  delwin(master);
  return 0;
}
