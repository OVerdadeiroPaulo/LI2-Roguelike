#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "draw.c"



	// a105684 - Joshua David
	// Função que atualiza o jogo
void play (STATE *st, int ncols, int nrows, int raio) {
	clear();

    draw_Cood (st, ncols, nrows);
    draw_light (st, raio, ncols, nrows);
    draw_player (ncols, nrows);

    if (st->dificulty == 1) combat_easy(st, ncols , nrows);
    else if (st->dificulty == 2) combat_mid(st, ncols , nrows);
    else combat_hard(st, ncols, nrows);

    moviment (st, ncols, nrows);
}



	// a105684 - Joshua David
	// Função que atualiza o menu Principal
void play_menu (STATE *st, int ncols, int nrows) {
	draw_menu (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



	// a105684 - Joshua David
	// Função que atualiza o menu de pause
void play_pause (STATE *st, int ncols, int nrows) {
	draw_pause (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



	// a105684 - Joshua David
	// Função que atualiza o menu de jogo Vencido
void play_GameWon (STATE *st, int ncols, int nrows) {
	draw_GameWon (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



	// a105684 - Joshua David
	// Função que atualiza o menu de jogo perdido
void play_GameOver (STATE *st, int ncols, int nrows) {
	draw_GameOver (st, ncols, nrows);
	moviment_menu (st, ncols, nrows);
}



	// a105684 - Joshua David
int main () {
	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

		// Variavel que define o raio de iluminação do jogador
	int radius_light = 18;

		// Estado Inicial do Jogo, mapa, jogador e inimigos
	STATE st;
	st.menu = 0;
    
	curs_set (0);   // Funcao que esconde cursor
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
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);

	
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