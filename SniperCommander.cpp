//
// Created by nivtal9 on 24.5.2020.
//

#include "SniperCommander.hpp"


bool SniperCommander::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-100);
    return soldiers.isAlive();
}

void SniperCommander::setMaxHp() {
    this->hp=120;
}
