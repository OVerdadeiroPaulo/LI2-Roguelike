#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "start.c"



	// Função que desenha as coordenadas do jogador
	// Ultilizar essa função para eventualmente desenhar
	// a vida e itens do jogador
void draw_Cood (STATE *st, int ncols, int nrows){

	move(nrows - 2, 5);
	attron(COLOR_PAIR(COLOR_BLUE));
	printw("(%d, %d) %d %d", st->playerX, st->playerY, ncols, nrows);
	attroff(COLOR_PAIR(COLOR_BLUE));

}



	// Função que desenha o jogador
void draw_player (int ncols, int nrows) {

	attron(COLOR_PAIR(COLOR_CYAN));
	mvaddch(nrows / 2, ncols / 2, '@' | A_BOLD);
	attroff(COLOR_PAIR(COLOR_CYAN));

}



	// Função que identifica parede, inimigos ou vazio na CELL
void draw_objects (STATE *st, int x, int y) {
	
		// Caso seja uma Parede
	if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (y, x, '#' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
	}
		// Caso seja um terreno de Rio
	else if (st->mapaEasy[x + st->playerX][y + st->playerY].is_water == TRUE) {
		attron(COLOR_PAIR(COLOR_BLUE));
		mvaddch (y, x, '~' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
		// Caso seja um terreno de Relva
	else if (st->mapaEasy[x + st->playerX][y + st->playerY].is_grass == TRUE) {
		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (y, x, '.' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
	}
		// Caso seja um terreno vazio
	else {
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch (y, x, '-' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));
	}
}



void erase_area (STATE *st, int x, int y, int raio) {
	int i, j;

	float dest;
	int quad = 0;

	if (st->playerX < x)
		dest = (y - st->playerY) / (x - st->playerX);
	else if (st->playerX > x)
		dest = (st->playerY - y) / (st->playerX - x);
	else
		quad = 1;

	for (i = 0; i < raio; i++) {
		for (j = 0; j < raio; j++) {
			if (quad != 1) {
				if (j >= round ((3/4) * dest * i) && j <= round ((5/4) * dest * i)) {
					mvaddch (j + st->playerY, i + st->playerX, ' ' | A_BOLD);
				}
			}
			else {
				
			}
		}
	}
}



void erase_shadow (STATE *st, int raio, int ncols, int nrows) {
	int i, j;
	int x, y;

		// Definição do circulo de luz do jogador
	for (x = - (2 * raio); x < 2 * raio; x++) {
		for (y = -(2 * raio); y < 2*raio; y++) {

			i = st->playerX + x + (ncols / 2);
			j = st->playerY + y + (nrows / 2);

			if (st->mapaEasy[i][j].is_wall == TRUE) {
				i = i - st->playerX;
				j = j - st->playerY;

				erase_area (st, i, j, raio);
			}
		}
	}
}



	// Função que desenha a iluminação
void draw_light (STATE *st, int raio, int ncols, int nrows) {
	int x, y;

		// Definição do circulo de luz do jogador
	for (x = - (2 * raio); x < 2 * raio; x++) {
		for (y = -(2 * raio); y < 2*raio; y++) {
			int i = (ncols / 2) + x;
			int j = (nrows / 2) + y;

			float d = sqrt ((x * x) + (y * y));
			if (d <= raio ) {
				draw_objects(st, i, j);
			}
		}
	}

	erase_shadow (st, raio, ncols, nrows);
}