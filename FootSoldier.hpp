//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_FOOTSOLDIER_HPP
#define WARGAME_A_FOOTSOLDIER_HPP


#include "Soldier.hpp"
using namespace::std;
class FootSoldier : public Soldier{

public:
    explicit FootSoldier(uint id) : Soldier(id) {
        t=type::footsoldier;
        hp=100;
        power=10;
    }
    bool attack_or_heal(Soldier & soldiers) override;
    void setMaxHp() override;
};


#endif //WARGAME_A_FOOTSOLDIER_HPP
