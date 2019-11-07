#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "fonctions_SDL.h"
#include <SDL2/SDL_ttf.h>
#include "CONST.h"
#include "grille.h"
#include "conversion.h"
#include "sprites.h"
#include "world.h"
#include "interface.h"
#include "attaque.h"

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
  world->grille = initialiser_grille("images/terre.bmp", ecran, "grilles/general.txt", 10, 10) ;

  //tableau de sprites
  world->tabSprites = allouer_tab_2D_Sprite(100,50);
  world->tabSprites[0] = initialiser_sprite(ecran,"images/Cadell.bmp", 4,0,32,64, 100, 'j');
  world->tabSprites[1] = initialiser_sprite(ecran,"images/alienor.bmp", 9,9,32,64, 100, 'j');
  world->tabSprites[2] = initialiser_sprite(ecran,"images/dietrich.bmp", 9,0,32,64, 100, 'j');
  world->tabSprites[3] = initialiser_sprite(ecran,"images/liz.bmp", 5,5,32,64, 100, 'j');
  world->tabSprites[4] = initialiser_sprite(ecran, "images/general.bmp", 5, 2, 96, 192, 100, 'e');

  //images chargement:
  SDL_Texture* lifebar = charger_image_transparente("images/interface/life.bmp", ecran, 0, 255, 255);
  SDL_Texture* cadre = charger_image_transparente("images/interface/cadre.bmp", ecran, 0, 255, 255);
  SDL_Texture* portrait = charger_image_transparente("images/interface/portraits.bmp", ecran, 0, 255, 255);
  SDL_Texture* PA = charger_image_transparente("images/interface/PA.bmp", ecran, 0, 255, 255);

  //coordonnées souris
  int mouseX, mouseY;

  //initialisation de l'entier déterminant l'écran à afficher
  world->screen = 1;

    //initialisation accueil
  world->accueil = init_accueil(ecran);

  //test attaque
  Tile* tt = malloc(sizeof(Tile) * 4);
  tt[0].x = 9;
  tt[0].y = 0;
  tt[1].x = 5;
  tt[1].y = 5;
  tt[2].x = 4;
  tt[2].y = 2;
  tt[3].x = 3;
  tt[3].y = 7;
  Attaque* a = initialiser_attaque("images/attaqueTest.bmp", ecran,55, "test", 'e', tt);


  SDL_Texture* brillant = charger_image_transparente("images/surbrillance.bmp", ecran, 0, 255,255);

  float delay = 0;
  //boucle principale
  while(!terminer) {
        switch (world->screen) {
            case 1:
            SDL_RenderClear(ecran);
            affichage_accueil(ecran, world->accueil);
            screenskip(world, evenements);
            SDL_RenderPresent(ecran);
            break;

            case 2:
            SDL_RenderClear(ecran);
            dessiner_grille(ecran, world->grille);
            SDL_GetMouseState(&mouseX, &mouseY);
            coord_to_iso(&mouseX, &mouseY);
	    dessiner_surbrillance(ecran, brillant, mouseX, mouseY);
            printf("%d,%d\n", mouseX, mouseY);
            if(a->draw == 1) {
                if(a->currentFrame > 2) {
                    delay = 0;
                    a->draw = 0;
                    a->currentFrame = 0;
                } else {
                    dessiner_attaque_sur_tile(a, ecran, 64, 32, 4);
                    delay += 0.2;
                    a->currentFrame = floor(delay);
                }
            }
            for(int i = 0; i<4; i++){
                dessiner_sprite(ecran, world->tabSprites[i], -TILE_WIDTH/8, -TILE_HEIGHT/2);
            }
	    dessiner_sprite(ecran, world->tabSprites[4], -(world->tabSprites[4]->width/2), -(world->tabSprites[4]->height/2 + TILE_HEIGHT));

            dessiner_cadre_perso(ecran, portrait, cadre, lifebar,PA, world->tabSprites);
            SDL_RenderPresent(ecran);
            for(int i=0; i<100; i++){
                DetruireSprites(world->tabSprites[i]);
            } break;

            case 3:
                terminer = true; break;
        }
        while (SDL_PollEvent(&evenements)) {
            switch(evenements.type) {
                case SDL_QUIT:
                terminer = true; break;
                case SDL_MOUSEBUTTONUP:
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                    terminer = true; break;
                    case SDLK_n:
			for(int i = 0; i<4; i++){
			    attaquer(world->tabSprites[i], a, world->grille);
			}
			break;
                    case SDLK_b:
			world->tabSprites[0]->PA += 1; 
			world->tabSprites[1]->PA += 2; 
			world->tabSprites[2]->PA -= 1; 
			world->tabSprites[3]->PA -= 4; 
			break;
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
