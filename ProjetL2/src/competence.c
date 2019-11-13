#include "competence.h"

Competence* initialiser_competence(Tile* tab, char ch, SDL_Renderer* renderer){
    Competence* c = malloc(sizeof(Competence));
    c->zonePossible = tab;
    c->type = ch;
    c->texture = charger_image_transparente("images/surbrillance.bmp", renderer, 0,255,255);
    return c;
}

Competence* ajouter_comp_liz(int spriteX, int spriteY, SDL_Renderer* renderer){ 
    Tile* t = malloc(sizeof(Tile)*9);
    for(int i=0; i<3; i++){
	for(int j=0; j<3; j++){
	    t[i+j].x = spriteX -1 +i;
	    t[i+j].y = spriteY -1 +j;
	}
    }
    Competence* c = initialiser_competence(t, 'd', renderer);
    return c;
}

void dessiner_comp_sur_tile(Competence* c, SDL_Renderer* renderer, int longueurTab){

    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int i = 0; i < longueurTab; i++){
    	SrcR.x = TILE_WIDTH/2;
    	SrcR.y = 0;
    	SrcR.w = TILE_WIDTH/2;
    	SrcR.h = TILE_HEIGHT/2;

	if(c->zonePossible[i].x > 0 && c->zonePossible[i].x < 9 && c->zonePossible[i].y > 0 && c->zonePossible[i].y < 9){
	    int RenderXcomp = c->zonePossible[i].x;
	    int RenderYcomp = c->zonePossible[i].y;
    	    iso_to_coord(&RenderXcomp, &RenderYcomp);

    	    DestR.x = RenderXcomp - TILE_WIDTH/2;
    	    DestR.y = RenderYcomp;
    	    DestR.w = TILE_WIDTH;
    	    DestR.h = TILE_HEIGHT;
	
	    SDL_RenderCopy(renderer, c->texture, &SrcR, &DestR);
	}
    }
}
