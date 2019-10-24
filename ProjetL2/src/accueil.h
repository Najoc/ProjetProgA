#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.h"
#include "CONST.h"


typedef struct{
    SDL_Texture* fond;
    SDL_Texture* titre;
    SDL_Texture* jouer;
    SDL_Texture* quitter;

} Accueil;


extern Accueil* init_accueil(SDL_Renderer* renderer);

extern void affichage_accueil (SDL_Renderer* renderer, Accueil* a);
extern void TextTitre (SDL_Renderer* renderer, SDL_Texture* titre);
extern void TextJouer (SDL_Renderer* renderer, SDL_Texture* jouer);
extern void TextQuitter(SDL_Renderer* renderer, SDL_Texture* quitter);

#endif // ACCUEIL_H
