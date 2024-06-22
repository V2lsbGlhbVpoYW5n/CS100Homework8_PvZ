#include "Seed.hpp"
#include "GameWorld.hpp"
#include "CooldownMask.hpp"

Seed::Seed(int imageID, int x, int y, pGameWorld gameWorld, int ORIGINAL_COST, int maxCooldown,
           bool activatedAtBeginning) :
    HandHoldObject(imageID, x, y, 50, 70, std::move(gameWorld), ObjectTag::TAG_NONE),
    ORIGINAL_COST(ORIGINAL_COST), maxCooldown(maxCooldown), activatedAtBeginning(activatedAtBeginning) {
    if (activatedAtBeginning) {
        cooldown = 0;
    } else {
        ResetCooldown();
    }
}

void Seed::OnClick() {
    if (!CheckValid()){
        return;
    }
    HandHoldObject::OnClick();
}

void Seed::Update(){
    if (cooldown > 0){
        --cooldown;
    }
}

void Seed::ChangeCost(int costDelta) {
    cost += costDelta;
}

void Seed::ChangeMaxCooldown(int maxCooldownDelta) {
    maxCooldown += maxCooldownDelta;
}

void Seed::ResetCooldown() {
    cooldown = maxCooldown;
    gameWorld->AddObject(std::make_shared<CooldownMask>(GetX(), GetY(), gameWorld, maxCooldown));
}

bool Seed::CheckValid() {
    if (cooldown == 0 && gameWorld->GetSun() >= cost){
        return true;
    } else {
        return false;
    }
}

void Seed::CostSun(){
    gameWorld->ChangeSun(-cost);
}