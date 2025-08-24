#pragma once
#define BOARD_LENGTH 8

enum Turn {
	White,
	Black
};

typedef struct {
	int whiteCanShortCastle;
	int whiteCanLongCastle;
	int blackCanShortCastle;
	int blackCanLongCastle;
} Castle;

typedef struct {
	enum Turn turn;
	Castle castle;
	char (*board) [BOARD_LENGTH];
} State;

typedef struct {
	int row;
	int col;
} Point;

typedef struct {
	Point start;
	Point end;
	char promotionPiece;
} Move;
