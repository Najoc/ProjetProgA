#include "pattern_init.h"

Attaque* tir_soldat_2(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*50);
    for(int i = 0; i < 50; i++){
        tir[i].x = 1 + (2*(i/10)); tir[i].y = i%10; tir[i].degats = 40;
    }
    Attaque* tirSoldat2 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 50 , TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat2;
}

Attaque* tir_soldat_6(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*50);
    for(int i = 0; i < 50; i++){
        tir[i].x = i%10; tir[i].y = (2*(i/10)); tir[i].degats = 40;
    }
    Attaque* tirSoldat6 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 50, TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat6;
}

Attaque* tir_soldat_10(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*100);
    for(int i = 0; i < 10; i++){
        tir[i].x = 1; tir[i].y = i; tir[i].degats = 40;
        tir[i+20].x = 3; tir[i+20].y = i; tir[i+20].degats = 40;
        tir[i+40].x = 5; tir[i+40].y = i; tir[i+40].degats = 40;
        tir[i+60].x = 7; tir[i+60].y = i; tir[i+60].degats = 40;
        tir[i+80].x = 9; tir[i+80].y = i; tir[i+80].degats = 40;
    }
    for(int i = 10; i < 20; i++){
        tir[i].x = i - 10; tir[i].y = 2; tir[i].degats = 40;
        tir[i+20].x = i - 10; tir[i+20].y = 4; tir[i+20].degats = 40;
        tir[i+40].x = i - 10; tir[i+40].y = 6; tir[i+40].degats = 40;
        tir[i+60].x = i - 10; tir[i+60].y = 8; tir[i+60].degats = 40;
        tir[i+80].x = i - 10; tir[i+80].y = 0; tir[i+80].degats = 40;
    }
    Attaque* tirSoldat10 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 100, TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat10;
}

Attaque* proximiteNS(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*56);
    int k = 0;
    for(int i = 0; i < 7; i++){
	for(int j = 0; j < i+1; j++){
	    mine[k].x = 0 + i - j; mine[k].y = 0 + j; mine[k].degats = 40;
	    k++;
	}
    }
    for(int i = 0; i < 7; i++){
	for(int j = 0; j < i+1; j++){
	    mine[k].x = 9 - i + j; mine[k].y = 9 - j; mine[k].degats = 40;
	    k++;
	}
    }
    Attaque* proxN = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 56, TILE_WIDTH, TILE_HEIGHT);
    return proxN;
}

Attaque* proximiteEO(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*56);
    int k = 0;
    for(int i = 0; i<7; i++){
        for(int j = 0; j < i+1; j++){
	    mine[k].x = 9 - i + j; mine[k].y = 0 + j; mine[k].degats = 100 - (40*i);
	    k++;
	}
    }
    for(int i = 0; i<7; i++){
        for(int j = 0; j < i+1; j++){
	    mine[k].x = 0 + j; mine[k].y = 9 - i + j; mine[k].degats = 100 - (40*i);
	    k++;
	}
    }
    Attaque* proxE = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 56, TILE_WIDTH, TILE_HEIGHT);
    return proxE;
}

Attaque* laser(SDL_Renderer* renderer){
    Tile* laser = malloc(sizeof(Tile)*40);
    for(int i = 0; i < 40; i++){
	laser[i].x = 3 + (i/10); laser[i].y = i%10; laser[i].degats = 40;
    }
    Attaque* tirLaser = initialiser_attaque("images/attaqueTest.bmp", renderer, "laser", 'e', 0, laser, 40, TILE_WIDTH, TILE_HEIGHT);
    return tirLaser;
}

Attaque* laser2(SDL_Renderer* renderer){
    Tile* laser = malloc(sizeof(Tile)*40);
    for(int i = 0; i < 40; i++){
	laser[i].x = i%10; laser[i].y = 3 + (i/10); laser[i].degats = 40;
    }
    Attaque* tirLaser = initialiser_attaque("images/attaqueTest.bmp", renderer, "laser", 'e', 0, laser, 40, TILE_WIDTH, TILE_HEIGHT);
    return tirLaser;
}


