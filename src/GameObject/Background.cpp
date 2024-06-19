#include "Background.hpp"

#include <utility>

Background::Background(pGameWorld gameWorld) :
    GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT,
               ANIMID_NO_ANIMATION, std::move(gameWorld)){
}

void Background::Update() {
}

void Background::OnClick() {
}

bool Background::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}
