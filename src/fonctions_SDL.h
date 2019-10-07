#ifndef FONCTIONS_SDL_H_
#define FONCTIONS_SDL_H_


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer);
extern SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);
extern SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color) ;


#endif //FONCTIONS_SDL_H_
