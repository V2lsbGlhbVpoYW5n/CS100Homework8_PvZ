#ifndef PVZ_SRC_GAMEOBJECT_SUN_HPP
#define PVZ_SRC_GAMEOBJECT_SUN_HPP

#include "GameObject.hpp"

class Sun : public GameObject {
public:
    Sun(int x, int y, pGameWorld gameWorld, bool plantProduced);
    Sun(const Sun &other) = delete;
    Sun(Sun &&other) = delete;
    Sun &operator=(const Sun &other) = delete;
    Sun &operator=(Sun &&other) = delete;
    ~Sun() override = default;

    void Update() override;
    void OnClick() override;

    bool operator==(const ObjectBase &other) override;

private:
    int sunValue = 25;
    int fallingTime;
    bool plantProduced;
    const int PLANTPRODUCED_FALLINGTIME = 12;

};

#endif //PVZ_SRC_GAMEOBJECT_SUN_HPP
