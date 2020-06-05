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
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

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
        board[{0,0}] = new FootSoldier(1);//player 1 soldier1
        assert(board.has_soldiers(1));
        board[{0,1}] = new FootCommander(1);//player 1 soldier2
        assert(board.has_soldiers(1));
        board[{0,2}] = new Sniper(1);//player 1 soldier3
        assert(board.has_soldiers(1));
        board[{0,3}] = new SniperCommander(1);//player 1 soldier4
        assert(board.has_soldiers(1));
        board[{0,4}] = new Paramedic(1);//player 1 soldier5
        board[{0,5}] = new ParamedicCommander(1);//player 1 soldier6
        assert(board.has_soldiers(1));
        assert(!board.has_soldiers(2));
        board[{7,0}] = new FootSoldier(2);//player 2 soldier1
        board[{7,1}] = new FootCommander(2);//player 2 soldier2
        board[{7,2}] = new Sniper(2);//player 2 soldier3
        board[{7,3}] = new SniperCommander(2);//player 2 soldier4
        board[{7,4}] = new Paramedic(2);//player 2 soldier5
        board[{7,5}] = new ParamedicCommander(2);//player 2 soldier6


        //consider using for.....
        assert(board.has_soldiers(2));
        board.move(1,{0,0},WarGame::Board::MoveDIR::Up); //player2 soldier1 - 90
        assert(board.has_soldiers(2));
        board.move(1,{0,1},WarGame::Board::MoveDIR::Up);//player2 soldier2 - 130, player 2 soldier1 - 80
        assert(board.has_soldiers(2));
        board.move(1,{0,2},WarGame::Board::MoveDIR::Up);//player2 soldier6 - 150
        assert(board.has_soldiers(2));
        board.move(1,{0,3},WarGame::Board::MoveDIR::Up);//player2 soldier6 - 50, player 2 soldier2 80 //need to define that commander shoots first
        assert(board.has_soldiers(2));
        board.move(1,{0,4},WarGame::Board::MoveDIR::Up);//player1 soldier4 - 120 //need to define that curing id done after the step/move
        assert(board.has_soldiers(2));
        board.move(1,{0,5},WarGame::Board::MoveDIR::Up); //player1 soldier5 - 100, player 1 soldier4 - 120, player 1 soldier6 - 200
        assert(board.has_soldiers(2));


        //sniper 1 will kill them all
        board.move(1,{1,3},WarGame::Board::MoveDIR::Down); //player2 soldier6 - 100, player 2 soldier2 80
        assert(board.has_soldiers(2));
        board.move(1,{0,3},WarGame::Board::MoveDIR::Up); //player2 soldier4 - 20, player2 soldier3 - 50 //need to define to check the closes when there are equalh healh points
        assert(board.has_soldiers(2));
        board.move(1,{1,3},WarGame::Board::MoveDIR::Down); //player2 soldier5 - 0, player2 soldier6 - 50
        assert(board.has_soldiers(2));
        board.move(1,{0,3},WarGame::Board::MoveDIR::Up); //player2 soldier1 - 0, player2 soldier2 - 30
        //just to be Sure all is dead

        board.move(1,{1,2},WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 20/10
        board.move(1,{0,2},WarGame::Board::MoveDIR::Up); //player2 soldier3 - 0, player2 soldier 6 - 0
        board.move(1,{1,2},WarGame::Board::MoveDIR::Down); //player2 soldier3 - 0, player2 soldier 6 - 0
        board.move(1,{0,2},WarGame::Board::MoveDIR::Up); //player2 soldier3 - 0, player2 soldier 6 - 0


        //just to be Sure all is dead
        assert(!board.has_soldiers(2));

        //good test


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