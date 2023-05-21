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
	// atualiza_hp(nrows);

	attron(COLOR_PAIR(COLOR_BLUE));
	// Coordenadas
		move(nrows - 2, 5);
		printw("(%d, %d) %d %d", st->playerX, st->playerY, ncols, nrows);
	attroff(COLOR_PAIR(COLOR_BLUE));

	// Vida doJogador
	attron(COLOR_PAIR(COLOR_GREEN));
		move(1, 3);
		printw("HP:\n");
	attroff(COLOR_PAIR(COLOR_GREEN));
	attron(COLOR_PAIR(COLOR_RED));
		move(2, 3);
		for (int i = 0; i < (st->playerHP / 10); i++)
			printw ("@");
	attroff(COLOR_PAIR(COLOR_RED));

}


	// Função que desenha o jogador
void draw_player (int ncols, int nrows) {

	attron(COLOR_PAIR(COLOR_CYAN));
	mvaddch(nrows / 2, ncols / 2, '@' | A_BOLD);
	attroff(COLOR_PAIR(COLOR_CYAN));

}


	// Função que identifica parede, inimigos ou vazio na CELL
void draw_objects (STATE *st, int x, int y, int dif) {
	int i;
	int  enemy_easy = 0, enemy_Mid = 0, enemy_Hard = 0;
	int  items_easy = 0, items_Mid = 0;

	for (i = 0; i < 20; i++) {
		if (st->enemy_list_Easy[i].enemyX == x + st->playerX && st->enemy_list_Easy[i].enemyY == y + st->playerY)
			enemy_easy = i + 1;
	}
	for (i = 0; i < 40; i++) {
		if (st->enemy_list_Mid[i].enemyX == x + st->playerX && st->enemy_list_Mid[i].enemyY == y + st->playerY)
			enemy_Mid = i + 1;
	}
	for (i = 0; i < 50; i++) {
		if (st->enemy_list_Hard[i].enemyX == x + st->playerX && st->enemy_list_Hard[i].enemyY == y + st->playerY)
			enemy_Hard = i + 1;
	}

	for (i = 0; i < 10; i++) {
		if (st->items_list_easy[i].posx == x + st->playerX && st->items_list_easy[i].posy == y + st->playerY)
			items_easy = i + 1;
	}
	for (i = 0; i < 10; i++) {
		if (st->items_list_Mid[i].posx == x + st->playerX && st->items_list_Mid[i].posy == y + st->playerY)
			items_Mid = i + 1;
	}



	if (dif == 1) {
		if (enemy_easy >= 1 && st->enemy_list_Easy[enemy_easy - 1].hp > 0) {
			draw_enemy (st->enemy_list_Easy[enemy_easy - 1], x, y, 1);
		}
		else if (st->mapaEasy[y + st->playerY][x + st->playerX].is_wall == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
		else if (st->mapaEasy[y + st->playerY][x + st->playerX].is_stairs == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '^' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
		else if (items_easy >= 1 && st->items_list_easy[items_easy - 1].used == FALSE) {
			draw_items (st->items_list_easy[items_easy - 1], x, y);
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
		if (enemy_Mid >= 1 && st->enemy_list_Mid[enemy_Mid - 1].hp > 0) {
			draw_enemy (st->enemy_list_Mid[enemy_Mid - 1], x, y, 2);
		}
		else if (st->mapaMid[y + st->playerY][x + st->playerX].is_wall == TRUE) {
			attron(COLOR_PAIR(COLOR_YELLOW));
			mvaddch (y, x, '#' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_YELLOW));
		}
		else if (st->mapaMid[y + st->playerY][x + st->playerX].is_stairs == TRUE) {
			attron(COLOR_PAIR(COLOR_GREEN));
			mvaddch (y, x, '^' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
		else if (items_Mid >= 1 && st->items_list_Mid[items_Mid - 1].used == FALSE) {
			draw_items (st->items_list_Mid[items_Mid - 1], x, y);
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
		if (enemy_Hard >= 1  && st->enemy_list_Hard[enemy_Hard - 1].hp > 0) {
			draw_enemy (st->enemy_list_Hard[enemy_Hard - 1], x, y, 3);
		}
		else if (st->mapaHard[y + st->playerY][x + st->playerX].is_wall == TRUE) {
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
			// Caso seja um terreno de Mud
		else if (st->mapaHard[y + st->playerY][x + st->playerX].is_mud == TRUE) {
			attron(COLOR_PAIR(COLOR_BLACK));
			mvaddch (y, x, ')' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_BLACK));
		}
			// Caso seja um terreno vazio
		else {
			attron(COLOR_PAIR(COLOR_YELLOW));
			mvaddch (y, x, '-' | A_BOLD);
			attroff(COLOR_PAIR(COLOR_YELLOW));
		}
	}
}



	// Função que identifica parede, inimigos ou vazio na CELL
void draw_wall (int x, int y) {

		attron(COLOR_PAIR(COLOR_GREEN));
		mvaddch (y, x, '#' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_GREEN));
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
				else if (x + st->playerX == 0 || y + st->playerY == 0 || x + st->playerX == 250 || y + st->playerY == 55) {
					if (aux == TRUE) {
						draw_wall (x, y);
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
				else if (x + st->playerX == 0 || y + st->playerY == 0 || x + st->playerX == 250 || y + st->playerY == 55) {
					if (aux == TRUE) {
						draw_wall (x, y);
						aux = FALSE;
					}
					else
						erase_objects (x, y);
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
				else if (x + st->playerX == 0 || y + st->playerY == 0 || x + st->playerX == 250 || y + st->playerY == 55) {
					if (aux == TRUE) {
						draw_wall (x, y);
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
				else if (x + st->playerX == 0 || y + st->playerY == 0 || x + st->playerX == 250 || y + st->playerY == 55) {
					if (aux == TRUE) {
						draw_wall (x, y);
						aux = FALSE;
					}
					else
						erase_objects (x, y);
				}
			}
		}
	}
}



void draw_menu (STATE *st, int ncols, int nrows) {
	clear ();
	int i;

	attron(COLOR_PAIR(COLOR_MAGENTA));
	for (i = 5; i < ncols - 5; i++) {
		move(7, i);
		printw("-");
		move(nrows - 7, i);
		printw("-");
	}
	for (i = 6; i < nrows - 5; i++) {
		move(i, 7);
		printw("|");
		move(i, ncols - 7);
		printw("|");
	}
	attroff(COLOR_PAIR(COLOR_MAGENTA));

	if (ncols >= 160 && nrows >= 44) {
		if (st->selection == TRUE) {
			move((nrows / 2) - 15, (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("WELCOME!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) - 5, (ncols / 2) - 27);
			printw(" ad88888ba 888888888888   db        88888888ba 888888888888");
			move((nrows / 2) - 4, (ncols / 2) - 27);
			printw("d8'     '8b     88       d88b       88      '8b     88");
			move((nrows / 2), (ncols / 2) - 27);
			printw("Y8,             88      d8'`8b      88      ,8P     88");
			move((nrows / 2) - 3, (ncols / 2) - 27);
			printw("`Y8aaaaa,       88     d8'  `8b     88aaaaaa8P'     88");
			move((nrows / 2) - 2, (ncols / 2) - 27);
			printw("  `'''''8b,     88    d8YaaaaY8b    88''''88'       88");
			move((nrows / 2) - 1, (ncols / 2) - 27);
			printw("        `8b     88   d8''''''''8b   88    `8b       88");
			move((nrows / 2), (ncols / 2) - 27);
			printw("Y8a     a8P     88  d8'        `8b  88     `8b      88");
			move((nrows / 2) + 1, (ncols / 2) - 27);
			printw(" 'Y88888P'      88 d8'          `8b 88      `8b     88");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 4, (ncols / 2) - 20);
			printw("  ,ad8888ba,   88        88 88 888888888888");
			move((nrows / 2) + 5, (ncols / 2) - 20);
			printw(" d8''    `'8b  88        88 88      88");
			move((nrows / 2) + 6, (ncols / 2) - 20);
			printw("d8'        `8b 88        88 88      88");
			move((nrows / 2) + 7, (ncols / 2) - 20);
			printw("88          88 88        88 88      88");
			move((nrows / 2) + 8, (ncols / 2) - 20);
			printw("88          88 88        88 88      88");
			move((nrows / 2) + 9, (ncols / 2) - 20);
			printw("Y8,    '88,,8P 88        88 88      88");
			move((nrows / 2) + 10, (ncols / 2) - 20);
			printw(" Y8a.    Y88P  Y8a.    .a8P 88      88");
			move((nrows / 2) + 11, (ncols / 2) - 20);
			printw("  `'Y8888Y'Y8a  `'Y8888Y''  88      88");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 15, (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("WELCOME!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) - 5, (ncols / 2) - 27);
			printw(" ad88888ba 888888888888   db        88888888ba 888888888888");
			move((nrows / 2) - 4, (ncols / 2) - 27);
			printw("d8'     '8b     88       d88b       88      '8b     88");
			move((nrows / 2), (ncols / 2) - 27);
			printw("Y8,             88      d8'`8b      88      ,8P     88");
			move((nrows / 2) - 3, (ncols / 2) - 27);
			printw("`Y8aaaaa,       88     d8'  `8b     88aaaaaa8P'     88");
			move((nrows / 2) - 2, (ncols / 2) - 27);
			printw("  `'''''8b,     88    d8YaaaaY8b    88''''88'       88");
			move((nrows / 2) - 1, (ncols / 2) - 27);
			printw("        `8b     88   d8''''''''8b   88    `8b       88");
			move((nrows / 2), (ncols / 2) - 27);
			printw("Y8a     a8P     88  d8'        `8b  88     `8b      88");
			move((nrows / 2) + 1, (ncols / 2) - 27);
			printw(" 'Y88888P'      88 d8'          `8b 88      `8b     88");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) + 4, (ncols / 2) - 20);
			printw("  ,ad8888ba,   88        88 88 888888888888");
			move((nrows / 2) + 5, (ncols / 2) - 20);
			printw(" d8''    `'8b  88        88 88      88");
			move((nrows / 2) + 6, (ncols / 2) - 20);
			printw("d8'        `8b 88        88 88      88");
			move((nrows / 2) + 7, (ncols / 2) - 20);
			printw("88          88 88        88 88      88");
			move((nrows / 2) + 8, (ncols / 2) - 20);
			printw("88          88 88        88 88      88");
			move((nrows / 2) + 9, (ncols / 2) - 20);
			printw("Y8,    '88,,8P 88        88 88      88");
			move((nrows / 2) + 10, (ncols / 2) - 20);
			printw(" Y8a.    Y88P  Y8a.    .a8P 88      88");
			move((nrows / 2) + 11, (ncols / 2) - 20);
			printw("  `'Y8888Y'Y8a  `'Y8888Y''  88      88");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
		}
	}
	else {
		if (st->selection == TRUE) {
			move((nrows / 2) - 5, (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("WELCOME!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2), (ncols / 2) - 2);
			printw("START");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 1, (ncols / 2) - 2);
			printw("QUIT!");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 5, (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("WELCOME!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2), (ncols / 2) - 2);
			printw("START");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) + 1, (ncols / 2) - 2);
			printw("QUIT!");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
		}
	}
}



void draw_pause (STATE *st, int ncols, int nrows) {
	clear ();
	int i;

	attron(COLOR_PAIR(COLOR_GREEN));
	for (i = 5; i < ncols - 5; i++) {
		move(7, i);
		printw("-");
		move(nrows - 7, i);
		printw("-");
	}
	for (i = 6; i < nrows - 5; i++) {
		move(i, 7);
		printw("|");
		move(i, ncols - 7);
		printw("|");
	}
	attroff(COLOR_PAIR(COLOR_GREEN));

	if (ncols >= 160 && nrows >= 44) {
		if (st->selection == TRUE) {
			move((nrows / 2) - 15, (ncols / 2) - 3);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("PAUSED!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_GREEN));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("  ,ad8888ba,   ,ad8888ba,   888b      88 888888888888 88 888b      88 88        88 88888888888");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw(" d8''    `'8b d8''    `'8b  8888b     88      88      88 8888b     88 88        88 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("d8'          d8'        `8b 88 `8b    88      88      88 88 `8b    88 88        88 88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("88           88          88 88  `8b   88      88      88 88  `8b   88 88        88 88aaaaa");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("88           88          88 88   `8b  88      88      88 88   `8b  88 88        88 88'");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("Y8,          Y8,        ,8P 88    `8b 88      88      88 88    `8b 88 88        88 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw(" Y8a.    .a8P Y8a.    .a8P  88     `8888      88      88 88     `8888 Y8a.    .a8P 88");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("  `'Y8888Y''   `'Y8888Y''   88      `888      88      88 88      `888  `'Y8888Y''  88888888888");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 4, (ncols / 2) - 26);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 26);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 26);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 26);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 26);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 26);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 26);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 26);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 15, (ncols / 2) - 3);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("PAUSED!");
			attroff(COLOR_PAIR(COLOR_GREEN));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("  ,ad8888ba,   ,ad8888ba,   888b      88 888888888888 88 888b      88 88        88 88888888888");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw(" d8''    `'8b d8''    `'8b  8888b     88      88      88 8888b     88 88        88 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("d8'          d8'        `8b 88 `8b    88      88      88 88 `8b    88 88        88 88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("88           88          88 88  `8b   88      88      88 88  `8b   88 88        88 88aaaaa");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("88           88          88 88   `8b  88      88      88 88   `8b  88 88        88 88'");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("Y8,          Y8,        ,8P 88    `8b 88      88      88 88    `8b 88 88        88 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw(" Y8a.    .a8P Y8a.    .a8P  88     `8888      88      88 88     `8888 Y8a.    .a8P 88");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("  `'Y8888Y''   `'Y8888Y''   88      `888      88      88 88      `888  `'Y8888Y''  88888888888");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_GREEN));
			move((nrows / 2) + 4, (ncols / 2) - 26);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 26);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 26);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 26);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 26);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 26);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 26);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 26);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
	}
	else {
		if (st->selection == TRUE) {
			move((nrows / 2) - 5, (ncols / 2) - 3);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("PAUSED");
			attroff(COLOR_PAIR(COLOR_GREEN));
			move((nrows / 2), (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("Continue");
			attroff(COLOR_PAIR(COLOR_GREEN));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 5, (ncols / 2) - 3);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("PAUSED");
			attroff(COLOR_PAIR(COLOR_GREEN));
			move((nrows / 2), (ncols / 2) - 4);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Continue");
			attroff(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_GREEN));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_GREEN));
		}
	}
}



void draw_GameWon (STATE *st, int ncols, int nrows) {
	clear ();
	int i;

	attron(COLOR_PAIR(COLOR_BLUE));
	for (i = 5; i < ncols - 5; i++) {
		move(7, i);
		printw("-");
		move(nrows - 7, i);
		printw("-");
	}
	for (i = 6; i < nrows - 5; i++) {
		move(i, 7);
		printw("|");
		move(i, ncols - 7);
		printw("|");
	}
	attroff(COLOR_PAIR(COLOR_BLUE));

	if (ncols >= 160 && nrows >= 44) {
		if (st->selection == TRUE) {
			move((nrows / 2) - 15, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("GAME WON!!");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("888888888888 88888888ba 8b        d8           db        ,ad8888ba,        db        88 888b      88");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw("     88      88      '8b Y8,    ,8P           d88b      d8''    `'8b      d88b       88 8888b     88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88      ,8P  Y8,  ,8P           d8'`8b    d8'               d8'`8b      88 88 `8b    88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("     88      88aaaaaa8P'   '8aa8'           d8'  `8b   88               d8'  `8b     88 88  `8b   88");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("     88      88''''88'      `88'           d8YaaaaY8b  88      88888   d8YaaaaY8b    88 88   `8b  88");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("     88      88    `8b       88           d8''''''''8b Y8,        88  d8''''''''8b   88 88    `8b 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88     `8b      88          d8'        `8b Y8a.    .a88 d8'        `8b  88 88     `8888");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("     88      88      `8b     88         d8'          `8b `'Y88888P' d8'          `8b 88 88      `888");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 4, (ncols / 2) - 24);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 24);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 24);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 24);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 24);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 24);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 24);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 24);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 15, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("GAME WON!!");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("888888888888 88888888ba 8b        d8           db        ,ad8888ba,        db        88 888b      88");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw("     88      88      '8b Y8,    ,8P           d88b      d8''    `'8b      d88b       88 8888b     88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88      ,8P  Y8,  ,8P           d8'`8b    d8'               d8'`8b      88 88 `8b    88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("     88      88aaaaaa8P'   '8aa8'           d8'  `8b   88               d8'  `8b     88 88  `8b   88");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("     88      88''''88'      `88'           d8YaaaaY8b  88      88888   d8YaaaaY8b    88 88   `8b  88");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("     88      88    `8b       88           d8''''''''8b Y8,        88  d8''''''''8b   88 88    `8b 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88     `8b      88          d8'        `8b Y8a.    .a88 d8'        `8b  88 88     `8888");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("     88      88      `8b     88         d8'          `8b `'Y88888P' d8'          `8b 88 88      `888");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) + 4, (ncols / 2) - 24);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 24);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 24);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 24);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 24);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 24);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 24);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 24);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
		}
	}
	else {
		if (st->selection == TRUE) {
			move((nrows / 2) - 5, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("GAME WON!!");
			attroff(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2), (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_MAGENTA));
			printw("Play Again");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 5, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("GAME WON!!");
			attroff(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2), (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Play Again");
			attroff(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_MAGENTA));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_MAGENTA));
		}
	}
}



void draw_GameOver (STATE *st, int ncols, int nrows) {
	clear ();
	int i;

	attron(COLOR_PAIR(COLOR_RED));
	for (i = 5; i < ncols - 5; i++) {
		move(7, i);
		printw("-");
		move(nrows - 7, i);
		printw("-");
	}
	for (i = 6; i < nrows - 5; i++) {
		move(i, 7);
		printw("|");
		move(i, ncols - 7);
		printw("|");
	}
	attroff(COLOR_PAIR(COLOR_RED));

	if (ncols >= 160 && nrows >= 44) {
		if (st->selection == TRUE) {
			move((nrows / 2) - 15, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_RED));
			printw("GAME LOST!");
			attroff(COLOR_PAIR(COLOR_RED));
			attron(COLOR_PAIR(COLOR_RED));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("888888888888 88888888ba 8b        d8           db        ,ad8888ba,        db        88 888b      88");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw("     88      88      '8b Y8,    ,8P           d88b      d8''    `'8b      d88b       88 8888b     88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88      ,8P  Y8,  ,8P           d8'`8b    d8'               d8'`8b      88 88 `8b    88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("     88      88aaaaaa8P'   '8aa8'           d8'  `8b   88               d8'  `8b     88 88  `8b   88");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("     88      88''''88'      `88'           d8YaaaaY8b  88      88888   d8YaaaaY8b    88 88   `8b  88");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("     88      88    `8b       88           d8''''''''8b Y8,        88  d8''''''''8b   88 88    `8b 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88     `8b      88          d8'        `8b Y8a.    .a88 d8'        `8b  88 88     `8888");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("     88      88      `8b     88         d8'          `8b `'Y88888P' d8'          `8b 88 88      `888");
			attroff(COLOR_PAIR(COLOR_RED));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 4, (ncols / 2) - 24);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 24);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 24);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 24);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 24);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 24);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 24);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 24);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 15, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_RED));
			printw("GAME LOST!");
			attroff(COLOR_PAIR(COLOR_RED));
			attron(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) - 5, (ncols / 2) - 46);
			printw("888888888888 88888888ba 8b        d8           db        ,ad8888ba,        db        88 888b      88");
			move((nrows / 2) - 4, (ncols / 2) - 46);
			printw("     88      88      '8b Y8,    ,8P           d88b      d8''    `'8b      d88b       88 8888b     88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88      ,8P  Y8,  ,8P           d8'`8b    d8'               d8'`8b      88 88 `8b    88");
			move((nrows / 2) - 3, (ncols / 2) - 46);
			printw("     88      88aaaaaa8P'   '8aa8'           d8'  `8b   88               d8'  `8b     88 88  `8b   88");
			move((nrows / 2) - 2, (ncols / 2) - 46);
			printw("     88      88''''88'      `88'           d8YaaaaY8b  88      88888   d8YaaaaY8b    88 88   `8b  88");
			move((nrows / 2) - 1, (ncols / 2) - 46);
			printw("     88      88    `8b       88           d8''''''''8b Y8,        88  d8''''''''8b   88 88    `8b 88");
			move((nrows / 2), (ncols / 2) - 46);
			printw("     88      88     `8b      88          d8'        `8b Y8a.    .a88 d8'        `8b  88 88     `8888");
			move((nrows / 2) + 1, (ncols / 2) - 46);
			printw("     88      88      `8b     88         d8'          `8b `'Y88888P' d8'          `8b 88 88      `888");
			attroff(COLOR_PAIR(COLOR_BLUE));
			attron(COLOR_PAIR(COLOR_RED));
			move((nrows / 2) + 4, (ncols / 2) - 24);
			printw("88888888ba        db        ,ad8888ba,  88      a8P");
			move((nrows / 2) + 5, (ncols / 2) - 24);
			printw("88      '8b      d88b      d8''    `'8b 88    ,88'");
			move((nrows / 2) + 6, (ncols / 2) - 24);
			printw("88      ,8P     d8'`8b    d8'           88  ,88'");
			move((nrows / 2) + 7, (ncols / 2) - 24);
			printw("88aaaaaa8P'    d8'  `8b   88            88,d88'");
			move((nrows / 2) + 8, (ncols / 2) - 24);
			printw("88''''''8b,   d8YaaaaY8b  88            8888'88,");
			move((nrows / 2) + 9, (ncols / 2) - 24);
			printw("88      `8b  d8''''''''8b Y8,           88P   Y8b");
			move((nrows / 2) + 10, (ncols / 2) - 24);
			printw("88      a8P d8'        `8b Y8a.    .a8P 88     '88,");
			move((nrows / 2) + 11, (ncols / 2) - 24);
			printw("88888888P' d8'          `8b `'Y8888Y''  88       Y8b");
			attroff(COLOR_PAIR(COLOR_RED));
		}
	}
	else {
		if (st->selection == TRUE) {
			move((nrows / 2) - 5, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_RED));
			printw("GAME LOST!");
			attroff(COLOR_PAIR(COLOR_RED));
			move((nrows / 2), (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_RED));
			printw("Play Again");
			attroff(COLOR_PAIR(COLOR_RED));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_BLUE));
		}
		else if (st->selection == FALSE) {
			move((nrows / 2) - 5, (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_RED));
			printw("GAME LOST!");
			attroff(COLOR_PAIR(COLOR_RED));
			move((nrows / 2), (ncols / 2) - 5);
			attron(COLOR_PAIR(COLOR_BLUE));
			printw("Play Again");
			attroff(COLOR_PAIR(COLOR_BLUE));
			move((nrows / 2) + 1, (ncols / 2) - 6);
			attron(COLOR_PAIR(COLOR_RED));
			printw("Back to Menus");
			attroff(COLOR_PAIR(COLOR_RED));
		}
	}
}