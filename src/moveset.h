#pragma once
#include "data.h"

int movesetKing(Move move);
int movesetKnight(Move move);
int movesetRook(Move move);
int movesetBishop(Move move);
int movesetPawn(Move move, char startPiece, char endPiece);
int movesetQueen(Move move);

int movesetBishopBlocked(Move move, State * state);
int movesetRookBlocked(Move move, State * state);
int movesetQueenBlocked(Move move, State * state);
int movesetPawnBlocked(Move move, State * state);

