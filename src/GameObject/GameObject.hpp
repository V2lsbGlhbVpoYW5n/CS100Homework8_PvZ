#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

enum class ObjectTag {
    TAG_PLANT,
    TAG_ZOMBIE,
    TAG_PEA,
    TAG_EXPLOSION,
    TAG_NONE
};

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
    using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".
    using pGameObejct = std::shared_ptr<GameObject>;

    GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld,
               ObjectTag tag);
    GameObject(const GameObject &other) = delete;
    GameObject(GameObject &&other) = delete;
    GameObject &operator=(const GameObject &other) = delete;
    GameObject &operator=(GameObject &&other) = delete;
    ~GameObject() override = default;

    void Update() override = 0;
    void OnClick() override = 0;
    virtual bool CheckCollide(pGameObejct other) const;
    virtual bool OnCollide(pGameObejct other);
    bool CanCollide() const;

    bool GetDead() const;

    ObjectTag GetTag() const;
    bool HasTag(ObjectTag targetTag) const;

protected:
    void Die();
    pGameWorld gameWorld;
private:
    bool isDead = false;
    ObjectTag tag = ObjectTag::TAG_NONE;
};

#endif // !GAMEOBJECT_HPP__
