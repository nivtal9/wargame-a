//
// Created by nivtal9 on 24.5.2020.
//

#include "FootSoldier.hpp"


bool FootSoldier::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-10);
    return soldiers.isAlive();
}

void FootSoldier::setMaxHp() {
    this->hp=100;
}
