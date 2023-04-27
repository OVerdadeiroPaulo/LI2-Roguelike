#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "start.c"



	// Função que desenha as coordenadas do jogador
void draw_Cood (STATE *st, int ncols, int nrows){

	move(nrows - 2, 5);
	attron(COLOR_PAIR(COLOR_BLUE));
	printw("(%d, %d) %d %d", st->playerX, st->playerY, ncols, nrows);
	attroff(COLOR_PAIR(COLOR_BLUE));

}



	// Função que desenha o jogador
void draw_player (STATE *st) {

	attron(COLOR_PAIR(COLOR_YELLOW));
	mvaddch(st->playerY, st->playerX, '@' | A_BOLD);
	attroff(COLOR_PAIR(COLOR_YELLOW));

}



	// Função que identifica parede, inimigos ou vazio na CELL
void draw_objects (STATE *st, int x, int y) {

	int vertical = st->playerY + y;
	int horizontal = st->playerX + x;

	if (st->mapaEasy[horizontal][vertical].is_wall == TRUE)
		mvaddch (vertical, horizontal, '#' | A_BOLD);
	// else if (exist_Enemy(st, x, y))
	// 	mvaddch (vertical, horizontal, 'K' | A_BOLD);
	else
		mvaddch (vertical, horizontal, '-' | A_BOLD);
}



	// Função que desenha a iluminação
void draw_light (STATE *st, int raio) {
	int x;
	int y;

	attron(COLOR_PAIR(COLOR_GREEN));
	for (x = 0; x < 2*raio+1; x++) {
		for (y = 0; y < 2*raio+1; y++) {
			float d = sqrt ((x * x) + (y * y));
			if (d <= raio) {
				draw_objects(st, x, y);
				draw_objects(st, -x, y);
				draw_objects(st, x, -y);
				draw_objects(st, -x, -y);
			}
		}
	}
	attroff(COLOR_PAIR(COLOR_GREEN));

}



	// Função para dar refresh na iluminação
void earse_all (STATE *st, int cumprimento, int altura) {
	int x, y;

	for (x = 0; x < cumprimento; x++) {
		for (y = 0; y < altura; y++) {
			mvaddch(st->playerY + y, st->playerX + x, ' ' | A_BOLD);
			mvaddch(st->playerY + y, st->playerX - x, ' ' | A_BOLD);
			mvaddch(st->playerY - y, st->playerX + x, ' ' | A_BOLD);
			mvaddch(st->playerY - y, st->playerX - x, ' ' | A_BOLD);
		}
	}
}