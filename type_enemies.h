#ifndef __type_enemies_H__
#define __type_enemies_H__


 	// Definição para os inimigos e monstros
typedef struct enemy {
 	// Ataque e Hp do inimigo
	int attack, hp;

 	// Coordenadas do inimigo
	int enemyX, enemyY;

 	// 1 - Direita
	// 2 - Cima
	// 3 - Baixo
	// 4 - Esquerda
	int direction;

	// 4 tipos de inimigos
	// 1 - 'r'
	// 2 - 'a'
	// 3 - 'X'
	int type; 

	// variável para guardar o tempo do último ataque.
	time_t lastSwing;

} ENEMY;

#endif