//
// Created by nivtal9 on 24.5.2020.
//
#include "Board.hpp"
#include "cmath"
// operator for putting soldiers on the game-board during initialization.
Soldier *& WarGame::Board::operator[](std::pair<int, int> location) {
    Soldier** s=&board[location.first][location.second];
    if(!isAuthorized(location)){
        throw std::runtime_error("unauthorized location");
    }
    //latestlocation.first=location.first;
    //latestlocation.second=location.second;
    //board[location.first][location.second]->setLocation(location);
    return *s;
}
// operator for reading which soldiers are on the game-board.
Soldier *WarGame::Board::operator[](std::pair<int, int> location) const {
    Soldier* s=board[location.first][location.second];
    if(!isAuthorized(location)){
        throw std::runtime_error("unauthorized location");
    }

    return s;
}

void WarGame::Board::move(uint player_number, std::pair<int, int> source, WarGame::Board::MoveDIR direction) {
    try {
        if (board[source.first][source.second]->getId() != player_number) {
            throw std::runtime_error("Not Found Player");
        }
    }
    catch(exception &e){
        throw std::runtime_error("unauthorized source");
    }
    switch (direction) {
        case Right:
            if (!isAuthorized(pair<int, int>(source.first, source.second + 1)) ||
                board[source.first][source.second + 1] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first][source.second+1]=board[source.first][source.second];
            //board[source.first][source.second+1]->setLocation({source.first,source.second+1});
            board[source.first][source.second]=nullptr;
            board[source.first][source.second+1]->attack_or_heal(getNearestSoldier(source.first,source.second+1
                    ,board[source.first][source.second+1]->getType(),board[source.first][source.second+1]->getId()));
            break;
        case Left:
            if (!isAuthorized(pair<int, int>(source.first, source.second - 1)) ||
                board[source.first][source.second - 1] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first][source.second-1]=board[source.first][source.second];
            //board[source.first][source.second-1]->setLocation({source.first,source.second-1});
            board[source.first][source.second]=nullptr;
            board[source.first][source.second-1]->attack_or_heal(getNearestSoldier(source.first,source.second-1
                    ,board[source.first][source.second-1]->getType(),board[source.first][source.second-1]->getId()));
            break;
        case Up:
            if (!isAuthorized(pair<int, int>(source.first - 1, source.second)) ||
                board[source.first -1][source.second] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first-1][source.second]=board[source.first][source.second];
            //board[source.first-1][source.second]->setLocation({source.first-1,source.second});
            board[source.first][source.second]=nullptr;
            board[source.first-1][source.second]->attack_or_heal(getNearestSoldier(source.first-1,source.second
                    ,board[source.first-1][source.second]->getType(),board[source.first-1][source.second]->getId()));
            break;
        case Down:
            if (!isAuthorized(pair<int, int>(source.first + 1, source.second)) ||
                board[source.first + 1][source.second] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first+1][source.second]=board[source.first][source.second];
            //board[source.first+1][source.second]->setLocation({source.first+1,source.second});
            board[source.first][source.second]=nullptr;
            board[source.first+1][source.second]->attack_or_heal(getNearestSoldier(source.first+1,source.second
                    ,board[source.first+1][source.second]->getType(),board[source.first+1][source.second]->getId()));
            break;
    }
}

bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i=0;i<board.size();i++){
        for(int j=0;i<board[0].size();j++){
            if(board[i][j]->getId()==player_number){
                return true;
            }
        }
    }
    return false;
}

bool WarGame::Board::isAuthorized(std::pair<int, int> location) const {
    return !(location.first > board.size() - 1 || location.second > board[0].size() - 1
    ||location.first<0||location.second<0);
}

