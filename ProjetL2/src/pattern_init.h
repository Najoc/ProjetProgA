#ifndef PATTERN_INIT_H
#define PATTERN_INIT_H

#include "attaque.h"
#include "enemy.h"

extern Attaque* tir_soldat_2(SDL_Renderer* renderer);
extern Attaque* tir_soldat_6(SDL_Renderer* renderer);
extern Attaque* tir_soldat_10(SDL_Renderer* renderer);
extern Attaque* proximiteNS(SDL_Renderer* renderer);
extern Attaque* proximiteEO(SDL_Renderer* renderer);
extern Attaque* laser(SDL_Renderer* renderer);
extern Attaque* laser2(SDL_Renderer* renderer);

#endif //PATTERN_INIT_H
