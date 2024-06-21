#include "CherryBomb.hpp"
#include "GameWorld.hpp"

CherryBomb::CherryBomb(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_CHERRY_BOMB, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 1500), Ash(){
}

void CherryBomb::Update() {
    Plant::Update();
}