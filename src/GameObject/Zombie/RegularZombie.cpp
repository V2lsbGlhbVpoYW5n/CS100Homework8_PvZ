#include "RegularZombie.hpp"

RegularZombie::RegularZombie(int x, int y, pGameWorld gameWorld) :
    Zombie(IMGID_REGULAR_ZOMBIE, x, y, 20, 80, ANIMID_WALK_ANIM, std::move(gameWorld), 200, 1) {
}
