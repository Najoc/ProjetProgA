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
#include "competence.h"
#include "enemy.h"
#include "pattern_init.h"
#include "tour.h"
#include "fin.h"

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
  ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  //initialisation du monde
  World* world = malloc(sizeof(world));

  //enregistrement contenant la map
  world->grille = initialiser_grille("images/terre.bmp", ecran, "grilles/general.txt", 10, 10) ;
  
  //tableau de sprites
  world->tabSprites = allouer_tab_2D_Sprite(16,1);
  world->tabSprites[0] = initialiser_sprite(ecran,"images/Cadell.bmp", 4,0,32,64, 100, 'j');
  world->tabSprites[1] = initialiser_sprite(ecran,"images/alienor.bmp", 8,9,32,64, 100, 'j');
  world->tabSprites[2] = initialiser_sprite(ecran,"images/dietrich.bmp", 7,0,32,64, 100, 'j');
  world->tabSprites[3] = initialiser_sprite(ecran,"images/liz.bmp", 5,6,32,64, 100, 'j');
  world->tabSprites[4] = initialiser_sprite(ecran, "images/soldat.bmp", -1, 0, 32, 64, 100, 'e');
  world->tabSprites[5] = initialiser_sprite(ecran, "images/soldat.bmp", -1, 2, 32, 64, 100, 'e');
  world->tabSprites[6] = initialiser_sprite(ecran, "images/soldat.bmp", -1, 4, 32, 64, 100, 'e');
  world->tabSprites[7] = initialiser_sprite(ecran, "images/soldat.bmp", -1, 6, 32, 64, 100, 'e');
  world->tabSprites[8] = initialiser_sprite(ecran, "images/soldat.bmp", -1, 8, 32, 64, 100, 'e');
  world->tabSprites[9] = initialiser_sprite(ecran, "images/soldat.bmp", 1, -1, 32, 64, 100, 'e');
  world->tabSprites[10] = initialiser_sprite(ecran, "images/soldat.bmp", 3,-1, 32, 64, 100, 'e');
  world->tabSprites[11] = initialiser_sprite(ecran, "images/soldat.bmp", 5, -1, 32, 64, 100, 'e');
  world->tabSprites[12] = initialiser_sprite(ecran, "images/soldat.bmp", 7, -1, 32, 64, 100, 'e');
  world->tabSprites[13] = initialiser_sprite(ecran, "images/soldat.bmp", 9, -1, 32, 64, 100, 'e');
  world->tabSprites[14] = initialiser_sprite(ecran, "images/commando.bmp", 5, -3, 32, 64, 100, 'e');
  world->tabSprites[15] = initialiser_sprite(ecran, "images/general.bmp", 5, 2, 96, 192, 1000, 'e');

  //ennemi
  Enemy* boss = initialiser_enemy(world->tabSprites[15], 10);
  Attaque* tir_soldat2 = tir_soldat_2(ecran);
  Attaque* tir_soldat6 = tir_soldat_6(ecran);
  Attaque* tir_soldat10 = tir_soldat_10(ecran);
  Attaque* mineN = proximiteN(ecran);
  Attaque* mineS = proximiteS(ecran);
  Attaque* mineE = proximiteE(ecran);
  Attaque* mineO = proximiteO(ecran);

  ajouter_pattern(boss, tir_soldat2, 0);
  ajouter_pattern(boss, tir_soldat6, 1);
  ajouter_pattern(boss, tir_soldat10, 2);
  ajouter_pattern(boss, mineN, 3);
  ajouter_pattern(boss, mineS, 4);
  ajouter_pattern(boss, mineE, 5);
  ajouter_pattern(boss, mineO, 6);

  //competences
  world->tabSprites[0]->comp[0] = ajouter_comp_deplacement(world->tabSprites[0]->x, world->tabSprites[0]->y, ecran, 0);
  world->tabSprites[1]->comp[0] = ajouter_comp_deplacement(world->tabSprites[1]->x, world->tabSprites[1]->y, ecran, 1);
  world->tabSprites[2]->comp[0] = ajouter_comp_deplacement(world->tabSprites[2]->x, world->tabSprites[2]->y, ecran, 2);
  world->tabSprites[3]->comp[0] = ajouter_comp_deplacement(world->tabSprites[3]->x, world->tabSprites[3]->y, ecran, 3);
  for(int i = 0; i < 4; i++){
    world->tabSprites[i]->comp[1] = ajouter_competence_attaque(world->tabSprites[i]->x, world->tabSprites[i]->y, ecran);
  }

  //images chargement:
  SDL_Texture* lifebar = charger_image_transparente("images/interface/life.bmp", ecran, 0, 255, 255);
  SDL_Texture* cadre = charger_image_transparente("images/interface/cadre.bmp", ecran, 0, 255, 255);
  SDL_Texture* portrait = charger_image_transparente("images/interface/portraits.bmp", ecran, 0, 255, 255);
  SDL_Texture* PA = charger_image_transparente("images/interface/PA.bmp", ecran, 0, 255, 255);
  SDL_Texture* bouton = charger_image_transparente("images/interface/finTour.bmp", ecran, 0, 255, 255);
  SDL_Texture* comp = charger_image_transparente("images/interface/competence.bmp", ecran, 0, 255, 255);

  //coordonnées souris
  int mouseX, mouseY;

  //initialisation de l'entier déterminant l'écran à afficher
  int screen = 1;

  //initialisation accueil
  world->accueil = init_accueil(ecran);

  SDL_Texture* brillant = charger_image_transparente("images/surbrillance.bmp", ecran, 0, 255,255);
  
  //ecran fin
  world->fin = initialiser_ecran_fin(ecran);

  int compdraw = -1;
  int noPA = 0;
  int draw_surb=0;
  int perso = -1;
  int draw = 0; //draw attaque
  int tour = 1; //à qui le tour? 1 = joueur, -1 = ennemi
  int nbrframe = 0; //nbr frame attaque
  int nouveauTour = 0; //le tour vient-il juste de changer?
  //boucle principale
  while(!terminer) {
	SDL_GetMouseState(&mouseX, &mouseY);
	int mousecoordX = mouseX;
	int mousecoordY = mouseY;
        coord_to_iso(&mouseX, &mouseY);
        switch (screen) {
            case 1:
            SDL_RenderClear(ecran);
            affichage_accueil(ecran, world->accueil);
            screen = screenskip( evenements);
            SDL_RenderPresent(ecran);
            break;

            case 2:
            SDL_RenderClear(ecran);
            dessiner_grille(ecran, world->grille);
	    dessiner_surbrillance(ecran, brillant, mouseX, mouseY);
	    if(draw_surb == 1){
		if(perso == 1){
	            dessiner_comp_sur_tile(world->tabSprites[perso]->comp[0], ecran, 4, mouseX, mouseY);
		}else{
		     dessiner_comp_sur_tile(world->tabSprites[perso]->comp[0], ecran, 8, mouseX, mouseY);
		}
	    }
	    if(draw_surb == 2)
		dessiner_comp_sur_tile(world->tabSprites[perso]->comp[1], ecran, 25, mouseX, mouseY);
	    if(draw){
		if(nbrframe == 120){
			draw = 0;
			nbrframe = 0;
			tour = 1;
			nouveauTour = 1;
		}else{
		dessiner_attaque_sur_tile(boss->atk[boss->pattern - 1], ecran, boss->atk[boss->pattern - 1]->tailletab);
		nbrframe++;
		}
	    }
            printf("%d,%d\n", mouseX, mouseY);


            for(int i = 0; i<15; i++){
                dessiner_sprite(ecran, world->tabSprites[i], -TILE_WIDTH/8, -TILE_HEIGHT/2);
            }
	    dessiner_sprite(ecran, world->tabSprites[15], -(world->tabSprites[15]->width/2), -(world->tabSprites[15]->height/2 + TILE_HEIGHT));

	    dessin_competence_cadre(ecran, comp, mousecoordX, mousecoordY, compdraw, noPA);

            dessin_interface_niveau(ecran, portrait, cadre, lifebar,PA, bouton, mousecoordX, mousecoordY, tour, world->tabSprites);
	    //gestion tour
	    if(tour == -1 && draw == 0){
	    	tour_ennemi(boss, world->tabSprites);
		draw = 1;
	    }
	    if(nouveauTour){
		for(int i = 0; i < 4; i++){
		    if((world->tabSprites[i]->PA + 4) <= 6)
			world->tabSprites[i]->PA += 4;
		    else
			world->tabSprites[i]->PA = 6;
		}
		nouveauTour = 0;
		}
            SDL_RenderPresent(ecran);

	    //fin jeu
	    if(boss->sp->vie == 0)
		screen = 4;
	    break;

            case 3:
                terminer = true; break;

	    case 4:
		SDL_RenderClear(ecran);
		dessiner_ecran_fin(world->fin, ecran, mousecoordX, mousecoordY, evenements, &screen);
	        SDL_RenderPresent(ecran);
		break;
        }
        while (SDL_PollEvent(&evenements)) {
            switch(evenements.type) {
                case SDL_QUIT:
                terminer = true; break;
                case SDL_MOUSEBUTTONUP:
		    if(tour == 1){
			    if(compdraw >= 0){
				perso = compdraw;
				if((noPA != 1) && collisions_cadre_competence(mousecoordX, mousecoordY))
				    draw_surb = 1;
				if((noPA != 1) && collisions_cadre_competence_attaque(mousecoordX, mousecoordY))
				    draw_surb = 2;
			    }
			    if(draw_surb == 1 && collisions_competence(mouseX, mouseY, world->tabSprites[perso], 8, 0)){ //bug Liz
				gestion_competence_deplacement(ecran, world->tabSprites[perso], mouseX,mouseY,-TILE_WIDTH/8,-TILE_HEIGHT/2, perso);
				draw_surb = 0;
			    }
			    if(draw_surb == 2 && collisions_competence(mouseX, mouseY, world->tabSprites[perso], 24, 1)){
				gestion_competence_attaque(world->tabSprites[perso], boss, mouseX,mouseY);
				draw_surb = 0;
			    }
			    compdraw = collisions_cadre_perso(mousecoordX,mousecoordY);
			    if(compdraw >= 0){
				if(world->tabSprites[compdraw]->PA < 2){
				    noPA = 1;
				}else{
				    noPA = 0;
				}
			    }
			    //tour terminé?
		    	    tour = fin_tour(mousecoordX, mousecoordY);
		    }
		    break;
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                    terminer = true; break;
                    case SDLK_n:
			world->tabSprites[15]->vie -= 50;
			break;
                    case SDLK_b:
			break;
                }
            }
        }
    }

  //libération
  liberer_monde(world, 16);
  SDL_DestroyTexture(brillant);
  SDL_DestroyTexture(lifebar);
  SDL_DestroyTexture(cadre);
  SDL_DestroyTexture(portrait);
  SDL_DestroyTexture(PA);
  SDL_DestroyTexture(bouton);
  SDL_DestroyTexture(comp);
  effacer_enemy(boss);
  
  // Fermer la police et quitter
  TTF_Quit();
  // Libération de l'écran (renderer)
  SDL_DestroyRenderer(ecran);

  //Quitter SDL
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return 0;
}
