#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.h"
#include "CONST.h"
#include "grille.h"
#include "world.h"

extern void affichage_accueil (SDL_Renderer* renderer);
extern void TextTitre (SDL_Renderer* renderer);
extern void TextJouer (SDL_Renderer* renderer);
extern void screenskip (World* w, SDL_Event event);

#endif // ACCUEIL_H
