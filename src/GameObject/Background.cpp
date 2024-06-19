#include "Background.hpp"

Background::Background(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID) :
    GameObject(imageID, x, y, layer, width, height, animID) {
}

void Background::Update() {
}

void Background::OnClick() {

}

bool Background::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}
