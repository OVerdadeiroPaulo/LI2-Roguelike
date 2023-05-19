#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"

    //Função para checkar se terreno é valido para gerar inimigo.
int relva_check (STATE *st, int y, int x){
    if (st->mapaEasy[y][x].is_grass == TRUE && st->mapaEasy[y][x].is_wall == FALSE && 
        st->mapaEasy[y][x].is_water == FALSE && 
        st->mapaEasy[y][x].is_stairs == FALSE) 
            return 1;
    return 0;
}


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




void random_Pos_Mid (STATE *st, int x, int y, int i) {
    int aux = 0;

    if (x < 120) {
        if (y < 22) {
            for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; x++) {
                if (st->mapaMid[y][x + 1].is_wall == FALSE) {
                    x ++;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaMid[y + 1][x].is_wall == FALSE) {
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
            for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; x++) {
                if (st->mapaMid[y][x + 1].is_wall == FALSE) {
                    x ++;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; y--) {
                        if (st->mapaMid[y - 1][x].is_wall == FALSE) {
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
            for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; x--) {
                if (st->mapaMid[y][x - 1].is_wall == FALSE) {
                    x --;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaMid[y + 1][x].is_wall == FALSE) {
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
            for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; x--) {
                if (st->mapaMid[y][x - 1].is_wall == FALSE) {
                    x --;
                    st->enemy_list_Easy[i].enemyX = x;
                    st->enemy_list_Easy[i].enemyY = y;
                    aux = 1;
                }
                else {
                    for ( ; st->mapaMid[y][x].is_wall == TRUE && aux == 0; y--) {
                        if (st->mapaMid[y - 1][x].is_wall == FALSE) {
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



    //Função para gerar posições aleatórias dos inimigos.
void random_Enemy (STATE *st){
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 20; i++) {

        int x = ((rand() % 50) * (rand() % 50)) / 10;
        int y = ((rand() % 25) * (rand() % 25)) / 10;
        
        random_Pos_Easy (st, x, y, i);
        st->enemy_list_Easy[i].lastSwing = 0;
        st->enemy_list_Easy[i].direction = 1;
        st->enemy_list_Easy[i].is_Following = FALSE;
        st->enemy_list_Easy[i].just_Walking = FALSE;
        st->enemy_list_Easy[i].can_attack = FALSE;

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

    for (i = 0; i < 30; i++) {

        int x = ((rand() % 50) * (rand() % 50)) / 10;
        int y = ((rand() % 25) * (rand() % 25)) / 10;
        
        if (i < 25) {
            random_Pos_Mid (st, x, y, i);
            st->enemy_list_Mid[i].lastSwing = 0;
            st->enemy_list_Mid[i].direction = 1;
            st->enemy_list_Mid[i].is_Following = FALSE;
            st->enemy_list_Mid[i].just_Walking = FALSE;
            st->enemy_list_Mid[i].can_attack = FALSE;

            if (i < 20) {
                st->enemy_list_Mid[i].type = 1;
                st->enemy_list_Mid[i].attack = 10;
                st->enemy_list_Mid[i].hp = 50;
            }

            else if (i >= 20 && i < 23) {
                st->enemy_list_Mid[i].type = 2;
                st->enemy_list_Mid[i].attack = 15;
                st->enemy_list_Mid[i].hp = 40;
            }

            else if (i > 23) {
                st->enemy_list_Mid[i].type = 3;
                st->enemy_list_Mid[i].attack = 30;
                st->enemy_list_Mid[i].hp = 100;
            }
        }

        // else {
        //     int x, y = i;

        //     for (x = i; st->mapaMid[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
        //         for ( ; st->mapaMid[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
        //     }

        //     st->enemy_list_Mid[0].enemyX = x + (ncols / 2);
        //     st->enemy_list_Mid[0].enemyY = y + (nrows / 2);
        //     st->enemy_list_Mid[i].direction = 1;

        //     st->enemy_list_Mid[i].is_Following = FALSE;
        //     st->enemy_list_Mid[i].just_Walking = TRUE;
        //     st->enemy_list_Mid[i].can_attack = FALSE;

        //     st->enemy_list_Mid[i].type = 4;
        //     st->enemy_list_Mid[i].attack = 50;
        //     st->enemy_list_Mid[i].hp = 200;
        // }
    }
}

    // Função que define o caminho do inimigo sem direção
// void walk_unactive (STATE *st, int ind, int ncols) {
    
//     if (st->enemy_list_Easy[ind].type != 4){
//         int x = st->enemy_list_Easy[ind].enemyX;
//         int y = st->enemy_list_Easy[ind].enemyY;
//         int direction = st->enemy_list_Easy[ind].direction;

//         if (direction == 1 && x+1 < ncols && terreno_check (st, y, x+1)){
//             st->enemy_list_Easy[ind].enemyX++;
//             st->enemy_list_Easy[ind].direction++;  
//         }
//         else if (direction == -1 && x-1 > 0 && terreno_check(st, y, x-1)){
//             st->enemy_list_Easy[ind].enemyX--;
//         }
//         st->enemy_list_Easy[ind].direction *= -1;
//     }
// }



    // Função que define o caminho do inimigo atrás do jogador
/*void walk_active () {
    
}*/

    //Funções para desenhar os inimigos.
void draw_enemy (ENEMY enemy, int x, int y){
    if (enemy.type == 1) {
        attron(COLOR_PAIR(COLOR_RED));
        mvaddch(y, x, 'r' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }
    else if (enemy.type == 2) {
        attron(COLOR_PAIR(COLOR_RED));
        mvaddch(y, x, 'a' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }
    else if (enemy.type == 3) {
        attron(COLOR_PAIR(COLOR_RED));
        mvaddch(y, x, 'X' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }
    else if (enemy.type == 4) {
        attron(COLOR_PAIR(COLOR_RED));
        mvaddch(y, x, 'G' | A_BOLD);
        attroff(COLOR_PAIR(COLOR_RED));
    }
}

// void update_enemies (STATE *st, int ncols, int nrows, int raio) {
//     int playerOffsetX = ncols/2;
//     int playerOffsetY = nrows/2;

//     for (int i = 0; i < 10; i++) {
//         int dx = st->enemy_list_Easy[i].enemyX - (st->playerX + playerOffsetX);
//         int dy = st->enemy_list_Easy[i].enemyY - (st->playerY + playerOffsetY);
//         int distance = sqrt (dx * dx + dy * dy);

        
//         if (distance < raio) {
//             st->enemy_list_Easy[i].just_Walking = FALSE;
//             st->enemy_list_Easy[i].is_Following = TRUE;
//         }
//         else {
//             walk_unactive (st, i, ncols);
//         }
//     }
// }

    //função que limpa vida do hp para atualização.
void atualiza_hp (void) {
    attron (COLOR_PAIR(COLOR_RED));
        move (2,3);
        clrtoeol ();
    attroff(COLOR_PAIR(COLOR_RED));
}

    //função para combate nível fácil.
void combat_easy (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

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

    //função para combate nível médio.
void combat_mid (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

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

    //função para combate nível difícil.
void combat_hard (STATE *st, int ncols, int nrows){
    int playerX = (ncols/2) + st->playerX;
    int playerY = (nrows/2) + st->playerY;

    time_t currentTime = time(NULL);

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
            if (st->enemy_list_Hard[i].type < 3) {
                if (playerX == enemyX && playerY == enemyY){
                    if (currentTime - st->enemy_list_Hard[i].lastSwing >= 2) {
                        st->playerHP -= st->enemy_list_Hard[i].attack;
                        st->enemy_list_Hard[i].lastSwing = currentTime;
                    }

                    st->enemy_list_Hard[i].hp -= st->playerAttack;
                }

                if (playerY == enemyY && (playerX + 1 == enemyX || playerX == enemyX - 1)) {
                    if (currentTime - st->enemy_list_Hard[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Hard[i].attack;
                        st->enemy_list_Hard[i].lastSwing = currentTime;
                    }
                }
                
                if (playerX == enemyX && (playerY + 1 == enemyY || playerY - 1 == enemyY)) {
                    if (currentTime - st->enemy_list_Hard[i].lastSwing >= 2){
                        st->playerHP -= st->enemy_list_Hard[i].attack;
                        st->enemy_list_Hard[i].lastSwing = currentTime;
                    }
                }
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
}