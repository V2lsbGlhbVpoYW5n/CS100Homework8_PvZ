#include "Wallnut.hpp"
#include "GameWorld.hpp"

Wallnut::Wallnut(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_WALLNUT, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 4000){
}

void Wallnut::Update() {
    Plant::Update();
    if (GetDead()) {
        return;
    } else if (HP < 4000/3) {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}