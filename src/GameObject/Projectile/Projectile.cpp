#include "Projectile.hpp"

Projectile::Projectile(int imageID, int x, int y, int width, int height, pGameWorld gameWorld, ObjectTag tag, int SPD) :
    GameObject(imageID, x, y, LAYER_PROJECTILES, width, height, ANIMID_NO_ANIMATION, std::move(gameWorld), tag), SPD(SPD) {
}

void Projectile::Update() {
    if (GetDead()) {
        return;
    }
    MoveTo(GetX() + SPD, GetY());
    if (GetX() >= WINDOW_WIDTH) {
        Die();
    }
}

void Projectile::OnClick() {
}

bool Projectile::OnCollide(pGameObject other) {
    if (!GameObject::OnCollide(other)) {
        return false;
    }
    return true;
}