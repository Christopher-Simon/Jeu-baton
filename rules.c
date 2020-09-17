#include "rules.h"

int RdJ (){
    int RetourMenu;

    printf("\n==========================REGLES DU JEU==========================\n");
    printf("20 bâtonnets en bois sont alignés les uns à côté des autres\n");
    printf("A tour de rôle chacun des 2 concurrents va devoir en retirer\n");
    printf("1, 2 ou 3 à l'endroit de leur choix, le but étant de laisser\n");
    printf("le dernier bâtonnet à son adversaire.\n");
    printf("Il leur faudra donc calculer et ne pas retirer de bâtonnet(s)\n");
    printf("au hasard.\n");
    printf("Celui qui se retrouve avec le dernier bâtonnet a perdu.\n");
    printf("=================================================================\n\n");
    printf("Tapez 1 pour retourner au menu :");
    scanf("%s", &RetourMenu);
    menu();
}
