#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "enemy.c"
#include "items.c"

#define HEIGHT_dungeon 55
#define WIDTH_dungeon 250
#define HEIGHT_room 55
#define WIDTH_room 250
#define HEIGHT_dungeon_Hard 150
#define WIDTH_dungeon_Hard 300


	// aXXXXXX - Silvério Mário
    // Funcao que inicializa todo o array para criar grutas.
void Initialize_dungeon_Mid(STATE *s) {
   
    for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
               
                s->mapaMid[i][j].is_wall = FALSE;
                s->mapaMid[i][j].is_grass = FALSE;
                s->mapaMid[i][j].is_water = FALSE;
                s->mapaMid[i][j].is_stairs = FALSE;
                s->mapaMid[i][j].is_mud = FALSE;

            if (i == 0 || i == HEIGHT_dungeon - 5 || j == 0 || j == WIDTH_dungeon - 5) {
                s->mapaMid[i][j].is_wall = TRUE;

               }
            else {
               
                if (rand() % 100 < 45){
                   s->mapaMid[i][j].is_wall = TRUE;
                   }
                    else{
                        s->mapaMid[i][j].is_wall = FALSE;
                         }
                }
        }
    }
}



	// aXXXXXX - Silvério Mário
    // Funcao que inicializa os Terrenos de Rio e Relva
void Build_rios_relva(STATE *s,int i, int j, int size_rel, int size_rel_max, int altura_rel, int altura_rel_max, int center_rel_x, int center_rel_y, int radius, int center_rel_x_2, int center_rel_y_2, int radius_2, int size_rio ,int size_rio_max ,int altura_rio ,int altura_rio_max , int size_rio_1, int size_rio_max_1, int altura_rio_1, int altura_rio_max_1,int center_rio_x ,int center_rio_y ,int radius_rio){

 

      if (j > size_rel && j < size_rel + size_rel_max  && i > altura_rel && i < altura_rel + altura_rel_max){   // clausula para colocar paredes ao redor da gruta, para nao criar uma gruta infinita.
                          
              if (s->mapaMid [i][j].is_wall != TRUE) s->mapaMid[i][j].is_grass = TRUE;
           }
    
            int distance_x = abs(j - center_rel_x);  // Calculos da distancia horizontal para o centro.
            int distance_y = abs(i - center_rel_y);  // Calculos da distancia vertical para o centro.
            
            double distance = sqrt(distance_x * distance_x + distance_y * distance_y);  // Clausula para calcular a distancia euclidiana
            if (distance <= radius) {  // clausula para checar se a distancia esta dentro do raio.
                if (s->mapaMid[i][j].is_wall != TRUE) {
                    s->mapaMid[i][j].is_grass = TRUE;
                }
            }
            
              int distance_x_2 = abs(j - center_rel_x_2);  // Calculos da distancia horizontal para o centro.
            int distance_y_2 = abs(i - center_rel_y_2);  // Calculos da distancia vertical para o centro.
            
            double distance_2 = sqrt(distance_x_2 * distance_x_2 + distance_y_2 * distance_y_2);  // Clausula para calcular a distancia euclidiana
            if (distance_2 <= radius_2) {  // clausula para checar se a distancia esta dentro do raio.
                if (s->mapaMid[i][j].is_wall != TRUE) {
                    s->mapaMid[i][j].is_grass = TRUE;
                }
            }

           // geracao de rios 

            if (j > size_rio && j < size_rio + size_rio_max  && i > altura_rio && i < altura_rio + altura_rio_max){   // clausula para colocar paredes ao redor da gruta, para nao criar uma gruta infinita.
                     
              if (s->mapaMid [i][j].is_wall != TRUE) {

                 s->mapaMid[i][j].is_grass = FALSE;
                 s->mapaMid[i][j].is_water = TRUE;
              }
           }
           
           if (j > size_rio_1 && j < size_rio_1 + size_rio_max_1  && i > altura_rio_1 && i < altura_rio_1 + altura_rio_max_1){   // clausula para colocar paredes ao redor da gruta, para nao criar uma gruta infinita.
                     
              if (s->mapaMid [i][j].is_wall != TRUE){
                 s->mapaMid[i][j].is_grass = FALSE;
                 s->mapaMid[i][j].is_water = TRUE;
              }
           }

            int distance_x_rio = abs(j - center_rio_x);  // Calculos da distancia horizontal para o centro.
            int distance_y_rio = abs(i - center_rio_y);  // Calculos da distancia vertical para o centro.
            
            double distance_rio = sqrt(distance_x_rio * distance_x_rio + distance_y_rio * distance_y_rio);  // Clausula para calcular a distancia euclidiana
            if (distance_rio <= radius_rio) {  // clausula para checar se a distancia esta dentro do raio.
                if (s->mapaMid[i][j].is_wall != TRUE) {
                    s->mapaMid[i][j].is_grass = FALSE;
                    s->mapaMid[i][j].is_water = TRUE;

                }
            }


}



	// aXXXXXX - Silvério Mário
    // Funcao que pega no array inicializado e controi as grutas.
