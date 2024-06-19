#include "GameObject.hpp"

GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID) :
    ObjectBase(imageID, x, y, layer, width, height, animID){
}

bool GameObject::operator==(const ObjectBase &other) {
    return ObjectBase::operator==(other);
}

