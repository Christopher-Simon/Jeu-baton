#include "multi.h"

int multiplayer()
{
    int nombreDeBatons = 20;
    int batonsRetire = 0;
    char player1[100];
    char player2[100];
    int currentPlayer = 1;

    printf("Nom du joueur 1 : ");
    scanf("%s", player1);

    printf("Nom du joueur 2 : ");
    scanf("%s", player2);

    play_multi(nombreDeBatons, batonsRetire, player1, player2, currentPlayer);
}

int play_multi(nombreDeBatons, batonsRetire, player1, player2, currentPlayer)
{
    while (nombreDeBatons > 0)
    {
        currentPlayerValue(currentPlayer, player1, player2);

        printf("Nombre de batons a retirer : ");
        scanf("%d", &batonsRetire);

        nombreDeBatons = playMultiValue(batonsRetire, nombreDeBatons);

        printf("%d\n", nombreDeBatons);

        if(nombreDeBatons <= 0)
        {
            if(currentPlayer == 1)
                    {
                        printf("****** %s a perdu ******\n\n", player1);
                    }
                    else
                    {
                        printf("****** %s a perdu ******\n\n", player2);
                    }
            replayMulti();
        }

        currentPlayer = change_turn(currentPlayer);

    }
}

int currentPlayerValue(currentPlayer, player1, player2)
    {
        if(currentPlayer == 1)
            {
                printf("\nC'est a %s de jouer\n", player1);
            }
        else
            {
                printf("\nC'est a %s de jouer\n", player2);
            }
    }

int playMultiValue(batonsRetire, nombreDeBatons) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
    {
        if(batonsRetire >3 || batonsRetire <=0)
        {
            printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
            play_multi();
        }
        else
        {
            nombreDeBatons = nombreDeBatons - batonsRetire;
            printf("%d\n", nombreDeBatons);
            return nombreDeBatons;
        }
    }

int change_turn(currentPlayer)
{
    if(currentPlayer == 1)
    {
        currentPlayer = currentPlayer + 1;
    }
    else
    {
        currentPlayer = currentPlayer - 1;
    }
    return currentPlayer;
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
        else if (strcmp (replayValue, non) == 0){
            menu();
        }
        else {
            printf("Ceci n'est pas une réponse valide\n");
            replayMulti();
        }
    }
