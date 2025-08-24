#pragma once
#include "data.h"

int pieceMatchesTurn(char piece, State * state);
int getPieceLegalMoves(State * state, Point p, Move moves[32]);

int getKingMoves(State * state, Point p, Move moves[32]);
