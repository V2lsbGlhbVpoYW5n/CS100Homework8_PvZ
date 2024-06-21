#include "CooldownMask.hpp"

CooldownMask::CooldownMask(int x, int y, pGameWorld gameWorld, int livingTime) : GameObject(IMGID_COOLDOWN_MASK, x, y,
                                                                                            LAYER_COOLDOWN_MASK, 50, 70,
                                                                                            ANIMID_NO_ANIMATION,
                                                                                            std::move(gameWorld),
                                                                                            ObjectTag::TAG_NONE),
                                                                                 livingTime(livingTime) {
}

void CooldownMask::Update() {
    if (livingTime > 0) {
        --livingTime;
    } else {
        Die();
    }
}

void CooldownMask::OnClick() {
}

