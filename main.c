#include <stdio.h>
#include <stdlib.h>

int nombreDeBatons = 20;
int batonsRetire = 0;
int menuValue;
int currentPlayer = 1;
char player1[100];
char player2[100];
// Variable pour replay or not
char oui[]="oui";
char non[]="non";
char replayValue[];
int choix;

int menu()/*Adding a menu to choose to play against a friend or AI*/
    {
        printf("*********************************************\n");
        printf("1) Jouer contre the unbeatable Bot\n");
        printf("2) Jouer avec un ami\n");
        printf("3) Lire les règles du jeux\n");
        printf("4) Quittez le jeu \n");
        printf("*********************************************\n");
        scanf("%d", &menuValue);
        menuFct(menuValue);
    }

int menuFct(int nombre)/* Identifying the menuValue, for single or multiplayer */
    {
        if(nombre == 1)
            {
                printf("Tu vas prendre ta raclée!\n\n");
                game();
            }
            else if(nombre == 2)
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
                printf("Il reste %d batons\n", nombreDeBatons);
                printf("Combien de batons voulez vous retirer ? Retirez entre 1 et 3 : ");
                scanf("%d", &batonsRetire);
                play(batonsRetire);
            }
        replayAI();
    }

int intro()/* Se lance au début de la partie. Permet de remettre le compteur de batons à 20 et de faire commencer l'IA. */
    {
        nombreDeBatons = 20;
        printf("Nous commencons avec %d batons\n", nombreDeBatons);
        printf("Je commence par retirer 3 batons.\n\n");
        nombreDeBatons = nombreDeBatons - 3;
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
            printf("Il reste %d batons\n", nombreDeBatons);
            batonsRetire = 4 - nombre;
            if (nombreDeBatons == 0){
                printf("Tu as perdu, you looser\n");
            }
            else{
                nombreDeBatons = nombreDeBatons - batonsRetire;
                printf("Je vais retirer %d batons\n\n", batonsRetire);
            }
        }
    }

int replayAI()/* Propose de rejouer la partie, entre une valeur*/
    {
        printf("Voulez-vous refaire une partie ? oui/non\n");
        scanf("%s", &replayValue);
        choix = strcmp(replayValue, oui);
        if (strcmp (replayValue,oui) == 0){
            printf("Okay let's go !\n");
            game();
        }
        else if (strcmp (replayValue,non) == 0){
            printf("Merci d'avoir joue !\n");
        }
        else {
            printf("Ceci n'est pas une reponse valide\n");
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
        printf("Voulez-vous refaire une partie ?\n");
        scanf("%s", &replayValue);
        choix = strcmp(replayValue, oui);
        if (strcmp (replayValue,oui) == 0){
            printf("Okay let's go !\n");
            multiplayer();
        }
        else if (strcmp (replayValue,non) == 0){
            printf("Merci d'avoir joue !\n");
        }
        else {
            printf("Ceci n'est pas une réponse valide\n");
            replayMulti();
        }
    }

int main()
    {
        printf("Bonjour humain.\n");

        menu();

        return 0;
    }
