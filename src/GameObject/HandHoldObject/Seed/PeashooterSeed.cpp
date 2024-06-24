#include "PeaShooterSeed.hpp"
#include "Plant/PeaShooter.hpp"

PeaShooterSeed::PeaShooterSeed(int x, int y, pGameWorld gameWorld) :
    Seed(IMGID_SEED_PEASHOOTER, x, y, std::move(gameWorld), 100, 240, true) {
}

void PeaShooterSeed::UseObject(int x, int y) {
    Seed::MakePlant<PeaShooter>(x, y);
}