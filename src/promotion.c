#include "data.h"
#include "promotion.h"
#include "moveset.h"
#include "move.h"
#include <ctype.h>

int isMovePromotion(State * state, Move move) {
	char piece = getPieceAtPoint(state, move.start);
	if (piece == 'P' && move.end.row == 7) {return 1;}
	if (piece == 'p' && move.end.row == 1) {return 1;}

	return 0;
}

int isPromotionLegal(State * state, Move move) {
	char startPiece = getPieceAtPoint(state, move.start);
	char endPiece = getPieceAtPoint(state, move.end);
	if (movesetPawn(move, startPiece, endPiece)) {
		if (movesetPawnBlocked(move, state) && promotionPieceValid(startPiece, move.promotionPiece)) {
			return 1;
		}
	}
	return 0;	
}

int promotionPieceValid(char startPiece, char promotionPiece) {
	if (promotionPiece == 'R' || promotionPiece == 'B' || promotionPiece == 'Q' || promotionPiece == 'N') {
		return 1;
	}
	return 0;
}



void executePromotion(State * state, Move move) {

	char startPiece = getPieceAtPoint(state, move.start);
	executeMove(state, move);

	if (pieceIsWhite(startPiece)) {
		state->board[move.end.row][move.end.col] = toupper(move.promotionPiece);
	}
	else {
		state->board[move.end.row][move.end.col] = tolower(move.promotionPiece);
	}

}


