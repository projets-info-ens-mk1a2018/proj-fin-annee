#include <stdio.h>
#include "7colors.h"
#include "territory.h"
#include "stop_condition.h"


char game_end(int *who_won)
{
	int wn=BOARD_SIZE*BOARD_SIZE/2;
	
	if((territory(0)>wn)) {
		who_won[0]++;
		return 1;
	}
	if((territory(1)>wn)) {
		who_won[1]++;
		return 1;
	}
	
	//Dans le cas où on a une égalité, et donc aussi que la taille de la carte est paire
	if((territory(1)==wn) & (territory(0)==wn) & !(BOARD_SIZE%2)) {
		return 1;
	}
		
	
	
	return 0;
}
