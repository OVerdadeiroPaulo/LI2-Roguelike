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
void draw_objects (STATE *st, int x, int y, int dif) {

	// Caso seja uma Parede
	if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
		if (dif == 1) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		} else if (dif == 2) {
			attron(COLOR_PAIR(COLOR_YELLOW));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_YELLOW));
		} else if (dif == 3) {
			attron(COLOR_PAIR(COLOR_RED));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_RED));
		}
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




	// Função que identifica parede, inimigos ou vazio na CELL
void erase_objects (int x, int y) {

		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (y, x, ' ' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
}





	// Função que desenha a iluminação
void draw_light (STATE *st, int raio, int ncols, int nrows) {
	int x, y;
	float grau;
	int i, j;
	bool aux;

		// Definição do circulo de luz do jogador
	if (st->dificulty == 1) {
		for (i = 360; i > 0; i--) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 1);
						aux = FALSE;
					}
					else
						erase_objects (x, y);
				}
				else
					if (aux == TRUE)
						draw_objects (st, x, y, 1);
					else
						erase_objects (x, y);
			}
		}

			// Adicionando paredes no sentido anti-horario
		for (i = 0; i < 360; i++) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 1);
						aux = FALSE;
					}
				}
			}
		}



	}
	else if (st->dificulty == 2) {
		for (i = 360; i > 0; i--) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 2);
						aux = FALSE;
					}
					else
						erase_objects (x, y);
				}
				else
					if (aux == TRUE)
						draw_objects (st, x, y, 2);
					else
						erase_objects (x, y);
			}
		}

			// Adicionando paredes no sentido anti-horario
		for (i = 0; i < 360; i++) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 2);
						aux = FALSE;
					}
				}
			}
		}



	}
	else if (st->dificulty == 3) {
		for (i = 360; i > 0; i--) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 3);
						aux = FALSE;
					}
					else
						erase_objects (x, y);
				}
				else
					if (aux == TRUE)
						draw_objects (st, x, y, 3);
					else
						erase_objects (x, y);
			}
		}

			// Adicionando paredes no sentido anti-horario
		for (i = 0; i < 360; i++) {
			aux = TRUE;
			grau = i * 0.01745329251;

			for (j = 0; j <= raio; j++) {
				x = ceil (j * cosf (grau) + (ncols / 2));
				y = ceil (j * sinf (grau) + (nrows / 2));

				if (st->mapaEasy[x + st->playerX][y + st->playerY].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 3);
						aux = FALSE;
					}
				}
			}
		}
	}
}