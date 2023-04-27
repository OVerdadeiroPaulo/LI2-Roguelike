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
	draw_light (st, raio);
	draw_player (st);

	moviment (st);
}



int main () {
	WINDOW *wnd = initscr();
	int ncols, nrows;
	getmaxyx(wnd,nrows,ncols);

	STATE st;

	srand48(time(NULL));
	start_color();
	keypad(stdscr, true);

	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);

	gerar(&st, ncols, nrows);

	while (1) {
		play (&st, ncols, nrows, 20);
	}

	return 0;
}