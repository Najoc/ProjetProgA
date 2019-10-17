#ifndef SPRITES_H
#define SPRITES_H

typedef struct{
    SDL_Texture* asset;
    int x,y;
    int width, height;
    int isDead;
    int frame;
}Sprite;

extern Sprite** allouer_tab_2D_Sprite(int n, int m);
extern Sprite* initialiser_sprite(SDL_Renderer* renderer, const char* nomFichier, int xsprite, int ysprite, int widths, int heights);
extern void dessiner_sprite(SDL_Renderer* renderer, Sprite* s);
extern void moveTo(SDL_Renderer* renderer, Sprite* s, int indexX, int indexY);
extern void DetruireSprites(Sprite* s);


#endif //SPRITES_H
