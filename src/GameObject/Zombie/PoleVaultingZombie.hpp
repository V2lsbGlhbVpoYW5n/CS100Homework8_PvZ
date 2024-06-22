
#ifndef PVZ_SRC_GAMEOBJECT_ZOMBIE_POLEVAULTINGZOMBIE_HPP
#define PVZ_SRC_GAMEOBJECT_ZOMBIE_POLEVAULTINGZOMBIE_HPP

#include "Zombie.hpp"

class PoleVaultingZombie : public Zombie {
public:
    PoleVaultingZombie(int x, int y, pGameWorld gameWorld);
    PoleVaultingZombie(const PoleVaultingZombie &other) = delete;
    PoleVaultingZombie(PoleVaultingZombie &&other) = delete;
    PoleVaultingZombie &operator=(const PoleVaultingZombie &other) = delete;
    PoleVaultingZombie &operator=(PoleVaultingZombie &&other) = delete;
    ~PoleVaultingZombie() override = default;

    void Update() override;
private:
    int jumpTimer = 0;
    bool isJumped = false;
};

#endif //PVZ_SRC_GAMEOBJECT_ZOMBIE_POLEVAULTINGZOMBIE_HPP
