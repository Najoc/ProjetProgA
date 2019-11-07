#ifndef CONVERSION_H
#define CONVERSION_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include "CONST.h"
#include "grille.h"

extern void coord_to_iso(int* coordX, int* coordY);
extern void iso_to_coord(int* indexX, int* indexY);

#endif //CONVERSION_H
