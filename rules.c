#include "rules.h"

int RdJ (){
    int RetourMenu;

    printf("\n==========================REGLES DU JEU==========================\n");
    printf("20 b�tonnets en bois sont align�s les uns � c�t� des autres\n");
    printf("A tour de r�le chacun des 2 concurrents va devoir en retirer\n");
    printf("1, 2 ou 3 � l'endroit de leur choix, le but �tant de laisser\n");
    printf("le dernier b�tonnet � son adversaire.\n");
    printf("Il leur faudra donc calculer et ne pas retirer de b�tonnet(s)\n");
    printf("au hasard.\n");
    printf("Celui qui se retrouve avec le dernier b�tonnet a perdu.\n");
    printf("=================================================================\n\n");
    printf("Tapez 1 pour retourner au menu :");
    scanf("%s", &RetourMenu);
    menu();
}
