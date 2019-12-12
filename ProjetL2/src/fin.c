#include "fin.h"

Ecran_fin* initialiser_ecran_fin(SDL_Renderer* renderer){
    Ecran_fin* ef = malloc(sizeof(Ecran_fin));
    ef->fond = charger_image_transparente("images/ecran/Fond_Ecran_Fin.bmp", renderer, 0,255,255);
    ef->quitter = charger_image_transparente("images/quitter.bmp", renderer, 0,255,255);
    ef->you_win = charger_image_transparente("images/ecran/You_Win.bmp", renderer, 0,255,255);
    return ef;
}

void dessiner_ecran_fin(Ecran_fin* ef, SDL_Renderer* renderer, int mouseX, int mouseY, SDL_Event evenement, int* ecran){
	if(collisions_point_rect(mouseX, mouseY, (SCREEN_WIDTH/2) - (QUIT_WIDTH), 2*SCREEN_HEIGHT/3 - (QUIT_HEIGHT/2), QUIT_WIDTH*2, QUIT_HEIGHT*2) && (evenement.type == SDL_MOUSEBUTTONUP))
	    *ecran = 3;
	dessiner_fond_ecran(ef->fond, renderer);
	dessiner_quitter(ef->quitter, renderer, mouseX, mouseY);
	dessiner_you_win(ef->you_win, renderer);
}

void dessiner_fond_ecran(SDL_Texture* text, SDL_Renderer* renderer){
	SDL_Rect SrcR, DestR;
	
	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = SCREEN_WIDTH;
	SrcR.h = SCREEN_HEIGHT;
	
	DestR.x = 0;
	DestR.y = 0;
	DestR.w = SCREEN_WIDTH;
	DestR.h = SCREEN_HEIGHT;
	
	SDL_RenderCopy(renderer, text, &SrcR, &DestR);
}

void dessiner_quitter(SDL_Texture* text, SDL_Renderer* renderer, int mouseX, int mouseY){
	SDL_Rect SrcR, DestR;
	
	DestR.x = (SCREEN_WIDTH/2) - (QUIT_WIDTH);
	DestR.y = 2*SCREEN_HEIGHT/3 - (QUIT_HEIGHT/2);
	DestR.w = QUIT_WIDTH*2;
	DestR.h = QUIT_HEIGHT*2;
	
	int Offset = 0;
	if(collisions_point_rect(mouseX, mouseY, DestR.x, DestR.y, DestR.w, DestR.h))
		Offset = QUIT_HEIGHT;
		
	SrcR.x = 0;
	SrcR.y = 0 + Offset;
	SrcR.w = QUIT_WIDTH;
	SrcR.h = QUIT_HEIGHT;

	SDL_RenderCopy(renderer, text, &SrcR, &DestR);
}

void dessiner_you_win(SDL_Texture* text, SDL_Renderer* renderer){
	SDL_Rect SrcR, DestR;
	
	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = YOUWIN_WIDTH;
	SrcR.h = YOUWIN_HEIGHT;
	
	DestR.x = SCREEN_WIDTH/2 - YOUWIN_WIDTH;
	DestR.y = SCREEN_HEIGHT/4;
	DestR.w = YOUWIN_WIDTH*2;
	DestR.h = YOUWIN_HEIGHT*2;
	
	SDL_RenderCopy(renderer, text , &SrcR, &DestR);
}

void effacer_fin(Ecran_fin* ef){
    SDL_DestroyTexture(ef->fond); ef->fond = NULL;
    SDL_DestroyTexture(ef->quitter); ef->quitter = NULL;
    SDL_DestroyTexture(ef->you_win); ef->you_win = NULL;
    free(ef); ef = NULL;
}
