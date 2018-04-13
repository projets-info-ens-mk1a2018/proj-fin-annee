/**
 * 7 colors par Julien Baltazar et Alexandre Faye-Bédrin
 */
#ifndef smart_glouton
#define smart_glouton

int count_territory(char symbole, int x, int y, char *visite, char *colors, int iter, int max_iter, int terr);
char smart_glouton_color(int player);

#endif
