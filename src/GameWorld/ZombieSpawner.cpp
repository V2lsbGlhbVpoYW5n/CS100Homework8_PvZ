#include <algorithm>
#include "ZombieSpawner.hpp"

int ZombieSpawner::Update(int wave) {
    if (timer == 0) {
        timer = GetNextTimer(wave);
        return (15+wave)/10;
    }
    timer--;
    return 0;
}

int ZombieSpawner::GetNextTimer(int wave) {
    return std::max(150, 600-20*wave);
}

void ZombieSpawner::Reset() {
    timer = 1200;
}