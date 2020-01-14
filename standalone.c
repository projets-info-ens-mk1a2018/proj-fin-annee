#include <stdio.h>     /* printf */
#include <stdlib.h>    
#include <time.h>


#include "7colors.h"
#include "maj.h"
#include "map_gen.h"
#include "human.h"
#include "stop_condition.h"
#include "territory.h"
#include "alea1.h"
#include "alea2.h"
#include "glouton.h"
#include "hegemonique.h"
#include "smart_glouton.h"



/** Program entry point */
int main(void)
{
	srand(time(NULL));
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
	   "*****************************************************\n\n");
	
/** Choix des types de joueurs
 */
	int player_type[2];
	printf("Quel est le type du joueur 1 ? \n");
	printf("Tape :\n");
	printf("1 pour un humain\n");
	printf("2 pour une IA aléatoire\n");
	printf("3 pour une IA semi-aléatoire\n");
	printf("4 pour une IA gloutonne\n");
	printf("5 pour une IA hégémonique\n");
	printf("6 pour une IA grosse gloutonne.\n");
	scanf("%d",&(player_type[0]));
	
	printf("Quel est le type du joueur 2 ? \n");
	printf("Tape :\n");
	printf("1 pour un humain\n");
	printf("2 pour une IA aléatoire\n");
	printf("3 pour une IA semi-aléatoire\n");
	printf("4 pour une IA gloutonne\n");
	printf("5 pour une IA hégémonique\n");
	printf("6 pour une IA grosse gloutonne.\n");
	scanf("%d",&(player_type[1]));
	
	int nb_games;
	int who_won[2]={0};
	printf("Combien de parties veux-tu jouer ? ");
	scanf("%d",&nb_games);
	
/** Affichage des conditions et du terrain
 */
	print_legal_colors();
	
	int player=0;
	for(int i=0;i<nb_games;i++) {
		map_gen();
		print_board();
		
		while (!game_end(who_won)){
			switch (player_type[player]){
				case 1:
				maj_board(human_color(player), player);
				break;
				case 2:
				maj_board(alea1_color(),player);
				break;
				case 3:
				maj_board(alea2_color(player),player);
				break;
				case 4:
				maj_board(glouton_color(player),player);
				break;
				case 5:
				maj_board(hegemonique_color(player),player);
				//maj_board(glouton_color(player),player);
				break;
				case 6:
				maj_board(smart_glouton_color(player),player);
			}
			
			print_territory(0);
			print_territory(1);
			print_board();
			
			player=1-player;
		}
		
		printf("Joueur 1 : %d victoires\n",who_won[0]);
		printf("Joueur 2 : %d victoires\n",who_won[1]);
	}
	
	
	
    return 0; // Everything went well
}
