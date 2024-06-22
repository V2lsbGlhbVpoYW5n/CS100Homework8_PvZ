#include "CooldownMask.hpp"
#include "TextBase.hpp"

CooldownMask::CooldownMask(int x, int y, pGameWorld gameWorld, int livingTime) : GameObject(IMGID_COOLDOWN_MASK, x, y,
                                                                                            LAYER_COOLDOWN_MASK, 50, 70,
                                                                                            ANIMID_NO_ANIMATION,
                                                                                            std::move(gameWorld),
                                                                                            ObjectTag::TAG_NONE),
                                                                                 livingTime(livingTime), cooldownText(
        std::make_shared<TextBase>(x, y, std::to_string(livingTime), 255, 98, 57)) {
}

void CooldownMask::Update() {
    if (livingTime > 0) {
        --livingTime;
    } else {
        Die();
    }
    if (livingTime / 30 != (livingTime + 1) / 30) {
        cooldownText->SetText(std::to_string(livingTime / 30 + 1));
    }
}

void CooldownMask::OnClick() {
}

