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

typedef struct world{
    Tilemap* grille;
    Sprite** tabSprites;
    Enemy* tabEnemy;
    Accueil* accueil;

}World;

int screenskip(SDL_Event event) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //condition chaangement écran
    if (mouseX > 490 && mouseX < 490+PLAY_WIDTH && mouseY > 450 && mouseY < 450+PLAY_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP)
        return 2;
    }
    if (mouseX > 440 && mouseX < 440+QUIT_WIDTH && mouseY > 550 && mouseY < 550+QUIT_HEIGHT) {
        if (event.type == SDL_MOUSEBUTTONUP)
        return 3;
    }
    return 1;
}

#endif
