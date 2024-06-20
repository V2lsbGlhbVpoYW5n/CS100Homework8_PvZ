#ifndef PVZ_SRC_GAMEOBJECT_SEED_SEED_HPP
#define PVZ_SRC_GAMEOBJECT_SEED_SEED_HPP

#include "HandHoldObject/HandHoldObject.hpp"
#include "GameWorld.hpp"

class Seed : public HandHoldObject {
public:
    Seed(int imageID, int x, int y, pGameWorld gameWorld, int ORIGINAL_COST, int MaxCooldown,
         bool activatedAtBeginning);
    Seed(const Seed &other) = delete;
    Seed(Seed &&other) = delete;
    Seed &operator=(const Seed &other) = delete;
    Seed &operator=(Seed &&other) = delete;
    ~Seed() override = default;

    void ChangeCost(int costDelta);
    void ChangeMaxCooldown(int MaxCooldownDelta);
    bool CheckCooldown();
    void ResetCooldown();

protected:
    template<typename type> void MakePlant(int x, int y){
        gameWorld->AddObject(std::make_shared<type>(x, y, gameWorld));
    }

private:
    const int ORIGINAL_COST;
    int cost = ORIGINAL_COST;
    int MaxCooldown;
    bool activatedAtBeginning;
    int cooldown;

};

#endif //PVZ_SRC_GAMEOBJECT_SEED_SEED_HPP
