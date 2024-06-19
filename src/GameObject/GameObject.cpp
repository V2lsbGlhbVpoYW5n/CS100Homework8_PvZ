#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld):
    ObjectBase(imageID, x, y, layer, width, height, animID), gameWorld(std::move(gameWorld)){
}

bool GameObject::operator==(const ObjectBase &other) {
    return ObjectBase::operator==(other);
}

void GameObject::Die(){
    isDead = true;
}

bool GameObject::GetDead() {
    return isDead;
}