#include "Pea.hpp"

Pea::Pea(int x, int y, pGameWorld gameWorld) :
    Projectile(IMGID_PEA, x, y, 28, 28, std::move(gameWorld), ObjectTag::TAG_PEA, 8) {
}

bool Pea::OnCollide(pGameObject other) {
    if (!Projectile::OnCollide(other)) {
        return false;
    }
    if (other->HasTag(ObjectTag::TAG_ZOMBIE)) {
        Die();
    }
    return true;
}
