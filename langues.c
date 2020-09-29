#include "langues.h"

int langues()
{
    int menuValue;

    printf("Choisis ta langue.\n\n");
    printf("\n*********************************************\n");
    printf("1) Francais\n");
    printf("2) Anglais\n");
    printf("3) Espagnol\n");
    printf("4) Allemand\n");
    printf("5) Retourner au menu\n");
    printf("*********************************************\n\n");

    printf("Votre choix :");
    scanf(" %d", &menuValue);

    while(getchar()!='\n');
    langueFct(menuValue);
}

int langueFct(int nombre)/* Identifying the menuValue, for single or multiplayer */
{
    int RetourMenu;

        if(nombre == 1){
            printf("Et bien parfait ! On change rien !\n");
            printf("Entrez 5 pour retourner au menu :");
            scanf("%s", &RetourMenu);
            system("clear");
            menu();
        }
        else if(nombre == 2){
            printf("Nan en vrai, j'ai pas pris le temps de tout traduire désolé !\n");
            printf("Please enter an input to return to the menu :");
            scanf("%s", &RetourMenu);
            system("clear");
            menu();
        }
        else if(nombre == 3){
            printf("no hablo espanol");
            printf("Ingrese una entrada para regresar al menu :\n");
            scanf("%s", &RetourMenu);
            system("clear");
            menu();
        }
        else if(nombre == 4){
            printf("In Wirklichkeit kann ich diese Gelegenheit mit 42 wirklich nutzen\n");
            printf("Et je vais profiter de l'Allemand pour parler de moi !\n");
            printf("Je suis d'origine sud-africaine et alsacienne(mon vrai cote exotique). \n\n");
            printf("Comme je le dis lors de votre deuxieme partie, je suis obsede par l'entrepreneuriat, et je compte continuer. \n\n");
            printf("Et enfin, les petites passions : \n");
            printf("Un cuisinier passionne (Insta : christo_wells\n");
            printf("Piano en autodidacte depuis 7 ans, en quete de l'oreille absolue \n");
            printf("Triathlete : j'ai fini mon premier IronMan 70.3 en septembre\n\n");
            printf("Entrez 5 pour retourner au menu :");
            scanf("%s", &RetourMenu);
            system("clear");
            menu();
        }
        else if(nombre == 5){
            scanf("%s", &RetourMenu);
            system("clear");
            menu();
        }
        else
        {
            printf("Veuillez selectionner une option valide\n");
            langues();
        }
}
