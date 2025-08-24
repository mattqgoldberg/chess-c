#include "data.h"
#include "move.h"
#include "piece.h"
#include "moveset.h"
#include "moveList.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


int pieceMatchesTurn(char piece, State * state) {
	if (pieceIsWhite(piece) && state->turn == White) {return 1;}
	if (pieceIsBlack(piece) && state->turn == Black) {return 1;}
	return 0;
}

int getPieceLegalMoves(State * state, Point p, Move moves[32]) {
	
	char piece = getPieceAtPoint(state, p);

	if (pieceIsEmpty(piece)) {return 0;}

	if (!pieceMatchesTurn(piece, state)) {return 0;}
		
	switch (piece) {
		case 'K':
			return getKingMoves(state, p, moves);
		default:
			return 0;
		
	}
}

int getKingMoves(State * state, Point p, Move moves[32]) {

	int m = 0;
	
	for (int i = 0; i < BOARD_LENGTH; i++) {
		for (int j = 0; j < BOARD_LENGTH; j++) {
			Move move = {{p.row,p.col},{i,j}};
			if (movesetKing(move)) {
				moves[m] = move;
				m++;
			}
		}
	}

	return m;
}

