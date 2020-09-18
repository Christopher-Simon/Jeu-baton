#include "menu.h"

void menu()/*Adding a menu to choose to play against a friend or AI*/
    {
        int menuValue;
        printf("\n*********************************************\n");
        printf("1) Jouer contre the unbeatable Bot\n");
        printf("2) Jouer avec un ami\n");
        printf("3) Lire les regles du jeux\n");
        printf("4) Quittez le jeu \n");
        printf("*********************************************\n\n");
        printf("Votre choix :");
        scanf(" %d", &menuValue);
        while(getchar()!='\n');
        menuFct(menuValue);
    }

int menuFct(int nombre)/* Identifying the menuValue, for single or multiplayer */
{
    if(nombre == 1){
            printf("Tu vas prendre ta raclee!\n\n");
            game();
    }
    else if(nombre == 2){
        printf("****** ASOBO ******\n\n");
        multiplayer();
    }
    else if(nombre == 3){
        RdJ();
    }
    else if(nombre == 4){
        printf("\nMerci, au revoir Humain");
    }
    else
    {
        printf("Veuillez selectionner une option valide\n");
        menu();
    }
}

    int menuValue()
{
    printf("\n*********************************************\n");
    printf("1) Jouer contre the unbeatable Bot\n");
    printf("2) Jouer avec un ami\n");
    printf("3) Lire les regles du jeux\n");
    printf("4) Quittez le jeu \n");
    printf("*********************************************\n\n");
    printf("Votre choix :");
    scanf(" %d", &menuValue);
    while(getchar()!='\n');
    menuFct(menuValue);
}
