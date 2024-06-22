#ifndef PVZ_SRC_GAMEOBJECT_PROJECTILE_EXPLOSION_HPP
#define PVZ_SRC_GAMEOBJECT_PROJECTILE_EXPLOSION_HPP

#include "Projectile.hpp"

class Explosion : public Projectile {
public:
    Explosion(int x, int y, pGameWorld gameWorld);
    Explosion(const Explosion &other) = delete;
    Explosion(Explosion &&other) = delete;
    Explosion &operator=(const Explosion &other) = delete;
    Explosion &operator=(Explosion &&other) = delete;
    ~Explosion() override = default;

    void Update() override;
    bool OnCollide(pGameObject other) override;
private:
    int explosionTimer = 3;
};

#endif //PVZ_SRC_GAMEOBJECT_PROJECTILE_EXPLOSION_HPP
