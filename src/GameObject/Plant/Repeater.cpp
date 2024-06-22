#include "Repeater.hpp"
#include "GameWorld.hpp"
#include "Projectile/Pea.hpp"

Repeater::Repeater(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_REPEATER, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 300),
    Attacker(5,2,30) {
}

void Repeater::Update() {
    Plant::Update();
    if (GetDead()) {
        return;
    }
    if (Attacker::Update()) {
        gameWorld->AddObject(std::make_shared<Pea>(GetX() + 30, GetY() + 20, gameWorld));
    }
}