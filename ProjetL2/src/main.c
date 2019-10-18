#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "fonctions_SDL.h"
#include <SDL2/SDL_ttf.h>
#include "CONST.h"
#include "grille.h"
#include "conversion.h"
#include "sprites.h"
#include "world.h"
#include "accueil.h"


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

  //initialisation de l'entier déterminant l'écran à afficher
  world->screen = 1;

  //boucle principale
  while(!terminer) {
        switch (world->screen) {
            case 1:
            SDL_RenderClear(ecran);
            affichage_accueil(ecran);
            TextTitre(ecran);
            screenskip(world, evenements);
            SDL_RenderPresent(ecran);

            break;
            case 2:
            SDL_RenderClear(ecran);
            dessiner_grille(ecran, world->grille);
            SDL_GetMouseState(&mouseX, &mouseY);
            coord_to_iso(&mouseX, &mouseY);
            printf("%d,%d\n", mouseX, mouseY);
            dessiner_sprite(ecran, world->tabSprites[0]);
            SDL_RenderPresent(ecran);
            for(int i=0; i<100; i++){
                DetruireSprites(world->tabSprites[i]);
            }
        }
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
		case SDLK_n:
	          world->tabSprites[0]->isDead = 1; break;


		}
	    }
	}
    }



  //libération de la grille
  free(world);
  world = NULL;
  // Fermer la police et quitter
  TTF_Quit();
  // Libération de l'écran (renderer)
  SDL_DestroyRenderer(ecran);

  //Quitter SDL
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}
