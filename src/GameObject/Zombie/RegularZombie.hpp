#ifndef PVZ_SRC_GAMEOBJECT_ZOMBIE_REGULARZOMBIE_HPP
#define PVZ_SRC_GAMEOBJECT_ZOMBIE_REGULARZOMBIE_HPP

#include "Zombie.hpp"

class RegularZombie : public Zombie {
public:
    RegularZombie(int x, int y, pGameWorld gameWorld);
    RegularZombie(const RegularZombie &other) = delete;
    RegularZombie(RegularZombie &&other) = delete;
    RegularZombie &operator=(const RegularZombie &other) = delete;
    RegularZombie &operator=(RegularZombie &&other) = delete;
    ~RegularZombie() override = default;
};

#endif //PVZ_SRC_GAMEOBJECT_ZOMBIE_REGULARZOMBIE_HPP
