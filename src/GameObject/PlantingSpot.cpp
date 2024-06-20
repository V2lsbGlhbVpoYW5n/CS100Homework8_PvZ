#include "PlantingSpot.hpp"
#include "GameWorld.hpp"
#include "HandHoldObject/HandHoldObject.hpp"

PlantingSpot::PlantingSpot(int x, int y, pGameWorld gameWorld) :
    GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, gameWorld, ObjectTag::TAG_NONE) {
}

void PlantingSpot::Update() {
}

void PlantingSpot::OnClick() {
    std::cout << "Fucka";
    gameWorld->GetHandObjectUseFunction()(GetX(), GetY());
    if(!gameWorld->IsHandEmpty()){
        std::cout << "Fucka";

    }
}

bool PlantingSpot::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}