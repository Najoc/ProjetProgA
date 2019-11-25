#ifndef ATTAQUE_H
#define ATTAQUE_H

#include "grille.h"
#include "CONST.h"
#include "sprites.h"


typedef struct attaque{

    SDL_Texture* Frame;
    int largeurImage;
    int hauteurImage;
    Tile* zone;
    char* nom;
    char type;
    int mono;  //monocible = 1, aoe = 0
    int tailletab;
    int currentFrame;
    int draw;
   
}Attaque;

extern Attaque* initialiser_attaque(const char* frame, SDL_Renderer* renderer, char* nom, char type, int mono,Tile* tabTile, int taille, int largeur, int hauteur);
extern void attaquer(Sprite* s, Attaque* attaque, int taille);
extern void dessiner_attaque_sur_tile(Attaque* a, SDL_Renderer* renderer, int largeur, int hauteur, int longueurTab);
extern void dessiner_attaque_sur_sprite(Attaque* a, SDL_Renderer* renderer, Sprite* s, int largeur, int hauteur);
extern void effacer_attaque(Attaque* a);

#endif //ATTAQUE_H
