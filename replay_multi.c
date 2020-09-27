#include "replay_multi.h"

int replayMulti(player1, player2)
{
    char replayValue[3];
    printf("Voulez-vous refaire une partie ? (oui/non) :");
    scanf("%s", &replayValue);
    printf("replayValue = %s\n", replayValue);
    if (strcmp (replayValue,"oui") == 0){
        printf("Okay let's go !\n");
        launch_multi(player1, player2);
    }
    else if (strcmp (replayValue,"non") == 0){
        menu();
    }
    else {
        printf("Ceci n'est pas une reponse valide\n");
        replayMulti();
    }
}
