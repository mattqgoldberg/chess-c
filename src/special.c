#include "special.h"
#include "move.h"

int isMoveCastles(State * state, Move move) {
	char startPiece = state->board[move.start.row][move.start.col];
	char endPiece = state->board[move.end.row][move.end.col];

	if (startPiece == 'K') {
		Move shortCastle = (Move){{0,4},{0,6}};
		Move longCastle = (Move){{0,4},{0,2}};

		if (movesAreEqual(move, shortCastle)) {return 1;}
		if (movesAreEqual(move, longCastle)) {return 1;}
	}

	if (startPiece == 'k') {
		Move shortCastle = (Move){{7,4},{7,6}};
		Move longCastle = (Move){{7,4},{7,2}};

		if (movesAreEqual(move, shortCastle)) {return 1;}
		if (movesAreEqual(move, longCastle)) {return 1;}
	}
	return 0;
}

int isLegalCastles(State * state, Move move) {
	
	Move whiteShortCastle = (Move){{0,4},{0,6}};
	Move whiteLongCastle = (Move){{0,4},{0,2}};
	Move blackShortCastle = (Move){{7,4},{7,6}};
	Move blackLongCastle = (Move){{7,4},{7,2}};

	if (movesAreEqual(move, whiteShortCastle)) {
		if (!state->castle.whiteCanShortCastle)	{return 0;}	
		if (state->board[0][4] != 'K') {return 0;}
		if (state->board[0][5] != ' ') {return 0;}
		if (state->board[0][6] != ' ') {return 0;}
		if (state->board[0][7] != 'R') {return 0;}
	}

	if (movesAreEqual(move, whiteLongCastle)) {
		if (!state->castle.whiteCanLongCastle)	{return 0;}	
		if (state->board[0][4] != 'K') {return 0;}
		if (state->board[0][3] != ' ') {return 0;}
		if (state->board[0][2] != ' ') {return 0;}
		if (state->board[0][1] != ' ') {return 0;}
		if (state->board[0][0] != 'R') {return 0;}
	}
	
	if (movesAreEqual(move, blackShortCastle)) {
		if (!state->castle.blackCanShortCastle)	{return 0;}	
		if (state->board[7][4] != 'k') {return 0;}
		if (state->board[7][5] != ' ') {return 0;}
		if (state->board[7][6] != ' ') {return 0;}
		if (state->board[7][7] != 'r') {return 0;}
	}

	if (movesAreEqual(move, blackLongCastle)) {
		if (!state->castle.blackCanLongCastle)	{return 0;}	
		if (state->board[7][4] != 'k') {return 0;}
		if (state->board[7][3] != ' ') {return 0;}
		if (state->board[7][2] != ' ') {return 0;}
		if (state->board[7][1] != ' ') {return 0;}
		if (state->board[7][0] != 'r') {return 0;}
	}

	return 1;
}

void executeMoveCastles(State * state, Move move) {

	Move whiteShortCastle = (Move){{0,4},{0,6}};
	Move whiteLongCastle = (Move){{0,4},{0,2}};
	Move blackShortCastle = (Move){{7,4},{7,6}};
	Move blackLongCastle = (Move){{7,4},{7,2}};

	if (movesAreEqual(move, whiteShortCastle)) {
		state->board[0][4] = ' ';
		state->board[0][5] = 'R';
		state->board[0][6] = 'K';
		state->board[0][7] = ' ';
	}

	if (movesAreEqual(move , whiteLongCastle)) {
		state->board[0][0] = ' ';
		state->board[0][1] = ' ';
		state->board[0][2] = 'K';
		state->board[0][3] = 'R';
		state->board[0][4] = ' ';
	}

	if (movesAreEqual(move, blackShortCastle)) {
		state->board[7][4] = ' ';
		state->board[7][5] = 'R';
		state->board[7][6] = 'K';
		state->board[7][7] = ' ';
	}

	if (movesAreEqual(move , blackLongCastle)) {
		state->board[7][0] = ' ';
		state->board[7][1] = ' ';
		state->board[7][2] = 'K';
		state->board[7][3] = 'R';
		state->board[7][4] = ' ';
	}

	updateState(state, move);
}

