#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"

#define HEIGHT_dungeon 55
#define WIDTH_dungeon 249
#define HEIGHT_room 55
#define WIDTH_room 250
#define HEIGHT_dungeon_Hard 150
#define WIDTH_dungeon_Hard 299

int map_criation = 0;   // variavel para activar a escolha do mapa tipo quartos e tuneis;
int dungeon_mod = 1;  // variavel para activar a escolha do mapa tipo gruta. 
int r_oldcenter_y, r_center_y, r_oldcenter_x, r_center_x;
int player_criation = 0, playerX = 1, playerY = 1;

// Funcao que inicializa todo o array para criar grutas. 
void Initialize_dungeon_Mid(STATE *s) {
    
    for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
                
				s->mapaMid[i][j].is_wall = FALSE;
				s->mapaMid[i][j].is_mud = FALSE;
				s->mapaMid[i][j].is_grass = FALSE;
				s->mapaMid[i][j].is_water = FALSE;
				s->mapaMid[i][j].is_stairs = FALSE;

			if (i == 0 || i == HEIGHT_dungeon - 1 || j == 0 || j == WIDTH_dungeon - 1) {
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



// Funcao que pega no array inicializado e controi as grutas.
void Build_dungeon_Mid(STATE *s) {
    int n_walls;
    int dungeon_data [HEIGHT_dungeon][WIDTH_dungeon];

    for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
            n_walls = 0;

            // Clausulas para contar o numero de paredes vizinhas.
            if (s->mapaMid [i - 1][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i - 1][j].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i - 1][j + 1].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i][j + 1].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i + 1][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i + 1][j].is_wall == TRUE) n_walls++;
            if (s->mapaMid[i + 1][j + 1].is_wall == TRUE) n_walls++;

            // Clausula para escolher o conteudo de cada celula.
            if (s->mapaMid[i][j].is_wall == TRUE) {
                 if (n_walls >= 4){
					dungeon_data [i][j] = TRUE;
					} 
				 else{
					dungeon_data [i][j] = FALSE;
					}
            }
			    else {
                    if (n_walls >= 5){
					   dungeon_data [i][j] = TRUE;
					   } 
					else {
					   dungeon_data [i][j] = FALSE;
					   }
                   }
        }
    }

    // clausula para copiar para o array novo mapa.
    for (int i = 0; i < HEIGHT_dungeon; i++) {
        for (int j = 0; j < WIDTH_dungeon; j++) {
            s->mapaMid [i][j].is_wall = dungeon_data [i][j];
        }
    }

		   // criacao de escadas.
    int stairs_y, stairs_x;

    do { 
            stairs_y = rand() %55;
            stairs_x = rand() %250;
     
           }
            while (s->mapaEasy[stairs_y] [stairs_x].is_wall != FALSE); 

            s->mapaEasy [stairs_y] [stairs_x].is_stairs = TRUE;
}


// Funcao que inicializa todo o array para criar grutas. 
void Initialize_dungeon_Hard(STATE *s) {
    
    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
                
				s->mapaHard[i][j].is_wall = FALSE;
				s->mapaHard[i][j].is_mud = FALSE;
				s->mapaHard[i][j].is_grass = FALSE;
				s->mapaHard[i][j].is_water = FALSE;
				s->mapaHard[i][j].is_stairs = FALSE;

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



// Funcao que pega no array inicializado e controi as grutas.
void Build_dungeon_Hard(STATE *s) {
    int n_walls;
    int dungeon_data [HEIGHT_dungeon_Hard][WIDTH_dungeon_Hard];

    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
            n_walls = 0;

            // Clausulas para contar o numero de paredes vizinhas.
            if (s->mapaHard [i - 1][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i - 1][j].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i - 1][j + 1].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i][j + 1].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i + 1][j - 1].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i + 1][j].is_wall == TRUE) n_walls++;
            if (s->mapaHard[i + 1][j + 1].is_wall == TRUE) n_walls++;

            // Clausula para escolher o conteudo de cada celula.
            if (s->mapaHard[i][j].is_wall == TRUE) {
                 if (n_walls >= 4){
					dungeon_data [i][j] = TRUE;
					} 
				 else{
					dungeon_data [i][j] = FALSE;
					}
            }
			    else {
                    if (n_walls >= 5){
					   dungeon_data [i][j] = TRUE;
					   } 
					else {
					   dungeon_data [i][j] = FALSE;
					   }
                   }
        }
    }

    // clausula para copiar para o array novo mapa.
    for (int i = 0; i < HEIGHT_dungeon_Hard; i++) {
        for (int j = 0; j < WIDTH_dungeon_Hard; j++) {
            s->mapaHard [i][j].is_wall = dungeon_data [i][j];
        }
    }

		   // criacao de escadas.
    int stairs_y, stairs_x;

    do { 
            stairs_y = rand() %55;
            stairs_x = rand() %250;
     
           }
            while (s->mapaEasy[stairs_y] [stairs_x].is_wall != FALSE); 

            s->mapaEasy [stairs_y] [stairs_x].is_stairs = TRUE;
}




