#include <stdio.h>
#include "board.h"
#include "move.h"
#include "input.h"
#include "special.h"
#include "moveList.h"

int main() {
	char board[8][8];
	resetBoard(board);

	clearBoard(board);
	board[4][4] = 'K';
	printBoard(board);

	// Initialize all 1's since all castling is allowed at the start
	Castle castle = (Castle){1,1,1,1};
	State state = {White, castle, board};


	while (1) {
		Move move = getMove();
		
		printf("%d %d, %d %d\n", move.start.row, move.start.col, move.end.row, move.end.col);


		Point p = {move.start.row, move.start.col};
		Move moveList[32];
		printf("Here\n");
		int numMoves = getPieceLegalMoves(&state, p, moveList);

		printf("Number of legal moves: %d\n", numMoves);
	
		for (int i = 0; i < numMoves; i++) {
			Move m = moveList[i];
			printMove(m);
		}

		continue;





		if (isMoveCastles(&state, move)) {
			printf("urmom\n");
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

		// printf("State: %d", state.turn);
	}

	return 0;
}
