#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "CONST.h"
#include "grille.h"
#include "sprites.h"
#include "accueil.h"
#include "enemy.h"
#include "fin.h"

typedef struct world{
    Tilemap* grille;
    Sprite** tabSprites;
    Enemy* tabEnemy;
    Accueil* accueil;
    Ecran_fin* fin;
}World;

#endif
