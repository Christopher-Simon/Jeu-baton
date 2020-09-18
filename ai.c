#include "ai.h"

int game() /* Boucle pour permettre au joueur de retirer entre 1 et 3 batons. Lance la fonction replay  la fin */
{
    int nombreDeBatons = 20;
    char buf[1024];
    nombreDeBatons = intro(nombreDeBatons);
    while (nombreDeBatons > 0)
        {
            int batonsRetire = 0;
            printf("Il reste %d batons\n", nombreDeBatons);

            while (batonsRetire == 0)
            {
                printf("Combien de batons souhaites tu retirer ? Entre 1 et 3 uniquement: ");
                if (!fgets(buf, 1024, stdin))
                {
                    // reading input failed, give up:
                    return 1;
                }

                // have some input, convert it to integer:
                batonsRetire = atoi(buf);
            }

            printf("Tu veux en retirer %d ?\n", batonsRetire);

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
    char replayValue[3];
    printf("Voulez-vous refaire une partie ? (oui/non) :\n");
    scanf("%s", &replayValue);
    if (strcmp (replayValue,"oui") == 0){
        printf("Okay let's go !\n");
        game();
    }
    else if (strcmp (replayValue,"non") == 0){
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayAI();
    }
}
