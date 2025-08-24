#pragma once
#include "data.h"

int isMovePromotion(State * state, Move move);
int isPromotionLegal(State * state, Move move);
void executePromotion(State * state, Move move);
int promotionPieceValid(char startPiece, char promotionPiece);

