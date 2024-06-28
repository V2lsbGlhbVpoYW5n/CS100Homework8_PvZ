#include "Zombie.hpp"

Zombie::Zombie(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP, int SPD) :
    GameObject(imageID, x, y, LAYER_ZOMBIES, width, height, animID, std::move(gameWorld), ObjectTag::TAG_ZOMBIE),
    HP(HP), SPD(SPD) {
}

void Zombie::Update() {
    if (HP <= 0) {
        Die();
        return;
    }

    if (status == ZombieStatus::WALK) {
        if (GetCurrentAnimation() != ANIMID_WALK_ANIM) {
            PlayAnimation(ANIMID_WALK_ANIM);
        }
        MoveTo(GetX() - SPD, GetY());
    } else if (status == ZombieStatus::EAT && GetCurrentAnimation() != ANIMID_EAT_ANIM) {
        PlayAnimation(ANIMID_EAT_ANIM);
    }
}

bool Zombie::OnCollide(pGameObejct other) {
    if (!GameObject::OnCollide(other)) {
        return false;
    }
    switch (other->GetTag()) {
        case ObjectTag::TAG_PLANT:
            if (other->GetX() < GetX() + 20) {
                status = ZombieStatus::EAT;
            }
            if (other->GetDead()) {
                status = ZombieStatus::WALK;
            }
            break;
        case ObjectTag::TAG_EXPLOSION:
            Die();
            break;
        case ObjectTag::TAG_PEA:
            HP -= 20;
            break;
        case ObjectTag::TAG_ZOMBIE:
        case ObjectTag::TAG_NONE:
            break;
    }
    return true;
}

void Zombie::OnClick() {
}