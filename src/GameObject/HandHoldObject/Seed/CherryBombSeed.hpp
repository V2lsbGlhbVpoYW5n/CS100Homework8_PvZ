#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_CHERRYBOMBSEED_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_CHERRYBOMBSEED_HPP

#include "Seed.hpp"

class CherryBombSeed : public Seed {
public:
    CherryBombSeed(int x, int y, pGameWorld gameWorld);
    CherryBombSeed(const CherryBombSeed &other) = delete;
    CherryBombSeed(CherryBombSeed &&other) = delete;
    CherryBombSeed &operator=(const CherryBombSeed &other) = delete;
    CherryBombSeed &operator=(CherryBombSeed &&other) = delete;
    ~CherryBombSeed() override = default;

    void UseObject(int x, int y) override;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_CHERRYBOMBSEED_HPP
