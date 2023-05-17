#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"

    //Função para checkar se terreno é valido para gerar inimigo.
int relva_check (STATE *st, int y, int x){
    if (st->mapaEasy[y][x].is_grass == TRUE && st->mapaEasy[y][x].is_wall == FALSE && 
        st->mapaEasy[y][x].is_water == FALSE && st->mapaEasy[y][x].is_mud == FALSE && 
        st->mapaEasy[y][x].is_stairs == FALSE) 
            return 1;
    return 0;
}

    //Função para gerar posições aleatórias dos inimigos.
void random_Enemy (STATE *st){
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < 10; i++) {

        int x = rand() % 250;
        int y = rand() % 55;
        
        if (i < 8) {
            int aux = 0;

            if (x < 125 && y < 20)
                for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x++) {
                    if (st->mapaEasy[y][x + 1].is_wall == FALSE) {
                        x ++;
                        aux = 1;
                    }
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaEasy[y + 1][x].is_wall == FALSE) {
                            y ++;
                            aux = 1;
                        }
                    };
                }
            else
                for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; x--) {
                    if (st->mapaEasy[y][x - 1].is_wall == FALSE) {
                        x --;
                        aux = 1;
                    }
                    for ( ; st->mapaEasy[y][x].is_wall == TRUE && aux == 0; y++) {
                        if (st->mapaEasy[y - 1][x].is_wall == FALSE) {
                            y --;
                            aux = 1;
                        }
                    };
                }


            st->enemy_list[i].enemyX = x;
            st->enemy_list[i].enemyY = y;
            st->enemy_list[i].direction = 1;

            st->enemy_list[i].is_Following = FALSE;
            st->enemy_list[i].just_Walking = FALSE;
            st->enemy_list[i].can_attack = FALSE;

            if (i < 4) {
                st->enemy_list[i].type = 1;
                st->enemy_list[i].attack = 10;
                st->enemy_list[i].hp = 50;
            }

            else if (i >= 4 && i < 7) {
                st->enemy_list[i].type = 2;
                st->enemy_list[i].attack = 20;
                st->enemy_list[i].hp = 40;
            }

            else if (i == 7 || i == 8) {
                st->enemy_list[i].type = 3;
                st->enemy_list[i].attack = 30;
                st->enemy_list[i].hp = 100;
            }
        }

        // else {
        //     int x, y = i;

        //     for (x = i; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
        //         for ( ; st->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
        //     }

        //     st->enemy_list[0].enemyX = x + (ncols / 2);
        //     st->enemy_list[0].enemyY = y + (nrows / 2);
        //     st->enemy_list[i].direction = 1;

        //     st->enemy_list[i].is_Following = FALSE;
        //     st->enemy_list[i].just_Walking = TRUE;
        //     st->enemy_list[i].can_attack = FALSE;

        //     st->enemy_list[i].type = 4;
        //     st->enemy_list[i].attack = 50;
        //     st->enemy_list[i].hp = 200;
        // }
    }
}

    // Função que define o caminho do inimigo sem direção
// void walk_unactive (STATE *st, int ind, int ncols) {
    
//     // if (st->enemy_list[ind].type != 4){
//     //     int x = st->enemy_list[ind].enemyX;
//     //     int y = st->enemy_list[ind].enemyY;
//     //     int direction = st->enemy_list[ind].direction;

//     //     if (direction == 1 && x+1 < ncols && terreno_check (st, y, x+1)){
//     //         st->enemy_list[ind].enemyX++;
//     //         st->enemy_list[ind].direction++;  
//     //     }
//     //     else if (direction == -1 && x-1 > 0 && terreno_check(st, y, x-1)){
//     //         st->enemy_list[ind].enemyX--;
//     //     }
//     //     st->enemy_list[ind].direction *= -1;
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
//         int dx = st->enemy_list[i].enemyX - (st->playerX + playerOffsetX);
//         int dy = st->enemy_list[i].enemyY - (st->playerY + playerOffsetY);
//         int distance = sqrt (dx * dx + dy * dy);

        
//         if (distance < raio) {
//             st->enemy_list[i].just_Walking = FALSE;
//             st->enemy_list[i].is_Following = TRUE;
//         }
//         else {
//             walk_unactive (st, i, ncols);
//         }
//     }
// }