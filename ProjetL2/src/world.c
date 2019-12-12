#include "world.h"

World* initialiser_monde(SDL_Renderer* renderer)
{
	World* w = malloc(sizeof(World));
	w->grille = initialiser_grille("images/terre.bmp", renderer, "grilles/general.txt", 10, 10);
	w->tabSprites = allouer_tab_2D_Sprite(16,1);
	w->accueil = init_accueil(renderer);
	//w->Ecran_fin = initialiser_ecran_fin(renderer);
	return w;
}

int screenskip(SDL_Event event, Accueil *a) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //condition chaangement écran
    if (mouseX > 300 && mouseX < 300+PLAY_WIDTH && mouseY > SCREEN_HEIGHT - 70 && mouseY < SCREEN_HEIGHT - 20) {

        if (event.type == SDL_MOUSEBUTTONUP) {
            detruire_accueil(a); a = NULL;
            return 2;
        }
    }
    if (mouseX > 650 && mouseX < 650+QUIT_WIDTH && mouseY > SCREEN_HEIGHT - 70 && mouseY < SCREEN_HEIGHT - 20) {
        if (event.type == SDL_MOUSEBUTTONUP)
        return 3;
    }
    return 1;
}

void liberer_monde(World* w, int tailleSprites){
    detruire_grille(w->grille); w->grille = NULL;
    for(int i = 0; i < tailleSprites; i++){
	DetruireSprites(w->tabSprites[i]);
    }
    free(w->tabSprites); w->tabSprites = NULL;
    free(w); w = NULL;
}
