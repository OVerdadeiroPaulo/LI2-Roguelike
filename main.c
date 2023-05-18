#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "draw.c"



void play (STATE *st, int ncols, int nrows, int raio) {

	draw_Cood (st, ncols, nrows);
	draw_light (st, raio, ncols, nrows);
	draw_player (ncols, nrows);

	moviment (st, ncols, nrows);
}



void play_menu (STATE *st, int ncols, int nrows) {
	draw_menu (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



void play_pause (STATE *st, int ncols, int nrows) {
	draw_pause (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



void play_GameWon (STATE *st, int ncols, int nrows) {
	draw_GameWon (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



void play_GameOver (STATE *st, int ncols, int nrows) {
	draw_GameOver (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



int main () {
	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

		// Variavel que define o raio de iluminação do jogador
	int radius_light = 18;

		// Estado Inicial do Jogo, mapa, jogador e inimigos
	STATE st;
	st.menu = 0;

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

	
	st.selection = TRUE;

	while (1) {
		while (st.menu == 0)
			play_menu (&st, ncols, nrows);
		while (st.menu == 1)
			play (&st, ncols, nrows, radius_light);
		while (st.menu == 2)
			play_pause (&st, ncols, nrows);
		while (st.menu == 3)
			play_GameWon (&st, ncols, nrows);
		while (st.menu == 4)
			play_GameOver (&st, ncols, nrows);
	}

	return 0;
}