#include "Sunflower.hpp"
#include "GameWorld.hpp"
#include "Sun.hpp"

Sunflower::Sunflower(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_SUNFLOWER, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 300),
    SunProducer(randInt(30, 600), 600) {
}

void Sunflower::Update() {
    Plant::Update();
    if (GetDead()) {
        return;
    }
    if (SunProducer::Update()) {
        gameWorld->AddObject(std::make_shared<Sun>(GetX(), GetY(), gameWorld, true));
    }
}