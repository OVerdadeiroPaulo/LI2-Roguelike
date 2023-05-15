typedef struct item
{
    char nome[10];
    char tipo[10];
    char elemento[10];
    int magnitude;
    struct item *prox;
} *Item;
void efeitodapocao (){
    
}
typedef struct Jogador
{
    int hp, mp, ammo, atk, def, speed;
    int posX;
    int posY;
    Item weapEquipado;
    Item armadura;
    struct item;
} Jogador;
typedef struct atacks
{
    char nome[10];
    char elemento[10];
    int magnitude;
    struct atacks *prox;
} *atacks;

typedef struct Monstro
{
    int hp, def, speed;
    int posX;
    int posY;
    struct atacks;
} Monstro;
char *Elementos[] = {"Agua", "Fogo", "Terra", "Ar", "Holy", "Unholy"};

int dmggiven(Jogador playr, Monstro monstr)
{
    int dano = playr.atk - monstr.def;
    float varElement = elementMult(playr.armadura->elemento, monstr.atacks.elemento);
}
float elementMult(char *element1, char *element2) // funcao quer controla os efeitos elementais sendo o element 1 o atacante e element 2 o do defensor 
{
    if ((*element1 == "Agua" && *element2 == "Fogo") || (*element1 == "Fogo" && *element2 == "Ar") || (*element1 == "Ar" && *element2 == "Terra") || (*element1 == "Terra" && *element2 == "Agua"))
        return 2;
        else if ((*element2 == "Agua" && *element1 == "Fogo") || (*element2 == "Fogo" && *element1 == "Ar") || (*element2 == "Ar" && *element1 == "Terra") || (*element2 == "Terra" && *element1 == "Agua")) return (1/2);
       else if ((*element1 == "Holy" && *element2 == "Unholy")||(*element2 == "Holy" && *element1 == "Unholy")) return 2;
       else return 1;
}