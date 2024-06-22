#include "Plant.hpp"
#include "GameWorld.hpp"

Plant::Plant(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP) :
    GameObject(imageID, x, y, LAYER_PLANTS, width, height, animID, std::move(gameWorld), ObjectTag::TAG_PLANT), HP(HP) {
}

void Plant::Update() {
    if (HP <= 0) {
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

bool Plant::OnCollide(pGameObejct other) {
    if (!GameObject::OnCollide(other)) {
        return false;
    }
    switch (other->GetTag()) {
        case ObjectTag::TAG_ZOMBIE:
            HP -= 3;
            break;
        case ObjectTag::TAG_PLANT:
        case ObjectTag::TAG_PEA:
        case ObjectTag::TAG_EXPLOSION:
        case ObjectTag::TAG_NONE:
            break;
    }
    return true;
}