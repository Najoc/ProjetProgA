#include "accueil.h"


Accueil* init_accueil(SDL_Renderer* renderer) {
    Accueil* a = malloc(sizeof(Accueil));
    a->fond = charger_image_transparente("images/Background.bmp", renderer, 0, 255, 255);
    a->titre = charger_image_transparente("images/ntitre.bmp", renderer, 0, 255, 255);
    a->jouer = charger_image_transparente("images/jouer.bmp", renderer, 0, 255, 255);
    a->quitter = charger_image_transparente("images/quitter.bmp", renderer, 0, 255, 255);

    return a;
}

void affichage_accueil(SDL_Renderer* renderer, Accueil* a, int *mouseX, int *mouseY) {
    SDL_RenderCopy(renderer, a->fond, NULL, NULL);
    int offplay = 0; int offquit = 0;
    if (*mouseX > 300 && *mouseX < 300+PLAY_WIDTH && *mouseY > SCREEN_HEIGHT - 70 && *mouseY < SCREEN_HEIGHT - 20)
        offplay = 40;
    if (*mouseX > 650 && *mouseX < 650+QUIT_WIDTH && *mouseY > SCREEN_HEIGHT - 70 && *mouseY < SCREEN_HEIGHT - 20)
        offquit = 20;
    renderElement(renderer,a->titre, 0, 0, TITLE_WIDTH, TITLE_HEIGHT, 240, 200, TITLE_WIDTH, TITLE_HEIGHT);
    renderElement(renderer,a->jouer, 0, 0 + offplay, PLAY_WIDTH, PLAY_HEIGHT, 300, SCREEN_HEIGHT - 70 , PLAY_WIDTH, 50);
    renderElement(renderer,a->quitter, 0, 0 + offquit, QUIT_WIDTH, QUIT_HEIGHT, 650, SCREEN_HEIGHT - 70 , QUIT_WIDTH, 50);
}

int collision_play(int mouseX, int mouseY) {
    if (mouseX > 300 && mouseX < 300+PLAY_WIDTH && mouseY > SCREEN_HEIGHT - 70 && mouseY < SCREEN_HEIGHT - 20)
        return 40;
    return 0 ;
}

int collision_quit(int mouseX, int mouseY) {
    if (mouseX > 650 && mouseX < 650+QUIT_WIDTH && mouseY > SCREEN_HEIGHT - 70 && mouseY < SCREEN_HEIGHT - 20)
        return 20;
    return 0;
}

void renderElement(SDL_Renderer* renderer, SDL_Texture* image, int SrcX, int SrcY, int SrcW, int SrcH, int DestX, int DestY, int DestW, int DestH){
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = SrcX;
    SrcR.y = SrcY;
    SrcR.w = SrcW;
    SrcR.h = SrcH;

    DestR.x = DestX;
    DestR.y = DestY;
    DestR.w = DestW;
    DestR.h = DestH;

    SDL_RenderCopy(renderer, image, &SrcR, &DestR);
}

void detruire_accueil(Accueil* a){
	SDL_DestroyTexture(a->fond); a->fond = NULL;
	SDL_DestroyTexture(a->titre); a->titre = NULL;
	SDL_DestroyTexture(a->jouer); a->jouer = NULL;
	SDL_DestroyTexture(a->quitter); a->quitter = NULL;
	free(a);
	a = NULL;
}
