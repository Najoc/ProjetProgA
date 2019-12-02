#ifndef SPRITES_H
#define SPRITES_H

#include "grille.h"
#include "conversion.h"
#include "competence.h"

typedef struct{
    SDL_Texture* asset;
    int x,y;
    int width, height;
    int isDead;
    int frame;
    int vie;
    int* lifebar;
    int PA;
    int* jaugePA;
    char type;
    Competence** comp;
    
}Sprite;

extern Sprite** allouer_tab_2D_Sprite(int n, int m);
extern Sprite* initialiser_sprite(SDL_Renderer* renderer, const char* nomFichier, int xsprite, int ysprite, int widths, int heights, int v, char type);
extern void dessiner_sprite(SDL_Renderer* renderer, Sprite* s, int offsetX, int offsetY);
extern void moveTo(SDL_Renderer* renderer, Sprite* s, int indexX, int indexY, int offsetX, int offsetY);
extern void DetruireSprites(Sprite* s);
extern void gestion_competence_deplacement(SDL_Renderer* renderer, Sprite* s, int mouseX, int mouseY, int offsetX, int offsetY, int choix);

#include "interface.h"

#endif //SPRITES_H
