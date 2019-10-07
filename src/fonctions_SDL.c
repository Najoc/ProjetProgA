#include "fonctions_SDL.h"

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer)
{
  SDL_Surface* surf = SDL_LoadBMP(nomfichier);
  return SDL_CreateTextureFromSurface(renderer, surf);
}

SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
  SDL_Surface* surf = SDL_LoadBMP(nomfichier);
  SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, r, g, b));
  return SDL_CreateTextureFromSurface(renderer, surf);
}

SDL_Texture* charger_texte(const char* message, SDL_Renderer* renderer,TTF_Font *font, SDL_Color color){
  SDL_Surface* surf = TTF_RenderText_Solid(font, message, color); 
  return SDL_CreateTextureFromSurface(renderer, surf);

}
