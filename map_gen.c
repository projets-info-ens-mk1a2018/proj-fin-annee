#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "7colors.h"
#include "map_gen.h"

char random_color(void) {
	return 'A'+rand()%7;
}

void map_gen(void) {   
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
			set_cell(i,j,random_color());
        }
    }
	set_cell(BOARD_SIZE-1,0,player_sym(0));
	set_cell(0,BOARD_SIZE-1,player_sym(1));
}
