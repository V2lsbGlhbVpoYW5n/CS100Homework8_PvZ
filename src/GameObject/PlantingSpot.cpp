#include "PlantingSpot.hpp"
#include "GameWorld.hpp"
#include <fstream>
#include <iostream>

PlantingSpot::PlantingSpot(int x, int y, pGameWorld gameWorld) :
    GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, std::move(gameWorld), ObjectTag::TAG_NONE) {
}

void PlantingSpot::Update() {
}

void PlantingSpot::OnClick() {
    if (!gameWorld->IsHandEmpty() && !gameWorld->IsHandShovel()) {
        gameWorld->GetHandObjectUseFunction()(GetX(), GetY());
        std::fstream f;
        f.open("logDebug.txt", std::ios::out | std::ios::app);
        f << std::to_string(GetX()) + " PLANT" +std::to_string(GetY()) + "\n" << std::endl;
        f.close();
        gameWorld->ClearHandObjectUseFunction();
    }
}