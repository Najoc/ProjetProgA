#ifndef ENEMY_H
#define ENEMY_H

#include "sprites.h"
#include "attaque.h"

typedef struct enemy{

    Sprite* sp;
    Attaque* atk;
    int tailleAtk;
    int pattern;
    
}Enemy;

extern Enemy* initialiser_enemy(Sprite* sp, Attaque* a, int taille);
extern void jouer_pattern(Enemy* e, SDL_Renderer* renderer, Sprite** tab, int cible);

#endif //ENEMY_H
