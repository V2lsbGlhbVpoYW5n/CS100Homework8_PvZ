#include "BucketHeadZombie.hpp"

BucketHeadZombie::BucketHeadZombie(int x, int y, pGameWorld gameWorld) :
    Zombie(IMGID_BUCKET_HEAD_ZOMBIE, x, y, 20, 80, ANIMID_WALK_ANIM, std::move(gameWorld), 1300, 1) {
}

void BucketHeadZombie::Update() {
    Zombie::Update();
    if (GetDead()) {
        return;
    }
    if (HP <= 200) {
        ChangeImage(IMGID_REGULAR_ZOMBIE);
    }
}
