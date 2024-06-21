#include "Background.hpp"

#include <utility>

Background::Background(pGameWorld gameWorld) :
    GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT,
               ANIMID_NO_ANIMATION, std::move(gameWorld), ObjectTag::TAG_NONE){
}

void Background::Update() {
}

void Background::OnClick() {
}