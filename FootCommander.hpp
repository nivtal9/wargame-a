//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_FOOTCOMMANDER_HPP
#define WARGAME_A_FOOTCOMMANDER_HPP
#include "FootSoldier.hpp"
using namespace ::std;
class FootCommander : public FootSoldier{
public:
    FootCommander(uint id) : FootSoldier(id) {
        t=type::footcommander;
        hp=150;
        power=20;
    }
    void attack_or_heal(Soldier & soldiers) override;
    void setMaxHp() override;
};


#endif //WARGAME_A_FOOTCOMMANDER_HPP
