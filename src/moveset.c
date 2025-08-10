#include "data.h"
#include "moveset.h"
#include <stdlib.h>

int movesetKing(Move move) {
	
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {

			if (i == 0 && j == 0) {continue;}

			if (move.end.row == move.start.row + i) {
				if (move.end.col == move.start.col + j) {
					return 1;
				}
			}
		}
	}

	return 0;
		
}

int movesetKnight(Move move) {
	
	if (abs(move.start.row - move.end.row) == 1) {
		if ((move.start.col - move.end.col) == 2) {
			return 1;
		}
	}
	else if (abs(move.start.row - move.end.row) == 2) {
		if (abs(move.start.col - move.end.col) == 1) {
			return 1;
		}
	}
	return 0;
}

int movesetRook(Move move) {

	if (move.start.row - move.end.row == 0) {
		return 1;
	}
	else if (move.start.col - move.end.col == 0) {
		return 1;
	}
	return 0;
}


int movesetBishop(Move move) {
	
	return abs(move.start.row - move.end.row) == abs(move.start.col - move.end.col);
}

int movesetQueen(Move move) {
	return movesetBishop(move) || movesetRook(move);
}

int movesetPawn(Move move, char startPiece, char endPiece) {
	if (startPiece == 'P') {
		// Move pawn forward 2 if starting position
		if (move.start.row == 1 && move.end.row == 3 && move.start.col == move.end.col) {
			return 1;
		}
		//Move forward if no capture
		if (move.start.row + 1 == move.end.row && move.start.col == move.end.col && endPiece == ' ') {
			return 1;
		}
		//Move diagonal capture
		if (move.start.row + 1 == move.end.row && abs(move.start.col - move.end.col) == 1 && endPiece != ' ') {
			return 1;
		}
	}
	if (startPiece == 'p') {
		// Move pawn forward 2 if starting position
		if (move.start.row == 6 && move.end.row == 4 && move.start.col == move.end.col) {
			return 1;
		}
		//Move forward if no capture
		if (move.start.row - 1 == move.end.row && move.start.col == move.end.col && endPiece == ' ') {
			return 1;
		}
		//Move diagonal capture
		if (move.start.row - 1 == move.end.row && abs(move.start.col - move.end.col) == 1 && endPiece != ' ') {
			return 1;
		}
	}

	return 0;
}




