#include <stdio.h>
#include "main.h"
#include "move.h"

void printBoard(char (*board) [BOARD_LENGTH]) {
	printBarrier();
	for (int i = BOARD_LENGTH - 1; i >= 0; i--) {
		for (int j = 0; j < BOARD_LENGTH; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printBarrier();
}

void printBarrier() {
	printf("========\n");
}

void clearBoard(char board [BOARD_LENGTH][BOARD_LENGTH]) {
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_LENGTH; j++) {
			board[i][j] = ' ';
		}
	}
}

void resetBoard(char board [BOARD_LENGTH][BOARD_LENGTH]) {
	//Clear board
	clearBoard(board);	

	// First rank
	board[0][0] = 'R';
	board[0][1] = 'N';
	board[0][2] = 'B';
	board[0][3] = 'Q';
	board[0][4] = 'K';
	board[0][5] = 'B';
	board[0][6] = 'N';
	board[0][7] = 'R';

	//Second rank
	for (int i = 0; i < BOARD_LENGTH; i++) {
		board[1][i] = 'P';
	}

	//Seventh rank
	for (int i = 0; i < BOARD_LENGTH; i++) {
		board[6][i] = 'p';
	}

	//Eighth rank
	board[7][0] = 'r';
	board[7][1] = 'n';
	board[7][2] = 'b';
	board[7][3] = 'q';
	board[7][4] = 'k';
	board[7][5] = 'b';
	board[7][6] = 'n';
	board[7][7] = 'r';
}


int main() {
	char board[8][8];
	resetBoard(board);
	printBoard(board);

	State state = {1, board};
	if (isMoveLegal(state)) {
		printf("Hooray!\n");
	}

	return 0;
}
