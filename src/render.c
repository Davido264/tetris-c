#include "../include/data_structures.h"
#include "../include/tetromino.h"
#include <curses.h>

void render_tetromino(int x, int y, Tetromino *pfig, WINDOW *w) {
  const wchar_t blockch[] = L"\u2586";

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      Pixel pix = (*pfig)[i][j];
      if (pix.value == 1) {
        if (has_colors()) {
          wattron(w,COLOR_PAIR(pix.color));
        }
        mvwaddwstr(w, y + i, x + j, blockch);
        if (has_colors()) {
          wattroff(w,COLOR_PAIR(pix.color));
        }
      } else {
        mvwprintw(w, y + i, x + j, " ");
      }
    }
  }
  wrefresh(w);
}
