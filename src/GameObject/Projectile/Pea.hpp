#ifndef PVZ_SRC_GAMEOBJECT_PROJECTILE_PEA_HPP
#define PVZ_SRC_GAMEOBJECT_PROJECTILE_PEA_HPP

#include "Projectile.hpp"

class Pea : public Projectile {
public:
    Pea(int x, int y, pGameWorld gameWorld);
    Pea(const Pea &other) = delete;
    Pea(Pea &&other) = delete;
    Pea &operator=(const Pea &other) = delete;
    Pea &operator=(Pea &&other) = delete;
    ~Pea() override = default;

    bool OnCollide(pGameObject other) override;
};

#endif //PVZ_SRC_GAMEOBJECT_PROJECTILE_PEA_HPP
