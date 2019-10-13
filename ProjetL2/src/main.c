#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.c"
#include <SDL2/SDL_ttf.h>
#include "CONST.h"
#include "grille.c"
#include "collisions.c"


int main(){
  
  SDL_Window* fenetre; //déclaration fenêtre
  SDL_Event evenements; // évènements de la fenpetre
  bool terminer = false;
  if(SDL_INIT_VIDEO<0) //Initialisation de la SDL
    {
      printf("erreur d'initialisation de la fenêtre %s", SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
    }



  //création fenêtre
  fenetre = SDL_CreateWindow("jeu",
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             SCREEN_WIDTH,
                             SCREEN_HEIGHT,
                             SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL)
    {
      printf("erreur création de la fenêtre %s", SDL_GetError());
      SDL_Quit();
      return EXIT_FAILURE;
    }

  //mise en place d'un contexte de rendu pour l'écran
  SDL_Renderer* ecran;
  ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

  
  //enregistrement contenant la map
  Tilemap* grille = initialiser_grille("images/Double.bmp", ecran, "grilles/general.txt", 10, 10) ;

  int mouseX, mouseY;
  SDL_GetGlobalMouseState(&mouseX, &mouseY);

  //transformation des coordonnées cartésiennens en coordonnées grille
  int mouse_grid_x = (mouseY/grille->htile) + (mouseX/grille->ltile);
  int mouse_grid_y = -(mouseX/grille->ltile) + (mouseY/grille->htile);

  //boucle principale
  while(!terminer)
    {
      SDL_RenderClear(ecran);
      dessiner_grille(ecran, grille);
      //collisions_mouse_tilemap(grille);
      
      SDL_GetMouseState(&mouseX, &mouseY);

      mouseX -= -64 + SCREEN_WIDTH/2;
      mouseY -= 160;
      mouse_grid_x = (mouseX/64 + mouseY/32)/2;
      mouse_grid_y = (mouseY/32 - (mouseX/64))/2;
      printf("%d,%d\n%d,%d\n", mouseX, mouseY, mouse_grid_x, mouse_grid_y);
      SDL_RenderPresent(ecran);
      
      while (SDL_PollEvent(&evenements))
	{
	  switch(evenements.type)
	    {
	    case SDL_QUIT:
	      terminer = true; break;
	    case SDL_KEYDOWN:
	      switch(evenements.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		case SDLK_q:
		  terminer = true; break;
		  
		}
	    }
	}
    }
  //libération de la grille
  free(grille);
  // Fermer la police et quitter
  TTF_Quit();
  // Libération de l'écran (renderer)
  SDL_DestroyRenderer(ecran);
  
  //Quitter SDL
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}
