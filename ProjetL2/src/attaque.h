#ifndef ATTAQUE_H
#define ATTAQUE_H

#include "grille.h"
#include "CONST.h"
#include "sprites.h"


typedef struct attaque{

    SDL_Texture* Frame;
    Tile* zone;
    char* nom;
    int degats;
    char type;
    int currentFrame;
    int draw;
   
}Attaque;

extern Attaque* initialiser_attaque(const char* frame, SDL_Renderer* renderer, int degat, char* nom, char type, Tile* tabTile);
extern void attaquer(Sprite* s, Attaque* attaque, Tilemap* t);
extern void dessiner_attaque_sur_tile(Attaque* a, SDL_Renderer* renderer, int largeur, int hauteur, int longueurTab);
extern void effacer_attaque(Attaque* a);

#endif //ATTAQUE_H
