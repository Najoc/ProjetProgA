#include "attaque.h"

Attaque* initialiser_attaque(const char* frame, SDL_Renderer* renderer, char* nom, char type, int mono, Tile* tabTile, int taille, int largeur, int hauteur){

    Attaque* a = malloc(sizeof(Attaque));
    a->Frame = charger_image_transparente(frame, renderer, 0, 255, 255);
    a->nom = nom;
    a->type = type;
    a->mono = mono;
    a->zone = tabTile;
    a->currentFrame = 0;
    a->draw = 0;
    a->tailletab = taille;
    a->largeurImage = largeur;
    a->hauteurImage = hauteur;
    return a;
}

void attaquer(Sprite* s, Attaque* attaque, int taille){

    //les attaques ne touche pas les alliés
    if(s->type != attaque->type){

	//parcours de la zone d'attaque
	for(int i = 0; i<taille; i++){
	    
	    //Si un sprite est dans la zone d'attaque
	    if((s->x == attaque->zone[i].x) && (s->y == attaque->zone[i].y)){

		//calcul de dégâts
		if((s->vie - attaque->zone[i].degats < 0)){
		     s->vie = 0;
		}else{
		     s->vie -= attaque->zone[i].degats;
		
	        }
	    }
        }
    }

}

void dessiner_attaque_sur_tile(Attaque* a, SDL_Renderer* renderer, int taille){

    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int j = 0; j < taille; j++){
		SrcR.x = a->currentFrame%3 * TILE_WIDTH/2;
		SrcR.y = 0;
		SrcR.w = TILE_WIDTH/2;
		SrcR.h = TILE_HEIGHT/2;

		int RenderXatk = a->zone[j].x;
		int RenderYatk = a->zone[j].y;
		iso_to_coord(&RenderXatk, &RenderYatk);

		DestR.x = RenderXatk - TILE_WIDTH/2;
		DestR.y = RenderYatk;
		DestR.w = TILE_WIDTH;
		DestR.h = TILE_HEIGHT;
			
		SDL_RenderCopy(renderer, a->Frame, &SrcR, &DestR);
    }
    a->currentFrame++;
}

void dessiner_attaque_sur_sprite(Attaque* a, SDL_Renderer* renderer, Sprite* s, int largeur, int hauteur){

    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = a->currentFrame%3 * largeur;
    SrcR.y = 0;
    SrcR.w = largeur;
    SrcR.h = hauteur;

    DestR.x = s->x;
    DestR.y = s->y - s->height/2;
    DestR.w = TILE_WIDTH;
    DestR.h = TILE_HEIGHT;
	
    SDL_RenderCopy(renderer, a->Frame, &SrcR, &DestR);
}



void effacer_attaque(Attaque* a){
	SDL_DestroyTexture(a->Frame); a->Frame = NULL;
	free(a->zone); a->zone = NULL;
	free(a); a = NULL;
}















