#include "7colors.h"
/** Cherche autour d'une case s'il y a une case de la couleur voulue de manière récursive
 */
void search_cells(char symbole, char color, int x, int y)
{
	if (x-1>0){
		if (get_cell(x-1,y)==color)){
			set_cell(x-1,y,symbole);
		}
		if (get_cell(x-1,y)==color)){
			search_cells(symbole, color, x-1, y);
		}
	}
	if (x+1<BOARD_SIZE){
		if (get_cell(x+1,y)==color)){
			set_cell(x+1,y,symbole);
		}
		if (get_cell(x+1,y)==color)){
			search_cells(symbole, color, x+1, y);
		}
	}
	if (y-1>0){
		if (get_cell(x,y-1)==color)){
			set_cell(x,y-1,symbole);
		}
		if (get_cell(x,y-1)==color)){
			search_cells(symbole, color, x, y-1);
		}
	}
	if (y+1<BOARD_SIZE){
		if (get_cell(x,y+1)==color)){
			set_cell(x,y+1,symbole);
		}
		if (get_cell(x,y+1)==color)){
			search_cells(symbole, color, x, y+1);
		}
	}
}

/** met à jour le tableau quand le player joue la color
 */
void maj_board(char color, int player)
{	
	int x,y;
	if (player==1) {
		x=0;
		y=BOARD_SIZE-1;
	else 
		y=0;
		x=BOARD_SIZE-1;
	}
		char symbole;
	if (player==1){
		symbole='^';
	}
	else {
		symbole='v';
	}	
	search_cells(symbole, color, int x, int y)
}
