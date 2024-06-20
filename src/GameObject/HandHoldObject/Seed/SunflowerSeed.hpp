#ifndef PVZ_SRC_GAMEOBJECT_SUNFLOWERSEED_HPP
#define PVZ_SRC_GAMEOBJECT_SUNFLOWERSEED_HPP

#include "Seed.hpp"

class SunflowerSeed : public Seed {
public:
    SunflowerSeed(int x, int y, pGameWorld gameWorld);
    SunflowerSeed(const SunflowerSeed &other) = delete;
    SunflowerSeed(SunflowerSeed &&other) = delete;
    SunflowerSeed &operator=(const SunflowerSeed &other) = delete;
    SunflowerSeed &operator=(SunflowerSeed &&other) = delete;
    ~SunflowerSeed() override = default;

    void UseObject(int x, int y) override;
};

#endif //PVZ_SRC_GAMEOBJECT_SUNFLOWERSEED_HPP