// Funcao que inicializa o array para com tudo walls para comecar a contruir os mapas.
void Initialize_rooms(STATE *s){

     for(int y = 0; y < HEIGHT_room; y++){
	  	for(int x = 0; x < WIDTH_room; x++){
	    		
	    	s->mapaEasy[y][x].is_wall = FALSE;
	    	s->mapaEasy[y][x].is_mud = FALSE;
	    	s->mapaEasy[y][x].is_grass = FALSE;
	    	s->mapaEasy[y][x].is_water = FALSE;
	    	s->mapaEasy[y][x].is_stairs = FALSE;   
	    	
			if (x == WIDTH_room || x == 0){
	    		
	    		s -> mapaEasy [y] [x].is_wall = TRUE;
			}   
	    	else if (y == HEIGHT_room || y == 0) {   
	    		s -> mapaEasy [y] [x].is_wall = TRUE;
	    	}
	    	
	    	   else {
	    	      s -> mapaEasy [y] [x].is_wall = TRUE;
	    	      }
	    }
	 }
}



// Funcao que verifica se um quarto esta a sobrepor-se a outro.
int is_valid_room(STATE *s, int center_x, int center_y, int size_x, int size_y) {

	for (int y = center_y; y <= center_y + size_y ; y++){
           for(int x = center_x; x <= center_x + size_x ; x++){
              if ((s -> mapaEasy [y] [x].is_wall != TRUE  || s -> mapaEasy [y+2][x].is_wall != TRUE|| s -> mapaEasy[y-2][x].is_wall != TRUE || s -> mapaEasy [y][x + 2].is_wall != TRUE|| s -> mapaEasy [y][x - 2].is_wall != TRUE) && y >= 0 && y < 55 && x >= 0 && x < 250){

				return FALSE;
              }
           }
       }
	return TRUE;
}



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



// Funcao que controi os quartos.
void Build_rooms(STATE *s, int ncols, int nrows){
	
	int n_rooms;

	n_rooms = rand () % 15 + 7;

		for (int i = 0; i <= n_rooms ; i++) {
        int r_size_x, r_size_y, r_start_x, r_start_y;
        int max_iterations = 100, n_iteration = 0;
      
	  if ( i == n_rooms){
         r_start_x =38;
         r_start_y =16;
         r_size_x = 5;
         r_size_y = 5;
	  }
	  else{
	 do {		
            r_start_x = rand() % 250;
            r_start_y = rand() % 55;
            r_size_x = rand() % 15 + 7;
            r_size_y = rand() % 25 + 7;
            
			n_iteration++;

        } while (!is_valid_room(s, r_start_x, r_start_y, r_size_x, r_size_y) && n_iteration < max_iterations);

	    if ( n_iteration == max_iterations ) {
            // 
            r_start_y = 0; r_start_x = 0;
            r_size_y = 5; r_size_x = 5;
		 	//continue;
           }      
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
       
	   if (i > 0){

	        dig_tunnel(s, prev_center_x, prev_center_y, center_x, center_y);

		}
        
	}
		
	   // criacao de escadas.
    int stairs_y, stairs_x;

    do { 
            stairs_y = rand() %55;
            stairs_x = rand() %250;
     
           }
            while (s->mapaEasy[stairs_y] [stairs_x].is_wall != FALSE); 

            s->mapaEasy [stairs_y] [stairs_x].is_stairs = TRUE;

	int x, y = 0;

	for (x = 0; s->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; x++) {
		for ( ; s->mapaEasy[y + (nrows/2)][x + (ncols/2)].is_wall == TRUE; y++) { };
	}

	s->playerX = x;
	s->playerY = y;

}



// Funcao que gera e controla a geracao dos mapas.
void gen_map (STATE *s, int ncols, int nrows) {
	
    
    Initialize_rooms(s);
    Build_rooms(s, ncols, nrows);

	Initialize_dungeon_Mid(s);
	Build_dungeon_Mid(s);

	Initialize_dungeon_Hard(s);
	Build_dungeon_Hard(s);
	dungeon_mod++;

}



void gerar(STATE *s, int ncols, int nrows) {
	
	srand(time(NULL));
	//random_Enemy(s);
	gen_map(s, ncols, nrows);
	s->dificulty = 1;
}