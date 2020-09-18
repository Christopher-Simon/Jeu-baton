#include "ai.h"

int game() /* Boucle pour permettre au joueur de retirer entre 1 et 3 batons. Lance la fonction replay  la fin */
{
    int nombreDeBatons = 20;
    int batonsRetire = 0;
    nombreDeBatons = intro(nombreDeBatons);
    while (nombreDeBatons > 0)
        {
            printf("Il reste %d batons\n", nombreDeBatons);
            printf("Combien de batons voulez vous retirer ? Retirez entre 1 et 3 : ");
            scanf("%d", &batonsRetire);
            nombreDeBatons = play(batonsRetire, nombreDeBatons);
        }
    replayAI();
}

int intro(int nombre) /* Se lance au début de la partie. Permet de remettre le compteur de batons à 20 et de faire commencer l'IA. */
{
    int resultat;
    printf("Nous commencons avec %d batons\n", nombre);
    printf("Je commence par retirer 3 batons.\n\n");
    return resultat = nombre - 3;
}

int play(int nombreRetire, int nombre) /* Identifie la valeur entrée dans game, si elle est supérieur ou inférieur à 3, n'effectue aucune action */
{
    int resultat;
    if(nombreRetire >3 || nombreRetire <=0)
    {
        printf("Tu ne peux retirer qu'entre 1 et 3 batons\n\n");
    }
    else
    {
        nombre = nombre - nombreRetire;
        if (nombre == 0){
            printf("\nTu as retire le dernier baton\n");
            printf("********* GAME OVER *********\n");
        }
        else if (nombre <= 0){
            printf("\nTu as essaye d'en retirer trop, you still loose\n");
            printf("********* GAME OVER *********\n\n");
        }
        else{
        printf("Il reste %d batons\n", nombre);
        nombreRetire = 4 - nombreRetire;
        nombre = nombre - nombreRetire;
        printf("Je vais retirer %d batons\n\n", nombreRetire);
        }
    }
    return resultat = nombre;
}

void replayAI() /* Propose de rejouer la partie, entre une valeur*/
{
    char oui[]="oui";
    char non[]="non";
    char replayValue[3];
    int choix;
    printf("Voulez-vous refaire une partie ? (oui/non) :\n");
    scanf("%s", &replayValue);
    choix = strcmp(replayValue, oui);
    if (strcmp (replayValue,oui) == 0){
        printf("Okay let's go !\n");
        game();
    }
    else if (strcmp (replayValue,oui) == 1){
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayAI();
    }
}
