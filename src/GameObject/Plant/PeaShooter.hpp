#ifndef PVZ_SRC_GAMEOBJECT_PLANT_PEASHOOTER_HPP
#define PVZ_SRC_GAMEOBJECT_PLANT_PEASHOOTER_HPP

#include "Plant.hpp"
#include "GameObject/Interface/Attacker.hpp"

class PeaShooter : public Plant, public Attacker {
public:
    PeaShooter(int x, int y, pGameWorld gameWorld);
    PeaShooter(const PeaShooter &other) = delete;
    PeaShooter(PeaShooter &&other) = delete;
    PeaShooter &operator=(const PeaShooter &other) = delete;
    PeaShooter &operator=(PeaShooter &&other) = delete;
    ~PeaShooter() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_PLANT_PEASHOOTER_HPP
