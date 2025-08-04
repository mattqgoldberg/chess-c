#pragma once
#define BOARD_LENGTH 8

typedef struct {
	int isWhitesTurn;
	char (*board) [BOARD_LENGTH];
} State;
