#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "menu.h"
#include "rules.h"





int multiplayer()
{
    char player1[100];
    char player2[100];
    int currentPlayer = 1;
    int nombreDeBatons = 20;
    printf("Nom du joueur 1 : ");
    scanf("%s", player1);

    printf("Nom du joueur 2 : ");
    scanf("%s", player2);

    printf("La partie commence avec 20 batons\n");

    while (nombreDeBatons > 0)
        {
            playMulti(currentPlayer, nombreDeBatons, player1, player2);
            if(nombreDeBatons>0 && currentPlayer == 1)
            {
                currentPlayerPlus(currentPlayer);
            }
            else if(nombreDeBatons>0 && currentPlayer == 2)
            {
                currentPlayerMinus(currentPlayer);
            }
            else
                {
                    if(currentPlayer == 1)
                    {
                        printf("****** %s a perdu ******\n\n", player1);
                    }
                    else
                    {
                        printf("****** %s a perdu ******\n\n", player2);
                    }
                }
        }
    replayMulti();
}

int playMulti(currentPlayer, nombreDeBatons, player1, player2)
{
    int batonsRetire;
    currentPlayerValue(currentPlayer, player1, player2);
    scanf("%d", &batonsRetire);
    playMultiValue(batonsRetire);
    if (nombreDeBatons >= 0){
    printf("Il reste %d batons\n", nombreDeBatons);
    }
    else{
    printf("Bien essayé, tu as voulu en retirer trop. Il reste 0 batons\n", nombreDeBatons);
    }
}

int playMultiValue(batonsRetire, nombreDeBatons) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
{
    if(batonsRetire >3 || batonsRetire <=0)
    {
        printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
        playMulti();
    }
    else
    {
        nombreDeBatons = nombreDeBatons - batonsRetire;
    }
}

int currentPlayerPlus(currentPlayer)
{
    int resultat;
    currentPlayer = currentPlayer + 1;
    return resultat = currentPlayer;
}

int currentPlayerMinus(currentPlayer)
{
    int resultat;
    currentPlayer = currentPlayer - 1;
    return resultat = currentPlayer;
}

int currentPlayerValue(currentPlayer, player1, player2)
{
    if(currentPlayer == 1)
        {
            printf("\nC'est a %s de jouer\n", player1);
            printf("Nombre de batons à retirer : ");
        }
    else
        {
            printf("\nC'est a %s de jouer\n", player2);
            printf("Nombre de batons à retirer : ");
        }
}

int replayMulti()
{
    char oui[]="oui";
    char non[]="non";
    char replayValue[3];
    int choix;
    printf("Voulez-vous refaire une partie ? (oui/non) :");
    scanf("%s", &replayValue);
    choix = strcmp(replayValue, oui);
    if (strcmp (replayValue,oui) == 0){
        printf("Okay let's go !\n");
        multiplayer();
    }
    else if (strcmp (replayValue,non) == 0){
        menu();
    }
    else {
        printf("Ceci n'est pas une réponse valide\n");
        replayMulti();
    }
}



int main()
{
    printf("Bonjour humain.\n");
    printf("Bienvenue dans le jeu des batons. Que veux-tu faire ?\n");
    menu();
    return 0;
}
