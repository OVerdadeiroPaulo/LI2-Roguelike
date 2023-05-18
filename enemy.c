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
    else {
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
    else {
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

        int x = (rand() % 12) * i;
        int y = (rand() % 22) * (i / 10);

        random_Pos_Easy (st, x, y, i);
        st->enemy_list_Easy[i].direction = ((x * i) % 4) + 1;
        st->enemy_list_Easy[i].is_Following = FALSE;
        st->enemy_list_Easy[i].just_Walking = TRUE;
        st->enemy_list_Easy[i].can_attack = FALSE;

        if (i < 12) {
            st->enemy_list_Easy[i].type = 1;
            st->enemy_list_Easy[i].attack = 10;
            st->enemy_list_Easy[i].hp = 50;
        }

        else if (i >= 12 && i < 17) {
            st->enemy_list_Easy[i].type = 2;
            st->enemy_list_Easy[i].attack = 20;
            st->enemy_list_Easy[i].hp = 40;
        }

        else if (i >= 17) {
            st->enemy_list_Easy[i].type = 3;
            st->enemy_list_Easy[i].attack = 30;
            st->enemy_list_Easy[i].hp = 100;
        }
    }

    for (i = 0; i < 30; i++) {

        int x = rand() % 250;
        int y = rand() % 55;

        if (i < 25) {
            random_Pos_Mid (st, x, y, i);
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
                st->enemy_list_Mid[i].attack = 20;
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
void walk_unactive (STATE *st, int ind) {

    int x = st->enemy_list_Easy[ind].enemyX;
    int y = st->enemy_list_Easy[ind].enemyY;
    int direc = st->enemy_list_Easy[ind].direction;

    if (direc == 1) {
        if (st->mapaEasy[y][x + 1].is_wall == FALSE) {
            st->enemy_list_Easy[ind].enemyX ++;
        }
        else {
            st->enemy_list_Easy[ind].direction = 2;
        }
    }
    else if (direc == 2) {
        if (st->mapaEasy[y + 1][x].is_wall == FALSE) {
            st->enemy_list_Easy[ind].enemyY ++;
        }
        else {
            st->enemy_list_Easy[ind].direction = 3;
        }
    }
    else if (direc == 3) {
        if (st->mapaEasy[y - 1][x].is_wall == FALSE) {
            st->enemy_list_Easy[ind].enemyY --;
        }
        else {
            st->enemy_list_Easy[ind].direction = 4;
        }
    }
    else if (direc == 4) {
        if (st->mapaEasy[y][x - 1].is_wall == FALSE) {
            st->enemy_list_Easy[ind].enemyX --;
        }
        else {
            st->enemy_list_Easy[ind].direction = 1;
        }
    }

    // st->enemy_list_Easy[ind].enemyX ++;
}



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



void update_enemies (STATE *st) {
    time (&(st->timeCurrent));

    if (st->dificulty == 1) {
        if (st->timeCurrent % 5 == 3) {
            for (int i = 0; i < 20; i++) {
                walk_unactive (st, i);
            }
        }
    }
}