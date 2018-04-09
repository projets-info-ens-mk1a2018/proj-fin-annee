#ifndef SEVCOL
#define SEVCOL

/* We want a 30x30 board game by default */
#define BOARD_SIZE 30

void set_cell(int x, int y, char color);
char get_cell(int x, int y);
void print_board(void);

#endif
