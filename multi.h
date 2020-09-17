#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED

int multiplayer();
int play_multi(nombreDeBatons, batonsRetire, player1, player2, currentPlayer);
int currentPlayerValue(currentPlayer, player1, player2);
int playMultiValue(batonsRetire, nombreDeBatons);
int change_turn(currentPlayer);
int replayMulti();

#endif // MULTI_H_INCLUDED
