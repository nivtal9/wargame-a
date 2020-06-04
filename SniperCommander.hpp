//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Soldier.hpp"
using namespace::std;
class SniperCommander : public Soldier{
public:
    explicit SniperCommander(uint id) : Soldier(id) {
            t=type::snipercommander;
            hp=120;
            power=100;
    }
    bool attack_or_heal(Soldier & soldiers) override;
    void setMaxHp() override;
};


#endif //WARGAME_A_SNIPERCOMMANDER_HPP
