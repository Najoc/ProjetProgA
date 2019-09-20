/**
 * \file main.c
 * \brief Programme principal du niveau 0, à compléter
 * \author Mathieu Constant
 * \version 0.1
 * \date 13 mars 2019
 */

#include "sdl-light.h"

int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 600;

/**
 * \brief Représentation du monde du jeu
 */

struct world_s{
    SDL_Surface* background;
    int gameover;

    
    };

typedef struct world_s world_t;



/**
 * \brief La fonction initialise les données du monde du jeu
 * \param world les données du monde
 */


void init_data(world_t * world){
    world->background = load_image( "ressources/background.bmp" );
    world->gameover = 0;
    
}


/**
 * \brief La fonction nettoie les données du monde
 * \param world les données du monde
 */


void clean_data(world_t *world){
    SDL_FreeSurface(world->background);
    
    
}




/**
 * \brief La fonction indique si le jeu est fini en fonction des données du monde
 * \param world les données du monde
 * \return 1 si le jeu est fini, 0 sinon
 */

int is_game_over(world_t *world){
    return world->gameover;
}


/**
 * \brief La fonction met à jour les données en tenant compte de la physique du monde
 * \param les données du monde
 */

void update_data(world_t *world){
}


/**
 * \brief La fonction initialise les transparences des différentes surfaces
 * \param screen la surface correspondant à l'écran de jeu
 * \param world les données du monde
 */

void  init_graphics(SDL_Surface *screen, world_t *world){
    
}


/**
 * \brief La fonction applique la surface de l'image de fond à quatre positions différentes sur l'écran de jeu, de sorte de complètement couvrir ce dernier
 * \param screen l'écran de jeu
 * \param bg la surface de l'image de fond
 */
void apply_background(SDL_Surface *bg, SDL_Surface *screen){
    apply_surface(bg,screen,0,0);
    apply_surface(bg, screen,SCREEN_WIDTH/2, 0);
    apply_surface(bg, screen, 0, SCREEN_HEIGHT/2 );
    apply_surface(bg, screen, SCREEN_WIDTH/2, SCREEN_HEIGHT/2 );
}





/**
 * \brief La fonction rafrachit l'écran en fonction de l'état des données du monde
 * \param screen la surface de l'écran de jeu
 * \param world les données du monde
 */

void refresh_graphics(SDL_Surface *screen, world_t *world){
    apply_background(world->background,screen);
    
    
    
    
    refresh_surface(screen);
}



/**
 * \brief La fonction gère les évènements ayant eu lieu et qui n'ont pas encore été traités
 * \param event paramètre qui contient les événements
 * \param world les données du monde
 */


void handle_events(SDL_Event *event,world_t *world){
    Uint8 *keystates;
    while( SDL_PollEvent( event ) ) {
        //Si l'utilisateur a cliqué sur le X de la fenêtre
        if( event->type == SDL_QUIT ) {
            //On quitte le programme
            world->gameover = 1;
        }
        
        /* gestion des evenements clavier */
        keystates = SDL_GetKeyState( NULL );
        /* Si l'utilisateur appuie sur
         la touche h (constante SDLK_h) */
        if( keystates[ SDLK_h ] ) {
            printf("J'ai appuye sur la touche h!\n");
        }
        
        
        
    }
    
}

/**
 *  \brief programme principal qui implémente la boucle du jeu
 */


int main( int argc, char* args[] )
{
    SDL_Event event;
    world_t world;
    SDL_Surface *screen;

    screen = init_sdl(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    init_data(&world);
    init_graphics(screen,&world);
    
    
    while(!is_game_over(&world)){
        handle_events(&event,&world);
        update_data(&world);
        refresh_graphics(screen,&world);
        SDL_Delay(10);
    }
    
    clean_data(&world);
    quit_sdl();
    
    
    return 0;
}
