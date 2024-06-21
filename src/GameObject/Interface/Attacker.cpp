#include "Attacker.hpp"

Attacker::Attacker(int firstAttackTime, int attackInterval) : firstAttackTime(firstAttackTime), attackInterval(attackInterval) {
}

//bool Attacker::Update() {
//    if (currentInterval == 0) {
//        currentInterval = attackInterval;
//        return true;
//    } else {
//        currentInterval--;
//        return false;
//    }
//}

bool Attacker::Update() {
    return false;
}