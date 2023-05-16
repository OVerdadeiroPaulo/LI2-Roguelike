#include <string.h>
#include <ncurses.h>
#include <stdbool.h>
#include <type_enemies.h>

typedef struct item // struct que define os items
{
    int posx, posy;
    char nome[10];
    char tipo[10];
    int magnitude;
    char visual;
    struct item *prox;
} *Item;

void pocao(Jogador player, Item pocao)
{ // funcao modular que da vida quando a pocao e consumida
    player.hp += pocao->magnitude;
}

typedef struct Jogador // struct que define o jogador
{
    int hp, mp, ammo, atk, def, speed;
    int posX;
    int posY;
    Item weapEquipado;
    Item armadura;
    Item inventario;
} Jogador;

void atribuiCamposItem(Item item)
{
    int semente = rand() % 3;
    if (semente == 0)
    {
        strcpy(item->tipo, "potion");
        strcpy(item->nome, "Potion");
        item->visual = '&';
    }
    else if (semente == 1)
    {
        strcpy(item->tipo, "melee");
        strcpy(item->nome, "Sword");
                item->visual = 'l';

    }
    else if (semente == 2)
    {
        strcpy(item->tipo, "ranged");
        strcpy(item->nome, "Bow");
                item->visual = 'D';

    }
    else
    {
        strcpy(item->tipo, "Impossivel");
        strcpy(item->nome, "ERROR");
                item->visual = 'E';
                

    }
}

Item geraitem()
{
    Item item = (Item)malloc(sizeof(struct item));
    if (item != NULL)
    {
        strcpy(item->nome, "nometemp");
        item->magnitude = 10;
        item->visual = ' ';
        item->prox = NULL;
        atribuiCamposItem(item);
    }
    return item;
}
Item spawnaItem(ENEMY inimigo)
{
    if (inimigo.hp <= 0)
    { geraitem;
    }
}
void apanhaItem (Jogador player, Item item) {
    if (player.posX == item->posx && player.posY == item->posy)
{    Item inv = player.inventario;
    while (inv->prox !=NULL) inv = inv->prox;
    inv->prox = item ;}
}