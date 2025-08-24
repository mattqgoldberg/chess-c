#pragma once 
#include "data.h"
int isMoveCastles(State * state, Move move);
int isLegalCastles(State * state, Move move);
void executeMoveCastles(State * state, Move move);
