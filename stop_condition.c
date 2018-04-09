#include <stdio.h>
#include "7colors.h"
#include "territory.h"
#include "stop_condition.h"


char game_end(void)
{
	int wn=BOARD_SIZE*BOARD_SIZE/2;
	
	if((territory(0)>wn) | (territory(1)>wn) | ((territory(1)==wn) & (territory(0)==wn))) {
		return 1;
	}
	
	
	return 0;
}
