#include "CherryBombSeed.hpp"
#include "Plant/CherryBomb.hpp"

CherryBombSeed::CherryBombSeed(int x, int y, pGameWorld gameWorld) :
    Seed(IMGID_SEED_CHERRY_BOMB, x, y, std::move(gameWorld), 150, 1200, false) {
}

void CherryBombSeed::UseObject(int x, int y) {
    Seed::MakePlant<CherryBomb>(x, y);
}