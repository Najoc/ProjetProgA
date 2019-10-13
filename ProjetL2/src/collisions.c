#include "collisions.h"
#include "grille.h"

void collisions_mouse_tilemap(Tilemap* g){
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	//transformation des coordonnées cartésiennens en coordonnées grille
	int mouse_grid_x = (mouseY/(g->htile*4)) + (mouseX/(g->ltile*4));
	int mouse_grid_y = -(mouseX/(g->ltile*4)) + (mouseY/(g->htile*4));
	
	for(int i; i<g->largeur; i++){
	    for(int j; j < g->hauteur-1; j++){
	        if((mouse_grid_x == g->tabTile[g->largeur][g->hauteur].x)
	        && (mouse_grid_y == g->tabTile[g->largeur][g->hauteur].y)){
		  printf("La souris se situe sur la case (%d,%d)", g->tabTile[g->largeur][g->hauteur].x,g->tabTile[g->largeur][g->hauteur].x);
	        }
	    }
	}
}
