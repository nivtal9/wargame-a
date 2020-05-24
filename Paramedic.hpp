//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_PARAMEDIC_HPP
#define WARGAME_A_PARAMEDIC_HPP

#include "Soldier.hpp"
using namespace::std;
class Paramedic : public Soldier{
public:
    Paramedic(uint id) : Soldier(id) {
            t=type::paramedic;
            hp=100;
            power=100;
    }
    void attack_or_heal(Soldier & soldiers) override;

};


#endif //WARGAME_A_PARAMEDIC_HPP
