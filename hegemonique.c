/**
 * 7 colors par Julien Baltazar et Alexandre Faye-Bédrin
 */
#include "7colors.h"
#include "hegemonique.h"
#include "alea2.h"

char hegemonique_color(int player)
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

/** On définit un tableau contenant les couleurs adjacentes (1 si présente)
 */
	char colors[7]={0};
	
	char visite[BOARD_SIZE * BOARD_SIZE]={0};
	
/** On définit une fonction assez proche de celle de l'humain mais pas tout à fait
 */
	search_colors(symbole, x, y, visite, colors);
	
/** On définit un tableau contenant les couleurs adjacentes (1 si présente)
 */
	int perimeters[7]={0};
/** On définit une fonction assez proche de celle de l'humain mais pas tout à fait
 */
	for (int i=0; i<7; i++){
		/** on définit un tableau rempli de 0, les cases passeront à 1 lorsqu'elles auront été visitées
		*/
		if (colors[i]){
			char visite[BOARD_SIZE * BOARD_SIZE]={0};
			perimeters[i]=count_perimeter(symbole, x, y, visite, 'A'+i, 0);
		}
	}
	
	char color=0;
	
	for(int i=1;i<7;i++) {
		if(perimeters[i]>perimeters[(int)color]) {
			color=(char)i;
		}
	}
	
	return color+'A';
}

int count_perimeter(char symbole, int x, int y, char *visite, char current_color, int perimeter) 
{
/** cette case (x,y) a été visité, on y retournera pas
 */
	visite[y * BOARD_SIZE + x]=1; 
	
	char color;
	
/** case à gauche
 */
	
	if ((x-1>=0) & (visite[y * BOARD_SIZE + x-1]==0)){
		color=get_cell(x-1,y);
		if ((color<='G') & (color>='A')& (color!=current_color)) {
			visite[y * BOARD_SIZE + x-1]=1;
			perimeter++;			
		}
		if ((color==symbole) | (color==current_color)){
			perimeter+=count_perimeter(symbole, x-1, y, visite, current_color, perimeter);
		}
	}
/** case à droite
 */
	if ((x+1<BOARD_SIZE)& (visite[(y) * BOARD_SIZE + x+1]==0)){
		color=get_cell(x+1,y);
		if ((color<='G') & (color>='A')& (color!=current_color)) {
			visite[y * BOARD_SIZE + x+1]=1;
			perimeter++;			
		}
		if ((color==symbole) | (color==current_color)){
			perimeter+=count_perimeter(symbole, x+1, y, visite, current_color, perimeter);
		}
	}
/** case en haut
 */
	if ((y-1>=0)& (visite[(y-1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y-1);
		if ((color<='G') & (color>='A')& (color!=current_color)) {
			visite[(y-1) * BOARD_SIZE + x]=1;
			perimeter++;			
		}
		if ((color==symbole) | (color==current_color)){
			perimeter+=count_perimeter(symbole, x, y-1, visite, current_color, perimeter);
		}
	}
/** case en bas
 */
	if ((y+1<BOARD_SIZE)& (visite[(y+1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y+1);
		if ((color<='G') & (color>='A')& (color!=current_color)) {
			visite[(y+1) * BOARD_SIZE + x]=1;
			perimeter++;			
		}
		if ((color==symbole) | (color==current_color)){
			perimeter+=count_perimeter(symbole, x, y+1, visite, current_color, perimeter);
		}
	}
	
	return perimeter;
}
