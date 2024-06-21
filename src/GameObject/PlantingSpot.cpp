#include "PlantingSpot.hpp"
#include "GameWorld.hpp"

PlantingSpot::PlantingSpot(int x, int y, pGameWorld gameWorld) :
    GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, std::move(gameWorld), ObjectTag::TAG_NONE) {
}

void PlantingSpot::Update() {
}

void PlantingSpot::OnClick() {
    if (!gameWorld->IsHandEmpty() && !gameWorld->IsHandShovel()) {
        gameWorld->GetHandObjectUseFunction()(GetX(), GetY());
        gameWorld->ClearHandObjectUseFunction();
    }
}