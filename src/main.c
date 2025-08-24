#include <stdio.h>
#include "board.h"
#include "move.h"
#include "input.h"
#include "special.h"

int main() {
	char board[8][8];
	resetBoard(board);
	printBoard(board);

	// Initialize all 1's since all castling is allowed at the start
	Castle castle = (Castle){1,1,1,1};
	State state = {White, castle, board};

	while (1) {
		Move move = getMove();
		
		printf("%d %d, %d %d\n", move.start.row, move.start.col, move.end.row, move.end .col);

		if (isMoveCastles(&state, move)) {
			if (isLegalCastles(&state, move)) {
				executeMoveCastles(&state, move);
				printBoard(board);
			}
		}
		else if (isMoveLegal(&state, move)) {
			executeMove(&state, move);
			printBoard(board);
		}
		else {
			printf("Failed\n");
		}

		// printf("State: %d\n", state.turn);
	}

	return 0;
}
