#include <stdio.h>
#include "7colors.h"


int territory(int player)
{
	char sym=player_sym(player);
	int t=0;
	for(int i=0;i<BOARD_SIZE;i++) {
		for(int j=0;j<BOARD_SIZE;j++) {
			if(get_cell(i,j)==sym)
				t++;
		}
	}
	return t;
}

void print_territory(int player)
{
	int nb=territory(player);
	int percent=(100*nb)/(BOARD_SIZE*BOARD_SIZE);
	printf("Territoire joueur %d : %d (%d %%)\n",player+1,nb,percent);
}
