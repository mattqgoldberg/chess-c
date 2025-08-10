#pragma once
#include "data.h"

// Rules return 1 if rule was followed properly
int ruleCheckCorrectTurn(char startPiece, State * state);
int ruleCheckStartingSquareNotEmpty(char startPiece);
int ruleCheckNotCapturingOwnPiece(char startPiece, char endPiece);
int ruleCheckPieceMoveset(char startPiece, char endPiece, Move move);
int ruleCheckStartAndEndDifferent(Move move);
//Helpers
int pieceIsBlack(char piece);
int pieceIsWhite(char piece);


// Main check
int isMoveLegal(State * state, Move move);

void executeMove(State * state, Move move);
