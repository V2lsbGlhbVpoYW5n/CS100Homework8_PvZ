
#ifndef PVZ_SRC_GAMEOBJECT_ZOMBIE_BUCKETHEADZOMBIE_HPP
#define PVZ_SRC_GAMEOBJECT_ZOMBIE_BUCKETHEADZOMBIE_HPP

#include "Zombie.hpp"

class BucketHeadZombie : public Zombie {
public:
    BucketHeadZombie(int x, int y, pGameWorld gameWorld);
    BucketHeadZombie(const BucketHeadZombie &other) = delete;
    BucketHeadZombie(BucketHeadZombie &&other) = delete;
    BucketHeadZombie &operator=(const BucketHeadZombie &other) = delete;
    BucketHeadZombie &operator=(BucketHeadZombie &&other) = delete;
    ~BucketHeadZombie() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_ZOMBIE_BUCKETHEADZOMBIE_HPP
