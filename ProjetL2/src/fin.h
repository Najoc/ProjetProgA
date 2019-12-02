#ifndef FIN_H
#define FIN_H

#include "collisions.h"

typedef struct Ecran_fin{

    SDL_Texture* fond;
    SDL_Texture* quitter;
    SDL_Texture* you_win;
} Ecran_fin;

extern Ecran_fin* initialiser_ecran_fin();
extern void dessiner_ecran_fin(Ecran_fin* ef, SDL_Renderer* renderer, int mouseX, int mouseY, SDL_Event evenement, int* ecran);
extern void dessiner_fond_ecran(SDL_Texture* text, SDL_Renderer* renderer);
extern void dessiner_quitter(SDL_Texture* text, SDL_Renderer* renderer, int mouseX, int mouseY);
extern void dessiner_you_win(SDL_Texture* text, SDL_Renderer* renderer);


#endif
