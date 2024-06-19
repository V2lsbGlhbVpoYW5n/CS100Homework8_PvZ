#include "GameWorld.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Sun.hpp"

GameWorld::GameWorld() : SunProducer(180, 300) {
}

GameWorld::~GameWorld() {
}

void GameWorld::Init() {
    // initialize sun and round
    sun = 50;
    round = 0;

    // create planting spots
    gameObjects.push_back(std::make_shared<Background>(shared_from_this()));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            gameObjects.push_back(std::make_shared<PlantingSpot>(FIRST_COL_CENTER + j * LAWN_GRID_WIDTH,
                                                                 FIRST_ROW_CENTER + i * LAWN_GRID_HEIGHT,
                                                                 shared_from_this()));
        }
    }
}

LevelStatus GameWorld::Update() {
    // update all game objects
    SunProducer::Update();
    if (SunProducer::GetCurrentInterval() == 0) {
        AddObject(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, shared_from_this(), false));
    }
    std::list<pGameObject> toRemove;
    for (auto &obj : gameObjects) {
        obj->Update();
        if (obj->GetDead()) {
            toRemove.push_back(obj);
        }
    }
    RemoveObject(toRemove);
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
    gameObjects.clear();
}

//void GameWorld::PlantSeed(pGameObject seed) {
//    gameObjects.push_back(std::make_shared<seed.getPlant()>());
//}

void GameWorld::AddObject(pGameObject obj) {
    gameObjects.push_back(obj);
}

void GameWorld::RemoveObject(const std::list<pGameObject>& toRemove) {
    for(auto &obj : toRemove) {
        gameObjects.remove(obj);
    }
}

void GameWorld::ChangeSun(int sunValueDelta) {
    sun += sunValueDelta;
}
