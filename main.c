#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "draw.c"
#include "moviment.c"



void play (STATE *st, int ncols, int nrows, int raio) {

	draw_Cood (st, ncols, nrows);
	draw_light (st, raio, ncols, nrows);
	draw_player (ncols, nrows);

	moviment (st, ncols, nrows);
}



int main () {
	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

		// Variavel que define o raio de iluminação do jogador
	int radius_light = 15;
		// Estado Inicial do Jogo, mapa, jogador e inimigos
	STATE st;

	srand48(time(NULL));
	start_color();
	keypad(stdscr, true);

		// Inicializando as Cores
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);

	gerar(&st);

	while (1) {
		play (&st, ncols, nrows, radius_light);
	}

	return 0;
}