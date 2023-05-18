#include <ncurses.h>
void dadano(Jogador playr, Monstro monstr)
{
    int dano = playr.atk ;
    monstr.hp-= dano;
}
void recebedano (Jogador playr, Monstro monstr)
{player.hp-= monstr.attack; }
