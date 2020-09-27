#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

int multiplayer();
int play_multi(nombreDeBatons, currentPlayer, player1, player2);
int launch_multi(nombreDeBatons, currentPlayer, player1, player2);
int rand_player();
void currentPlayerValue(currentPlayer, player1, player2);
int playMultiValue(int batonsRetire,int nombreDeBatons,int* a,int player1,int player2);

#endif // MULTI_H_INCLUDED
