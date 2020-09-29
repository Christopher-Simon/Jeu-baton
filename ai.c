#include "ai.h"

int launch()
{
    int nbround = 0;
    printf("Tu vas prendre ta raclee!\n\n");
    game(nbround);

}

int game(nbround) /* Boucle pour permettre au joueur de retirer entre 1 et 3 batons. Lance la fonction replay  la fin */
{
    int nombreDeBatons = 20;
    char buf[1024];

    nbround++;
    round_message(nbround);
    printf("Round %d\n", nbround);

    nombreDeBatons = intro(nombreDeBatons);

    while (nombreDeBatons > 0)
        {
            int batonsRetire = 0;
            printf("Il reste %d batons\n", nombreDeBatons);
            printf("Combien de batons souhaites tu retirer ? Entre 1 et 3 uniquement: ");

            while (batonsRetire == 0)
            {
                if (!fgets(buf, 1024, stdin))
                {
                    // reading input failed, give up:
                    return 1;
                }

                // have some input, convert it to integer:
                batonsRetire = atoi(buf);
            }

            printf("Tu veux en retirer %d ?\n\n", batonsRetire);

            nombreDeBatons = play(batonsRetire, nombreDeBatons);
        }
    replayAI(nbround);
}

int round_message(nbround)
{
    if(nbround == 2)
    {
        printf("Je suis content de voir que vous jetiez un coup d'oeil !\n\n");
        printf("Et sans transition, je vous donne plus de details sur mes motivations et mon background.\n\n");
        printf("Je suis diplome de l ecole de management de Grenoble. \n\n");
        printf("J'ai multiplie les projets entrepreneuriaux:\n");
        printf("La creation d un reseau social gaming (je travaillais avec des devs et une designer en y connaissant rien, pire idee).\n");
        printf("Un outil de rencontre rh pour les grands groupes (pour lequel j'ai plonge dans le Ruby et qu'on a teste juste avant le confinement).\n");
        printf("Du freelance pour aider dans le telemanagement (mais le service pur, ce n'est pas vraiment pour moi).\n\n");
        printf("Je veux continuer a creer : apprendre techniquement et partager humainement.\n");
        printf("Et je pense que 42 combine a la perfection ces deux mondes. \n\n");
        printf("Vous pouvez reprendre votre partie !\n\n");
    }
    if(nbround == 3)
    {
        printf("Jamais deux sans trois\n\n");
    }
    if(nbround == 4)
    {
        printf("Tu commences a y prendre goût\n\n");
    }
    if(nbround == 5)
    {
        printf("Aller, celle la c'est la bonne\n\n");
    }
    if(nbround == 6)
    {
        printf("C'est pas commme ca que tu vas reussir à me vaincre\n\n");
    }
    if(nbround == 10)
    {
        printf("Tu peux recommencer, mais je triche donc tu ne peux pas gagner\n\n");
    }

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
    if(nombreRetire == 42)
    {
        printf("C'est le sens de la vie, c'est vrai.\n");
        printf("On arrete tout, mais ca ne veut pas dire que tu gagnes!\n");
        main();
    }

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

void replayAI(nbround) /* Propose de rejouer la partie, entre une valeur*/
{
    char replayValue[3];
    printf("Voulez-vous refaire une partie ? (oui/non) :\n");
    scanf("%s", &replayValue);
    if (strcmp (replayValue,"oui") == 0){
        printf("Okay let's go !\n");
        system("clear");
        game(nbround);
    }
    else if (strcmp (replayValue,"non") == 0){
        system("clear");
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayAI(nbround);
    }
}
