//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_PARAMEDICCOMMANDER_HPP
#define WARGAME_A_PARAMEDICCOMMANDER_HPP


#include "Paramedic.hpp"
using namespace::std;
class ParamedicCommander: public Paramedic {
public:
    ParamedicCommander(uint &id) : Paramedic(id) {
            t=type::paramediccommander;
            hp=100;
            power=10;
    }
    void attack_or_heal(Soldier & soldiers) override;
};


#endif //WARGAME_A_PARAMEDICCOMMANDER_HPP
