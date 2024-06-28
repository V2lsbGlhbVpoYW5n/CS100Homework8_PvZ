#include "Attacker.hpp"

Attacker::Attacker(int attackInterval, int attackTimes, int roundInterval) : attackInterval(attackInterval),
                                                                             attackTimes(attackTimes),
                                                                             roundInterval(roundInterval) {
}

bool Attacker::Update() {
    if (currentInterval > 0) {
        currentInterval--;
        return false;
    } else {
        currentTimes++;
        if (currentTimes < attackTimes) {
            currentInterval = attackInterval;
        } else {
            currentTimes = 0;
            currentInterval = roundInterval;
        }
        return true;
    }
}