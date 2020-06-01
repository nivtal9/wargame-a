//
// Created by nivtal9 on 24.5.2020.
//

#include "FootSoldier.hpp"


void FootSoldier::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-10);
}

void FootSoldier::setMaxHp() {
    this->hp=100;
}
