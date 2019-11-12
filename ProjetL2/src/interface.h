#ifndef INTERFACE_H
#define INTERFACE_H

#include "sprites.h"
#include "CONST.h"
#include "collisions.h"

extern int* initialiser_lifebar();
extern int* initialiser_PA();

extern void dessin_interface_niveau(SDL_Renderer* renderer, 
			     SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, SDL_Texture* PA, SDL_Texture* button,
			     int mouseX, int mouseY,
			     Sprite** tab);

extern void dessiner_lifebar(SDL_Renderer* renderer, SDL_Texture* spritesheet, Sprite* s, int x, int y);
extern void dessiner_PA(SDL_Renderer* renderer, SDL_Texture* spritesheet, Sprite* s, int x, int y);
extern void dessiner_cadre_perso(SDL_Renderer* renderer, SDL_Texture* portrait, SDL_Texture* cadre, SDL_Texture* lifebar, SDL_Texture* PA, Sprite** tab, int mouseX, int mouseY);
extern void dessin_cadre(SDL_Renderer* renderer, SDL_Texture* cadre, int mouseX, int mouseY);
extern void dessin_portraits(SDL_Renderer* renderer, SDL_Texture* portrait);
extern void dessin_finTour(SDL_Renderer* renderer, SDL_Texture* button, int mouseX, int mouseY);
extern void dessin_competence_cadre(SDL_Renderer* renderer, SDL_Texture* comp, int mouseX, int mouseY, int compdraw, int noPA);

#endif //INTERFACE_H
