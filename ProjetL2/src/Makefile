CC = gcc
CFLAGS = -W -Wall -ansi -std=c99 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES = -I./SDL2_ttf
EXEC = main 
SRC = main.c accueil.c collisions.c conversion.c fonctions_SDL.c grille.c sprites.c
HEADERS = accueil.h collisions.h CONST.h conversion.h fonctions_SDL.h grille.h world.h sprites.h

main: $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -lm $(LIBS) $(LDFLAGS) -o $(EXEC)

clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)
