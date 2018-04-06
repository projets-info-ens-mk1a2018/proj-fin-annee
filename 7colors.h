#ifndef SEVCOL
#define SEVCOL

/* We want a 30x30 board game by default */
#define BOARD_SIZE 30

void set_cell(int x, int y, char color);
void get_cell(int x, int y, char color);
extern char board[];

#endif
