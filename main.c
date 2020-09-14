#include <stdio.h>
#include <stdlib.h>

int nombreDeBatons = 20;
int batonsRetire = 0;
int replayValue;
int menuValue;
int currentPlayer = 1;
char player1[100];
char player2[100];

int menu()/*Adding a menu to choose to play against a friend or AI*/
    {
        printf("Souhaitez-vous jouer contre l'IA ou a deux ? 0/1\n");
        scanf("%d", &menuValue);
        menuFct(menuValue);
    }

int menuFct(int nombre)/* Identifying the menuValue, for single or multiplayer */
    {
        if(nombre == 1)
            {
                printf("Tu vas prendre ta raclée!\n");
                game();
            }
            else if(nombre == 0)
            {
                printf("Asobo !\n");
                multiplayer();
            }
            else
            {
                printf("Veuillez selectionner 0/1\n");
                menu();
            }
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
        replayAI();
    }

int intro()/* Se lance au début de la partie. Permet de remettre le compteur de batons à 20 et de faire commencer l'IA. */
    {
        nombreDeBatons = 20;
        printf("Je commence, je vais retirer 3 batons.\n");
        nombreDeBatons = nombreDeBatons - 3;
        printf("Il reste %d batons\n", nombreDeBatons);
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

int replayAI()/* Propose de rejouer la partie, entre une valeur*/
{
    printf("Replay ? 0/1\n");
    scanf("%d", &replayValue);
    replayAIFct(replayValue);
}

int replayAIFct(int nombre) /* Identifie la valeur entrée dans replayMenu, lance le jeu, relance replay ou quitte */
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
            replayAI();
        }
}

int multiplayer()
    {
        nombreDeBatons = 20;
        printf("Nom du joueur 1\n");
        scanf("%s", player1);

        printf("Nom du joueur 2\n");
        scanf("%s", player2);

        while (nombreDeBatons > 0)
            {
                playMulti();
                if(nombreDeBatons>0 && currentPlayer == 1)
                {
                    currentPlayerPlus();
                }
                else if(nombreDeBatons>0 && currentPlayer == 2)
                {
                    currentPlayerMinus();
                }
                else
                    {
                        if(currentPlayer == 1)
                        {
                            printf("%s a perdu", player1);
                        }
                        else
                        {
                            printf("%s a perdu", player2);
                        }
                    }
            }
        replayMulti();
    }

int currentPlayerPlus()
    {
        currentPlayer = currentPlayer + 1;
    }

int currentPlayerMinus()
    {
      currentPlayer = currentPlayer - 1;
    }

int currentPlayerValue()
    {
        if(currentPlayer == 1)
            {
                printf("C'est a %s de jouer", player1);
            }
        else
            {
                printf("C'est a %s de jouer", player2);
            }
    }

int playMulti()
    {
        currentPlayerValue();
        scanf("%d", &batonsRetire);
        playMultiValue(batonsRetire);
        printf("Il reste %d batons\n", nombreDeBatons);
    }

int playMultiValue(int nombre) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
    {
        if(nombre >3 || nombre <=0)
        {
            printf("Vous ne pouvez retirer qu'entre 1 et 3 batons\n");
            playMulti();
        }
        else
        {
            nombreDeBatons = nombreDeBatons - nombre;
        }
    }

int replayMulti()
    {
        printf("Replay ? 0/1\n");
        scanf("%d", &replayValue);
        replayMultiFct(replayValue);
    }

int replayMultiFct(int nombre) /* Identifie la valeur entrée dans replayMenu, lance le jeu, relance replay ou quitte */
{
    if(nombre == 1)
        {
            printf("Okay let's go !\n");
            multiplayer();
        }
        else if(nombre == 0)
        {
            printf("Merci d'avoir joue !\n");
        }
        else
        {
            printf("Veuillez selectionner 0/1\n");
            replayMulti();
        }
}

int main()
    {
        printf("Bonjour humain.\n");

        menu();

        return 0;
    }
