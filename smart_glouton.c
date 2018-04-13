#include "7colors.h"
#include "smart_glouton.h"

char smart_glouton_color(int player)
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
	
	
	
	int territories[7][7]={0};

	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
				if(i!=j) {
				/** on définit un tableau rempli de 0, les cases passeront à 1 lorsqu'elles auront été visitées
				 */
					char visite[BOARD_SIZE * BOARD_SIZE]={0};
				/** On définit un tableau contenant les couleurs adjacentes (1 si présente)
				 */
					char colors[2]={'A'+i,'A'+j};
					territories[i][j]=count_territory(symbole, x, y, visite, colors, 0, 2, 0);
				}
		}
	}
	char color=0;
	char color2=0;
	
	for(int i=0;i<7;i++) {
		for(int j=0;j<7;j++) {
			if(territories[i][j]>territories[(int)color][(int)color2]) {
				color=(char)i;
				color2=(char)j;
			}
		}
	}
	
	return color+'A';
}

int count_territory(char symbole, int x, int y, char *visite, char *colors, int iter, int max_iter, int terr) 
{
	
	//colors contient les couleurs des coups suivants, mais pas du coup en cours
/** cette case (x,y) a été visité, on y retournera pas
 */
	visite[y * BOARD_SIZE + x]=1; 
	
	char color,current_color=get_cell(x,y);
	
/** case à gauche
 */
	
	if ((x-1>=0) & (visite[y * BOARD_SIZE + x-1]==0)){
		color=get_cell(x-1,y);
		if((color<='G') & (color>='A')) {
			// Si on reste dans la même couleur, on continue à se balader pareil
			if(color==current_color) {
				terr++;
				terr+=count_territory(symbole, x-1, y, visite, colors, iter, max_iter, 0);
			} else
			// Sinon on vérifie qu'on a bien le droit
			if(iter<max_iter) {
				int can_pass=0;
				for(int i=iter;i<max_iter;i++) {
					if(color==colors[i]) {
						can_pass=1;
					}
				}
				if(can_pass) {
					terr++;
					terr+=count_territory(symbole, x-1, y, visite, colors, iter+1, max_iter, 0);
				}
			}
		}
		if (color==symbole){
			terr+=count_territory(symbole, x-1, y, visite, colors, 0, max_iter, 0);
		}
	}
/** case à droite
 */
	if ((x+1<BOARD_SIZE)& (visite[(y) * BOARD_SIZE + x+1]==0)){
		color=get_cell(x+1,y);
		if((color<='G') & (color>='A')) {
			if(color==current_color) {
				terr++;
				terr+=count_territory(symbole, x+1, y, visite, colors, iter, max_iter, 0);
			} else
			if(iter<max_iter) {
				int can_pass=0;
				for(int i=iter;i<max_iter;i++) {
					if(color==colors[i]) {
						can_pass=1;
					}
				}
				if(can_pass) {
					terr++;
					terr+=count_territory(symbole, x+1, y, visite, colors, iter+1, max_iter, 0);
				}
			}
		}
		if (color==symbole){
			terr+=count_territory(symbole, x+1, y, visite, colors, 0, max_iter, 0);
		}
	}
/** case en haut
 */
	if ((y-1>=0)& (visite[(y-1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y-1);
		if((color<='G') & (color>='A')) {
			if(color==current_color) {
				terr++;
				terr+=count_territory(symbole, x, y-1, visite, colors, iter, max_iter, 0);
			} else
			if(iter<max_iter) {
				int can_pass=0;
				for(int i=iter;i<max_iter;i++) {
					if(color==colors[i]) {
						can_pass=1;
					}
				}
				if(can_pass) {
					terr++;
					terr+=count_territory(symbole, x, y-1, visite, colors, iter+1, max_iter, 0);
				}
			}
		}
		if (color==symbole){
			terr+=count_territory(symbole, x, y-1, visite, colors, 0, max_iter, 0);
		}
	}
/** case en bas
 */
	if ((y+1<BOARD_SIZE)& (visite[(y+1) * BOARD_SIZE + x]==0)){
		color=get_cell(x,y+1);
		if((color<='G') & (color>='A')) {
			if(color==current_color) {
				terr++;
				terr+=count_territory(symbole, x, y+1, visite, colors, iter, max_iter, 0);
			} else
			if(iter<max_iter) {
				int can_pass=0;
				for(int i=iter;i<max_iter;i++) {
					if(color==colors[i]) {
						can_pass=1;
					}
				}
				if(can_pass) {
					terr++;
					terr+=count_territory(symbole, x, y+1, visite, colors, iter+1, max_iter, 0);
				}
			}
		}
		if (color==symbole){
			terr+=count_territory(symbole, x, y+1, visite, colors, 0, max_iter, 0);
		}
	}
	return terr;
}
