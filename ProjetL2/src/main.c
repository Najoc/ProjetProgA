#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.c"
#include <SDL2/SDL_ttf.h>
#include "CONST.h"
#include "grille.c"
#include "conversion.c"
#include "sprites.c"
#include "world.h"


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

  //initialisation du monde
  World* world = malloc(sizeof(world));
  
  //enregistrement contenant la map
  world->grille = initialiser_grille("images/Double.bmp", ecran, "grilles/general.txt", 10, 10) ;
  //tableau de sprites
  world->tabSprites = allouer_tab_2D_Sprite(100,50);
  world->tabSprites[0] = initialiser_sprite(ecran,"images/dummy2.bmp", 0,0,64,128);
  //coordonnées souris
  int mouseX, mouseY;

  

  //boucle principale
  while(!terminer)
    {
      SDL_RenderClear(ecran);
      dessiner_grille(ecran, world->grille);
      SDL_GetMouseState(&mouseX, &mouseY);
      coord_to_iso(&mouseX, &mouseY);
      printf("%d,%d\n", mouseX, mouseY);
      dessiner_sprite(ecran, world->tabSprites[0]);
      SDL_RenderPresent(ecran);
      
      while (SDL_PollEvent(&evenements))
	{
	  switch(evenements.type)
	    {
	    case SDL_QUIT:
	      terminer = true; break;
	    case SDL_MOUSEBUTTONUP:
	      moveTo(ecran, world->tabSprites[0], mouseX, mouseY); break;
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
  free(world->grille);
  // Fermer la police et quitter
  TTF_Quit();
  // Libération de l'écran (renderer)
  SDL_DestroyRenderer(ecran);
  
  //Quitter SDL
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}
