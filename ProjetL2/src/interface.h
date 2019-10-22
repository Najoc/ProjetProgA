#ifndef INTERFACE_H
#define INTERFACE_H

#include "sprites.h"
#include "CONST.h"

extern int* initialiser_lifebar();
extern void dessiner_lifebar(SDL_Renderer* renderer, SDL_Texture* spritesheet, Sprite* s, int x, int y);
extern void dessiner_cadre_perso(SDL_Renderer* renderer, SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, Sprite** tab);

#endif //INTERFACE_H