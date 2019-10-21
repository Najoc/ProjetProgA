#include "sprites.h"

Sprite** allouer_tab_2D_Sprite(int n, int m){
    Sprite** tab2D = malloc(n*sizeof(Sprite*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(m*sizeof(Sprite));
    }
    return tab2D;
}

Sprite* initialiser_sprite(SDL_Renderer* renderer,const char* nomFichier, int xsprite, int ysprite, int widths, int heights, int v){
    Sprite* s = malloc(sizeof(Sprite));
    s->x = xsprite;
    s->y = ysprite;
    s->width = widths;
    s->height = heights;
    s->frame = 0;
    s->isDead = 0;
    s->asset = charger_image_transparente(nomFichier, renderer,0, 255, 255);
    s->vie = v;
    s->lifebar = initialiser_lifebar();

    return s;
}

void dessiner_sprite(SDL_Renderer* renderer, Sprite* s){
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.x = s->frame * s->width;
    SrcR.y = 0;
    SrcR.w = s->width;
    SrcR.h = s->height;

    int renderX, renderY;
    renderX = s->x;
    renderY = s->y;
    iso_to_coord(&renderX, &renderY);

    DestR.x = renderX - TILE_WIDTH/8 ;
    DestR.y = renderY - TILE_HEIGHT/2;
    DestR.w = s->width/2;
    DestR.h = s->height/2;

    SDL_RenderCopy(renderer, s->asset, &SrcR, &DestR);
}

void moveTo(SDL_Renderer* renderer, Sprite* s, int indexX, int indexY){
    if(indexX >= 0 && indexX <= 9 && indexY >= 0 && indexY <= 9 && s->isDead == 0){
       s->x = indexX;
       s->y = indexY;
       dessiner_sprite(renderer, s);
    }
}

void DetruireSprites(Sprite* s){

    if(s->isDead == 1){
	SDL_DestroyTexture(s->asset);
    }
}
