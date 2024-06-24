#include "Zombie.hpp"
#include <fstream>
#include <iostream>

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

void Zombie::ChangeStatus(ZombieStatus status) {
    this->status = status;
}

bool Zombie::OnCollide(pGameObejct other) {
//    std::fstream f;
//    f.open("logDebug.txt", std::ios::out | std::ios::app);
//    f << std::to_string(GetX()) + " " +std::to_string(GetY()) + "\n" << std::endl;
    if (!GameObject::OnCollide(other)) {
//        f.close();
        return false;
    }
    switch (other->GetTag()) {
        case ObjectTag::TAG_PLANT:
//            f << "PLANT\n" << std::endl;
            if (other->GetX() < GetX() + 20){
                status = ZombieStatus::EAT;
            }
            if(other->GetDead()){
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
//    if (status == ZombieStatus::EAT){
//        f << "EAT-----------\n" << std::endl;
//    }
//    f.close();
    return true;
}

void Zombie::OnClick() {
}