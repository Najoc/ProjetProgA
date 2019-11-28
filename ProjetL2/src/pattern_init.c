#include "pattern_init.h"

Attaque* tir_soldat_2(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*20);
    for(int i = 0; i < 10; i++){
        tir[i].x = 5; tir[i].y = i; tir[i].degats = 10;
    }
    for(int i = 10; i < 20; i++){
        tir[i].x = i - 10; tir[i].y = 6; tir[i].degats = 10;
    }
    Attaque* tirSoldat2 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 20, TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat2;
}

Attaque* tir_soldat_6(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*60);
    for(int i = 0; i < 10; i++){
        tir[i].x = 5; tir[i].y = i; tir[i].degats = 10;
        tir[i+20].x = 1; tir[i+20].y = i; tir[i+20].degats = 10;
        tir[i+40].x = 9; tir[i+40].y = i; tir[i+40].degats = 10;
    }
    for(int i = 10; i < 20; i++){
        tir[i].x = i - 10; tir[i].y = 2; tir[i].degats = 10;
        tir[i+20].x = i - 10; tir[i+20].y = 6; tir[i+20].degats = 10;
        tir[i+40].x = i - 10; tir[i+40].y = 10; tir[i+40].degats = 10;
    }
    Attaque* tirSoldat6 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 60, TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat6;
}

Attaque* tir_soldat_10(SDL_Renderer* renderer){
    Tile* tir = malloc(sizeof(Tile)*100);
    for(int i = 0; i < 10; i++){
        tir[i].x = 1; tir[i].y = i; tir[i].degats = 10;
        tir[i+20].x = 3; tir[i+20].y = i; tir[i+20].degats = 10;
        tir[i+40].x = 5; tir[i+40].y = i; tir[i+40].degats = 10;
        tir[i+60].x = 7; tir[i+60].y = i; tir[i+60].degats = 10;
        tir[i+80].x = 9; tir[i+80].y = i; tir[i+80].degats = 10;
    }
    for(int i = 10; i < 20; i++){
        tir[i].x = i - 10; tir[i].y = 2; tir[i].degats = 10;
        tir[i+20].x = i - 10; tir[i+20].y = 4; tir[i+20].degats = 10;
        tir[i+40].x = i - 10; tir[i+40].y = 6; tir[i+40].degats = 10;
        tir[i+60].x = i - 10; tir[i+60].y = 8; tir[i+60].degats = 10;
        tir[i+80].x = i - 10; tir[i+80].y = 0; tir[i+80].degats = 10;
    }
    Attaque* tirSoldat10 = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir soldat", 'e', 0, tir, 100, TILE_WIDTH, TILE_HEIGHT);
    return tirSoldat10;
}

Attaque* proximiteN(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*15);
    mine[0].x = 0; mine[0].y = 0; mine[0].degats = 100;
    mine[1].x = 1; mine[1].y = 0; mine[1].degats = 80;
    mine[2].x = 0; mine[2].y = 1; mine[2].degats = 80;
    mine[3].x = 2; mine[3].y = 0; mine[3].degats = 60;
    mine[4].x = 1; mine[4].y = 1; mine[4].degats = 60;
    mine[5].x = 0; mine[5].y = 2; mine[5].degats = 60;
    mine[6].x = 3; mine[6].y = 0; mine[6].degats = 40;
    mine[7].x = 2; mine[7].y = 1; mine[7].degats = 40;
    mine[8].x = 1; mine[8].y = 2; mine[8].degats = 40;
    mine[9].x = 0; mine[9].y = 3; mine[9].degats = 40;
    mine[10].x = 4; mine[10].y = 0; mine[10].degats = 20;
    mine[11].x = 3; mine[11].y = 1; mine[11].degats = 20;
    mine[12].x = 2; mine[12].y = 2; mine[12].degats = 20;
    mine[13].x = 1; mine[13].y = 3; mine[13].degats = 20;
    mine[14].x = 0; mine[14].y = 4; mine[14].degats = 20;
    Attaque* proxN = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 15, TILE_WIDTH, TILE_HEIGHT);
    return proxN;
}

Attaque* proximiteS(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*15);
    mine[0].x = 9; mine[0].y = 9; mine[0].degats = 100;
    mine[1].x = 8; mine[1].y = 9; mine[1].degats = 80;
    mine[2].x = 9; mine[2].y = 8; mine[2].degats = 80;
    mine[3].x = 7; mine[3].y = 9; mine[3].degats = 60;
    mine[4].x = 8; mine[4].y = 8; mine[4].degats = 60;
    mine[5].x = 9; mine[5].y = 7; mine[5].degats = 60;
    mine[6].x = 6; mine[6].y = 9; mine[6].degats = 40;
    mine[7].x = 7; mine[7].y = 8; mine[7].degats = 40;
    mine[8].x = 8; mine[8].y = 7; mine[8].degats = 40;
    mine[9].x = 9; mine[9].y = 6; mine[9].degats = 40;
    mine[10].x = 5; mine[10].y = 9; mine[10].degats = 20;
    mine[11].x = 6; mine[11].y = 8; mine[11].degats = 20;
    mine[12].x = 7; mine[12].y = 7; mine[12].degats = 20;
    mine[13].x = 8; mine[13].y = 6; mine[13].degats = 20;
    mine[14].x = 9; mine[14].y = 5; mine[14].degats = 20;
    Attaque* proxS = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 15, TILE_WIDTH, TILE_HEIGHT);
    return proxS;
}

Attaque* proximiteE(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*15);
    int k = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j < i+1; j++){
	    mine[k].x = 9 - i + j; mine[k].y = 0 + j; mine[k].degats = 100 - (20*i);
	    k++;
	}
    }
    Attaque* proxE = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 15, TILE_WIDTH, TILE_HEIGHT);
    return proxE;
}

Attaque* proximiteO(SDL_Renderer* renderer){
    Tile* mine = malloc(sizeof(Tile)*15);
    int k = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j < i+1; j++){
	    mine[k].x = 0 + j; mine[k].y = 9 - i + j; mine[k].degats = 100 - (20*i);
	    k++;
	}
    }
    Attaque* proxO = initialiser_attaque("images/attaqueTest.bmp", renderer, "tir d'obus", 'e', 0, mine, 15, TILE_WIDTH, TILE_HEIGHT);
    return proxO;
}



