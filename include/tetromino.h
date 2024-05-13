#ifndef FIGURE_FACTORY_H
#define FIGURE_FACTORY_H
#include "data_structures.h"

#define MAX_TETROMINO_TYPE_COUNT 7


typedef Pixel Tetromino[4][4];
typedef enum { L, J, O, I, S, Z, T } TetrominoType;

Tetromino *get_tetromino(TetrominoType type, Color color);
void lrotate_tetromino(Tetromino *fig);

#endif
