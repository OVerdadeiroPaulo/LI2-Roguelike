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

	attron(COLOR_PAIR(COLOR_BLUE));
	// Coordenadas
		move(nrows - 2, 5);
		printw("(%d, %d) %d %d", st->playerX, st->playerY, ncols, nrows);
	attroff(COLOR_PAIR(COLOR_BLUE));

	// Vida doJogador
	atualiza_hp();
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
	for (i = 0; i < 30; i++) {
		if (st->enemy_list_Mid[i].enemyX == x + st->playerX && st->enemy_list_Mid[i].enemyY == y + st->playerY)
			enemy_Mid = i + 1;
	}
	// for (i = 0; i < 30; i++) {
	// 	if (st->enemy_list_Ha[i].enemyX == x + st->playerX && st->enemy_list_Ha[i].enemyY == y + st->playerY)
	// 		enemy_Hard = i + 1;
	// }

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
			draw_enemy (st->enemy_list_Easy[enemy_easy - 1], x, y);
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
			draw_enemy (st->enemy_list_Mid[enemy_Mid - 1], x, y);
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
			draw_enemy (st->enemy_list_Easy[enemy_easy - 1], x, y);
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



void draw_GameWon (STATE *st, int ncols, int nrows) {
	clear();

	move (nrows / 2 - 5, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Game Won!");
		attroff(COLOR_PAIR(COLOR_BLUE));


	if (st->selection == TRUE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Play Again");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
	else if (st->selection == FALSE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Back to menu");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
}



void draw_GameOver (STATE *st, int ncols, int nrows) {
	clear();

	move (nrows / 2 - 5, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("You Lose :(");
		attroff(COLOR_PAIR(COLOR_BLUE));


	if (st->selection == TRUE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Play Again");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
	else if (st->selection == FALSE) {
		move(nrows / 2, ncols / 2);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("Back to menu");
		attroff(COLOR_PAIR(COLOR_BLUE));
	}
}