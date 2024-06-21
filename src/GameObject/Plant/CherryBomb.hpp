#ifndef PVZ_SRC_GAMEOBJECT_PLANT_CHERRYBOMB_HPP
#define PVZ_SRC_GAMEOBJECT_PLANT_CHERRYBOMB_HPP

#include "Plant.hpp"
#include "GameObject/Interface/Ash.hpp"

class CherryBomb : public Plant, public Ash {
public:
    CherryBomb(int x, int y, pGameWorld gameWorld);
    CherryBomb(const CherryBomb &other) = delete;
    CherryBomb(CherryBomb &&other) = delete;
    CherryBomb &operator=(const CherryBomb &other) = delete;
    CherryBomb &operator=(CherryBomb &&other) = delete;
    ~CherryBomb() override = default;

    void Update() override;
};

#endif //PVZ_SRC_GAMEOBJECT_PLANT_CHERRYBOMB_HPP
