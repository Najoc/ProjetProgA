#include "interface.h"

int* initialiser_lifebar(){

    int* lifebar = malloc(sizeof(int)*20);

    lifebar[0] = 0;
    lifebar[19] = 2;
    for(int i=1; i<19; i++){
	lifebar[i] = 1;
    }

    return lifebar;
}

void dessiner_lifebar(SDL_Renderer* renderer, SDL_Texture* spritesheet, Sprite* s, int x, int y){

    //gestion tableau
    //vie pleine
    int nombreUn = s->vie/5 ;
    int temp = 0;

    for(int i = 0; i<nombreUn; i++){
	s->lifebar[i] = 1;
	temp++;
    }
    if(nombreUn == 20)
	s->lifebar[19] = 2;
    if(nombreUn > 0)
	s->lifebar[0] = 0;

    //vie vide
    for(int j = temp; j < 19; j++){
	s->lifebar[j] = 4;
    }
    
    if(nombreUn < 20)
	s->lifebar[19] = 5;
    if(nombreUn == 0)
	s->lifebar[0] = 3;

    SDL_Rect SrcR;
    SDL_Rect DestR;

    //dessin
    for(int i = 0; i<20; i++){

	SrcR.x = (s->lifebar[i]%3) * 6;
	SrcR.y = s->lifebar[i] > 2? 10: 0;
	SrcR.w = 6;
	SrcR.h = 10;

	DestR.x = (x + i*6) * 2;
	DestR.y = y;
	DestR.w = 6 * 2;
	DestR.h = 10 * 2;

	SDL_RenderCopy(renderer, spritesheet, &SrcR, &DestR);
    }
}

void dessiner_cadre_perso(SDL_Renderer* renderer, SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, Sprite** tab){
	
    SDL_Rect SrcR;
    SDL_Rect DestR;

    //dessin des cadres
    for(int i = 0; i<4; i++){

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = 166;
	SrcR.h = 35;

	DestR.x = ((i%2)*166*2);
	DestR.y = i > 1? (SCREEN_HEIGHT -(35*2))  : (SCREEN_HEIGHT - (70*2)) ;
	DestR.w = 166 * 2;
	DestR.h = 35 * 2;

	SDL_RenderCopy(renderer, cadre, &SrcR, &DestR);
    }

    //dessin des portraits
    for(int i = 0; i<4; i++){

	SrcR.x = i%2 * 32;
	SrcR.y = i>1? 32 : 0;
	SrcR.w = 32;
	SrcR.h = 32;

	DestR.x = (1 + (i%2)*166) * 2;
	DestR.y = i > 1? (SCREEN_HEIGHT -(34*2)) : (SCREEN_HEIGHT - (69*2));
	DestR.w = 32 * 2;
	DestR.h = 32 * 2;

	SDL_RenderCopy(renderer, portrait, &SrcR, &DestR);
    }

    //dessin barres de vies
    for(int i = 0; i<4; i++){
	int x = (40 + ((i%2)*166));
	int y = i > 1? SCREEN_HEIGHT - (15*2): SCREEN_HEIGHT - (50*2);
	dessiner_lifebar(renderer, lifebar, tab[i], x,y);
    }

}






