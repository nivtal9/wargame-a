//
// Created by nivtal9 on 24.5.2020.
//

#include "Sniper.hpp"



void Sniper::attack_or_heal(Soldier &soldiers) {
soldiers.setHp(-50);
}

void Sniper::setMaxHp() {
this->hp=100;
}
