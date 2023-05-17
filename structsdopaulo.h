
// #include <stdbool.h>
// typedef struct item //struct quer define os items 
// {   int posx,posy;
//     char nome[10];
//     char tipo[10];
//     int magnitude;
//     char visual;
//     struct item *prox;
// } *Item;

// void pocao (Jogador player, Item pocao){ //funcao modular que da vida quando a pocao e consumida
//     player.hp += pocao->magnitude;
// }

// typedef struct enemy { //struct do inimigo
//     int hp, attack;
//     int enemyX;
//     int enemyY;
//     int type;
//     int direction;

//     bool is_Following;
//     bool just_Walking;
//     bool attack;
//     char visual;
// } ENEMY;
// typedef struct Jogador //struct que define o jogador
// {
//     int hp, mp, ammo, atk, def, speed;
//     int posX;
//     int posY;
//     Item weapEquipado;
//     Item armadura;
//     struct item;
// } Jogador;
// typedef struct atacks //antiga struct dos inimigos e atques
// {
//     char nome[10];
//     char elemento[10];
//     int magnitude;
//     struct atacks *prox;
// } *atacks;

// typedef struct Monstro
// {
//     int hp, def, speed;
//     int posX;
//     int posY;
//     struct atacks ataques;
//     char visual;
// } Monstro;
// char *Elementos[] = {"Agua", "Fogo", "Terra", "Ar", "Holy", "Unholy"};

// int dmggiven(Jogador playr, Monstro monstr)
// {
//     int dano = playr.atk - monstr.def;
//    // float varElement = elementMult(playr.armadura->elemento, monstr.ataques.elemento);

// }
// float elementMult(char *element1, char *element2) // funcao quer controla os efeitos elementais sendo o element 1 o atacante e element 2 o do defensor 
// {
//     if ((*element1 == "Agua" && *element2 == "Fogo") || (*element1 == "Fogo" && *element2 == "Ar") || (*element1 == "Ar" && *element2 == "Terra") || (*element1 == "Terra" && *element2 == "Agua"))
//         return 2;
//         else if ((*element2 == "Agua" && *element1 == "Fogo") || (*element2 == "Fogo" && *element1 == "Ar") || (*element2 == "Ar" && *element1 == "Terra") || (*element2 == "Terra" && *element1 == "Agua")) return (1/2);
//        else if ((*element1 == "Holy" && *element2 == "Unholy")||(*element2 == "Holy" && *element1 == "Unholy")) return 2;
//        else return 1;
// }