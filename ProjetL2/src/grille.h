#ifndef GRILLE_H
#define GRILLE_H

typedef struct Tilemap
{
	char** donnees;
	int largeur, hauteur; //taille de la grille
	SDL_Texture* tileset;
	int ltile, htile;     //largeur/hauteur des tiles
	int xtile, ytile;     //coordonnées des tiles/
} Tilemap;

extern char** allouer_tab_2D(int n, int m);
extern void desallouer_tab_2D(char** tab, int n);
extern void afficher_tab_2D(char** tab, int n, int m);
extern void taille_fichier(const char* nomFichier, int* nbLig, int* nbCol);
extern char** lire_fichier(const char* nomFichier);
extern Tilemap* initialiser_grille(const char* nomTileset ,SDL_Renderer* renderer, const char* nomFichier, int l,int h);
extern void dessiner_grille(SDL_Renderer* renderer, Tilemap* g);



#endif
