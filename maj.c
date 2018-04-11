#include <stdio.h>
#include "maj.h"
#include "7colors.h"
/** Cherche autour d'une case s'il y a une case de la couleur voulue et la modifie ou si il y une case du joueur. il se relance de manière récursive
 */
void search_cells(char symbole, char color, int x, int y, char *visite) 
{
/** cette case (x,y) a été visité, on y retournera pas
 */
	visite[y * BOARD_SIZE + x]=1; 
/** case à gauche
 */
	if ((x-1>=0) & (visite[y * BOARD_SIZE + x-1]==0)){
		if (get_cell(x-1,y)==color){
			set_cell(x-1,y,symbole);
			search_cells(symbole, color, x-1, y, visite);
		}
		if (get_cell(x-1,y)==symbole){
			search_cells(symbole, color, x-1, y, visite);
		}
	}
/** case à droite
 */
	if ((x+1<BOARD_SIZE)& (visite[(y) * BOARD_SIZE + x+1]==0)){
		if (get_cell(x+1,y)==color){
			set_cell(x+1,y,symbole);
			search_cells(symbole, color, x+1, y, visite);
		}
		if (get_cell(x+1,y)==symbole){
			search_cells(symbole, color, x+1, y, visite);
		}
	}
/** case en haut
 */
	if ((y-1>=0)& (visite[(y-1) * BOARD_SIZE + x]==0)){
		if (get_cell(x,y-1)==color){
			set_cell(x,y-1,symbole);
			search_cells(symbole, color, x, y-1, visite);
		}
		if (get_cell(x,y-1)==symbole){
			search_cells(symbole, color, x, y-1, visite);
		}
	}
/** case en bas
 */
	if ((y+1<BOARD_SIZE)& (visite[(y+1) * BOARD_SIZE + x]==0)){
		if (get_cell(x,y+1)==color){
			set_cell(x,y+1,symbole);
			search_cells(symbole, color, x, y+1, visite);
		}
		if (get_cell(x,y+1)==symbole){
			search_cells(symbole, color, x, y+1, visite);
		}
	}
}

/** met à jour le tableau quand le player joue la color
 */
void maj_board(char color, int player)
{	
	int x,y;
	
/** On vérifie que la couleur est légalae
 */
	if((color>'G') | (color<'A')) {
		print_legal_colors();
		return;
	}
/** Si c'est le joueur 2 qui joue, on commence à regarder la case en haut à gauche
 */
	if (player==1) {
		x=0;
		y=BOARD_SIZE-1;
	}
/** Si c'est le joueur 1 qui joue, on commence à regarder la case en bas à droite
 */
	else {
		y=0;
		x=BOARD_SIZE-1;
	}
/** on définit le symbole assigné au joueur
 */
	char symbole=player_sym(player);
/** on définit un tableau rempli de 0, les cases passeront à 1 lorsqu'elles auront été visitées
 */
	char visite[BOARD_SIZE * BOARD_SIZE]={0};
	search_cells(symbole, color, x, y, visite);
}
