#include "enemy.h"

Attaque** allouer_tab_2D_atk(int n){
    Attaque** tab2D = malloc(n*sizeof(Attaque*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(sizeof(Attaque));
    }
    return tab2D;
}

Enemy* initialiser_enemy(Sprite* s, int nombre_pattern){
    Enemy* e = malloc(sizeof(Enemy));
    e->atk = allouer_tab_2D_atk(nombre_pattern);
    e->nbrPattern = nombre_pattern;
    e->sp = s;
    e->pattern = 0;

    return e;
}

void ajouter_pattern(Enemy* e, Attaque* a, int index){
    //on ajoute uniquement s'il reste de la place dans le tableau
    if(e->nbrPattern > index){
    	e->atk[index] = a;
    }
}

void jouer_pattern(Enemy* e, Sprite** tab, int cible){

    if(e->atk[e->pattern][0].mono){
	attaquer(tab[cible], e->atk[e->pattern], e->atk[e->pattern][0].tailletab);
    }else{
        for(int i=0; i < 4; i++){
	    attaquer(tab[i], e->atk[e->pattern], e->atk[e->pattern][0].tailletab);
	}
    }
}

void gestion_competence_attaque(Sprite* s, Enemy* e, int mouseX, int mouseY){
    if(mouseX >= s->comp[1]->zonePossible[0].x && mouseY >= s->comp[1]->zonePossible[0].y && mouseX <= s->comp[1]->zonePossible[24].x && mouseY <= s->comp[1]->zonePossible[24].x){
	printf("hey");
	if(e->sp->x == mouseX && e->sp->y == mouseY){
	    if(e->sp->vie - 500 < 0){
		e->sp->vie = 0;
	    }else{
		e->sp->vie -= 500;
	    }
	    s->PA -= 2;
	}
    }
}

void effacer_enemy(Enemy* e){
    DetruireSprites(e->sp); e->sp = NULL;
    for(int i=0; i<7; i++)
    	effacer_attaque(e->atk[i]);
    free(e->atk); e->atk = NULL;
    free(e); e = NULL;
}
