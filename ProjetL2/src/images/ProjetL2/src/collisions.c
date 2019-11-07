#include "collisions.h"
#include "grille.h"

int collisions_point_rect(int pointX,int pointY,int rectX,int rectY,int largeur,int hauteur){
    if(pointX >= rectX
    && pointX < rectX + largeur
    && pointY >= rectY
    && pointY < rectY + hauteur){
	return 1;
    }else{
	return 0;
    }
}

int collisions_rect_rect(int rectAX,int rectAY,int largeurA,int hauteurA,int rectBX,int rectBY,int largeurB,int hauteurB){
    if(rectBX >= rectAX + largeurA
    && rectBX + largeurB <= rectAX
    && rectBY >= rectAY + hauteurA
    && rectBY + hauteurB <= rectAY){
	return 0;
    }else{
	return 1;
    }
}

int distance_deux_point(int x1, int x2, int y1, int y2){
    return floor(sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1))));
}
