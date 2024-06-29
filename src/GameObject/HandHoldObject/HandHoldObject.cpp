#include "HandHoldObject.hpp"
#include "GameWorld.hpp"
#include <functional>

HandHoldObject::HandHoldObject(int imageID, int x, int y, int width, int height, pGameWorld gameWorld, ObjectTag tag) :
    GameObject(imageID, x, y, LAYER_UI, width, height, ANIMID_NO_ANIMATION, std::move(gameWorld), tag) {
}

void HandHoldObject::Update() {
}

void HandHoldObject::OnClick() {
    auto useFunc =
        [this](int &&PH1, int &&PH2) { UseObject(PH1, PH2); };
    gameWorld->SetHandObjectUseFunction(std::move(useFunc), false);
}
