#include "7colors.h"
/** Cherche autour d'une case s'il y a une case de la couleur voulue et la modifie ou si il y une case du joueur il se relance de manière récursive
 */
void search_cells(char symbole, char color, int x, int y, int old) 
{
/** case à gauche
 * si old=2 on vient de la gauche, donc on regarde pas ne nouveau la case à gauche
 */
	if ((x-1>0) & (old!=2)){
		if (get_cell(x-1,y)==color)){
			set_cell(x-1,y,symbole);
		}
		if (get_cell(x-1,y)==color)){
			search_cells(symbole, color, x-1, y);
		}
	}
/** case à droite
 * A FAIRE DE MEME POUR LES 3 AUTRES
 */
	if (x+1<BOARD_SIZE){
		if (get_cell(x+1,y)==color)){
			set_cell(x+1,y,symbole);
		}
		if (get_cell(x+1,y)==color)){
			search_cells(symbole, color, x+1, y);
		}
	}
/** case en haut
 */
	if (y-1>0){
		if (get_cell(x,y-1)==color)){
			set_cell(x,y-1,symbole);
		}
		if (get_cell(x,y-1)==color)){
			search_cells(symbole, color, x, y-1);
		}
	}
/** case en bas
 */
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
	search_cells(symbole, color, x, y, 0);
}
