#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"



    // a76231 - Rui Felipe Sá Fernandes
    //Função para gerar posições aleatórias dos inimigos na dificuldade Easy
void random_Pos_Easy (STATE *st, int x, int y, int i) {
    int aux = 0;

    if (x < 120) {
        if (y < 22) {
            for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x++) {
                if (st->mapaEasy[y][x + 1].is_wall == FALSE) {
                    x ++;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaEasy[y + 1][x].is_wall == FALSE) {
                            y ++;
                            st->enemy_list_Easy[i].enemyX = x;
                            st->enemy_list_Easy[i].enemyY = y;
                            aux = 1;
                        }
                    }
                }
            }
        }
        else {
            for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x++) {
                if (st->mapaEasy[y][x + 1].is_wall == FALSE) {
                    x ++;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y--) {
                        if (st->mapaEasy[y - 1][x].is_wall == FALSE) {
                            y --;
                            st->enemy_list_Easy[i].enemyX = x;
                            st->enemy_list_Easy[i].enemyY = y;
                            aux = 1;
                        }
                    }
                }
            }
        }
    }
    else if (x < 120) {
        if (y < 22) {
            for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x--) {
                if (st->mapaEasy[y][x - 1].is_wall == FALSE) {
                    x --;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaEasy[y + 1][x].is_wall == FALSE) {
                            y ++;
                            st->enemy_list_Easy[i].enemyX = x;
                            st->enemy_list_Easy[i].enemyY = y;
                            aux = 1;
                        }
                    }
                }
            }
        }
        else {
            for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x--) {
                if (st->mapaEasy[y][x - 1].is_wall == FALSE) {
                    x --;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y--) {
                        if (st->mapaEasy[y - 1][x].is_wall == FALSE) {
                            y --;
                            st->enemy_list_Easy[i].enemyX = x;
                            st->enemy_list_Easy[i].enemyY = y;
                            aux = 1;
                        }
                    }
                }
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //Função para gerar posições aleatórias dos inimigos na dificuldade Mid
void random_Pos_Mid (STATE *st, int x, int y, int i) {
    if (st->mapaMid[y][x].is_wall == FALSE) {
        st->enemy_list_Mid[i].enemyX = x;
        st->enemy_list_Mid[i].enemyY = y;
    }
    else {
        for (; (x > 0 && x < 250) && (y > 0 && y < 55); x++, y++) {
            if (st->mapaMid[y][x].is_wall == FALSE) {
                st->enemy_list_Mid[i].enemyX = x;
                st->enemy_list_Mid[i].enemyY = y;
                break;
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //Função para gerar posições aleatórias dos inimigos na dificuldade Hard
void random_Pos_Hard (STATE *st, int x, int y, int i) {
    if (st->mapaHard[y][x].is_wall == FALSE) {
        st->enemy_list_Hard[i].enemyX = x;
        st->enemy_list_Hard[i].enemyY = y;
    }
    else {
        for (; (x > 0 && x < 300) && (y > 0 && y < 150); x++, y++) {
            if (st->mapaHard[y][x].is_wall == FALSE) {
                st->enemy_list_Hard[i].enemyX = x;
                st->enemy_list_Hard[i].enemyY = y;
                break;
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //Função para gerar inimigos
void random_Enemy (STATE *st){
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 20; i++) {

        int x = ((rand() % 50) * (rand() % 50)) / 10;
        int y = ((rand() % 25) * (rand() % 25)) / 10;
       
        random_Pos_Easy (st, x, y, i);
        st->enemy_list_Easy[i].lastSwing = 0;
        st->enemy_list_Easy[i].direction = 1;

        if (i < 12) {
            st->enemy_list_Easy[i].type = 1;
            st->enemy_list_Easy[i].attack = 10;
            st->enemy_list_Easy[i].hp = 50;
        }

        else if (i >= 12 && i < 17) {
            st->enemy_list_Easy[i].type = 2;
            st->enemy_list_Easy[i].attack = 15;
            st->enemy_list_Easy[i].hp = 40;
        }

        else if (i >= 17) {
            st->enemy_list_Easy[i].type = 3;
            st->enemy_list_Easy[i].attack = 30;
            st->enemy_list_Easy[i].hp = 100;
        }
    }

    for (i = 0; i < 40; i++) {

        int x = (rand() % 249) + 1;
        int y = (rand () % 54) + 1;
       
        random_Pos_Mid (st, x, y, i);
        st->enemy_list_Mid[i].lastSwing = 0;
        st->enemy_list_Mid[i].direction = 1;

        if (i < 20) {
            st->enemy_list_Mid[i].type = 1;
            st->enemy_list_Mid[i].attack = 10;
            st->enemy_list_Mid[i].hp = 50;
        }

        else if (i >= 20  && i < 31) {
            st->enemy_list_Mid[i].type = 2;
            st->enemy_list_Mid[i].attack = 15;
            st->enemy_list_Mid[i].hp = 40;
        }

        else if (i > 30) {
            st->enemy_list_Mid[i].type = 3;
            st->enemy_list_Mid[i].attack = 30;
            st->enemy_list_Mid[i].hp = 100;
        }
    }

    for (i = 0; i < 50; i++) {

        int x = (rand() % 299) + 1;
        int y = (rand () % 149) + 1;
       
        random_Pos_Hard (st, x, y, i);
        st->enemy_list_Hard[i].lastSwing = 0;
        st->enemy_list_Hard[i].direction = 1;
        st->enemy_list_Hard[i].type = 3;
        st->enemy_list_Hard[i].attack = 30;
        st->enemy_list_Hard[i].hp = 100;
    }
}



// a101536 - Silverio Mario Samuel
// Funcao para cacar o player
void enemy_hunt(STATE *st, ENEMY *enemy_list, int numEnemies, int ncols, int nrows){
    int playerX = st->playerX + (ncols / 2);
    int playerY = st->playerY + (nrows / 2);
   
    for (int i = 0; i < numEnemies; i++) {  // Loop que vai passar de todos os monstros
        int enemyX = enemy_list[i].enemyX;
        int enemyY = enemy_list[i].enemyY;

        // calculos da distancia do monstro para o player.
        int dx = abs(playerX - enemyX);
        int dy = abs(playerY - enemyY);
               
        if (dy < 9 && dx < 9) {   // Clausula para usar somente os monstros a uma distancia de 9 blocos.
   
            // Funcao que move os monstros.
            if (dy > dx) {
                if (enemyY < playerY)
                    enemyY++;
                else
                    enemyY--;
            }
            else {
                if (enemyX < playerX)
                    enemyX++;
                else
                    enemyX--;
            }
       
            // Funcao que esquiva da parede
            if (st->mapaEasy[enemyY][enemyX].is_wall == TRUE) {
           
                enemyY = enemy_list[i].enemyY;
                enemyX = enemy_list[i].enemyX;

                if (dy < playerY)
                    enemyY++;
                else
                    enemyY--;

                if (dx < playerX)
                    enemyX++;
                else
                    enemyX--;
            }

            // Funcao para caso o inimigo fique preso na parede.
            if (st->mapaEasy[enemyY][enemyX].is_wall == TRUE) {
                if (dy > dx) {
                    if (enemyY > playerY)
                        enemyY++;
                    else
                        enemyY--;
                }
                else {
                    if (enemyX > playerX)
                        enemyX++;
                    else
                        enemyX--;
                }
            }

            if (enemyY <= 1 && enemyX <= 1) {
                st->playerHP -= 1;
            }
            else if (st->mapaEasy[enemyY][enemyX].is_wall == FALSE) {
                enemy_list[i].enemyY = enemyY;
                enemy_list[i].enemyX = enemyX;
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //função para combate nível fácil.
void combat_easy (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

    enemy_hunt(st, st->enemy_list_Easy, st->numEnemies_Easy, ncols, nrows);
   

    for (int i = 0; i < st->numEnemies_Easy; i++) {
        int enemyX = st->enemy_list_Easy[i].enemyX;
        int enemyY = st->enemy_list_Easy[i].enemyY;

        if (st->playerHP <= 0) {
            st->menu = 4;
        }

        else if (st->enemy_list_Easy[i].hp <= 0){
            for (int j = i; j < st->numEnemies_Easy -1; j++) {
                st->enemy_list_Easy[j] = st->enemy_list_Easy[j+1];
            }
            st->numEnemies_Easy--;
            break;
        }

        else {
            if (st->enemy_list_Easy[i].type < 3) {
                if (playerX == enemyX && playerY == enemyY){
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 2) {
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }

                    st->enemy_list_Easy[i].hp -= st->playerAttack;
                }

                if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }
                }
               
                if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }
                }
            }
            else {
                if (playerX == enemyX && playerY == enemyY){
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 3) {
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }

                    st->enemy_list_Easy[i].hp -= st->playerAttack;
                }

                if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 3){
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }
                }
               
                if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                    if (currentTime - st->enemy_list_Easy[i].lastSwing >= 3){
                        st->playerHP -= st->enemy_list_Easy[i].attack;
                        st->enemy_list_Easy[i].lastSwing = currentTime;
                    }
                }
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //função para combate nível médio.
void combat_mid (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

    enemy_hunt(st, st->enemy_list_Mid, st->numEnemies_Mid, ncols, nrows);

    for (int i = 0; i < st->numEnemies_Mid; i++) {
        int enemyX = st->enemy_list_Mid[i].enemyX;
        int enemyY = st->enemy_list_Mid[i].enemyY;

        if (st->playerHP <= 0) {
            st->menu = 4;
        }

        else if (st->enemy_list_Mid[i].hp <= 0){
            for (int j = i; j < st->numEnemies_Mid -1; j++) {
                st->enemy_list_Mid[j] = st->enemy_list_Mid[j+1];
            }
            st->numEnemies_Mid--;
            break;
        }

        else {
            if (st->enemy_list_Mid[i].type < 3) {
                if (playerX == enemyX && playerY == enemyY){
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 2) {
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }

                    st->enemy_list_Mid[i].hp -= st->playerAttack;
                }

                if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }
                }
               
                if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }
                }
            }
            else {
                if (playerX == enemyX && playerY == enemyY){
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 3) {
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }

                    st->enemy_list_Mid[i].hp -= st->playerAttack;
                }

                if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 3){
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }
                }
               
                if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                    if (currentTime - st->enemy_list_Mid[i].lastSwing >= 3){
                        st->playerHP -= st->enemy_list_Mid[i].attack;
                        st->enemy_list_Mid[i].lastSwing = currentTime;
                    }
                }
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //função para combate nível difícil.
void combat_hard (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

    enemy_hunt(st, st->enemy_list_Hard, st->numEnemies_Hard, ncols, nrows);

    for (int i = 0; i < st->numEnemies_Hard; i++) {
        int enemyX = st->enemy_list_Hard[i].enemyX;
        int enemyY = st->enemy_list_Hard[i].enemyY;

        if (st->playerHP <= 0) {
            st->menu = 4;
        }

        else if (st->enemy_list_Hard[i].hp <= 0){
            for (int j = i; j < st->numEnemies_Hard -1; j++) {
                st->enemy_list_Hard[j] = st->enemy_list_Hard[j+1];
            }
            st->numEnemies_Hard--;
            break;
        }

        else {
            if (playerX == enemyX && playerY == enemyY){
                if (currentTime - st->enemy_list_Hard[i].lastSwing >= 3) {
                    st->playerHP -= st->enemy_list_Hard[i].attack;
                    st->enemy_list_Hard[i].lastSwing = currentTime;
                }
                st->enemy_list_Hard[i].hp -= st->playerAttack;
            }

            if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                if (currentTime - st->enemy_list_Hard[i].lastSwing >= 3){
                    st->playerHP -= st->enemy_list_Hard[i].attack;
                    st->enemy_list_Hard[i].lastSwing = currentTime;
                }
            }
           
            if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                if (currentTime - st->enemy_list_Hard[i].lastSwing >= 3){
                    st->playerHP -= st->enemy_list_Hard[i].attack;
                    st->enemy_list_Hard[i].lastSwing = currentTime;
                }
            }
        }
    }
}



    // a76231 - Rui Felipe Sá Fernandes
    //Funções para desenhar os inimigos.
void draw_enemy (ENEMY enemy, int x, int y, int dif){
    if (dif < 3) {
        attron(COLOR_PAIR(COLOR_RED));
        if (enemy.type == 1)
            mvaddch(y, x, 'r' | A_BOLD);
        else if (enemy.type == 2)
            mvaddch(y, x, 'a' | A_BOLD);
        else if (enemy.type == 3)
            mvaddch(y, x, 'X' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }

    else {
        attron(COLOR_PAIR(COLOR_CYAN));
        if (enemy.type == 1) {
            mvaddch(y, x, 'r' | A_BOLD);
        }
        else if (enemy.type == 2) {
            mvaddch(y, x, 'a' | A_BOLD);
        }
        else if (enemy.type == 3) {
            mvaddch(y, x, 'X' | A_BOLD);
        }
        attroff(COLOR_PAIR(COLOR_CYAN));
    }
}