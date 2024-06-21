#include "SunflowerSeed.hpp"
#include "Plant/Sunflower.hpp"

SunflowerSeed::SunflowerSeed(int x, int y, pGameWorld gameWorld) :
    Seed(IMGID_SEED_SUNFLOWER, x, y, std::move(gameWorld), 50, 240, false) {
}

void SunflowerSeed::UseObject(int x, int y) {
    Seed::MakePlant<Sunflower>(x, y);
}