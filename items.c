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
    pocao= pocao->prox;
}

typedef struct Jogador // struct que define o jogador
{
    int hp, mp, ammo, atk, def, speed;
    int posX;
    int posY;
    Item bowEquipado;
    Item weapEquipado;
    Item armadura;
    Item inventario;
} Jogador;

void atribuiCamposItem(Item item) // auxiliar que da o tipo nome e char ao item
{
    int semente = rand() % 4;
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

    else if (semente == 3)
    {
        strcpy(item->tipo, "armor");
        strcpy(item->nome, "Armour");
        item->visual = 'H';
    }
}
Item geraArrow() // igual a de baixo mas so para arrows para possibilitar um  inicio com items random
{
    Item item = (Item)malloc(sizeof(struct item));
    if (item != NULL)
    {
        strcpy(item->nome, "Arrow");
        strcpy(item->nome, "Arrow");
        item->magnitude = 10;
        item->visual = 'i';
        item->prox = NULL;
    }
    return item;
}
Item geraitem() // gera um item auxiliar
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
Item spawnaItem(ENEMY inimigo) // cria um item na posiçao do inimigo quando este morre
{
    int semente = rand() % 3;
    if (inimigo.hp <= 0)
    {
        if (semente == 1)
        {
            Item item = geraArrow;
            return item;
        }
        else
        {
            Item item = geraitem;
            item->posx = inimigo.enemyX;
            item->posy = inimigo.enemyY;
            return item;
        }
    }
}
void apanhaItem(Jogador player, Item item) // colecta um item do chao
{

    if (player.posX == item->posx && player.posY == item->posy)
    {
        Item inv = player.inventario;
        if (item->tipo == "ammo")
        {
            player.ammo += item->magnitude;
        }
        else
        {
            while (inv->prox != NULL)
                inv = inv->prox;
            inv->prox = item;
        }
    }
}
void equipaitems(Jogador player, Item item) // auxiliar para gerir inventario
{
    Item temp;

    if (item->nome == "Bow")
    {
        temp = player.bowEquipado;
        player.bowEquipado = item;
        item = temp;
    }
    else if (item->nome == "Sword")
    {
        temp = player.weapEquipado;
        player.weapEquipado = item;
        item = temp;
    }
    else if (item->nome == "Armour")
    {
        temp = player.armadura;
        player.armadura = item;
        item = temp;
    }
    free(temp);
}
void dropaItems(Jogador player, Item item) {// auxiliar para deitar fora items
item = item->prox;
}
