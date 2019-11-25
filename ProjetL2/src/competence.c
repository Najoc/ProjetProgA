#include "competence.h"

Competence* initialiser_competence(Tile* tab, char ch, SDL_Renderer* renderer){
    Competence* c = malloc(sizeof(Competence));
    c->zonePossible = tab;
    c->type = ch;
    c->texture = charger_image_transparente("images/surbrillance.bmp", renderer, 0,255,255);
    return c;
}

Competence* ajouter_comp_deplacement(int spriteX, int spriteY, SDL_Renderer* renderer, int perso){
    Tile* t;
    Competence* c;
    int k;
    switch(perso) {
	case 0:
	t = malloc(sizeof(Tile)*8);
        t[0].x = spriteX - 2; t[0].y = spriteY;
        t[1].x = spriteX - 1; t[1].y = spriteY;
        t[2].x = spriteX + 1; t[2].y = spriteY;
        t[3].x = spriteX + 2; t[3].y = spriteY;
        t[4].x = spriteX; t[4].y = spriteY - 2;
        t[5].x = spriteX; t[5].y = spriteY - 1;
        t[6].x = spriteX; t[6].y = spriteY + 1;
        t[7].x = spriteX; t[7].y = spriteY + 2;
	break;

        case 1:
	t = malloc(sizeof(Tile)*4);
        t[0].x = spriteX - 1; t[0].y = spriteY;
        t[1].x = spriteX + 1; t[1].y = spriteY;
        t[2].x = spriteX; t[2].y = spriteY - 1;
        t[3].x = spriteX; t[3].y = spriteY + 1;
	break;

	case 2:
	t = malloc(sizeof(Tile)*8);
        t[0].x = spriteX - 1; t[0].y = spriteY - 1;
        t[1].x = spriteX - 1; t[1].y = spriteY + 1;
        t[2].x = spriteX - 2; t[2].y = spriteY - 2;
        t[3].x = spriteX - 2; t[3].y = spriteY + 2;
        t[4].x = spriteX + 1; t[4].y = spriteY - 1;
        t[5].x = spriteX + 1; t[5].y = spriteY + 1;
        t[6].x = spriteX + 2; t[6].y = spriteY - 2;
        t[7].x = spriteX + 2; t[7].y = spriteY + 2;
	break;

        case 3:
	t = malloc(sizeof(Tile)*8);
        k = 0;
        for(int i=0; i<3; i+=2){
	    for(int j=0; j<3; j++){
	        t[k].x = (spriteX-1) +i;
	        t[k].y = (spriteY-1) +j;
	        ++k;
	    }
        }
        t[6].x = spriteX; t[6].y = spriteY-1;
        t[7].x = spriteX; t[7].y = spriteY+1;
    }
    c = initialiser_competence(t, 'd', renderer);
    return c;
}

void dessiner_comp_sur_tile(Competence* c, SDL_Renderer* renderer, int longueurTab, int mouseX, int mouseY){

    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int i = 0; i < longueurTab; i++){

        int offset = 0;
	if((mouseX == c->zonePossible[i].x) && (mouseY == c->zonePossible[i].y))
	    offset = TILE_WIDTH/2;
    	SrcR.x = TILE_WIDTH/2 + offset;
    	SrcR.y = 0;
    	SrcR.w = TILE_WIDTH/2;
    	SrcR.h = TILE_HEIGHT/2;

	if(c->zonePossible[i].x >= 0 && c->zonePossible[i].x <= 9 && c->zonePossible[i].y >= 0 && c->zonePossible[i].y <= 9){
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
