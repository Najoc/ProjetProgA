#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.h"
#include "CONST.h"
#include "collisions.h"

typedef struct{
    SDL_Texture* fond;
    SDL_Texture* titre;
    SDL_Texture* jouer;
    SDL_Texture* quitter;

} Accueil;


extern Accueil* init_accueil(SDL_Renderer* renderer);

extern void affichage_accueil (SDL_Renderer* renderer, Accueil* a, int mouseX, int mouseY);
extern void renderElement(SDL_Renderer* renderer, SDL_Texture* image, int SrcX, int SrcY, int SrcW, int SrcH, int DestX, int DestY, int DestW, int destH);
extern void detruire_accueil(Accueil* a);

#endif // ACCUEIL_H
