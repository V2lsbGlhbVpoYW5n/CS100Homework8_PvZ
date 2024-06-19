#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"

#include "TextBase.hpp"
#include "utils.hpp"

#include "SunProducer.hpp"

using pGameObject = std::shared_ptr<GameObject>;

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld>, public SunProducer {
public:
    // Use shared_from_this() instead of "this" to create a pointer to oneself.
    GameWorld();
    virtual ~GameWorld();

    void Init() override;

    LevelStatus Update() override;

    void CleanUp() override;

    void AddObject(pGameObject seed);

    void RemoveObject(const std::list<pGameObject>& toRemove);

    void ChangeSun(int sunValueDelta);


private:
    std::list<pGameObject> gameObjects;
    int sun = 0;
    int round = 0;
};

#endif // !GAMEWORLD_HPP__
