#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"



    // Função que avalia se o terreno é valido para movimento
void move_action (STATE *st, int movex, int movey) {
	st->playerX += movex;
	st->playerY += movey;
}



    // Função que busca o caractere do jogador
void moviment(STATE *st) {

	int key = getch();

	earse_all (st, 1000, 1000);

    switch(key) {
		case KEY_UP: move_action(st, 0, -1); break;
		case KEY_DOWN: move_action(st, +0, +1); break;
		case KEY_LEFT: move_action(st, -1, +0); break;
		case KEY_RIGHT: move_action(st, +1, +0); break;
		case KEY_A1: move_action(st, -1, -1); break;
		case KEY_A3: move_action(st, -1, +1); break;
		case KEY_C1: move_action(st, +1, -1); break;
		case KEY_C3: move_action(st, +1, +1); break;
		case KEY_B2: break;
		case 'q': endwin(); exit(0); break;
	}
}