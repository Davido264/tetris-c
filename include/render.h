#ifndef RENDER_H
#define RENDER_H

#include <curses.h>

#include "tetromino.h"

void render_tetromino(int x, int y, Tetromino *pfig, WINDOW *w);

#endif
