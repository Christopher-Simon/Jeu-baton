#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "menu.h"
#include "rules.h"
#include "multi.h"
#include "replay_multi.h"

int main()
{
    int a;
    char buf[1024]; // use 1KiB just to be sure

    // repeat until we got a valid number

    printf("You entered %d.\n", a);
    printf("Bonjour humain.\n");
    printf("Bienvenue dans le jeu des batons. Que veux-tu faire ?\n");
    menu();
    return 0;
}
