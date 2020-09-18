#include <stdio.h>
#include <stdlib.h>
#include "multi.h"

int multiplayer()
{
    int nombreDeBatons = 20;
    char player1[100];
    char player2[100];

    printf("Nom du joueur 1 : ");
    scanf("%s", player1);

    printf("Nom du joueur 2 : ");
    scanf("%s", player2);

    play_multi(nombreDeBatons, player1, player2);
}

int play_multi(nombreDeBatons, player1, player2)
{
    int currentPlayer = 1;
    char buf[1024];
    while (nombreDeBatons > 0)
    {
        int batonsRetire = 0;
        currentPlayerValue(currentPlayer, player1, player2);

        while (batonsRetire == 0)
        {
            printf("Nombre de batons a retirer : ");
            if (!fgets(buf, 1024, stdin))
            {
                // reading input failed, give up:
                return 1;
            }

            // have some input, convert it to integer:
            batonsRetire = atoi(buf);
        }

        printf("Tu veux en retirer %d\n", batonsRetire);
        nombreDeBatons = playMultiValue(batonsRetire, nombreDeBatons, &currentPlayer,player1, player2);

        printf("%d\n", nombreDeBatons);
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

int playMultiValue(int batonsRetire,int nombreDeBatons,int* a,int player1,int player2) /* Identifie la valeur entr�e dans game, si elle est sup�rieur ou inf�rieur � 3, n'effectue aucune action */
{
    if(batonsRetire >3 || batonsRetire <=0)
    {
        printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
        printf("Il reste %d\n", nombreDeBatons);
        return nombreDeBatons;
        play_multi();
    }
    else
    {
        nombreDeBatons = nombreDeBatons - batonsRetire;
        if(nombreDeBatons <= 0)
        {
            if(a == 1)
                    {
                        printf("****** %s a perdu ******\n\n", player2);
                    }
                    else
                    {
                        printf("****** %s a perdu ******\n\n", player1);
                    }
            replayMulti();
        }
        else
        {
            printf("%d\n", nombreDeBatons);
            *a = change_turn(*a);
            return nombreDeBatons;
        }
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
