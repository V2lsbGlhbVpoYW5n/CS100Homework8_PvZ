#include "GameObject.hpp"

#include <utility>

GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,
                       pGameWorld gameWorld, ObjectTag tag) :
    ObjectBase(imageID, x, y, layer, width, height, animID), gameWorld(std::move(gameWorld)), tag(tag) {
}

bool GameObject::CheckCollide(pGameObejct other) {
    return abs(this->GetX() - other->GetX()) <= (this->GetWidth() + other->GetWidth()) / 2
        && abs(this->GetY() - other->GetY()) <= (this->GetHeight() + other->GetHeight()) / 2;
}

bool GameObject::OnCollide(pGameObejct other){
    if (!CheckCollide(other)){
        return false;
    }
    return true;
}

bool GameObject::CanCollide() {
    return !HasTag(ObjectTag::TAG_NONE);
}

void GameObject::Die() {
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