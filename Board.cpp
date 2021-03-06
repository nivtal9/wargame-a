//
// Created by nivtal9 and avi130 on 24.5.2020.
//
#include "Board.hpp"
#include "cmath"
// operator for putting soldiers on the game-board during initialization.
Soldier *& WarGame::Board::operator[](std::pair<int, int> location) {
    Soldier** s=&board[location.first][location.second];
    if(!isAuthorized(location)){
        throw std::runtime_error("unauthorized location");
    }

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

        if (board[source.first][source.second]== nullptr || board[source.first][source.second]->getId() != player_number) {
            throw std::runtime_error("Not Found Player");
        }

    switch (direction) {
        case Right:
        {
            if (!isAuthorized(pair<int, int>(source.first, source.second + 1)) ||
                board[source.first][source.second + 1] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first][source.second + 1] = board[source.first][source.second];
            board[source.first][source.second] = nullptr;
            Soldier &sol1 = getNearestSoldier(source.first, source.second + 1,
                                              board[source.first][source.second + 1]->getType(),
                                              board[source.first][source.second + 1]->getId());
            if(board[sol1.getLocation().first][sol1.getLocation().second] != nullptr && sol1.getId()!=board[source.first ][source.second+1]->getId()) {
                if (board[source.first][source.second + 1]->getType() == footsoldier ||
                    board[source.first][source.second + 1]->getType() == sniper) {

                    if (!board[source.first][source.second + 1]->attack_or_heal(sol1)) {
                        cout << "Right via Move" << endl;
                        board[sol1.getLocation().first][sol1.getLocation().second] = nullptr;
                    }
                }
            }
            break;
        }
        case Left: {
            if (!isAuthorized(pair<int, int>(source.first, source.second - 1)) ||
                board[source.first][source.second - 1] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first][source.second - 1] = board[source.first][source.second];
            //board[source.first][source.second-1]->setLocation({source.first,source.second-1});
            board[source.first][source.second] = nullptr;
            Soldier &sol2 = getNearestSoldier(source.first, source.second - 1,
                                              board[source.first][source.second - 1]->getType(),
                                              board[source.first][source.second - 1]->getId());
            if(board[sol2.getLocation().first][sol2.getLocation().second] != nullptr && sol2.getId()!=board[source.first][source.second-1]->getId()) {
                if (board[source.first][source.second-1]->getType() == footsoldier ||
                    board[source.first ][source.second-1]->getType() == sniper) {

                    if (!board[source.first][source.second - 1]->attack_or_heal(sol2)) {
                        cout << "left via Move" << endl;
                        board[sol2.getLocation().first][sol2.getLocation().second] = nullptr;
                    }
                }
            }
            break;
        }
        case Up: {
            if (!isAuthorized(pair<int, int>(source.first + 1, source.second)) ||
                board[source.first + 1][source.second] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first + 1][source.second] = board[source.first][source.second];
            board[source.first][source.second] = nullptr;
            Soldier &sol3 = getNearestSoldier(source.first + 1, source.second,
                                              board[source.first + 1][source.second]->getType(),
                                              board[source.first + 1][source.second]->getId());
            if(board[sol3.getLocation().first][sol3.getLocation().second] != nullptr && sol3.getId()!=board[source.first + 1][source.second]->getId()){
                if( board[source.first + 1][source.second]->getType()==footsoldier||board[source.first + 1][source.second]->getType()==sniper ) {

                    if (!board[source.first + 1][source.second]->attack_or_heal(sol3)) {
                        cout << "Up via Move" << endl;
                        board[sol3.getLocation().first][sol3.getLocation().second] = nullptr;

                    }
                }
        }


            break;
        }
        case Down: {
            if (!isAuthorized(pair<int, int>(source.first - 1, source.second)) ||
                board[source.first - 1][source.second] != nullptr) {
                throw std::runtime_error("unauthorized Move");
            }
            board[source.first - 1][source.second] = board[source.first][source.second];
            //board[source.first-1][source.second]->setLocation({source.first-1,source.second});
            board[source.first][source.second] = nullptr;
            Soldier &sol4=getNearestSoldier(source.first - 1, source.second,
                                            board[source.first - 1][source.second]->getType(),
                                            board[source.first - 1][source.second]->getId());

            if(board[sol4.getLocation().first][sol4.getLocation().second] != nullptr && sol4.getId()!=board[source.first - 1][source.second]->getId() ){
           if( board[source.first - 1][source.second]->getType()==footsoldier||board[source.first - 1][source.second]->getType()==sniper ) {
               if (!board[source.first - 1][source.second]->attack_or_heal(sol4)) {
                   cout << "Down via Move" << endl;
                   board[sol4.getLocation().first][sol4.getLocation().second] = nullptr;
               }
           }
           }


            break;
        }
    }
}

