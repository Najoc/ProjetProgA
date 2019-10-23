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
#include "interface.h"


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
  world->grille = initialiser_grille("images/caseSheet.bmp", ecran, "grilles/general.txt", 10, 10) ;

  //tableau de sprites
  world->tabSprites = allouer_tab_2D_Sprite(100,50);
  world->tabSprites[0] = initialiser_sprite(ecran,"images/guy.bmp", 0,0,64,128, 100);
  world->tabSprites[1] = initialiser_sprite(ecran,"images/alienor.bmp", 9,9,64,128, 100);
  world->tabSprites[2] = initialiser_sprite(ecran,"images/dietrich.bmp", 9,0,64,128, 100);
  world->tabSprites[3] = initialiser_sprite(ecran,"images/liz.bmp", 5,5,64,128, 100);

  //images chargement:
  SDL_Texture* lifebar = charger_image_transparente("images/interface/life.bmp", ecran, 0, 255, 255);
  SDL_Texture* cadre = charger_image_transparente("images/interface/cadre.bmp", ecran, 0, 255, 255);
  SDL_Texture* portrait = charger_image_transparente("images/portraits.bmp", ecran, 0, 255, 255);

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
            TextJouer(ecran);
            screenskip(world, evenements);
            SDL_RenderPresent(ecran);

            break;
            case 2:
            SDL_RenderClear(ecran);
            dessiner_grille(ecran, world->grille);
            SDL_GetMouseState(&mouseX, &mouseY);
            coord_to_iso(&mouseX, &mouseY);
            printf("%d,%d\n", mouseX, mouseY);

	    for(int i = 0; i<4; i++){
                dessiner_sprite(ecran, world->tabSprites[i]);
	    }

	    dessiner_cadre_perso(ecran, portrait, cadre, lifebar, world->tabSprites);
            SDL_RenderPresent(ecran);
            for(int i=0; i<100; i++){
                DetruireSprites(world->tabSprites[i]);
            }
        }
        while (SDL_PollEvent(&evenements)) {
            switch(evenements.type) {
                case SDL_QUIT:
                terminer = true; break;
                case SDL_MOUSEBUTTONUP:
                moveTo(ecran, world->tabSprites[0], mouseX, mouseY); break;
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                    terminer = true; break;
                    case SDLK_n:
                    world->tabSprites[0]->vie -= 3;
                    world->tabSprites[1]->vie -= 3;
                    world->tabSprites[2]->vie -= 3;
                    world->tabSprites[3]->vie -= 3; break;
                    case SDLK_b:
                    world->tabSprites[0]->vie += 3;
                    world->tabSprites[1]->vie += 3;
                    world->tabSprites[2]->vie += 3;
                    world->tabSprites[3]->vie += 3; break;
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
