#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "menu.h"
#include "rules.h"
#include "multi.h"
#include "replay_multi.h"


int main()
{
    printf("Bonjour humain.\n");
    printf("Bienvenue dans le jeu des batons. Que veux-tu faire ?\n");
    menu();
    return 0;
}