bool WarGame::Board::has_soldiers(uint player_number) const {
    for (int i=0;i<board.size();i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getId() == player_number) {
                    return true;
                }
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
    Soldier *s=nullptr;
    if(id==1 && !has_soldiers(2) || id==2 && !has_soldiers(1) ){
        s=board[x][y];
        return *s;
    }
    if (t == footsoldier) {
        double MinDest = INT16_MAX;
        pair<int, int> MinDestPlace(-1, -1);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() != id) {
                    if (sqrt(pow(std::abs(x - i), 2) +pow(std::abs(y - j), 2) ) < MinDest) {
                        MinDest = sqrt(pow(std::abs(x - i), 2) +pow(std::abs(y - j), 2) );
                        MinDestPlace.first = i;
                        MinDestPlace.second = j;
                    }
                }
            }
        }
        if (MinDestPlace.second != -1 && MinDestPlace.first != -1) {
            s = board[MinDestPlace.first][MinDestPlace.second];
            s->setLocation(MinDestPlace);


        }
    }
    if (t == footcommander) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == footsoldier) {
                    Soldier &sol5=getNearestSoldier(i, j, footsoldier, id);
                    if(!board[i][j]->attack_or_heal(sol5)){
                        cout<<"footcomander via getNearest"<<endl;
                        board[sol5.getLocation().first][sol5.getLocation().second]=nullptr;
                    }
                }
                else if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == footcommander) {
                    s = board[i][j];
                    s->setLocation(pair<int, int> (i,j));
                    Soldier &sol5=getNearestSoldier(i, j, footsoldier, id);
                    if(!board[i][j]->attack_or_heal(sol5)){
                        cout<<"footcomander via getNearest"<<endl;
                        board[sol5.getLocation().first][sol5.getLocation().second]=nullptr;
                    }
                }


            }
        }
    }
    if(t==sniper){
        double MaxHp = INT16_MIN;
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
            s->setLocation(MaxHpPlace);
        }
    }
    if(t==snipercommander){

        for (int i = 0; i <board.size() ; ++i) {
            for (int j = 0; j <board[0].size() ; ++j) {
                 if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == snipercommander) {
                    s = board[i][j];
                    s->setLocation(pair<int, int> (i,j));
                    Soldier &sol7=getNearestSoldier(i, j, sniper, id);
                    if(!board[i][j]->attack_or_heal(sol7)){
                        cout<<"snipercomander1 via getNearest"<<endl;
                        board[sol7.getLocation().first][sol7.getLocation().second]=nullptr;
                    }
                }
            }
        }
        for (int i = 0; i <board.size() ; ++i) {
            for (int j = 0; j <board[0].size() ; ++j) {
                if (board[i][j] != nullptr && board[i][j]->getId() == id && board[i][j]->getType() == sniper) {
                    Soldier &sol7 = getNearestSoldier(i, j, sniper, id);
                    if (!board[i][j]->attack_or_heal(sol7)) {
                        cout << "snipercomander1 via getNearest" << endl;
                        board[sol7.getLocation().first][sol7.getLocation().second] = nullptr;
                    }
                }

            }
        }

    }
    if(t==paramedic){
        s=board[x][y];
        try {
            if(board[x][y+1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x][y+1]->getHp()<<endl;
                board[x][y+1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x][y-1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x][y-1]->getHp()<<endl;
                board[x][y-1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x+1][y]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x+1][y]->getHp()<<endl;
                board[x+1][y]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x-1][y]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x-1][y]->getHp()<<endl;
                board[x-1][y]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x+1][y+1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x+1][y+1]->getHp()<<endl;
                board[x+1][y+1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x-1][y+1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x-1][y+1]->getHp()<<endl;
                board[x-1][y+1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x+1][y-1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x+1][y-1]->getHp()<<endl;
                board[x+1][y-1]->setMaxHp();
            }
        }
        catch(exception &e){}
        try {
            if(board[x-1][y-1]!= nullptr&&board[x][y]->getId()==id){
                cout<<board[x-1][y-1]->getHp()<<endl;
                board[x-1][y-1]->setMaxHp();
            }
        }
        catch(exception &e){}
    }
    if(t==paramediccommander){
        s=board[x][y];
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