void Build_dungeon_Mid(STATE *s) {
    int n_walls;
    int dungeon_dataMID [HEIGHT_dungeon][WIDTH_dungeon];

    for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
            n_walls = 0;

            // Clausulas para contar o numero de paredes vizinhas.
            if (j > 0 && j < WIDTH_dungeon-1 && i > 0 && i < HEIGHT_dungeon-1){    // clausula para garantir que a funcao nao procura paredes fora do array.
               
               if (s->mapaMid [i - 1][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i - 1][j].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i - 1][j + 1].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i][j + 1].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i + 1][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i + 1][j].is_wall == TRUE) n_walls++;
               if (s->mapaMid[i + 1][j + 1].is_wall == TRUE) n_walls++;
            }
            
            // Clausula para escolher o conteudo de cada celula.
            if (s->mapaMid[i][j].is_wall == TRUE) {
                 if (n_walls >= 6){    // numeros de probabilidades maiores para garantir construcao do deserto.
                    dungeon_dataMID [i][j] = TRUE;
                    }
                 else{
                    dungeon_dataMID [i][j] = FALSE;
                    }
            }
                else {
                    if (n_walls >= 8){
                       dungeon_dataMID [i][j] = TRUE;
                       }
                    else {
                       dungeon_dataMID [i][j] = FALSE;
                       }
                   }
        }
    }
 int size_rel, size_rel_max, altura_rel, altura_rel_max, center_rel_x, center_rel_y, radius, center_rel_x_2, center_rel_y_2, radius_2;
 int size_rio_1, size_rio_max_1, altura_rio_1, altura_rio_max_1, size_rio ,size_rio_max ,altura_rio ,altura_rio_max, center_rio_x, center_rio_y, radius_rio;

//variaveis para relvas circulares e retangulares
size_rel = rand() % 50 + 6;
size_rel_max = rand() % 50 + 6;
altura_rel = rand() % 20 + 15;
altura_rel_max = rand() % 10 + 6;

center_rel_x = rand () % 100 + 100;
center_rel_y = rand () % 40 + 5;
radius = rand() %10 +5;

center_rel_x_2 = rand () % 100 + 50;
center_rel_y_2 = rand () % 10 + 30;
radius_2 = rand() % 5 + 5;

// variaveis para rios retangulares e circulares
size_rio = rand() % 20 + 6;
size_rio_max = rand() % 40 + 10;
altura_rio = rand() % 5 + 5 ;
altura_rio_max = rand() % 8 + 6;

size_rio_1 = rand() % 50 + 100;
size_rio_max_1 = rand() % 20 + 10;
altura_rio_1 = rand() % 20 + 6;
altura_rio_max_1 = rand() % 9 + 6;

