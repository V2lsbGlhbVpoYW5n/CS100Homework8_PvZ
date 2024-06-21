#ifndef PVZ_SRC_GAMEOBJECT_PLANT_REPEATER_HPP
#define PVZ_SRC_GAMEOBJECT_PLANT_REPEATER_HPP

#include "Plant.hpp"
#include "GameObject/Interface/Attacker.hpp"

class Repeater : public Plant, public Attacker {
public:
    Repeater(int x, int y, pGameWorld gameWorld);
    Repeater(const Repeater &other) = delete;
    Repeater(Repeater &&other) = delete;
    Repeater &operator=(const Repeater &other) = delete;
    Repeater &operator=(Repeater &&other) = delete;
    ~Repeater() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_PLANT_REPEATER_HPP
