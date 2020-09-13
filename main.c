#include <stdio.h>
#include <stdlib.h>

int nombreDeBatons = 20;
int batonsRetire = 0;
int replayValue;
int intro()
    {
        nombreDeBatons = 20;
        printf("Je commence, je vais retirer 3 batons.\n");
        nombreDeBatons = nombreDeBatons - 3;
        printf("Il reste %d batons\n", nombreDeBatons);
    }

int game()
{
    intro();
    while (nombreDeBatons > 0)
        {
            printf("Combien de batons voulez vous retirer ? Retirez entre 1 et 3\n");
            scanf("%d", &batonsRetire);
            play(batonsRetire);
            printf("Il reste %d batons\n", nombreDeBatons);
        }
    replay();
}

int replay()
{
    printf("Replay ? 0/1\n");
    scanf("%d", &replayValue);
    replayMenu(replayValue);
}

int replayMenu(int nombre)
{
    if(nombre == 1)
        {
            printf("Okay let's go !\n");
            game();
        }
        else if(nombre == 0)
        {
            printf("Merci d'avoir joue !\n");
        }
        else
        {
            printf("Veuillez selectionner 0/1\n");
            replay();
        }
}

int play(int nombre)
    {
        if(nombre >3 || nombre <=0)
        {
            printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
        }
        else
        {
            nombreDeBatons = nombreDeBatons - nombre;
        }
    }

int main()
    {
        printf("Bonjour humain.\n");

        game();

        return 0;
    }
