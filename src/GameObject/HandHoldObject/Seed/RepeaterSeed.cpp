#include "RepeaterSeed.hpp"
#include "Plant/Repeater.hpp"

RepeaterSeed::RepeaterSeed(int x, int y, pGameWorld gameWorld) :
    Seed(IMGID_SEED_REPEATER, x, y, std::move(gameWorld), 200, 240, true) {
}

void RepeaterSeed::UseObject(int x, int y) {
    Seed::MakePlant<Repeater>(x, y);
}