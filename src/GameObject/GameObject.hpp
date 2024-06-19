#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
    using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

    GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
    GameObject(const GameObject& other) = delete;
    GameObject(GameObject&& other) = delete;
    GameObject& operator=(const GameObject& other) = delete;
    GameObject& operator=(GameObject&& other) = delete;
    ~GameObject() override = default;

    void Update() override = 0;
    void OnClick() override = 0;

    void Die();

    bool GetDead();

    bool operator==(const ObjectBase& other) override;
protected:
    pGameWorld gameWorld;
private:
    bool isDead = false;
};

#endif // !GAMEOBJECT_HPP__
