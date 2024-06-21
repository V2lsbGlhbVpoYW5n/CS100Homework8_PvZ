#include "PeaShooter.hpp"
#include "GameWorld.hpp"

PeaShooter::PeaShooter(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_PEASHOOTER, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 300),
    Attacker(30, 30) {
}

void PeaShooter::Update() {
    Plant::Update();
}