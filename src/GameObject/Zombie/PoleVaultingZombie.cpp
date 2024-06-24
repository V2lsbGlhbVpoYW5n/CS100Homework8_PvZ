#include "PoleVaultingZombie.hpp"
#include "GameWorld.hpp"

PoleVaultingZombie::PoleVaultingZombie(int x, int y, pGameWorld gameWorld) :
    Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, 20, 80, ANIMID_RUN_ANIM, std::move(gameWorld), 340, 2) {
    status = ZombieStatus::RUN;
}

void PoleVaultingZombie::Update() {
    if (HP <= 0) {
        Die();
        return;
    }
    switch (status) {
        case ZombieStatus::RUN:
            if (isJumped) {
                if (jumpTimer != 0) {
                    jumpTimer--;
                    if (jumpTimer == 0) {
                        PlayAnimation(ANIMID_WALK_ANIM);
                        status = ZombieStatus::WALK;
                        SPD = 1;
                        MoveTo(GetX() - 150, GetY());
                    }
                }
            } else {
                MoveTo(GetX() - SPD, GetY());
                if (gameWorld->IsPoleVaultingZombieJump(shared_from_this())) {
                    jumpTimer = 42;
                    isJumped = true;
                    PlayAnimation(ANIMID_JUMP_ANIM);
                }
            }
            break;
        case ZombieStatus::WALK:
            if (GetCurrentAnimation() != ANIMID_WALK_ANIM) {
                PlayAnimation(ANIMID_WALK_ANIM);
            }
            MoveTo(GetX() - SPD, GetY());
            break;
        case ZombieStatus::EAT:
            if (GetCurrentAnimation() != ANIMID_EAT_ANIM) {
                PlayAnimation(ANIMID_EAT_ANIM);
            }
            break;
    }
}