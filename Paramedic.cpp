//
// Created by nivtal9 on 24.5.2020.
//

#include "Paramedic.hpp"

void Paramedic::attack_or_heal(Soldier &soldiers) {
soldiers.setMaxHp();
}

void Paramedic::setMaxHp() {
this->hp=100;
}
