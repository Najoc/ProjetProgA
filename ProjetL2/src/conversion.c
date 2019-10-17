#include "conversion.h"

void coord_to_iso(int* coordX, int* coordY){
      int VX_x = 64;
      int VX_y = 32;
      int VY_x = -64;
      int VY_y = 32;

      int denom = (VX_x * VY_y) - (VX_y * VY_x);
      int coord_iso_y = -((VX_y * *coordX) - (VX_x * *coordY) + (VX_x*160) - (SCREEN_WIDTH/2*VX_y))/denom;
      int coord_iso_x = ((VY_y * *coordX) - (VY_x * *coordY) + (VY_x*160) - (SCREEN_WIDTH/2*VY_y))/denom;

      *coordX = coord_iso_x;
      *coordY = coord_iso_y;
      
}

extern void iso_to_coord(int* indexX, int* indexY){
	int globalX;
	int globalY;
	globalX = SCREEN_WIDTH/2 + ((*indexX - *indexY) * 64);
	globalY = 160 + ((*indexX + *indexY) *32);
	*indexX = globalX;
	*indexY = globalY;

}
