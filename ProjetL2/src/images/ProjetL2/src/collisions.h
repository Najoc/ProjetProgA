#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <math.h>

extern int collisions_point_rect(int pointX, int pointY,int rectX,int rectY,int largeur,int hauteur);
extern int collisions_rect_rect(int rectAX,int rectAY,int largeurA,int hauteurA,int rectBX,int rectBY,int largeurB,int hauteurB);
extern int distance_deux_point(int x1, int x2, int y1, int y2);

#endif
