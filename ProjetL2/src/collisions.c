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

int collisions_cadre_perso(int mouseX, int mouseY){
    int originY = SCREEN_HEIGHT - CADRE_HEIGHT*4;
    if(collisions_point_rect(mouseX, mouseY, 0, originY, CADRE_WIDTH*2, CADRE_HEIGHT*2))
		return 0;
    if(collisions_point_rect(mouseX, mouseY, CADRE_WIDTH*2, originY, CADRE_WIDTH*2, CADRE_HEIGHT*2))
		return 1;
    if(collisions_point_rect(mouseX, mouseY, 0, originY+(CADRE_HEIGHT*2), CADRE_WIDTH*2, CADRE_HEIGHT*2))
		return 2;
    if(collisions_point_rect(mouseX, mouseY, CADRE_WIDTH*2, originY+(CADRE_HEIGHT*2), CADRE_WIDTH*2, CADRE_HEIGHT*2))
		return 3;
    return -1;
}

int collisions_cadre_competence(int mouseX, int mouseY){
    int originY = SCREEN_HEIGHT - 4*(CADRE_HEIGHT) - COMP_HEIGHT;
    if(collisions_point_rect(mouseX,mouseY, 0, originY, CADRE_WIDTH, COMP_HEIGHT))
		return 1;
    return 0;
}

int collisions_cadre_competence_attaque(int mouseX, int mouseY){
    int originY = SCREEN_HEIGHT - 4*(CADRE_HEIGHT) - COMP_HEIGHT;
    if(collisions_point_rect(mouseX,mouseY, CADRE_WIDTH, originY, CADRE_WIDTH, COMP_HEIGHT))
		return 1;
    return 0;
}

int collisions_competence(int mouseX, int mouseY, Sprite* s, int longueur, int numero_competence){
	for(int i=0; i<longueur; i++){
		if(mouseX >= 0 && mouseX <= 9 && mouseY >= 0 && mouseY <= 9){
			if(mouseX == s->comp[numero_competence]->zonePossible[i].x && mouseY == s->comp[numero_competence]->zonePossible[i].y)
				return 1;
		}
    }
	return 0;
}





