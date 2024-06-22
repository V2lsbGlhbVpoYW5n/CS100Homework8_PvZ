#include "Ash.hpp"

Ash::Ash(int timer) : timer(timer) {
}

bool Ash::Update() {
    if (timer == 0) {
        return true;
    } else {
        timer--;
        return false;
    }
}