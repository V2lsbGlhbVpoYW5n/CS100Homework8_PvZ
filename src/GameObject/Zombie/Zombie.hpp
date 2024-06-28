#ifndef PVZ_SRC_GAMEOBJECT_ZOMBIE_ZOMBIE_HPP
#define PVZ_SRC_GAMEOBJECT_ZOMBIE_ZOMBIE_HPP

#include "GameObject.hpp"

enum class ZombieStatus {
    WALK,
    EAT,
    RUN
};

class Zombie : public GameObject {
public:
    Zombie(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP, int SPD);
    Zombie(const Zombie &other) = delete;
    Zombie(Zombie &&other) = delete;
    Zombie &operator=(const Zombie &other) = delete;
    Zombie &operator=(Zombie &&other) = delete;
    ~Zombie() override = default;

    void Update() override;
    bool OnCollide(pGameObejct other) override;
    void OnClick() override;

protected:
    ZombieStatus status = ZombieStatus::WALK;
    int HP;
    int SPD;
};

#endif //PVZ_SRC_GAMEOBJECT_ZOMBIE_ZOMBIE_HPP
