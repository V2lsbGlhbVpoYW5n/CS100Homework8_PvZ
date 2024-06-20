#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, ObjectTag tag) :
    ObjectBase(imageID, x, y, layer, width, height, animID), gameWorld(std::move(gameWorld)), tag(tag){
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

ObjectTag GameObject::GetTag() {
    return tag;
}

bool GameObject::HasTag(ObjectTag tag) {
    return this->tag == tag;
}