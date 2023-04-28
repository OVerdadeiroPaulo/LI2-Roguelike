#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"



	// Função que gera um mapa aleatorio
void random_map(STATE *s, int nCols, int nRows) {
	int i, j;

		// gerando mapa inicial
	for (i = 0; i < nCols; i++) {
		for (j = 0; j < nRows; j ++) {
		// Local das paredes
			if (i == 0 || i == nCols - 1 || j == 0 || j == nRows - 1) {
				s->mapaEasy[i][j].is_wall = TRUE;
				s->mapaEasy[i][j].was_seen = FALSE;
				s->mapaEasy[i][j].is_grass = FALSE;
				s->mapaEasy[i][j].is_water = FALSE;
			}
		// Local dos Rios
			else if ((i-60)*(i-60) + (j-15)*(j-15) <= 100) {
				s->mapaEasy[i][j].is_wall = FALSE;
				s->mapaEasy[i][j].was_seen = FALSE;
				s->mapaEasy[i][j].is_grass = FALSE;
				s->mapaEasy[i][j].is_water = TRUE;
			}
		// Local das Relvas
			else if (((i > 1 && j > 1) && (i < 20 && j < 45))) {
				s->mapaEasy[i][j].is_wall = FALSE;
				s->mapaEasy[i][j].was_seen = FALSE;
				s->mapaEasy[i][j].is_grass = TRUE;
				s->mapaEasy[i][j].is_water = FALSE;
			}
		// Espaços vazios
			else {
				s->mapaEasy[i][j].is_wall = FALSE;
				s->mapaEasy[i][j].was_seen = FALSE;
				s->mapaEasy[i][j].is_grass = FALSE;
				s->mapaEasy[i][j].is_water = FALSE;
			}
	 	}
	}
}



 	// Função que inicia os inimigos em posições aleatórias
void random_Enemy(STATE *s) {
	int i;

			// Posições Iniciais dos Inimigos
	for (i = 0; i < 5; i++){
		s->enemy_list[i].enemyX = 50;
		s->enemy_list[i].enemyY = 25;
		s->enemy_list[i].is_Following = FALSE;
		s->enemy_list[i].just_Walking = TRUE;
		s->enemy_list[i].attack = FALSE;
	}
}



 	// Dado uma coordenada identifica se existe inimigos
// int exist_Enemy( ) {

// }



	// Inicialização do mapa e Jogador
void gerar(STATE *s, int nCols, int nRows) {
		// Colocando o Jogador no meio do mapa
	s->playerX = nCols / 2;
	s->playerY = nRows / 2;

	random_Enemy(s);
	random_map(s, nCols, nRows);
}