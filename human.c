#include <stdio.h>
#include "maj.h"

char human_color(int player)
{
	char color;
	printf("Joueur %d, à toi de jouer\nCouleur: ",player+1);
	scanf(" %c", &color);
	return color;
}
