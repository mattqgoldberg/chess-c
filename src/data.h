#pragma once
#define BOARD_LENGTH 8

enum Turn {
	White,
	Black
};

typedef struct {
	enum Turn turn;
	char (*board) [BOARD_LENGTH];
} State;

typedef struct {
	int row;
	int col;
} Point;

typedef struct {
	Point start;
	Point end;
} Move;
