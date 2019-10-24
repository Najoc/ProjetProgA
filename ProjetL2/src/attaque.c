#include "attaque.h"

Attaque* initialiser_attaque(const char* frame, SDL_Renderer* renderer, int degat, char* nom, char type, Tile* tabTile){

    Attaque* a = malloc(sizeof(Attaque));
    a->Frame = charger_image_transparente(frame, renderer, 0, 255, 255);
    a->degats = degat;
    a->nom = nom;
    a->type = type;
    a->zone = tabTile;
    a->currentFrame = 0;
    a->draw = 0;

    return a;
}

void attaquer(Sprite* s, Attaque* attaque, Tilemap* t){

    //les attaques ne touche pas les alliés
    attaque->draw = 1;
    if(s->type != attaque->type){

	//parcours de la zone d'attaque
	for(int i = 0; i<t->largeur; i++){
	    
	    //Si un sprite est dans la zone d'attaque
	    if((s->x == attaque->zone[i].x) && (s->y == attaque->zone[i].y)){

		//calcul de dégâts
		if((s->vie - attaque->degats < 0)){
		     s->vie = 0;
		}else{
		     s->vie -= attaque->degats;
		
	        }
	    }
        }
    }

}  

void dessiner_attaque_sur_tile(Attaque* a, SDL_Renderer* renderer, int largeur, int hauteur, int longueurTab){

    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int i = 0; i < longueurTab; i++){
    	SrcR.x = a->currentFrame%3 * largeur;
    	SrcR.y = 0;
    	SrcR.w = largeur;
    	SrcR.h = hauteur;

	int RenderXatk = a->zone[i].x;
	int RenderYatk = a->zone[i].y;
    	iso_to_coord(&RenderXatk, &RenderYatk);

    	DestR.x = RenderXatk - TILE_WIDTH/2;
    	DestR.y = RenderYatk;
    	DestR.w = TILE_WIDTH;
    	DestR.h = TILE_HEIGHT;
	
	SDL_RenderCopy(renderer, a->Frame, &SrcR, &DestR);
    }
}

void effacer_attaque(Attaque* a){

   
}















