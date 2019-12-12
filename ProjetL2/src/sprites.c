#include "sprites.h"

Sprite** allouer_tab_2D_Sprite(int n, int m){
    Sprite** tab2D = malloc(n*sizeof(Sprite*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(m*sizeof(Sprite));
    }
    return tab2D;
}

Sprite* initialiser_sprite(SDL_Renderer* renderer,const char* nomFichier, int xsprite, int ysprite, int widths, int heights, int v, char type){

    Sprite* s = malloc(sizeof(Sprite));
    s->x = xsprite;
    s->y = ysprite;
    s->width = widths;
    s->height = heights;
    s->frame = 0;
    s->isDead = 0;
    s->asset = charger_image_transparente(nomFichier, renderer,0, 255, 255);
    s->vie = v;
    s->lifebar = initialiser_lifebar(s->vie);
    s->type = type;
    s->PA = 4;
    s->jaugePA = initialiser_PA();
    s->comp = allouer_tab2D_competence();
    return s;
}

void dessiner_sprite(SDL_Renderer* renderer, Sprite* s, int offsetX, int offsetY){
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

    DestR.x = renderX + offsetX ;
    DestR.y = renderY + offsetY ;
    DestR.w = s->width;
    DestR.h = s->height;

    SDL_RenderCopy(renderer, s->asset, &SrcR, &DestR);
}

void moveTo(SDL_Renderer* renderer, Sprite* s, int indexX, int indexY, int offsetX, int offsetY){
    if(indexX >= 0 && indexX <= 9 && indexY >= 0 && indexY <= 9 && s->isDead == 0){
       s->x = indexX;
       s->y = indexY;
       dessiner_sprite(renderer, s, offsetX, offsetY);
    }
}

void DetruireSprites(Sprite* s){
    SDL_DestroyTexture(s->asset); s->asset = NULL;
	free(s->lifebar); s->lifebar = NULL;
	free(s->jaugePA); s->jaugePA = NULL;
	//desallouer_comp(s->comp[0]);
	//desallouer_comp(s->comp[1]);
	free(s); s = NULL;
}

void gestion_competence_deplacement(SDL_Renderer* renderer, Sprite* s, int mouseX, int mouseY, int offsetX, int offsetY, int choix){
    moveTo(renderer, s, mouseX, mouseY,  offsetX, offsetY);
    s->PA -= 2;
    free(s->comp[0]);
    free(s->comp[1]);
    s->comp[0] = ajouter_comp_deplacement(s->x, s->y, renderer, choix);
    s->comp[1] = ajouter_competence_attaque(s->x, s->y, renderer);

}