center_rio_x = rand () % 100 + 100;
center_rio_y = rand () % 10 + 10;
radius_rio = rand() % 5 + 5;


    // clausula para copiar para o array novo mapa.
   for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
           if (j == 0 || j == WIDTH_dungeon-1 || i == 0 || i == HEIGHT_dungeon-1){   // clausula para colocar paredes ao redor da gruta, para nao criar uma gruta infinita.
            s->mapaMid [i][j].is_wall = TRUE;
           }

           else{
               
                s->mapaMid [i][j].is_wall = dungeon_dataMID [i][j];    

                Build_rios_relva(s, i, j, size_rel, size_rel_max, altura_rel, altura_rel_max, center_rel_x, center_rel_y, radius, center_rel_x_2, center_rel_y_2, radius_2, size_rio, size_rio_max, altura_rio,altura_rio_max, size_rio_1,size_rio_max_1,altura_rio_1,altura_rio_max_1,center_rio_x,center_rio_y,radius_rio);
             

           }
        }
    }

           // criacao de escadas.
    for (int j = 0; j < 3; j++){
        int stairs_y_Mid, stairs_x_Mid;
            do {
                stairs_y_Mid = rand() % HEIGHT_dungeon;
                stairs_x_Mid = rand() % WIDTH_dungeon;
           }
            while (s->mapaMid[stairs_y_Mid] [stairs_x_Mid].is_wall != FALSE);

            s->mapaMid [stairs_y_Mid] [stairs_x_Mid].is_stairs = TRUE;
    }
}



	// aXXXXXX - Silvério Mário
    // Funcao que inicializa todo o array para criar grutas hard, grutas mais apertadas.
void Initialize_dungeon_Hard(STATE *s) {
   
    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
               
                s->mapaHard[i][j].is_wall = FALSE;
                s->mapaHard[i][j].is_grass = FALSE;
                s->mapaHard[i][j].is_water = FALSE;
                s->mapaHard[i][j].is_stairs = FALSE;
                s->mapaHard[i][j].is_mud = FALSE;

            if (i == 0 || i == HEIGHT_dungeon_Hard - 1 || j == 0 || j == WIDTH_dungeon_Hard - 1) {
                s->mapaHard[i][j].is_wall = TRUE;

               }
            else {
               
                if (rand() % 100 < 45){
                   s->mapaHard[i][j].is_wall = TRUE;
                   }
                    else{
                        s->mapaHard[i][j].is_wall = FALSE;
                         }
                }
        }
    }
}



	// aXXXXXX - Silvério Mário
    // Funcao que inicializa os terrenso de Mud
void Build_Mud(STATE *s, int i, int j, int center_mud_x, int center_mud_y, int radius_mud){  // Funcao que controi uma poca de lama no centro da caverna com tamanho aleatorio.

            int distance_x_mud = abs(j - center_mud_x);  // Calculos da distancia horizontal para o centro.
            int distance_y_mud = abs(i - center_mud_y);  // Calculos da distancia vertical para o centro.
            
            double distance_rio = sqrt(distance_x_mud * distance_x_mud + distance_y_mud * distance_y_mud);  // Clausula para calcular a distancia euclidiana
            if (distance_rio <= radius_mud) {  // clausula para checar se a distancia esta dentro do raio.
                
                if (s->mapaHard[i][j].is_wall != TRUE) {
                    s->mapaHard[i][j].is_grass = FALSE;
                    s->mapaHard[i][j].is_mud = TRUE;

                }
            }

    return; 
}



	// aXXXXXX - Silvério Mário
    // Funcao que pega no array inicializado e controi as grutas.
