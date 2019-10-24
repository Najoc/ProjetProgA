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
    TextTitre(renderer,a->titre);
    TextJouer(renderer,a->jouer);
    TextQuitter(renderer,a->quitter);
}

void TextTitre(SDL_Renderer* renderer, SDL_Texture* titre) {
    //création / affichage bouton titre
    SDL_Rect selec_titre;
    selec_titre.x = 0;
    selec_titre.y = 0;
    selec_titre.h = TITLE_HEIGHT;
    selec_titre.w = TITLE_WIDTH;

    SDL_Rect place_titre;
    place_titre.x = 240;
    place_titre.y = 200;
    place_titre.h = TITLE_HEIGHT;
    place_titre.w = TITLE_WIDTH;

    SDL_RenderCopy(renderer, titre, &selec_titre, &place_titre);
}

void TextJouer(SDL_Renderer* renderer, SDL_Texture* jouer) {
    //création / affichage bouton jouer
    SDL_Rect selec_jouer;
    selec_jouer.x = 0;
    selec_jouer.y = 0;
    selec_jouer.h = PLAY_HEIGHT;
    selec_jouer.w = PLAY_WIDTH;

    SDL_Rect place_jouer;
    place_jouer.x = 490;
    place_jouer.y = 450;
    place_jouer.h = PLAY_HEIGHT;
    place_jouer.w = PLAY_WIDTH;

    SDL_RenderCopy(renderer, jouer, &selec_jouer, &place_jouer);
}

void TextQuitter(SDL_Renderer* renderer, SDL_Texture* quitter) {
    //création / affichage bouton quitter
    SDL_Rect selec_quitter;
    selec_quitter.x = 0;
    selec_quitter.y = 0;
    selec_quitter.h = QUIT_HEIGHT;
    selec_quitter.w = QUIT_WIDTH;

    SDL_Rect place_quitter;
    place_quitter.x = 440;
    place_quitter.y = 550;
    place_quitter.h = QUIT_HEIGHT;
    place_quitter.w = QUIT_WIDTH;

    SDL_RenderCopy(renderer, quitter, &selec_quitter, &place_quitter);
}
