#include <assert.h>
#include "data.h"
#include "moveset.h"
#include "board.h"

void test_movesetKing() {

    //Test all 8 directions valid
    assert(movesetKing((Move){{4,4},{3,4}}) == 1);
    assert(movesetKing((Move){{4,4},{5,4}}) == 1);
    assert(movesetKing((Move){{4,4},{4,3}}) == 1);
    assert(movesetKing((Move){{4,4},{4,5}}) == 1);
    assert(movesetKing((Move){{4,4},{3,3}}) == 1);
    assert(movesetKing((Move){{4,4},{5,5}}) == 1);
    assert(movesetKing((Move){{4,4},{3,5}}) == 1);
    assert(movesetKing((Move){{4,4},{5,3}}) == 1);
        
    // same square should be invalid
    assert(movesetKing((Move){{4,4},{4,4}}) == 0);
    
    //Anything more than 1 square away should be invalid
    assert(movesetKing((Move){{4,4},{4,6}}) == 0);
    assert(movesetKing((Move){{4,4},{4,7}}) == 0);
    assert(movesetKing((Move){{4,4},{2,4}}) == 0);
    assert(movesetKing((Move){{4,4},{1,4}}) == 0);
    assert(movesetKing((Move){{4,4},{0,0}}) == 0);
}

void test_movesetRook() {

    assert(movesetRook((Move){{4,4},{4,0}}) == 1);
    assert(movesetRook((Move){{4,4},{0,4}}) == 1);
    assert(movesetRook((Move){{4,4},{4,7}}) == 1);

    assert(movesetRook((Move){{4,4},{0,0}}) == 0);
    assert(movesetRook((Move){{4,4},{7,5}}) == 0);
}

void test_movesetKnight() {

    assert(movesetKnight((Move){{4,4},{5,6}}) == 1);
    assert(movesetKnight((Move){{4,4},{6,5}}) == 1);
    assert(movesetKnight((Move){{4,4},{3,2}}) == 1);
    assert(movesetKnight((Move){{4,4},{2,3}}) == 1);
    assert(movesetKnight((Move){{4,4},{5,2}}) == 1);
    assert(movesetKnight((Move){{4,4},{2,3}}) == 1);
    assert(movesetKnight((Move){{4,4},{6,3}}) == 1);
    assert(movesetKnight((Move){{4,4},{2,5}}) == 1);


    assert(movesetKnight((Move){{4,4},{4,4}}) == 0);
    assert(movesetKnight((Move){{4,4},{4,5}}) == 0);
    assert(movesetKnight((Move){{4,4},{3,5}}) == 0);

    assert(movesetKnight((Move){{4,4},{3,4}}) == 0);
    assert(movesetKnight((Move){{4,4},{5,4}}) == 0);
    assert(movesetKnight((Move){{4,4},{7,1}}) == 0);
}

void test_movesetBishop() {

    assert(movesetBishop((Move){{4,4},{5,5}}) == 1);
    assert(movesetBishop((Move){{4,4},{3,3}}) == 1);
    assert(movesetBishop((Move){{4,4},{3,5}}) == 1);
    assert(movesetBishop((Move){{4,4},{5,3}}) == 1);

    assert(movesetBishop((Move){{4,4},{4,5}}) == 0);
    assert(movesetBishop((Move){{4,4},{5,4}}) == 0);
    assert(movesetBishop((Move){{4,4},{5,6}}) == 0);
}


void test_movesetQueen() {

    assert(movesetQueen((Move){{4,4},{5,5}}) == 1);
    assert(movesetQueen((Move){{4,4},{3,3}}) == 1);
    assert(movesetQueen((Move){{4,4},{3,5}}) == 1);
    assert(movesetQueen((Move){{4,4},{5,3}}) == 1);

    assert(movesetQueen((Move){{4,4},{4,5}}) == 1);
    assert(movesetQueen((Move){{4,4},{5,4}}) == 1);
    assert(movesetQueen((Move){{4,4},{4,0}}) == 1);
    assert(movesetQueen((Move){{4,4},{0,4}}) == 1);
    assert(movesetQueen((Move){{4,4},{4,7}}) == 1);

    assert(movesetQueen((Move){{4,4},{5,6}}) == 0);
    assert(movesetQueen((Move){{4,4},{6,5}}) == 0);
    assert(movesetQueen((Move){{4,4},{3,2}}) == 0);
    assert(movesetQueen((Move){{4,4},{2,3}}) == 0);
    assert(movesetQueen((Move){{4,4},{5,2}}) == 0);
    assert(movesetQueen((Move){{4,4},{2,3}}) == 0);
    assert(movesetQueen((Move){{4,4},{6,3}}) == 0);
    assert(movesetQueen((Move){{4,4},{2,5}}) == 0);
}

