//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP


#include "Soldier.hpp"
using namespace::std;
class ParamedicCommander: public Soldier {
public:
    explicit ParamedicCommander(uint id) : Soldier(id) {
            t=type::paramediccommander;
            hp=100;
            power=10;
    }
    bool attack_or_heal(Soldier & soldiers) override;
    void setMaxHp() override;
};


#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP
