#ifndef ___STATE_H___
#define ___STATE_H___

#include <time.h>

#include "type_maps.h"
#include "type_items.h"


	// Definição do Jogo e estados
typedef struct state {
 	// Coordenadas do Jogador
	int playerX, playerY;

 	// Ataque e Hp do Jogador
	int playerHP, playerAttack;

		// 1 if Easy
		// 2 if medium
		// 3 if Hard
	int dificulty;

		// 0 if Start
		// 1 if Play
		// 2 if Pause
		// 3 GameWon
		// 4 GameOver
	int menu;

		// Tempo Inicial
	time_t timeStart;
	time_t timeCurrent;

		// If in Start or Pause
		// TRUE if play
		// False if Exit
	bool selection;

	CELL mapaEasy[55][250];
	CELL mapaMid[55][250];
	CELL mapaHard[150][300];


	ENEMY enemy_list_Easy[20];
	ENEMY enemy_list_Mid[30];
	ENEMY enemy_list_Hard[50];

	
	Item items_list_easy [10];
	Item items_list_Mid [10];

	
	int numEnemies_Easy;
	int numEnemies_Mid;
	int numEnemies_Hard;

} STATE;

#endif