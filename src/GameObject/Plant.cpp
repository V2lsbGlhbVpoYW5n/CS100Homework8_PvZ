#include "Plant.hpp"

Plant::Plant(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP) :
    GameObject(imageID, x, y, LAYER_PLANTS, width, height, animID, gameWorld), HP(HP) {
}

void Plant::Update() {
    if (GetHP() <= 0) {
        Die();
        return;
    }
}

void Plant::OnClick() {
}

bool Plant::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}

int Plant::GetHP() const {
    return HP;
}

