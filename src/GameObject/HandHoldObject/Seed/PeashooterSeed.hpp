#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_PEASHOOTERSEED_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_PEASHOOTERSEED_HPP

#include "Seed.hpp"

class PeaShooterSeed : public Seed {
public:
    PeaShooterSeed(int x, int y, pGameWorld gameWorld);
    PeaShooterSeed(const PeaShooterSeed &other) = delete;
    PeaShooterSeed(PeaShooterSeed &&other) = delete;
    PeaShooterSeed &operator=(const PeaShooterSeed &other) = delete;
    PeaShooterSeed &operator=(PeaShooterSeed &&other) = delete;
    ~PeaShooterSeed() override = default;

    void UseObject(int x, int y) override;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_PEASHOOTERSEED_HPP
