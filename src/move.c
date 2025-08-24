#include <stdio.h>
#include "move.h"
#include "moveset.h"
#include <ctype.h>

int pieceIsWhite(char piece) {
	return (piece >= 'A' && piece <= 'Z');
}

int pieceIsBlack(char piece) {
	return (piece >= 'a' && piece <= 'z');
}

int movesAreEqual(Move a, Move b) {
	if (a.start.row == b.start.row && a.start.col == b.start.col) {
		if (a.end.row == b.end.row && a.end.col == b.end.col) {
			return 1;
		}
	}
	return 0;
}

int pointsAreEqual(Point a, Point b) {
	return (a.row == b.row && a.col == b.col);
}

int ruleCheckCorrectTurn(char startPiece, State * state) {
	if (state->turn == White && pieceIsWhite(startPiece)) {
		return 1;
	}
	if (state->turn == Black && pieceIsBlack(startPiece)) {
		return 1;
	}
	return 0;
}

int ruleCheckStartingSquareNotEmpty(char startPiece) {
	if (startPiece != ' ') {
		return 1;
	}
	return 0;
}

int ruleCheckNotCapturingOwnPiece(char startPiece, char endPiece){
	if (endPiece == ' ') {return 1;}

	if (pieceIsWhite(startPiece)) {
		if (pieceIsWhite(endPiece)) {
			return 0;
		} else {return 1;}
	}
	
	if (pieceIsBlack(startPiece)) {
		if (pieceIsBlack(endPiece)) {
			return 0;
		} else {return 1;}
	}
	
	return 0;
}

int ruleCheckStartAndEndDifferent(Move move) {
	return move.start.row != move.end.row || move.start.col != move.end.col;
}

int ruleCheckPieceMoveset(char startPiece, char endPiece, Move move) {
	switch (toupper(startPiece)) {
		case 'K':
			return movesetKing(move);
		case 'N':
			return movesetKnight(move);
		case 'B':
			return movesetBishop(move);
		case 'R':
			return movesetRook(move);
		case 'Q':
			return movesetQueen(move);
		case 'P':
			return movesetPawn(move, startPiece, endPiece);
		default:
			return 0;
	}
}

int ruleCheckPathNotBlocked(char startPiece, Move move, State * state) {
	switch(toupper(startPiece)) {
		case 'R':
			return movesetRookBlocked(move, state);
		case 'B':
			return movesetBishopBlocked(move, state);
		case 'Q':
			return movesetQueenBlocked(move, state);
		case 'P':
			return movesetPawnBlocked(move, state);
		default:
			return 1;
	}
}

int isMoveLegal(State * state, Move move) {

	char startPiece = state->board[move.start.row][move.start.col];
	char endPiece = state->board[move.end.row][move.end.col];


	// printf("%c %c\n", startPiece, endPiece); 

	if (!ruleCheckCorrectTurn(startPiece, state)) {return 0;}
	if (!ruleCheckStartingSquareNotEmpty(startPiece)) {return 0;}
	if (!ruleCheckNotCapturingOwnPiece(startPiece,endPiece)) {return 0;}
	if (!ruleCheckStartAndEndDifferent(move)) {return 0;}
	if (!ruleCheckPieceMoveset(startPiece, endPiece, move)) {return 0;}
	if (!ruleCheckPathNotBlocked(startPiece, move, state)) {return 0;}
	return 1;
}

void updateState(State * state, Move move) {
	if (state->turn == White) {
		state->turn = Black;
	}
	else {state->turn = White;}

	char startPiece = state->board[move.start.row][move.start.col];

	Point whiteKing = {0,4};
	Point blackKing = {7,4};
	if (pointsAreEqual(whiteKing, move.start) || pointsAreEqual(whiteKing, move.end)) {
		state->castle.whiteCanShortCastle = 0;
		state->castle.whiteCanLongCastle = 0;
	}
	if (pointsAreEqual(blackKing, move.start) || pointsAreEqual(blackKing, move.end)) {
		state->castle.blackCanShortCastle = 0;
		state->castle.blackCanLongCastle = 0;
	}

	Point whiteShortRook = {0,7};
	Point whiteLongRook = {0,0};

	if (pointsAreEqual(whiteShortRook, move.start) || pointsAreEqual(whiteShortRook, move.end)) {
		state->castle.whiteCanShortCastle = 0;
	}
	if (pointsAreEqual(whiteLongRook, move.start) || pointsAreEqual(whiteLongRook, move.end)) {
		state->castle.whiteCanLongCastle = 0;
	}

	Point blackShortRook = {7,7};
	Point blackLongRook = {7,0};

	if (pointsAreEqual(blackShortRook, move.start) || pointsAreEqual(blackShortRook, move.end)) {
		state->castle.blackCanShortCastle = 0;
	}
	if (pointsAreEqual(blackLongRook, move.start) || pointsAreEqual(blackLongRook, move.end)) {
		state->castle.blackCanLongCastle = 0;
	}
}

void executeMove(State * state, Move move) {
	char piece = state->board[move.start.row][move.start.col];
	state->board[move.end.row][move.end.col] = piece;
	state->board[move.start.row][move.start.col] = ' ';

}
