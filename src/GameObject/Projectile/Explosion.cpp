#include "Explosion.hpp"

Explosion::Explosion(int x, int y, pGameWorld gameWorld) :
    Projectile(IMGID_EXPLOSION, x, y, 3*LAWN_GRID_WIDTH, 3*LAWN_GRID_HEIGHT, std::move(gameWorld), ObjectTag::TAG_EXPLOSION, 0) {
}

bool Explosion::OnCollide(pGameObject other) {
    return true;
}

void Explosion::Update() {
    if (GetDead()) {
        return;
    }
    if (explosionTimer == 0) {
        Die();
    }
    explosionTimer--;
}