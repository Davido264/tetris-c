#include <stdlib.h>

#include "../include/data_structures.h"
#include "../include/tetromino.h"

Tetromino *get_tetromino(TetrominoType type, Color color) {
  Tetromino *fig = (Tetromino *)malloc(sizeof(Tetromino));
  Pixel active_pixel = {1, (char)color};

  switch (type) {
  case L: {
    (*fig)[0][1] = (*fig)[1][1] = (*fig)[2][1] = (*fig)[2][2] = active_pixel;
    break;
  }
  case J: {
    (*fig)[0][2] = (*fig)[1][2] = (*fig)[2][1] = (*fig)[2][2] = active_pixel;
    break;
  }
  case O: {
    (*fig)[1][1] = (*fig)[1][2] = (*fig)[2][1] = (*fig)[2][2] = active_pixel;
    break;
  }
  case I: {
    (*fig)[0][1] = (*fig)[1][1] = (*fig)[2][1] = (*fig)[3][1] = active_pixel;
    break;
  }
  case S: {
    (*fig)[1][2] = (*fig)[1][3] = (*fig)[2][1] = (*fig)[2][2] = active_pixel;
    break;
  }
  case Z: {
    (*fig)[1][1] = (*fig)[1][2] = (*fig)[2][2] = (*fig)[2][3] = active_pixel;
    break;
  }
  case T: {
    (*fig)[1][0] = (*fig)[1][1] = (*fig)[1][2] = (*fig)[2][1] = active_pixel;
    break;
  }
  }

  return fig;
}

void lrotate_tetromino(Tetromino *fig) {
  int top = 0;
  int bottom = 3;

  while (top < bottom) {
    int x = bottom + top;

    for (int i = top; i < bottom; i++) {
      Pixel carrier = (*fig)[top][i];
      (*fig)[top][i] = (*fig)[i][bottom];
      (*fig)[i][bottom] = (*fig)[bottom][x - i];
      (*fig)[bottom][x - i] = (*fig)[x - i][top];
      (*fig)[x - i][top] = carrier;
    }
    top++;
    bottom--;
  }
}
