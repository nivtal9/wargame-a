//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_SNIPER_HPP
#define WARGAME_A_SNIPER_HPP

#include "Soldier.hpp"
using namespace::std;
class Sniper : public Soldier{
public:
    explicit Sniper(uint id) : Soldier(id) {
            t=type::sniper;
            hp=100;
            power=50;
    }
    void attack_or_heal(Soldier & soldiers) override;
    void setMaxHp() override;
};


#endif //WARGAME_A_SNIPER_HPP
