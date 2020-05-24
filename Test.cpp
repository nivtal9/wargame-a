//
// Created by nivtal9 on 24.5.2020.
//


#include "Soldier.hpp"
#include "Board.hpp"
#include "doctest.h"
#include "FootSoldier.hpp"

TEST_CASE("assert has soldiers method") {
    WarGame::Board board(8,8);
        board[{0,1}] = new FootSoldier(1);
    for (int i = 0; i < 100; i++) {
                CHECK(board.has_soldiers(1));
    }
}