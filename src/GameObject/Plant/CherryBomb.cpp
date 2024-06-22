#include "CherryBomb.hpp"
#include "GameWorld.hpp"
#include "Projectile/Explosion.hpp"

CherryBomb::CherryBomb(int x, int y, pGameWorld gameWorld) :
    Plant(IMGID_CHERRY_BOMB, x, y, 60, 80, ANIMID_IDLE_ANIM, std::move(gameWorld), 1500), Ash(15){
}

void CherryBomb::Update() {
    Plant::Update();
    if (GetDead()) {
        return;
    }
    if (Ash::Update()){
        gameWorld->AddObject(std::make_shared<Explosion>(GetX(), GetY(), gameWorld));
        Die();
    }
}