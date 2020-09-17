#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "menu.h"
#include "rules.h"


int currentPlayer = 1;
char player1[100];
char player2[100];
// Variable pour replay or not
char oui[]="oui";
char non[]="non";
char replayValue[];
int choix;

/*int multiplayer()
    {
        int nombreDeBatons = 20;
        printf("Nom du joueur 1 : ");
        scanf("%s", player1);

        printf("Nom du joueur 2 : ");
        scanf("%s", player2);
        printf("La partie commence avec 20 batons\n");

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
                printf("\nC'est a %s de jouer\n", player1);
                printf("Nombre de batons à retirer : ");
            }
        else
            {
                printf("\nC'est a %s de jouer\n", player2);
                printf("Nombre de batons à retirer : ");
            }
    }

int playMulti()
    {
        currentPlayerValue();
        scanf("%d", &batonsRetire);
        playMultiValue(batonsRetire);
        if (nombreDeBatons >= 0){
        printf("Il reste %d batons\n", nombreDeBatons);
        }
        else{
        printf("Bien essayé, tu as voulu en retirer trop. Il reste 0 batons\n", nombreDeBatons);
        }
    }

int playMultiValue(int nombre) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
    /*{
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
    }*/



int main()
    {
        printf("Bonjour humain.\n");
        printf("Bienvenue dans le jeu des batons. Que veux-tu faire ?\n");
        menu();
        return 0;
    }