void Build_dungeon_Hard(STATE *s) {
    int n_walls;
    int dungeon_data [HEIGHT_dungeon_Hard][WIDTH_dungeon_Hard];

    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
            n_walls = 0;

            // Clausulas para contar o numero de paredes vizinhas.
            if (i > 0 && i < HEIGHT_dungeon_Hard - 1 && j > 0 && j < WIDTH_dungeon_Hard - 1){   // clausula feita para nao procurar paredes fora do array e produzir o erro out of bounds.
            
               if (s->mapaHard [i - 1][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i - 1][j].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i - 1][j + 1].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i][j + 1].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i + 1][j - 1].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i + 1][j].is_wall == TRUE) n_walls++;
               if (s->mapaHard[i + 1][j + 1].is_wall == TRUE) n_walls++;
            }
            // Clausula para escolher o conteudo de cada celula.
            if (s->mapaHard[i][j].is_wall == TRUE) {
                 if (n_walls >= 4){   // numeros de probabilidade de paredes mais baixos para criar grutas mais fechadas.
                    dungeon_data [i][j] = TRUE;
                    }
                 else{
                    dungeon_data [i][j] = FALSE;
                    }
            }
                else {
                    if (n_walls >= 5){   // numeros de probabilidade de paredes mais baixos para criar grutas mais fechadas.
                       dungeon_data [i][j] = TRUE;
                       }
                    else {
                       dungeon_data [i][j] = FALSE;
                       }
                   }
        }
    }

int center_mud_x ,center_mud_y ,radius_mud;

center_mud_x = WIDTH_dungeon_Hard/2;
center_mud_y = HEIGHT_dungeon_Hard/2;
radius_mud = rand() % 30 + 10;

    // clausula para copiar para o array novo mapa.
    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
            s->mapaHard [i][j].is_wall = dungeon_data [i][j];

            Build_Mud(s ,i, j, center_mud_x, center_mud_y, radius_mud);  

        }
    }

           // criacao de escadas.
    for (int j = 0; j < 3; j++){
        int stairs_y_Hard, stairs_x_Hard;
            do {
                stairs_y_Hard = rand() % HEIGHT_dungeon_Hard;
                stairs_x_Hard = rand() % WIDTH_dungeon_Hard;
           }
            while (s->mapaHard[stairs_y_Hard] [stairs_x_Hard].is_wall != FALSE);

            s->mapaHard [stairs_y_Hard] [stairs_x_Hard].is_stairs = TRUE;

    }
}



	// aXXXXXX - Silvério Mário
    // Funcao que inicializa o array para com tudo walls para comecar a contruir os mapas.
void Initialize_rooms(STATE *s){
     for(int y = 0; y < HEIGHT_room; y++){
        for(int x = 0; x < WIDTH_room; x++){
               
            s->mapaEasy[y][x].is_wall = FALSE;
            s->mapaEasy[y][x].is_grass = FALSE;
            s->mapaEasy[y][x].is_water = FALSE;
            s->mapaEasy[y][x].is_stairs = FALSE;  
            s->mapaEasy[y][x].is_mud = FALSE;
           
            if (x == WIDTH_room - 1 || x == 0){
               
                s -> mapaEasy [y] [x].is_wall = TRUE;
            }  
            else if (y == HEIGHT_room - 1 || y == 0) {  
                s -> mapaEasy [y] [x].is_wall = TRUE;
            }
           
               else {
                  s -> mapaEasy [y] [x].is_wall = TRUE;
                  }
        }
     }
 
}



	// aXXXXXX - Silvério Mário
    // Funcao que verifica se um quarto esta a sobrepor-se a outro.
int is_valid_room(STATE *s, int center_x, int center_y, int size_x, int size_y) {
    for (int y = center_y; y <= center_y + size_y; y++) {
        for (int x = center_x; x <= center_x + size_x; x++) {
            if ((s->mapaEasy[y][x].is_wall != TRUE || s->mapaEasy[y + 2][x].is_wall != TRUE || s->mapaEasy[y - 2][x].is_wall != TRUE || s->mapaEasy[y][x + 2].is_wall != TRUE || s->mapaEasy[y][x - 2].is_wall != TRUE)/* && y >= 0 && y < 55 && x >= 0 && x < 250*/) {

                return FALSE;
            }
        }
    }
    return TRUE;
}




	// aXXXXXX - Silvério Mário
    // Funcao que escava um tunil entre dois quartos.
