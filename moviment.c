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


	if (st->dificulty == 1) {	
		if (st->mapaEasy[ny][x].is_water == TRUE &&
			st->mapaEasy[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaEasy[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
	
	
	else if (st->dificulty == 2) {	
		if (st->mapaMid[ny][x].is_water == TRUE &&
			st->mapaMid[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaMid[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
	
	
	else if (st->dificulty == 3) {	
		if (st->mapaHard[ny][x].is_water == TRUE &&
			st->mapaHard[st->playerY + (nrows / 2)][st->playerX + (ncols / 2)].is_water == TRUE) {
				st->playerX += movex;
				st->playerY -= movey;
		}
		else if (st->mapaHard[y][x].is_wall != TRUE) {
			st->playerX += movex;
			st->playerY += movey;
		}
	}
}



void stairs_move (STATE *st, int ncols, int nrows) {
	int x = st->playerX + (ncols / 2);
	int y = st->playerY + (nrows / 2);

	if (st->dificulty == 1) {
		if (st->mapaEasy[y][x].is_stairs) {
			st->dificulty ++;
			int i, j = 0;

			for (i = 0; st->mapaHard[j][i].is_wall == TRUE; i++) {
				for (j = 0; st->mapaHard[j][i].is_wall == TRUE; j++) { };
			} 

			st->playerX = i;
			st->playerY = j;
		}
	}


	else if (st->dificulty == 2) {
		if (st->mapaMid[y][x].is_stairs) {
			st->dificulty ++;
			int i, j = 0;

			for (i = 0; st->mapaHard[j][i].is_wall; i++) {
				for (j = 0; st->mapaHard[j][i].is_wall; j++) { };
			} 

			st->playerX = i;
			st->playerY = j;
		}
	}


	else if (st->dificulty == 3) {
		if (st->mapaHard[y][x].is_stairs) {
			clear ();
		}
	}
}



    // Função que busca o caractere do jogador
void moviment(STATE *st, int ncols, int nrows) {

	int key = getch();

    switch(key) {
		case 'm': stairs_move (st, ncols, nrows); break;
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