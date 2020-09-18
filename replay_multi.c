#include "replay_multi.h"

int replayMulti()
{
    char oui[]="oui";
    char non[]="non";
    char replayValue[3];
    int choix;
    printf("Voulez-vous refaire une partie ? (oui/non) :");
    scanf("%s", &replayValue);
    choix = strcmp(replayValue, oui);
    if (strcmp (replayValue,oui) == 0){
        printf("Okay let's go !\n");
        multiplayer();
    }
    else if (strcmp (replayValue, non) == 0){
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayMulti();
    }
}
