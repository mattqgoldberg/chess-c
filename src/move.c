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


//Helpers
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

void executeMove(State * state, Move move) {
	char piece = state->board[move.start.row][move.start.col];
	state->board[move.end.row][move.end.col] = piece;
	state->board[move.start.row][move.start.col] = ' ';

	if (state->turn == White) {
		state->turn = Black;
	}
	else {state->turn = White;}
}
