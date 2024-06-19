#ifndef PVZ_SRC_GAMEOBJECT_PLANT_HPP
#define PVZ_SRC_GAMEOBJECT_PLANT_HPP

#include "GameObject.hpp"

class Plant : public GameObject {
public:
    Plant(int imageID, int x, int y, int width, int height, AnimID animID, pGameWorld gameWorld, int HP);
    Plant(const Plant &other) = delete;
    Plant(Plant &&other) = delete;
    Plant &operator=(const Plant &other) = delete;
    Plant &operator=(Plant &&other) = delete;
    ~Plant() override = default;

    void Update() override;
    void OnClick() override;

    bool operator==(const ObjectBase &other) override;

    int GetHP() const;

private:
    int HP;
};

#endif //PVZ_SRC_GAMEOBJECT_PLANT_HPP
