#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_HANDHOLDOBJECT_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_HANDHOLDOBJECT_HPP

#include "GameObject.hpp"

using pGameObject = std::shared_ptr<GameObject>;

class HandHoldObject : public GameObject{
public:
    HandHoldObject(int imageID, int x, int y, int width, int height, pGameWorld gameWorld, ObjectTag tag);
    HandHoldObject(const HandHoldObject &other) = delete;
    HandHoldObject(HandHoldObject &&other) = delete;
    HandHoldObject &operator=(const HandHoldObject &other) = delete;
    HandHoldObject &operator=(HandHoldObject &&other) = delete;
    ~HandHoldObject() override = default;

    void Update() override;
    void OnClick() override;

    virtual void UseObject(int x, int y) = 0;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_HANDHOLDOBJECT_HPP
