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
    uint Player_id;
    type t;
    int hp;
    uint power;
    pair<uint,uint> location;
public:

    Soldier(uint &id){
        this->Player_id=id;
    }
/*    Soldier(uint &id,pair<uint,uint> location){
        this->Player_id=id;
        this->location.first=location.first;
        this->location.second=location.second;
    }*/
    bool isAlive() const{
       return this->hp > 0;
   }
    uint getId(){
        return this->Player_id;
    }
    void setHp(int impact) {
        this->hp=hp+impact;
    }
    int getHp() {
        return this->hp;
    }
    pair<int,int> getLocation(){
        return this->location;
    }
    void setLocation(pair<int,int> loc){
        this->location.first=loc.first;
        this->location.second=loc.second;
    }
    type getType(){
        return this->t;
    }
   void MyStatus(){
       cout<<"id: "<<this->Player_id<<endl;
       cout<<"type: "<<this->t<<endl;
       cout<<"hp: "<<this->hp<<endl;
       cout<<"power: "<<this->power<<endl;
    }
    virtual void attack_or_heal(Soldier& soldiers)=0;
    virtual void setMaxHp()=0;
};


#endif //WARGAME_A_SOLDIER_HPP
