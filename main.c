#include <stdio.h>
#include <stdlib.h>

int nombreDeBatons = 20;
int batonsRetire = 0;
int replayValue;
int intro()/* Se lance au début de la partie. Permet de remettre le compteur de batons à 20 et de faire commencer l'IA. */
    {
        nombreDeBatons = 20;
        printf("Je commence, je vais retirer 3 batons.\n");
        nombreDeBatons = nombreDeBatons - 3;
        printf("Il reste %d batons\n", nombreDeBatons);
    }

int game()/* Boucle pour permettre au joueur de retirer entre 1 et 3 batons. Lance la fonction replay  la fin */
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

int replay()/* Propose de rejouer la partie, entre une valeur*/
{
    printf("Replay ? 0/1\n");
    scanf("%d", &replayValue);
    replayMenu(replayValue);
}

int replayMenu(int nombre) /* Identifie la valeur entrée dans replayMenu, lance le jeu, relance replay ou quitte */
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

int play(int nombre) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
    {
        if(nombre >3 || nombre <=0)
        {
            printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
        }
        else
        {
            nombreDeBatons = nombreDeBatons - nombre;
            batonsRetire = 4 - nombre;
            nombreDeBatons = nombreDeBatons - batonsRetire;
            printf("Je vais retirer %d batons\n", batonsRetire);
        }
    }

int main()
    {
        printf("Bonjour humain.\n");

        game(); /* fonction principale */

        return 0;
    }
