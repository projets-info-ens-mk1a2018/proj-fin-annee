/* Template of the 7 wonders of the world of the 7 colors assigment. */

/**
 * 7 colors par Julien Baltazar et Alexandre Faye-Bédrin
 */

#include <stdio.h>     /* printf */
#include <stdlib.h>    
#include "7colors.h"
#include "maj.h"
#include "map_gen.h"
#include "human.h"
#include "stop_condition.h"
#include "territory.h"
#include "alea1.h"
#include "alea2.h"
#include "glouton.h"
#include "hegemonique.h"
#include "smart_glouton.h"

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros

/** Retrieves the color of a given board cell */
char get_cell(int x, int y)
{
    return board[y * BOARD_SIZE + x];
}

/** Changes the color of a given board cell */
void set_cell(int x, int y, char color)
{
    board[y * BOARD_SIZE + x] = color;
}

char player_sym(int player)
{
	if (player==1){
		return '^';
	}
	else {
		return 'v';
	}	
}

void print_legal_colors(void)
{	
	printf("Les couleurs autorisées sont A,B,C,D,E,F,G\n");
}
/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(void)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", get_cell(i, j));
        }
        printf("\n");
    }
}
