#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "menu.h"
#include "rules.h"
#include "langues.h"
#include "multi.h"
#include "replay_multi.h"

int main()
{
    printf("Bonjour \n\n");
    printf("Comme vous avez vu dans le mail, j'ai essaye de m'inscrire a 42 pendant l'ete.\n");
    printf("Mais avec notre amie la Covid, plus de check in. \n\n");
    printf("Du style plutot impatient et un peu impetueux.\n");
    printf("J'ai ouvert OpenClassroom, recupere un vieux jeu que mon pere me faisait petit, \n");
    printf("auquel il me battait tout le temps et je l'ai code.\n");
    printf("Je vous propose de jouer contre the Unbeatable AI\n");
    printf("et de considerer mon humble demande pour rejoindre 42 a la piscine d'Octobre.\n\n");
    printf("Bonne partie !\n\n");
    printf("Christopher\n");
    printf("Entrez n'importe quelle valeur pour lancer le jeu\n");

    scanf("%s");
    system("clear");
    menu();
    return 0;
}
