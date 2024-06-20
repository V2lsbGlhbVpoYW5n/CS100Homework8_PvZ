#include "Seed.hpp"

Seed::Seed(int imageID, int x, int y, pGameWorld gameWorld, int ORIGINAL_COST, int MaxCooldown,
           bool activatedAtBeginning) :
    HandHoldObject(imageID, x, y, 50, 70, std::move(gameWorld), ObjectTag::TAG_SEED),
    ORIGINAL_COST(ORIGINAL_COST), MaxCooldown(MaxCooldown), activatedAtBeginning(activatedAtBeginning) {
    if (activatedAtBeginning) {
        cooldown = 0;
    } else {
        cooldown = MaxCooldown;
    }
}

void Seed::ChangeCost(int costDelta) {
    cost += costDelta;
}

void Seed::ChangeMaxCooldown(int MaxCooldownDelta) {
    MaxCooldown += MaxCooldownDelta;
}

void Seed::ResetCooldown() {
    cooldown = MaxCooldown;
}

bool Seed::CheckCooldown() {
    if (cooldown == 0) {
        return true;
    } else {
        return false;
    }
}