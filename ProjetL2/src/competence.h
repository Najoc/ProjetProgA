#ifndef COMPETENCE_H
#define COMPETENCE_H

#include "CONST.h"
#include "grille.h"

typedef struct Competence{

Tile* zonePossible;
char type;
SDL_Texture* texture;

}Competence;

extern Competence* initialiser_competence(Tile* tab, char c, SDL_Renderer* renderer);
extern Competence* ajouter_comp_liz(int SpriteX, int SpriteY, SDL_Renderer* renderer);
extern void dessiner_comp_sur_tile(Competence* c, SDL_Renderer* renderer, int longueurTab);

#endif //COMPETENCE_H
