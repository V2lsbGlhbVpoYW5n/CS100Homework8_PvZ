#ifndef PVZ_SRC_GAMEOBJECT_PLANT_WALLNUT_HPP
#define PVZ_SRC_GAMEOBJECT_PLANT_WALLNUT_HPP

#include "Plant.hpp"

class Wallnut : public Plant {
public:
    Wallnut(int x, int y, pGameWorld gameWorld);
    Wallnut(const Wallnut &other) = delete;
    Wallnut(Wallnut &&other) = delete;
    Wallnut &operator=(const Wallnut &other) = delete;
    Wallnut &operator=(Wallnut &&other) = delete;
    ~Wallnut() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_PLANT_WALLNUT_HPP
