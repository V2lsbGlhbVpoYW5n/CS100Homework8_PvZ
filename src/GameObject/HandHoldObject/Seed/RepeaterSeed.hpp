#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_REPEATERSEED_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_REPEATERSEED_HPP

#include "Seed.hpp"

class RepeaterSeed : public Seed {
public:
    RepeaterSeed(int x, int y, pGameWorld gameWorld);
    RepeaterSeed(const RepeaterSeed &other) = delete;
    RepeaterSeed(RepeaterSeed &&other) = delete;
    RepeaterSeed &operator=(const RepeaterSeed &other) = delete;
    RepeaterSeed &operator=(RepeaterSeed &&other) = delete;
    ~RepeaterSeed() override = default;

    void UseObject(int x, int y) override;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_REPEATERSEED_HPP
