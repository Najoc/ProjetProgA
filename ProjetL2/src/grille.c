#include "grille.h"

char** allouer_tab_2D(int n, int m){
    char** tab2D = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(m*sizeof(char));
    }
    return tab2D;
}

Tile** allouer_tab_2D_tile(int n, int m){
    Tile** tab2D = malloc(n*sizeof(Tile*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(m*sizeof(Tile));
    }
    return tab2D;
}

void desallouer_tab_2D(char** tab, int n){
    int i;
    for(i=0;i<n;i++){
	free(tab[i]);
    }
    free(tab);
    tab = NULL;
}

void afficher_tab_2D(char** tab, int n, int m){
    int i, j;
    for(i=0; i<n; i++){
	printf("ligne %d:", i);
	for(j=0; j<m; j++){
	   printf("%c", tab[i][j]);
	}
    }
}

void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol){
    FILE* file = fopen(nomFichier,  "r");
    int c;
    int temp = 0;
    if( file != NULL)
    {
	while((c = fgetc(file)) != EOF)
	{
	temp++;
	     if(c == '\n')
	     {
	     *nbLig = *nbLig + 1;
	     	if(temp > *nbCol)
		{
		    *nbCol = temp - 1;
		}
	     temp = 0;
	     }
	}
    }
    fclose(file);
}

char** lire_fichier(const char* nomFichier){
    int lig = 0;
    int col = 0;
    taille_fichier(nomFichier, &lig, &col);
    char** tab2D = allouer_tab_2D(lig,col);

    FILE* file = fopen(nomFichier, "r");
    char c;
    int i = 0;
    int j = 0;
    if(file != NULL)
    {
	 while((c = fgetc(file)) != EOF)
	 {
	     if(c == '\n')
	     {
	      	i++;
	      	j = 0;
	     }else{
	 	tab2D[i][j] = c;
	 	j++;
	     }
	 }
    }
    fclose(file);
    return tab2D;
}

Tilemap* initialiser_grille(const char* nomTileset ,SDL_Renderer* renderer, const char* nomFichier, int l,int h){
	Tilemap* g = malloc(sizeof(Tilemap));
	g->donnees = lire_fichier(nomFichier);
	g->largeur = l;
	g->hauteur = h;
	g->ltile = 64;
	g->htile = 32;
	g->tileset = charger_image_transparente(nomTileset, renderer, 0, 255, 255);

	g->tabTile = allouer_tab_2D_tile(g->largeur, g->hauteur);
	for(int i=0; i< g->largeur; i++){
	  for(int j=0; j< g->hauteur; j++){
	    g->tabTile[i][j].x = i;
	    g->tabTile[i][j].y = j;
	    g->tabTile[i][j].estOccupe = 0;
	    g->tabTile[i][j].degats = 0;
	  }
	}
	return g;
}

void dessiner_grille(SDL_Renderer* renderer, Tilemap* g){
	SDL_Rect SrcR;
	SDL_Rect DestR;
	for(int i=0; i < g->largeur; i++){
	    for(int j=0; j < g->hauteur; j++){

  	        SrcR.x = (g->donnees[i][j] % 48) * g->ltile;
  	        SrcR.y = 0;
  	        SrcR.w = g->ltile;
  	        SrcR.h = g->htile;

		DestR.x = -(TILE_WIDTH/2) + SCREEN_WIDTH/2 + (i-j) * 64;
		DestR.y = ORIGINY + (i+j) * 32;
                DestR.w = TILE_WIDTH;
                DestR.h = TILE_HEIGHT;

	        SDL_RenderCopy(renderer, g->tileset, &SrcR, &DestR);
	    }
	}

}

void dessiner_surbrillance(SDL_Renderer* renderer, SDL_Texture* jaune, int mouseX, int mouseY){
	SDL_Rect SrcR;
	SDL_Rect DestR;

	if(mouseX<=9 && mouseX>=0 && mouseY<=9 && mouseY>=0 ){
	  	SrcR.x = 0;
	  	SrcR.y = 0;
	  	SrcR.w = TILE_WIDTH/2;
	  	SrcR.h = TILE_HEIGHT/2;

		int renderX = mouseX;
		int renderY = mouseY;
		iso_to_coord(&renderX,&renderY);

		DestR.x = renderX - TILE_WIDTH/2;
		DestR.y = renderY;
		DestR.w = TILE_WIDTH;
		DestR.h = TILE_HEIGHT;

		SDL_RenderCopy(renderer, jaune, &SrcR, &DestR);
	}

}

void detruire_grille(Tilemap* t){
    desallouer_tab_2D(t->donnees, 10);
    for(int i = 0; i < 10; i++){
	free(t->tabTile[i]);
    }
    free(t->tabTile); t->tabTile = NULL;
    free(t); t = NULL;
}















