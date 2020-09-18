#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

int multiplayer();
int play_multi(nombreDeBatons, player1, player2);
int currentPlayerValue(currentPlayer, player1, player2);
int playMultiValue(int batonsRetire,int nombreDeBatons,int* a,int player1,int player2);
int change_turn(currentPlayer);

#endif // MULTI_H_INCLUDED
