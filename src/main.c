#include <stdio.h>
#include "board.h"
#include "move.h"
#include "input.h"

int main() {
	char board[8][8];
	resetBoard(board);
	printBoard(board);

	State state = {White, board};

	while (1) {
		Move move = getMove();
		
		printf("%d %d, %d %d\n", move.start.row, move.start.col, move.end.row, move.end .col);
		
		if (isMoveLegal(&state, move)) {
			executeMove(&state, move);
			printBoard(board);
		}
		else {
			printf("Failed\n");
		}

		// printf("State: %d", state.turn);
	}

	return 0;
}