void dig_tunnel(STATE *s, int prev_center_x, int prev_center_y, int to_x, int to_y) {
    int x = prev_center_x;
    int y = prev_center_y;

    while (x != to_x) {
       
        s->mapaEasy[y][x].is_wall = FALSE;
        s->mapaEasy[y+1][x].is_wall = FALSE;
        if (x < to_x) {
            x++;
        } else {
            x--;
        }
    }

    while (y != to_y) {
        s->mapaEasy[y][x].is_wall = FALSE;
         s->mapaEasy[y][x+1].is_wall = FALSE;
        if (y < to_y) {
            y++;
        } else {
            y--;
        }
    }

}



	// aXXXXXX - Silvério Mário
    // Funcao que controi os quartos.
void Build_rooms(STATE *s, int ncols, int nrows){
    int n_rooms;

    n_rooms = rand () % 15 + 7;   // Variavel que escolhe o numero de quartos.

        for (int i = 0; i <= n_rooms ; i++) {   // Loop que coloca o numero de quartos desejados no mapa.
        int r_size_x, r_size_y, r_start_x, r_start_y;
        int max_iterations = 100, n_iteration = 0;
     
     do {      
            r_start_x = rand() % WIDTH_room;
            r_start_y = rand() % HEIGHT_room;
            r_size_x = rand() % 15 + 7;
            r_size_y = rand() % 25 + 7;
           
            n_iteration++;

        } while ((!is_valid_room(s, r_start_x, r_start_y, r_size_x, r_size_y)) && n_iteration < max_iterations);

        if ( n_iteration == max_iterations ) {
           
            r_start_y = 0; r_start_x = 0;
            r_size_y = 5; r_size_x = 5;
           }      
           

     //Clausula que cria os quartos .
       for (int y = r_start_y; y <= r_start_y + r_size_y ; y++){
           for(int x = r_start_x; x <= r_start_x + r_size_x ; x++){
             
              s -> mapaEasy [y][x].is_wall = FALSE;
              }
           }
           
     int center_y, center_x;
     int prev_center_x;
     int prev_center_y;
     
     if (i > 0) {   
           
        prev_center_x = center_x;
        prev_center_y = center_y;

        }
       // centro do quaros.
       center_y = r_start_y + (r_size_y / 2);
       center_x = r_start_x + (r_size_x / 2);
       
       if (i > 0){   // clausula para garantir criancao de tuneis depois do segundo quarto. 

            dig_tunnel(s, prev_center_x, prev_center_y, center_x, center_y);

        }
       
    }
       
       // criacao de escadas.
for (int j = 0; j < 4; j++){
   int stairs_y, stairs_x;
    do {
            stairs_y = rand() %55;
            stairs_x = rand() %250;
     
           }
            while (s->mapaEasy[stairs_y] [stairs_x].is_wall != FALSE);

            s->mapaEasy [stairs_y] [stairs_x].is_stairs = TRUE;
}
    int x, y = 0;

    for (x = 0; s->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
        for ( ; s->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
    }

    s->playerX = x;
    s->playerY = y;

   
}



	// aXXXXXX - Silvério Mário
    // Funcao que gera e controla a geracao dos mapas.
void gen_map (STATE *s, int ncols, int nrows) {
   
    Initialize_rooms(s);
    Build_rooms(s, ncols, nrows);
   
    Initialize_dungeon_Mid(s);
    Build_dungeon_Mid(s);

    Initialize_dungeon_Hard(s);
    Build_dungeon_Hard(s);

}



	// aXXXXXX - Silvério Mário
    // Função que gera o mapa Inicial
void gerar(STATE *s, int ncols, int nrows) {
   
    srand(time(NULL));
    gen_map(s, ncols, nrows);
    random_Enemy(s);
    random_Items(s, ncols, nrows);
    time(&(s->timeStart));
    s->dificulty = 1;
    s->playerHP = 150;
    s->playerAttack = 10;
    s->numEnemies_Easy = 20;
    s->numEnemies_Mid = 40;
    s->numEnemies_Hard = 50;
}