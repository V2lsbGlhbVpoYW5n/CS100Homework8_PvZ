#include "Shovel.hpp"
#include "GameWorld.hpp"

Shovel::Shovel(pGameWorld gameWorld) :
    HandHoldObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, 50, 50, std::move(gameWorld), ObjectTag::TAG_NONE) {
}

void Shovel::UseObject(int x, int y) {
    // Can be used for someday
    // Like return some sun
}

void Shovel::OnClick() {
    if (!gameWorld->IsHandEmpty() && gameWorld->IsHandShovel()) {
        gameWorld->ClearHandObjectUseFunction();
        return;
    }
    auto useFunc =
        [this](int &&PH1, int &&PH2) { UseObject(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2)); };
    gameWorld->SetHandObjectUseFunction(std::move(useFunc), true);
}