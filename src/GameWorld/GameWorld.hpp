#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include <functional>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

#include "GameObject/Interface/SunProducer.hpp"
#include "GameObject/Interface/ZombieSpawner.hpp"

using pGameObject = std::shared_ptr<GameObject>;
using pTextBase = std::shared_ptr<TextBase>;

class GameWorld
    : public WorldBase, public std::enable_shared_from_this<GameWorld>, public SunProducer, public ZombieSpawner {
public:
    // Use shared_from_this() instead of "this" to create a pointer to oneself.
    GameWorld();
//    virtual ~GameWorld();
    ~GameWorld() override = default;

    void Init() override;
    LevelStatus Update() override;
    void CleanUp() override;

    void AddObject(pGameObject obj);
    void RemoveObject(const std::list<pGameObject> &toRemove);

    void ChangeSun(int sunValueDelta);
    int GetSun() const;

    void SetHandObjectUseFunction(std::function<void(int &&, int &&)> lambda, bool isShovel);
    std::function<void(int &&, int &&)> GetHandObjectUseFunction();
    bool IsHandEmpty() const;
    bool IsHandShovel() const;
    void ClearHandObjectUseFunction();

    bool IsPoleVaultingZombieJump(const pGameObject& zombie);

private:
    std::list<pGameObject> gameObjects;
    int sun = 0;
    int wave = 0;
    std::function<void(int &&, int &&)> handObjectUseFunction;
    bool isHandShovel = false;
    pTextBase sunText;
    pTextBase waveText;
    pTextBase handText;
};
#endif // !GAMEWORLD_HPP__
