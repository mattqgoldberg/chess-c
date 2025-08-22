#include <assert.h>
#include "data.h"
#include "moveset.h"

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

}


void test_movesetQueen() {

}

void test_movesetPawn() {

}

void test_movesetBishopBlocked() {

}

void test_movesetPawnBlocked() {

}

void test_movesetQueenBlocked() {

}

void test_movesetRookBlocked() {

}





    
