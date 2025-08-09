#pragma once
#define BOARD_LENGTH 8

enum Turn {
	White,
	Black
};

typedef struct {
	int isWhitesTurn;
	char (*board) [BOARD_LENGTH];
} State;
