#include "interface.h"

int* initialiser_lifebar(int vie){

    int taille = vie/5;
    int* lifebar = malloc(sizeof(int)*taille);

    lifebar[0] = 0;
    lifebar[taille - 1] = 2;
    for(int i=1; i<(taille - 1); i++){
	lifebar[i] = 1;
    }

    return lifebar;
}

int* initialiser_PA(){

    int taille = 6;
    int* jauge = malloc(sizeof(int)*taille);
    for(int i = 0; i< 4; i++){
	jauge[i] = 0;
    }
    jauge[4] = 1;
    jauge[5] = 1;

    return jauge;
}


void dessin_interface_niveau(SDL_Renderer* renderer, 
			     SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, SDL_Texture* PA, SDL_Texture* button,
			     int mouseX, int mouseY,
			     Sprite** tab){

	dessiner_cadre_perso(renderer, portrait, cadre, lifebar, PA, tab, mouseX, mouseY);
	dessin_finTour(renderer, button, mouseX, mouseY);
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

	SrcR.x = (s->lifebar[i]%3) * LIFE_WIDTH;
	SrcR.y = s->lifebar[i] > 2? LIFE_HEIGHT: 0;
	SrcR.w = LIFE_WIDTH;
	SrcR.h = LIFE_HEIGHT;

	DestR.x = (x + i*LIFE_WIDTH) * 2;
	DestR.y = y;
	DestR.w = LIFE_WIDTH * 2;
	DestR.h = LIFE_HEIGHT * 2;

	SDL_RenderCopy(renderer, spritesheet, &SrcR, &DestR);
    }
}

void dessiner_PA(SDL_Renderer* renderer, SDL_Texture* spritesheet, Sprite* s, int x, int y){
   //gestion du tableau
   for(int i = 0; i<s->PA; i++){
	s->jaugePA[i] = 0;
   }
   for(int j = s->PA; j<6; j++){
	s->jaugePA[j] = 1;
   }

    SDL_Rect SrcR;
    SDL_Rect DestR;
   
    //dessin

    for(int i = 0; i<6; i++){

	SrcR.x = (s->jaugePA[i]%2) * PA_WIDTH;
	SrcR.y = 0;
	SrcR.w = PA_WIDTH;
	SrcR.h = PA_HEIGHT;

	DestR.x = (x + i*PA_WIDTH) + 8*i;
	DestR.y = y;
	DestR.w = PA_WIDTH;
	DestR.h = PA_HEIGHT;

	SDL_RenderCopy(renderer, spritesheet, &SrcR, &DestR);
    }

}

void dessiner_cadre_perso(SDL_Renderer* renderer, SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, SDL_Texture* PA, Sprite** tab, int mouseX, int mouseY){
    //dessin des cadres
    dessin_cadre(renderer, cadre, mouseX, mouseY);
    dessin_portraits(renderer, portrait);

    //dessin barres de vies
    for(int i = 0; i<4; i++){
	int x = (40 + ((i%2)*CADRE_WIDTH));
	int y = i > 1? SCREEN_HEIGHT - (15*2): SCREEN_HEIGHT - (50*2);
	dessiner_lifebar(renderer, lifebar, tab[i], x,y);

	int xPA = 80 + ((i%2) * CADRE_WIDTH*2);
	int yPA = i > 1? SCREEN_HEIGHT - (50): SCREEN_HEIGHT - (120);
	dessiner_PA(renderer, PA, tab[i], xPA, yPA);
    }
}


void dessin_cadre(SDL_Renderer* renderer, SDL_Texture* cadre,int mouseX,int mouseY) {
    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int i = 0; i<4; i++){
	int offSet = 0;
   	if(collisions_point_rect(mouseX, mouseY,((i%2)*CADRE_WIDTH*2), i > 1? (SCREEN_HEIGHT -(CADRE_HEIGHT*2))  : (SCREEN_HEIGHT - ((CADRE_HEIGHT*2)*2)), CADRE_WIDTH * 2, 		CADRE_HEIGHT * 2))
		offSet = 35;
	SrcR.x = 0;
	SrcR.y = 0 + offSet;
	SrcR.w = CADRE_WIDTH;
	SrcR.h = CADRE_HEIGHT;

	DestR.x = ((i%2)*CADRE_WIDTH*2);
	DestR.y = i > 1? (SCREEN_HEIGHT -(CADRE_HEIGHT*2))  : (SCREEN_HEIGHT - ((CADRE_HEIGHT*2)*2)) ;
	DestR.w = CADRE_WIDTH * 2;
	DestR.h = CADRE_HEIGHT * 2;

	SDL_RenderCopy(renderer, cadre, &SrcR, &DestR);
    }
}


