#ifndef PVZ_SRC_GAMEOBJECT_PROJECTILE_PROJECTILE_HPP
#define PVZ_SRC_GAMEOBJECT_PROJECTILE_PROJECTILE_HPP

#include "GameObject.hpp"
#include "GameWorld.hpp"

class Projectile : public GameObject {
public:
    Projectile(int imageID, int x, int y, int width, int height, pGameWorld gameWorld, ObjectTag tag, int SPD);
    Projectile(const Projectile &other) = delete;
    Projectile(Projectile &&other) = delete;
    Projectile &operator=(const Projectile &other) = delete;
    Projectile &operator=(Projectile &&other) = delete;
    ~Projectile() override = default;

    void Update() override;
    void OnClick() override;
    bool OnCollide(pGameObject other) override;
private:
    int SPD;
};

#endif //PVZ_SRC_GAMEOBJECT_PROJECTILE_PROJECTILE_HPP
