#include "world.h"

int screenskip(SDL_Event event) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //condition chaangement écran
    if (mouseX > 490 && mouseX < 490+PLAY_WIDTH && mouseY > 450 && mouseY < 450+PLAY_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP)
        return 2;
    }
    if (mouseX > 440 && mouseX < 440+QUIT_WIDTH && mouseY > 550 && mouseY < 550+QUIT_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP)
        return 3;
    }
    return 1;
}

void liberer_monde(World* w, int tailleSprites){
    detruire_accueil(w->accueil); w->accueil = NULL;
    detruire_grille(w->grille); w->grille = NULL;
    //effacer_fin(w->fin); w->fin = NULL;
    effacer_enemy(w->tabEnemy); w->tabEnemy = NULL;
    for(int i = 0; i < tailleSprites; i++){
	DetruireSprites(w->tabSprites[i]);
    }
    w->tabSprites = NULL;
    free(w); w = NULL;
}
