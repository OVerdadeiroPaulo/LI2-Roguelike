#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"



    // Função que avalia se o terreno é valido para movimento
void move_action (STATE *st, int movex, int movey, int ncols, int nrows) {
	int x = st->playerX + movex + (ncols / 2);
	int y = st->playerY + movey + (nrows / 2);
	int ny = st->playerY - movey + (nrows / 2);

	
	if (st->mapaEasy[x][ny].is_water == TRUE &&
		st->mapaEasy[st->playerX + (ncols / 2)][st->playerY + (nrows / 2)].is_water == TRUE) {
			st->playerX += movex;
			st->playerY -= movey;
	}
	else if (st->mapaEasy[x][y].is_wall != TRUE) {
		st->playerX += movex;
		st->playerY += movey;
	}
}



    // Função que busca o caractere do jogador
void moviment(STATE *st, int ncols, int nrows) {

	int key = getch();

    switch(key) {
		case KEY_UP: move_action(st, +0, -1, ncols, nrows); break;
		case KEY_DOWN: move_action(st, +0, +1, ncols, nrows); break;
		case KEY_LEFT: move_action(st, -1, +0, ncols, nrows); break;
		case KEY_RIGHT: move_action(st, +1, +0, ncols, nrows); break;
		case KEY_A1: move_action(st, -1, -1, ncols, nrows); break;
		case KEY_A3: move_action(st, -1, +1, ncols, nrows); break;
		case KEY_C1: move_action(st, +1, -1, ncols, nrows); break;
		case KEY_C3: move_action(st, +1, +1, ncols, nrows); break;
		case KEY_B2: break;
		case 'q': endwin(); exit(0); break;
	}
}