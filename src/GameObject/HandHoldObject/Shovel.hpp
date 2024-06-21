#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SHOVEL_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SHOVEL_HPP

#include "HandHoldObject.hpp"

class Shovel : public HandHoldObject {
public:
    Shovel(pGameWorld gameWorld);
    Shovel(const Shovel &other) = delete;
    Shovel(Shovel &&other) = delete;
    Shovel &operator=(const Shovel &other) = delete;
    Shovel &operator=(Shovel &&other) = delete;
    ~Shovel() override = default;

    void UseObject(int x, int y) override;
    void OnClick() override;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SHOVEL_HPP
