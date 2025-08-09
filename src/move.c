#include <stdio.h>
#include "move.h"



int isMoveLegal(State state, Move move) {
	return 1;
}

void executeMove(State state, Move move) {
	char piece = state.board[move.start.row][move.start.col];
	state.board[move.end.row][move.end.col] = piece;
	state.board[move.start.row][move.start.col] = ' ';

	if (state.turn == White) {
		state.turn = Black;
	}
	else {state.turn = White;}
}
