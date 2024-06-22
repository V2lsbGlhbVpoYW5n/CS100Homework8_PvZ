#include "PeaShooter.hpp"
#include "GameWorld.hpp"
#include "Projectile/Pea.hpp"

PeaShooter::PeaShooter(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_PEASHOOTER, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 300),
    Attacker(0,1,30) {
}

void PeaShooter::Update() {
    Plant::Update();
    if (GetDead()) {
        return;
    }
    if (Attacker::Update()) {
        gameWorld->AddObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, gameWorld));
    }
}