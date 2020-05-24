//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_SOLDIER_HPP
#define WARGAME_A_SOLDIER_HPP
#include <iostream>
//this is an interface
enum type{footsoldier, footcommander ,sniper, snipercommander, paramedic, paramediccommander};

using namespace std;
class Soldier {
protected:
    uint id;
    type t;
    int hp;
    uint power;
public:
    Soldier(uint &id){
        this->id=id;
    }
    bool isAlive() const{
       return this->hp > 0;
   }
   void MyStatus(){
       cout<<"id: "<<this->id<<endl;
       cout<<"type: "<<this->t<<endl;
       cout<<"hp: "<<this->hp<<endl;
       cout<<"power: "<<this->power<<endl;
    }
    virtual void attack_or_heal(Soldier& soldiers)=0;
};


#endif //WARGAME_A_SOLDIER_HPP
