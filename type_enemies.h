#ifndef __type_enemies_H__
#define __type_enemies_H__


 	// Definição para os inimigos e monstros
typedef struct enemy { //struct do inimigo
    int hp, attack;
    int enemyX;
    int enemyY;
    int type;
    int direction;

    bool is_Following;
    bool just_Walking;
    bool attack;
    char visual;
} ENEMY;
#endif