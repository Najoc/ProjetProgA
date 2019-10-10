#include "grille.h"



char** allouer_tab_2D(int n, int m){
    char** tab2D = malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
	tab2D[i] = malloc(m*sizeof(char));
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
	     *nbCol = *nbCol + 1;
	     	if(temp > *nbLig)
		{
		    *nbLig = temp;
		}
	     temp = 0;
	     }
	}
    }
}

char** lire_fichier(const char* nomFichier){
    int lig = 0;
    int col = 0;
    taille_fichier(nomFichier, &lig, &col);
    char** tab2D = allouer_tab_2D(lig,col);

    FILE* file = fopen(nomFichier, "r");
    int c;
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
	     }
	 tab2D[i][j] = c;
	 j++;
	 }	
    }
    return tab2D;
}

Tilemap* initialiser_grille(const char* nomTileset ,SDL_Renderer* renderer, const char* nomFichier, int l,int h){
	Tilemap* g = malloc(sizeof(Tilemap));
	g->donnees = lire_fichier(nomFichier);
	g->largeur = l;
	g->hauteur = h;
	g->tileset = charger_image_transparente(nomTileset, renderer, 0, 255, 255);
	g->ltile = 32;
	g->htile = 16;
	g->xtile = 0;
	g->ytile = 0;
	return g;
}

void dessiner_grille(SDL_Renderer* renderer, Tilemap* g){
	SDL_Rect SrcR;
	SDL_Rect DestR;
	for(int i=0; i < g->largeur; i++){
	    for(int j = g->hauteur-1; j >= 0; j--){
		
  	        SrcR.x = 0;
  	        SrcR.y = 0;
  	        SrcR.w = g->ltile;
  	        SrcR.h = g->htile;

	        DestR.x = ORIGINX + (j * (g->ltile*4) / 2) + (i * (g->ltile*4) / 2);
                DestR.y = ORIGINY + (i * (g->htile*4) / 2) - (j * (g->htile*4) / 2);
                DestR.w = g->ltile*4;
                DestR.h = g->htile*4;
		
	        SDL_RenderCopy(renderer, g->tileset, &SrcR, &DestR);
	    }
	}

}
















