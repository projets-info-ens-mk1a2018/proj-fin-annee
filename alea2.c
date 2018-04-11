#include "map_gen.h"
#include "7colors.h"
#include "alea2.h"
#include <stdlib.h>

char alea2_color(int player)
{	
	int x,y;
	
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
	
/** On définit un tableau contenant les couleurs adjacentes (1 si présente)
 */
	char colors[7]={0};
/** On définit une fonction assez proche de celle de l'humain mais pas tout à fait
 */
	search_colors(symbole, x, y, visite, colors);
	
	char color='A'+rand()%7;
	while (colors[color-'A']==0){
		color='A'+rand()%7;
	}
	return color;
}


void search_colors(char symbole, int x, int y, char *visite, char *colors) 
{
/** cette case (x,y) a été visité, on y retournera pas
 */
	visite[y * BOARD_SIZE + x]=1; 
	
	char color;
	
/** case à gauche
 */
	
	if ((x-1>=0) & (visite[y * BOARD_SIZE + x-1]==0)){
		color=get_cell(x-1,y);
		if((color<='G') | (color>='A')) {
			colors[color-'A']=1;
		}
		if (get_cell(x-1,y)==symbole){
			search_colors(symbole, x-1, y, visite, colors);
		}
	}
/** case à droite
 */
	if ((x+1<BOARD_SIZE)& (visite[(y) * BOARD_SIZE + x+1]==0)){
		color=get_cell(x+1,y);
		if((color<='G') | (color>='A')) {
			colors[color-'A']=1;
		}
		if (get_cell(x+1,y)==symbole){
			search_colors(symbole, x+1, y, visite, colors);
		}
	}
/** case en haut
 */
	if ((y-1>=0)& (visite[(y-1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y-1);
		if((color<='G') | (color>='A')) {
			colors[color-'A']=1;
		}
		if (get_cell(x,y-1)==symbole){
			search_colors(symbole, x, y-1, visite, colors);
		}
	}
/** case en bas
 */
	if ((y+1<BOARD_SIZE)& (visite[(y+1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y+1);
		if((color<='G') | (color>='A')) {
			colors[color-'A']=1;
		}
		if (get_cell(x,y+1)==symbole){
			search_colors(symbole, x, y+1, visite, colors);
		}
	}
}
