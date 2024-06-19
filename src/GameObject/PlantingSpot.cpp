#include "PlantingSpot.hpp"
#include "GameWorld.hpp"
#include "Sunflower.hpp"

PlantingSpot::PlantingSpot(int x, int y, pGameWorld gameWorld) :
    GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, gameWorld) {
}

void PlantingSpot::Update() {
}

void PlantingSpot::OnClick() {
    gameWorld->AddObject(std::make_shared<Sunflower>(GetX(), GetY(), gameWorld));
}

bool PlantingSpot::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}