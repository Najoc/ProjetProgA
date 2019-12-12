#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <math.h>
#include "sprites.h"

extern int collisions_point_rect(int pointX, int pointY,int rectX,int rectY,int largeur,int hauteur);
extern int collisions_rect_rect(int rectAX,int rectAY,int largeurA,int hauteurA,int rectBX,int rectBY,int largeurB,int hauteurB);
extern int distance_deux_point(int x1, int x2, int y1, int y2);
extern int collisions_cadre_perso(int mouseX, int mouseY);
extern int collisions_cadre_competence(int mouseX, int mouseY);
extern int collisions_cadre_competence_attaque(int mouseX, int mouseY);
extern int collisions_competence(int mouseX, int mouseY, Sprite* s, int longueur, int numero_competence);
extern int collisions_souris_aide(int mouseX, int mouseY);

#endif //COLLISIONS_H
