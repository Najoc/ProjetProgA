#include "accueil.h"


Accueil* init_accueil(SDL_Renderer* renderer) {
    Accueil* a = malloc(sizeof(Accueil));
    a->fond = charger_image("images/accueil.bmp", renderer);
    a->titre = charger_image("images/titre.bmp", renderer);
    a->jouer = charger_image("images/jouer.bmp", renderer);
    a->quitter = charger_image("images/quitter.bmp", renderer);

    return a;
}

void affichage_accueil(SDL_Renderer* renderer, Accueil* a) {
    SDL_RenderCopy(renderer, a->fond, NULL, NULL);
    renderElement(renderer,a->titre, 0, 0, TITLE_WIDTH, TITLE_HEIGHT, 240, 200, TITLE_WIDTH, TITLE_HEIGHT);
    renderElement(renderer,a->jouer, 0, 0, PLAY_WIDTH, PLAY_HEIGHT, 490, 450, PLAY_WIDTH, PLAY_HEIGHT);
    renderElement(renderer,a->quitter, 0, 0, QUIT_WIDTH, QUIT_HEIGHT, 440, 550, QUIT_WIDTH, QUIT_HEIGHT);

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
