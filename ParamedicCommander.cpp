//
// Created by nivtal9 on 24.5.2020.
//

#include "ParamedicCommander.hpp"

void ParamedicCommander::attack_or_heal(Soldier &soldiers) {
    soldiers.setMaxHp();
}

void ParamedicCommander::setMaxHp() {
    this->hp=200;
}
