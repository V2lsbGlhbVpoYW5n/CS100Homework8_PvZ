#include "PoleVaultingZombie.hpp"
#include "GameWorld.hpp"

PoleVaultingZombie::PoleVaultingZombie(int x, int y, pGameWorld gameWorld) :
    Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, 20, 80, ANIMID_RUN_ANIM, std::move(gameWorld), 340, 2) {
}

void PoleVaultingZombie::Update() {
    if (HP <= 0) {
        Die();
        return;
    }
    if (jumpTimer != 0) {
        jumpTimer--;
        if (jumpTimer == 0) {
            PlayAnimation(ANIMID_WALK_ANIM);
            SPD = 1;
            MoveTo(GetX() - 150, GetY());
        }
    } else {
        if (!isJumped && gameWorld->IsPoleVaultingZombieJump(shared_from_this())) {
            jumpTimer = 42;
            isJumped = true;
            PlayAnimation(ANIMID_JUMP_ANIM);
        }
        if (status == ZombieStatus::WALK) {
            MoveTo(GetX() - SPD, GetY());
        }
    }
}