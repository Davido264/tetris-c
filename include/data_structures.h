#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define MAX_COLOR_COUNT 5

typedef enum {
  WHITE,
  RED,
  YELLOW,
  BLUE,
  GREEN
} Color;

typedef struct {
  unsigned char value : 1;
  unsigned char color : 3;
} Pixel;

typedef Pixel Row[10];

#endif
