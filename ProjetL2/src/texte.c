#include "texte.h"

//void test_TTF(SDL_Window* window, SDL_Renderer* renderer, Texte_t* t) {
    /*SDL_Color couleurNoire = {255, 255, 255, 0};
    SDL_Surface *texte = NULL;

    SDL_Rect position;
    position.x = 200;
    position.y = 450;

    //SDL_Surface *pSurf = SDL_GetWindowSurface(renderer);
    //SDL_FillRect(pSurf, NULL, SDL_MapRGB(pSurf->format, 255, 255, 255));

    Chargement de la police
    //police = TTF_OpenFont("texte/arial_narrow_7.ttf", 32);
    //texte = TTF_RenderText_Blended(police, "World Hello", couleurNoire);

    const char* texte = "World Hello";

    SDL_Texture *image = charger_texte(texte,renderer,t->police,couleurNoire);

    SDL_Rect SrcR;
    SrcR.x = 150;
    SrcR.y = 400;
    SrcR.h = 150;
    SrcR.w = 400;

    SDL_Rect DestR;
    DestR.x = 100;
    DestR.y = 100;
    DestR.h = 150;
    DestR.w = 400;


    //SDL_BlitSurface(texte, NULL, pSurf, &position);  Blit du texte
    SDL_UpdateWindowSurface(window);
    charger_texte(texte,renderer,t->police,couleurNoire);
    SDL_RenderCopy(renderer, image, &SrcR, &DestR); */

//}

void aff_TTF(SDL_Renderer* renderer) {

    TTF_Font *police = TTF_OpenFont("texte/arial_narrow_7.ttf", 32);
    SDL_Color color = {255,255,255,0};

    SDL_Surface *text_surface = NULL;
    text_surface = TTF_RenderText_Solid(police,"Hello World!",color);

    SDL_Texture *hey = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_Rect hey_position = {0,0,100,50};
    SDL_RenderCopy(renderer, hey, NULL, &hey_position);

    SDL_FreeSurface(text_surface);

    TTF_CloseFont(police);
}
