#ifndef COMPETENCE_H
#define COMPETENCE_H

#include "CONST.h"
#include "grille.h"

typedef struct Competence{

Tile* zonePossible;
char type;
SDL_Texture* texture;

}Competence;

extern Competence** allouer_tab2D_competence();
extern Competence* initialiser_competence(Tile* tab, char c, SDL_Renderer* renderer);
extern Competence* ajouter_competence_attaque(int spriteX, int spriteY, SDL_Renderer* renderer);
extern Competence* ajouter_comp_deplacement(int SpriteX, int SpriteY, SDL_Renderer* renderer, int choix);
extern void dessiner_comp_sur_tile(Competence* c, SDL_Renderer* renderer, int longueurTab, int mouseX, int mouseY);
extern void desallouer_comp(Competence* c);

#endif //COMPETENCE_H
