#ifndef ENEMY_H
#define ENEMY_H

#include "sprites.h"
#include "attaque.h"

typedef struct enemy{

    Sprite* sp;
    Attaque** atk;
    int nbrPattern;
    int pattern;
    
}Enemy;

extern Attaque** allouer_tab_2D_atk(int n);
extern Enemy* initialiser_enemy(Sprite* sp, int nombre_pattern);
extern void ajouter_pattern(Enemy* e, Attaque* a, int index);
extern void jouer_pattern(Enemy* e, Sprite** tab, int cible);

#endif //ENEMY_H
