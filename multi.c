#include "multi.h"

int multiplayer()
{
    char player1[100];
    char player2[100];

    printf("****** ASOBO ******\n\n");

    printf("Nom du joueur 1 : ");
    scanf("%s", player1);

    printf("Nom du joueur 2 : ");
    scanf("%s", player2);

    launch_multi(player1, player2);
}

int launch_multi(player1, player2)
{
    int nombreDeBatons = 20;
    int currentPlayer = rand_player();
    play_multi(nombreDeBatons, currentPlayer, player1, player2);
}

int rand_player()
{
    int number;
    srand(time(NULL));
    number = (rand() % (2 - 1 + 1)) + 1;
    return number;
}

int play_multi(nombreDeBatons, currentPlayer, player1, player2)
{
    char buf[1024] = "1";
    while (nombreDeBatons > 0)
    {
        //printf("debut boucle while nbbatons >0\n");
        int batonsRetire = 0;
        //printf("apr�s int batons retire\n");
        currentPlayerValue(currentPlayer, player1, player2);
        printf("Combien de batons souhaites tu retirer ? Entre 1 et 3 uniquement: ");
        while (batonsRetire == 0)
        {
            if (!fgets( buf, 1024, stdin))
            {
                // reading input failed, give up:
                return 1;
            }

            // have some input, convert it to integer:
            batonsRetire = atoi( buf);
        }

        printf("Tu veux en retirer %d\n\n", batonsRetire);
        nombreDeBatons = playMultiValue(batonsRetire, nombreDeBatons, &currentPlayer, player1, player2);

        printf("Il reste %d batons\n", nombreDeBatons);
    }
}

void currentPlayerValue(currentPlayer, player1, player2)
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

int playMultiValue(int batonsRetire,int nombreDeBatons,int* currentPlayer,int player1,int player2) /* Identifie la valeur entr�e dans game, si elle est sup�rieur ou inf�rieur � 3, n'effectue aucune action */
{
    if(batonsRetire >3 || batonsRetire <=0)
    {
        printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n\n");
        printf("Il reste %d\n", nombreDeBatons);
        play_multi(nombreDeBatons, *currentPlayer, player1, player2);
    }
    else
    {
        nombreDeBatons = nombreDeBatons - batonsRetire;
        if(nombreDeBatons <= 0)
        {
            printf("Current player is : %d \n", *currentPlayer);
            if(*currentPlayer == 1)
            {
                printf("****** %s a retire le dernier baton et perd ******\n", player1);
                printf("****** Bravo %s ****** !\n\n", player2);
            }
            else
            {
                printf("****** %s a perdu ******\n", player2);
                printf("****** Bravo %s ****** !\n\n", player1);
            }
            replayMulti(player1, player2);
        }
        else
        {
            *currentPlayer = change_turn(*currentPlayer);
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
