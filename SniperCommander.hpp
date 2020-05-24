//
// Created by nivtal9 on 24.5.2020.
//

#ifndef WARGAME_A_SNIPERCOMMANDER_HPP
#define WARGAME_A_SNIPERCOMMANDER_HPP

#include "Sniper.hpp"
using namespace::std;
class SniperCommander : public Sniper{
public:
    SniperCommander(uint &id) : Sniper(id) {
            t=type::snipercommander;
            hp=120;
            power=100;
    }
    void attack_or_heal(Soldier & soldiers) override;
};


#endif //WARGAME_A_SNIPERCOMMANDER_HPP
