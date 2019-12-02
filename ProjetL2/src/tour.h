#ifndef TOUR_H
#define TOUR_H

#include "collisions.h"
#include "CONST.h"
#include "enemy.h"
#include "sprites.h"

extern int fin_tour(int mousecoordX, int mousecoordY);
extern void tour_ennemi(Enemy* e, Sprite** tab);

#endif //TOUR_H 
