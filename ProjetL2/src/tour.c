#include "tour.h"


int fin_tour(int mousecoordX, int mousecoordY){
    if(collisions_point_rect(mousecoordX, mousecoordY, FIN_TOUR_X, FIN_TOUR_Y, FIN_TOUR_WIDTH, FIN_TOUR_HEIGHT))
	return -1;
    return 1;
}

void tour_ennemi(Enemy* e, Sprite** tab){
    if(e->pattern > 6)
	e->pattern = 0;
    jouer_pattern(e, tab, 0);
    e->pattern++;
}
