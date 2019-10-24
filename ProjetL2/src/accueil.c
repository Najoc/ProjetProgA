#include "accueil.h"


void affichage_accueil(SDL_Renderer* renderer) {
    SDL_Texture* fond = charger_image("images/accueil.bmp", renderer);
    SDL_RenderCopy(renderer, fond, NULL, NULL);

}

void TextTitre(SDL_Renderer* renderer) {
    //création / affichage bouton titre
    SDL_Texture* titre = charger_image("images/titre.bmp", renderer);

    SDL_Rect selec_titre;
    selec_titre.x = 0;
    selec_titre.y = 0;
    selec_titre.h = TITLE_HEIGHT;
    selec_titre.w = TITLE_WIDTH;

    SDL_Rect place_titre;
    place_titre.x = 200;
    place_titre.y = 200;
    place_titre.h = TITLE_HEIGHT;
    place_titre.w = TITLE_WIDTH;

    SDL_RenderCopy(renderer, titre, &selec_titre, &place_titre);
}

void TextJouer(SDL_Renderer* renderer) {
    //création / affichage bouton jouer
    SDL_Texture* jouer = charger_image("jouer.png", renderer);

    SDL_Rect selec_jouer;
    selec_jouer.x = 0;
    selec_jouer.y = 0;
    selec_jouer.h = 160;
    selec_jouer.w = 600;

    SDL_Rect place_jouer;
    place_jouer.x = 300;
    place_jouer.y = 400;
    place_jouer.h = 160;
    place_jouer.w = 600;

    SDL_RenderCopy(renderer, jouer, &selec_jouer, &place_jouer);
}

void screenskip(World* w, SDL_Event event) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //condition chaangement écran
    if (mouseX > 200 && mouseY > 200 && mouseX < 200+TITLE_WIDTH && mouseY < 200+TITLE_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP) {
        w->screen = 2;
        }
    }
}

