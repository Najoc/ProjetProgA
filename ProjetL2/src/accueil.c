#include "accueil.h"


void affichage_accueil(SDL_Renderer* renderer) {
    SDL_Texture* fond = charger_image("images/accueil.bmp", renderer);
    SDL_RenderCopy(renderer, fond, NULL, NULL);

}

void TextTitre(SDL_Renderer* renderer) {
    SDL_Texture* titre = charger_image("images/titre.bmp", renderer);

    SDL_Rect selec_titre;
    selec_titre.x = 0;
    selec_titre.y = 0;
    selec_titre.h = 300;
    selec_titre.w = 800;

    SDL_Rect place_titre;
    place_titre.x = 200;
    place_titre.y = 200;
    place_titre.h = 300;
    place_titre.w = 800;

    SDL_RenderCopy(renderer, titre, &selec_titre, &place_titre);
}

void screenskip(World* w, SDL_Event event) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX > 200 && mouseY > 200 && mouseX < 200+TITLE_WIDTH && mouseY < 200+TITLE_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP) {
        w->screen = 2;
        }
    }
}


