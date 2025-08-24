#include "piece.h"

int pieceIsEmpty(char piece) {
	return (piece == ' ');
}

int pieceIsWhite(char piece) {
	return (piece >= 'A' && piece <= 'Z');
}

int pieceIsBlack(char piece) {
	return (piece >= 'a' && piece <= 'z');
}
