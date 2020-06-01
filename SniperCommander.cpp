//
// Created by nivtal9 on 24.5.2020.
//

#include "SniperCommander.hpp"


void SniperCommander::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-100);
}

void SniperCommander::setMaxHp() {
    this->hp=120;
}
