#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "CONST.h"
#include "grille.h"
#include "sprites.h"

typedef struct world{
    Tilemap* grille;
    Sprite** tabSprites;
    int screen;
}World;

#endif
