#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_WALLNUTSEED_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_WALLNUTSEED_HPP

#include "Seed.hpp"

class WallnutSeed : public Seed {
public:
    WallnutSeed(int x, int y, pGameWorld gameWorld);
    WallnutSeed(const WallnutSeed &other) = delete;
    WallnutSeed(WallnutSeed &&other) = delete;
    WallnutSeed &operator=(const WallnutSeed &other) = delete;
    WallnutSeed &operator=(WallnutSeed &&other) = delete;
    ~WallnutSeed() override = default;

    void UseObject(int x, int y) override;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_WALLNUTSEED_HPP