void test_movesetPawn() {

    // White pawn moves
    assert(movesetPawn((Move){{4,4},{5,4}}, 'P', ' ') == 1);
    assert(movesetPawn((Move){{4,4},{5,4}}, 'P', 'r') == 0);
    assert(movesetPawn((Move){{4,4},{6,4}}, 'P', ' ') == 0);
    assert(movesetPawn((Move){{4,4},{6,4}}, 'P', 'r') == 0);
    assert(movesetPawn((Move){{4,4},{3,4}}, 'P', ' ') == 0);

    //Move 2 from starting pos
    assert(movesetPawn((Move){{1,1},{3,1}}, 'P', ' ') == 1);

    //White pawn captures
    assert(movesetPawn((Move){{1,1},{2,2}}, 'P', 'r') == 1);
    assert(movesetPawn((Move){{1,1},{2,2}}, 'P', ' ') == 0);
    assert(movesetPawn((Move){{1,1},{2,0}}, 'P', 'r') == 1);
    assert(movesetPawn((Move){{1,1},{2,0}}, 'P', ' ') == 0);

    // Black pawn moves
    assert(movesetPawn((Move){{4,4},{3,4}}, 'p', ' ') == 1);
    assert(movesetPawn((Move){{4,4},{3,4}}, 'p', 'R') == 0);
    assert(movesetPawn((Move){{4,4},{2,4}}, 'p', ' ') == 0);
    assert(movesetPawn((Move){{4,4},{2,4}}, 'p', 'R') == 0);

    //Move 2 from starting pos
    assert(movesetPawn((Move){{6,1},{4,1}}, 'p', ' ') == 1);

    //White pawn captures
    assert(movesetPawn((Move){{4,4},{3,3}}, 'p', 'R') == 1);
    assert(movesetPawn((Move){{4,4},{3,3}}, 'p', ' ') == 0);
    assert(movesetPawn((Move){{4,4},{3,5}}, 'p', 'R') == 1);
}

void test_movesetBishopBlocked() {
    char board[8][8];
    clearBoard(board);

    board[4][4] = 'B';
    board[5][5] = 'Q';
    board[6][6] = 'p';

    State state = {White, board};
    assert(movesetBishopBlocked((Move){{4,4},{6,6}}, &state) == 0);
    assert(movesetBishopBlocked((Move){{4,4},{3,3}}, &state) == 1);

}

void test_movesetPawnBlocked() {

    char board[8][8];
    clearBoard(board);
    board[1][1] = 'P';
    board[2][1] = 'Q';

    board[1][3] = 'P';
    State state = {White, board};

    assert(movesetPawnBlocked((Move){{1,1},{3,1}}, &state) == 0);
    assert(movesetPawnBlocked((Move){{1,3},{3,3}}, &state) == 1);

}

void test_movesetQueenBlocked() {

    char board[8][8];
    clearBoard(board);

    board[4][4] = 'R';
    board[5][5] = 'P';
    board[4][5] = 'Q';
    board[3][4] = 'K';

    State state = {White, board};
    assert(movesetQueenBlocked((Move){{4,4},{4,6}}, &state) == 0);
    assert(movesetQueenBlocked((Move){{4,4},{6,6}}, &state) == 0);
    assert(movesetQueenBlocked((Move){{4,4},{2,2}}, &state) == 1);
    assert(movesetQueenBlocked((Move){{4,4},{1,4}}, &state) == 0);
    assert(movesetQueenBlocked((Move){{4,4},{5,4}}, &state) == 1);
}

void test_movesetRookBlocked() {
    char board[8][8];
    clearBoard(board);

    board[4][4] = 'R';
    board[4][5] = 'Q';
    board[3][4] = 'K';

    State state = {White, board};
    assert(movesetRookBlocked((Move){{4,4},{4,6}}, &state) == 0);
    assert(movesetRookBlocked((Move){{4,4},{1,4}}, &state) == 0);
    assert(movesetRookBlocked((Move){{4,4},{5,4}}, &state) == 1);
}





    
