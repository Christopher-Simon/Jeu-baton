#include "multi.h"

int multiplayer()
{
    char player1[100];
    char player2[100];

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
    char buf[1024];
    while (nombreDeBatons > 0)
    {
        //printf("debut boucle while nbbatons >0\n");
        int batonsRetire = 0;
        //printf("après int batons retire\n");
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

int playMultiValue(int batonsRetire,int nombreDeBatons,int* a,int player1,int player2) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
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
            replayMulti(player1, player2);
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
