#ifndef PVZ_SRC_GAMEOBJECT_SUNFLOWER_HPP
#define PVZ_SRC_GAMEOBJECT_SUNFLOWER_HPP

#include "Plant.hpp"
#include "GameObject/Interface/SunProducer.hpp"

class Sunflower : public Plant, public SunProducer {
public:
    Sunflower(int x, int y, pGameWorld gameWorld);
    Sunflower(const Sunflower &other) = delete;
    Sunflower(Sunflower &&other) = delete;
    Sunflower &operator=(const Sunflower &other) = delete;
    Sunflower &operator=(Sunflower &&other) = delete;
    ~Sunflower() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_SUNFLOWER_HPP
