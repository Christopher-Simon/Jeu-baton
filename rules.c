#include "rules.h"

int RdJ ()
{
    int RetourMenu;

    printf("\n==========================REGLES DU JEU==========================\n");
    printf("20 batonnets en bois sont alignes les uns a cote des autres\n");
    printf("A tour de role chacun des 2 concurrents va devoir en retirer\n");
    printf("1, 2 ou 3 a l'endroit de leur choix, le but etant de laisser\n");
    printf("le dernier batonnet a son adversaire.\n");
    printf("Il leur faudra donc calculer et ne pas retirer de batonnet(s)\n");
    printf("au hasard.\n");
    printf("Celui qui se retrouve avec le dernier batonnet a perdu.\n");
    printf("=================================================================\n\n");
    printf("Entrez un input pour retourner au menu :");
    scanf("%s", &RetourMenu);
    menu();
}