void dessin_portraits(SDL_Renderer* renderer, SDL_Texture* portrait) {
    SDL_Rect SrcR;
    SDL_Rect DestR;

    for(int i = 0; i<4; i++){

	SrcR.x = i%2 * 32;
	SrcR.y = i>1? 32 : 0;
	SrcR.w = 32;
	SrcR.h = 32;

	DestR.x = (1 + (i%2)*CADRE_WIDTH) * 2;
	DestR.y = i > 1? (SCREEN_HEIGHT -((CADRE_HEIGHT-1)*2)) : (SCREEN_HEIGHT - (((CADRE_HEIGHT*2)-1)*2));
	DestR.w = 32 * 2;
	DestR.h = 32 * 2;

	SDL_RenderCopy(renderer, portrait, &SrcR, &DestR);
    }
}

void dessin_finTour(SDL_Renderer* renderer, SDL_Texture* button, int mouseX, int mouseY){
   SDL_Rect SrcR;
   SDL_Rect DestR;

   DestR.x = SCREEN_WIDTH - 200;
   DestR.y = SCREEN_HEIGHT -100;
   DestR.w = 200;
   DestR.h = 100;

   int offSet = 0;
   if(collisions_point_rect(mouseX, mouseY,DestR.x, DestR.y, DestR.w, DestR.h))
	offSet = 50;

   SrcR.x = 0;
   SrcR.y = 0 + offSet;
   SrcR.w = 100;
   SrcR.h = 50;

   SDL_RenderCopy(renderer, button, &SrcR, &DestR);

}

void dessin_competence_cadre(SDL_Renderer* renderer, SDL_Texture* comp, int mouseX, int mouseY, int compdraw, int noPA){
  
   SDL_Rect SrcR; 
   SDL_Rect SrcR2;
   SDL_Rect DestR;
   SDL_Rect DestR2;

   DestR.x = 0;
   DestR.y = SCREEN_HEIGHT - 4*(CADRE_HEIGHT) -COMP_HEIGHT;
   DestR.w = CADRE_WIDTH;
   DestR.h = COMP_HEIGHT;

   DestR2.x = CADRE_WIDTH;
   DestR2.y = SCREEN_HEIGHT - 4*(CADRE_HEIGHT) -COMP_HEIGHT;
   DestR2.w = CADRE_WIDTH;
   DestR2.h = COMP_HEIGHT;

   int personnage = compdraw;
   int offSet = 0;
   int offSet2 = 0;
   if(collisions_point_rect(mouseX, mouseY,DestR.x, DestR.y, DestR.w, DestR.h) && !noPA)
	offSet = 4*COMP_HEIGHT;
   if(noPA){
	if(collisions_point_rect(mouseX, mouseY,DestR.x, DestR.y, DestR.w, DestR.h))
	    offSet = 8*COMP_HEIGHT;
   }
   if(collisions_point_rect(mouseX, mouseY,DestR2.x, DestR2.y, DestR2.w, DestR2.h) && !noPA)
	offSet2 = 4*COMP_HEIGHT;
   if(noPA){
	if(collisions_point_rect(mouseX, mouseY,DestR2.x, DestR2.y, DestR2.w, DestR2.h))
	    offSet2 = 8*COMP_HEIGHT;
   }

   SrcR.x = 0;
   SrcR.y = 0 + (personnage * COMP_HEIGHT)+ offSet;
   SrcR.w = CADRE_WIDTH;
   SrcR.h = COMP_HEIGHT;

   SrcR2.x = CADRE_WIDTH;
   SrcR2.y = 0 + (personnage * COMP_HEIGHT)+ offSet2;
   SrcR2.w = CADRE_WIDTH;
   SrcR2.h = COMP_HEIGHT;

   SDL_RenderCopy(renderer, comp, &SrcR, &DestR);
   SDL_RenderCopy(renderer, comp, &SrcR2, &DestR2);

}




