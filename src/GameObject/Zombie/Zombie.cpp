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
        MoveTo(GetX() - SPD, GetY());
    } else if (status == ZombieStatus::EAT) {
    }
    if (status == ZombieStatus::EAT && GetCurrentAnimation() != ANIMID_EAT_ANIM) {
        PlayAnimation(ANIMID_EAT_ANIM);
    } else if (status == ZombieStatus::WALK && GetCurrentAnimation() != ANIMID_WALK_ANIM) {
        PlayAnimation(ANIMID_WALK_ANIM);
    }
}

void Zombie::ChangeStatus(ZombieStatus status) {
    this->status = status;
}

bool Zombie::OnCollide(pGameObejct other) {
    if (!GameObject::OnCollide(other)){
        ChangeStatus(ZombieStatus::WALK);
        return false;
    }
    switch (other->GetTag()) {
        case ObjectTag::TAG_PLANT:
                ChangeStatus(ZombieStatus::EAT);
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