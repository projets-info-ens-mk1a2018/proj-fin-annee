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
			if(i & j & (i!=BOARD_SIZE) & (j !=BOARD_SIZE))
				set_cell(i,j,random_color());
        }
    }
}
