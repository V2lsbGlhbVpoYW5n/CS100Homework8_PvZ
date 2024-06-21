#include "Plant.hpp"
#include "GameWorld.hpp"

Plant::Plant(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP) :
    GameObject(imageID, x, y, LAYER_PLANTS, width, height, animID, std::move(gameWorld), ObjectTag::TAG_PLANT), HP(HP) {
}

void Plant::Update() {
    if (GetHP() <= 0) {
        Die();
        return;
    }
}

void Plant::OnClick() {
    if (!gameWorld->IsHandEmpty() && gameWorld->IsHandShovel()) {
        gameWorld->GetHandObjectUseFunction()(GetX(), GetY());
        gameWorld->ClearHandObjectUseFunction();
        Die();
    }
}

int Plant::GetHP() const {
    return HP;
}

