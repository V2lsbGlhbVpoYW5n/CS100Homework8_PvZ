#include "Repeater.hpp"
#include "GameWorld.hpp"

Repeater::Repeater(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_REPEATER, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 300),
    Attacker(30, 30) {
}

void Repeater::Update() {
    Plant::Update();
}