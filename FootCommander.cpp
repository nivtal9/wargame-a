//
// Created by nivtal9 on 24.5.2020.
//

#include "FootCommander.hpp"


bool FootCommander::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-20);
    return soldiers.isAlive();
}

void FootCommander::setMaxHp() {
    this->hp=150;
}
