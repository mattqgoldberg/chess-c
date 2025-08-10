#include <stdio.h>
#include "testMoveset.h"


int main(void) {

    test_movesetKing();
    test_movesetKnight();
    test_movesetRook();
    test_movesetBishop();
    test_movesetPawn();
    test_movesetQueen();

    test_movesetBishopBlocked();
    test_movesetRookBlocked();
    test_movesetQueenBlocked();
    test_movesetPawnBlocked();
    printf("All tests passed!\n");
    return 0; // CTest sees 0 as success
}

