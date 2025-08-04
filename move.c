#include <stdio.h>
#include "move.h"

int isMoveLegal(State state) {
	if (state.isWhitesTurn) { return 1;}
	printf("%c", state.board[0][0]);
	return 0;
}
