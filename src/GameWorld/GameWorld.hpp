#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include <functional>

#include "WorldBase.hpp"

#include "GameObject.hpp"
#include "HandHoldObject/HandHoldObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

#include "GameObject/Interface/SunProducer.hpp"

using pGameObject = std::shared_ptr<GameObject>;
using pHandHoldObject = std::shared_ptr<HandHoldObject>;

class Hand {
public:
    void SetHandObject(pHandHoldObject obj);
    pHandHoldObject GetHandObject() const;
    void ClearHandObject();
    bool IsEmpty();

private:
    pHandHoldObject handObject = nullptr;
};

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>, public SunProducer {
public:
    // Use shared_from_this() instead of "this" to create a pointer to oneself.
    GameWorld();
    virtual ~GameWorld();

    void Init() override;

    LevelStatus Update() override;

    void CleanUp() override;

    void AddObject(pGameObject obj);
    void RemoveObject(const std::list<pGameObject> &toRemove);

    void ChangeSun(int sunValueDelta);

    void SetHandObject(pHandHoldObject obj);
    pHandHoldObject UseHandObject();
    bool IsHandEmpty();

    //
    void SetHandObjectUseFunction(std::function<void(int &&, int &&)> lambda);
    std::function<void(int &&, int &&)> GetHandObjectUseFunction();

private:
    std::list<pGameObject> gameObjects;
    int sun = 0;
    int round = 0;
    Hand hand = Hand();
    //
    std::function<void(int &&, int &&)> handObjectUseFunction;
};

#endif // !GAMEWORLD_HPP__
