#ifndef PVZ_SRC_GAMEOBJECT_BACKGROUND_HPP
#define PVZ_SRC_GAMEOBJECT_BACKGROUND_HPP

#include "GameObject.hpp"

class Background : public GameObject {
public:
    Background(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID);
    Background(const Background& other) = delete;
    Background(Background&& other) = delete;
    Background& operator=(const Background& other) = delete;
    Background& operator=(Background&& other) = delete;
    ~Background() override = default;

    void Update() override;
    void OnClick() override;

    bool operator==(const ObjectBase& other) override;

};

#endif //PVZ_SRC_GAMEOBJECT_BACKGROUND_HPP