Soldier &WarGame::Board::getNearestSoldier(int x,int y,type t,uint id) {
    Soldier *s;
    if (t == footsoldier) {
        int MinDest = 10000;
        pair<int, int> MinDestPlace(-1, -1);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() != id) {
                    if (std::abs(x - i) + std::abs(y - j) < MinDest) {
                        MinDest = std::abs(x - i) + std::abs(y - j);
                        MinDestPlace.first = i;
                        MinDestPlace.second = j;
                    }
                }
            }
        }
        if (MinDestPlace.second != -1 && MinDestPlace.first != -1) {
            s = board[MinDestPlace.first][MinDestPlace.second];
        }
    }
    if (t == footcommander) {
        int MinDest = INT16_MAX;
        pair<int, int> MinDestPlace(-1, -1);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == footsoldier) {
                    board[i][j]->attack_or_heal(getNearestSoldier(i, j, footsoldier, id));
                }
/*                if (board[i][j] != nullptr && board[i][j]->getId() != id) {
                    if (std::abs(x - i) + std::abs(y - j) < MinDest) {
                        MinDest = std::abs(x - i) + std::abs(y - j);
                        MinDestPlace.first = i;
                        MinDestPlace.second = j;
                    }
                }*/
            }
        }
/*        if (MinDestPlace.second != -1 && MinDestPlace.first != -1) {
            s = board[MinDestPlace.first][MinDestPlace.second];
        }*/
        board[x][y]->attack_or_heal(getNearestSoldier(x, y, footsoldier, id));
    }
    if(t==sniper){
        int MaxHp = INT16_MIN;
        pair<int, int> MaxHpPlace(-1, -1);
        for (int i = 0; i <board.size() ; ++i) {
            for (int j = 0; j <board[0].size() ; ++j) {
                if(board[i][j] != nullptr && board[i][j]->getId() != id){
                    if(board[i][j]->getHp()>MaxHp){
                        MaxHp=board[i][j]->getHp();
                        MaxHpPlace.first=i;
                        MaxHpPlace.second=j;
                    }
                }
            }
        }
        if (MaxHpPlace.second != -1 && MaxHpPlace.first != -1) {
            s = board[MaxHpPlace.first][MaxHpPlace.second];
        }
    }
    if(t==snipercommander){
        int MaxHp = INT16_MIN;
        pair<int, int> MaxHpPlace(-1, -1);
        for (int i = 0; i <board.size() ; ++i) {
            for (int j = 0; j <board[0].size() ; ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == sniper) {
                    board[i][j]->attack_or_heal(getNearestSoldier(i, j, sniper, id));
                }
/*                if(board[i][j] != nullptr && board[i][j]->getId() != id){
                    if(board[i][j]->getHp()>MaxHp){
                        MaxHp=board[i][j]->getHp();
                        MaxHpPlace.first=i;
                        MaxHpPlace.second=j;
                    }
                }*/
            }
        }
/*        if (MaxHpPlace.second != -1 && MaxHpPlace.first != -1) {
            s = board[MaxHpPlace.first][MaxHpPlace.second];
        }*/
        board[x][y]->attack_or_heal(getNearestSoldier(x, y, sniper, id));
    }
    if(t==paramedic){
        try {
            if(board[x][y+1]!= nullptr&&board[x][y]->getId()==id){
                board[x][y+1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x][y-1]!= nullptr&&board[x][y]->getId()==id){
                board[x][y-1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x+1][y]!= nullptr&&board[x][y]->getId()==id){
                board[x+1][y]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x-1][y]!= nullptr&&board[x][y]->getId()==id){
                board[x-1][y]->setMaxHp();
            }
        }
        catch(exception &e){}
    }
    if(t==paramediccommander){
        for (int i = 0; i <board.size() ; ++i) {
            for (int j = 0; j <board[0].size() ; ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == paramedic) {
                    board[i][j]->attack_or_heal(getNearestSoldier(i, j, paramedic, id));
                }
            }
        }
        board[x][y]->attack_or_heal(getNearestSoldier(x, y, paramedic, id));
    }
    return *s;
}
