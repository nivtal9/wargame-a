//
// Created by nivtal9 on 24.5.2020.
//

#include "FootCommander.hpp"


void FootCommander::attack_or_heal(Soldier &soldiers) {
    soldiers.setHp(-20);
}

void FootCommander::setMaxHp() {
    this->hp=150;
}
