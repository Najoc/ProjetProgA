#include "world.h"

int screenskip(SDL_Event event, Accueil *a) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //condition chaangement écran
    if (mouseX > 300 && mouseX < 300+PLAY_WIDTH && mouseY > SCREEN_HEIGHT - 70 && mouseY < SCREEN_HEIGHT - 20) {

        if (event.type == SDL_MOUSEBUTTONUP) {
            detruire_accueil(a);
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
    //detruire_accueil(w->accueil); w->accueil = NULL;
    detruire_grille(w->grille); w->grille = NULL;
    effacer_enemy(w->tabEnemy); w->tabEnemy = NULL;
    for(int i = 0; i < tailleSprites; i++){
	DetruireSprites(w->tabSprites[i]);
    }
    w->tabSprites = NULL;
    free(w); w = NULL;
}
