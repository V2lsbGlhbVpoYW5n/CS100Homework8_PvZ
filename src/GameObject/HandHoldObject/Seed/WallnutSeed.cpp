#include "WallnutSeed.hpp"
#include "Plant/Wallnut.hpp"

WallnutSeed::WallnutSeed(int x, int y, pGameWorld gameWorld) :
    Seed(IMGID_SEED_WALLNUT, x, y, std::move(gameWorld), 50, 900, false) {
}

void WallnutSeed::UseObject(int x, int y) {
    Seed::MakePlant<Wallnut>(x, y);
}