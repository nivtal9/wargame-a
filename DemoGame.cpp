/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include <assert.h>
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"


namespace WarGame {

    DemoGame::DemoGame(): board (numRows, numCols) {
       /* // Add soldiers for player 1:
        //assert(!board.has_soldiers(1));
        board[{0,1}] = new FootSoldier(1);
        board[{0,3}] = new FootCommander(1);
        board[{0,5}] = new FootSoldier(1);
        //assert(board.has_soldiers(1));

        // Add soldiers for player 2:
        //assert(!board.has_soldiers(2));
        board[{7,1}] = new FootSoldier(2);
        board[{7,3}] = new FootCommander(2);
        board[{7,5}] = new FootSoldier(2);
        //assert(board.has_soldiers(2));
*/        WarGame::Board board(8,8);
        assert(!board.has_soldiers(1));
        board[{0,1}] = new FootSoldier(1);//player 1 footSoldier1 {0,1}
        // CHECK_THROWS((board[{0,1}] = new FootSoldier(1))); //there is already soldier there
        board[{0,0}] = new FootCommander(1); //player 1 commanderSoldier {0,0}
        board[{0,2}] = new FootSoldier(1);//player 1 footSoldier2 {0,2}
        assert(board.has_soldiers(1)); //there is no need to write this any time

        assert(!board.has_soldiers(2));
        board[{7,0}] = new FootCommander(2);//player 2 commanderSoldier {7,0}
        board[{7,1}] = new FootSoldier(2);//player 2 footSoldier1 {7,1}
        board[{7,2}] = new FootSoldier(2);//player 2 footSoldier2 {7,2}

        assert(board.has_soldiers(2));

        board.move(1,{0,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 90
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        //try{(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));}
        //catch(exception &e){cout<<"nivtal1"<<endl;}//no soldier there
        board.move(1,{1,1},WarGame::Board::MoveDIR::Up); //player 2 footsoldier1 - 80
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));

        //try{(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));} // cant move left
        //catch(exception &e){cout<<"nivtal2"<<endl;}
        board.move(2,{7,0},WarGame::Board::MoveDIR::Down); //player 1 commanderSoldier - 130, player 1 footsoldier1 - 70,   player 1 footsoldier2 - 90,
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));

        board.move(1,{0,0},WarGame::Board::MoveDIR::Up);//player 2 commanderSoldier - 130, player 2 footsoldier1 - 70,   player 2 footsoldier2 - 90,
        //success
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
        //success
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{1,0},WarGame::Board::MoveDIR::Down);//success
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));

        board.move(1,{0,0},WarGame::Board::MoveDIR::Up);//sucess
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));
        board.move(1,{1,0},WarGame::Board::MoveDIR::Down);
        assert(board.has_soldiers(2));
        assert(board.has_soldiers(1));

        board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
        board.move(1,{1,2},WarGame::Board::MoveDIR::Up);
        assert(!board.has_soldiers(2));
        assert(board.has_soldiers(1));

        // In your game, you can put more soldier types, such as the sniper and the paramedic types.
    }

    uint DemoGame::play() {
        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
        if (!board.has_soldiers(2)) return 1;

        board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
        if (!board.has_soldiers(1)) return 2;

        board.move(1, {0,3}, Board::MoveDIR::Up);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
        if (!board.has_soldiers(2)) return 1;

        board.move(2, {7,3}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
        if (!board.has_soldiers(1)) return 2;

        /// Write more moves here..

        // If no player won, return "tie":
        return 0;
    }

    DemoGame::~DemoGame() {
        for (int iRow=0; iRow<numRows; ++iRow) {
            for (int iCol=0; iCol<numCols; ++iCol) {
                Soldier* soldier = board[{iRow,iCol}];
                if (soldier)
                    delete soldier;
            }
        }
    }
}