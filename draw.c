#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "moviment.c"



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
	int res = 0, i;

	for (i = 0; i < 9; i++) {
		if (st->enemy_list[i].enemyX == x + st->playerX && st->enemy_list[i].enemyY == y + st->playerY)
			res = i + 1;
	}

	if (res >= 1) {
			draw_enemy (st->enemy_list[res - 1], x, y);
	}
	else if (dif == 1) {
		if (st->mapaEasy[y + st->playerY][x + st->playerX].is_wall == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
		else if (st->mapaEasy[y + st->playerY][x + st->playerX].is_stairs == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '^' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
			// Caso seja um terreno de Rio
		else if (st->mapaEasy[y + st->playerY][x + st->playerX].is_water == TRUE) {
			attron(COLOR_PAIR(COLOR_BLUE));
			mvaddch (y, x, '~' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
			// Caso seja um terreno de Relva
		else if (st->mapaEasy[y + st->playerY][x + st->playerX].is_grass == TRUE) {
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
	

	
	else if (dif == 2) {
		if (st->mapaMid[y + st->playerY][x + st->playerX].is_wall == TRUE) {
			attron(COLOR_PAIR(COLOR_YELLOW));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_YELLOW));
		}
		else if (st->mapaMid[y + st->playerY][x + st->playerX].is_stairs == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '^' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
			// Caso seja um terreno de Rio
		else if (st->mapaMid[y + st->playerY][x + st->playerX].is_water == TRUE) {
			attron(COLOR_PAIR(COLOR_BLUE));
			mvaddch (y, x, '~' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
			// Caso seja um terreno de Relva
		else if (st->mapaMid[y + st->playerY][x + st->playerX].is_grass == TRUE) {
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
	

	
	else if (dif == 3) {
		if (st->mapaHard[y + st->playerY][x + st->playerX].is_wall == TRUE) {
			attron(COLOR_PAIR(COLOR_RED));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_RED));
		}
		else if (st->mapaHard[y + st->playerY][x + st->playerX].is_stairs == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '^' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
			// Caso seja um terreno de Rio
		else if (st->mapaHard[y + st->playerY][x + st->playerX].is_water == TRUE) {
			attron(COLOR_PAIR(COLOR_BLUE));
			mvaddch (y, x, '~' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
			// Caso seja um terreno de Relva
		else if (st->mapaHard[y + st->playerY][x + st->playerX].is_grass == TRUE) {
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

				if (st->mapaEasy[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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

				if (st->mapaEasy[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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

				if (st->mapaMid[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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

				if (st->mapaMid[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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

				if (st->mapaHard[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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

				if (st->mapaHard[y + st->playerY][x + st->playerX].is_wall == TRUE) {
					if (aux == TRUE) {
						draw_objects (st, x, y, 3);
						aux = FALSE;
					}
				}
			}
		}
	}
}



void draw_menu (STATE *st, int ncols, int nrows) {
	clear ();

	if (st->selection == TRUE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Play");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
	else if (st->selection == FALSE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Exit");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
}



void draw_pause (STATE *st, int ncols, int nrows) {
	clear();

	if (st->selection == TRUE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Continue");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
	else if (st->selection == FALSE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Back to menu");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
}