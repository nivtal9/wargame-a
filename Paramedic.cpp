//
// Created by nivtal9 on 24.5.2020.
//

#include "Paramedic.hpp"

bool Paramedic::attack_or_heal(Soldier &soldiers) {
soldiers.setMaxHp();
return true;
}

void Paramedic::setMaxHp() {
this->hp=100;
}
