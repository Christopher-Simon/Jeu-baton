#include "replay_multi.h"

int replayMulti()
{
    char replayValue[3];
    printf("Voulez-vous refaire une partie ? (oui/non) :");
    scanf("%s", &replayValue);
    printf("replayValue = %s\n", replayValue);
    if (strcmp (replayValue,"oui") == 0){
        printf("Okay let's go !\n");
        multiplayer();
    }
    else if (strcmp (replayValue,"non") == 0){
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayMulti();
    }
}
