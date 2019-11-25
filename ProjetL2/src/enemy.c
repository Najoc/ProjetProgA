#include "enemy.h"

Enemy* initialiser_enemy(Sprite* s, Attaque* a, int taille){
    Enemy* e = malloc(sizeof(Enemy));
    e->sp = s;
    e->atk = a;
    e->tailleAtk = taille;
    e->pattern = -1;

    return e;
}

void jouer_pattern(Enemy* e, SDL_Renderer* renderer, Sprite** tab, int cible){

    if(e->atk[e->pattern].mono){
	attaquer(tab[cible], &e->atk[e->pattern], e->atk[e->pattern].tailletab);
	dessiner_attaque_sur_sprite(&e->atk[e->pattern], renderer, tab[cible], e->atk[e->pattern].largeurImage ,e->atk[e->pattern].hauteurImage);
    }else{
        for(int i=0; i < 4; i++){
	    attaquer(tab[i], &e->atk[e->pattern], e->atk[e->pattern].tailletab);
	}
	dessiner_attaque_sur_tile(&e->atk[e->pattern], renderer,e->atk[e->pattern].largeurImage ,e->atk[e->pattern].hauteurImage, e->atk[e->pattern].tailletab);
    }
}
 
