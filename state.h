#ifndef ___STATE_H___
#define ___STATE_H___

#include "type_maps.h"
#include "type_enemies.h"


	// Definição do Jogo e estados
typedef struct state {
	int playerX;
	int playerY;

		// 0 if Easy
		// 1 if medium
		// 2 if Hard
	int dificulty;

		// 0 if Start
		// 1 if Play
		// 2 if Pause
	int menu;

		// If in Start or Pause
		// TRUE if play
		// False if Exit
	bool selection;

	CELL mapaEasy[55][250];
	CELL mapaMid[55][250];
	CELL mapaHard[150][300];
   // Item items[10];
	ENEMY enemy_list[10];

} STATE;

#endif