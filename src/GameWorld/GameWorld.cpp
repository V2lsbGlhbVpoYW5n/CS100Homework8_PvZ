#include "GameWorld.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Sun.hpp"
#include "HandHoldObject/Shovel.hpp"
#include "HandHoldObject/Seed/SunflowerSeed.hpp"
#include "HandHoldObject/Seed/PeashooterSeed.hpp"
#include "HandHoldObject/Seed/RepeaterSeed.hpp"
#include "HandHoldObject/Seed/WallnutSeed.hpp"
#include "HandHoldObject/Seed/CherryBombSeed.hpp"


GameWorld::GameWorld() : SunProducer(180, 300) {
}

GameWorld::~GameWorld() {
}

void GameWorld::Init() {
    // initialize sun and wave
    sun = 50;
    wave = 0;

    // create planting spots
    gameObjects.push_back(std::make_shared<Background>(shared_from_this()));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            gameObjects.push_back(std::make_shared<PlantingSpot>(FIRST_COL_CENTER + j * LAWN_GRID_WIDTH,
                                                                 FIRST_ROW_CENTER + i * LAWN_GRID_HEIGHT,
                                                                 shared_from_this()));
        }
    }

    //create shovel
    gameObjects.push_back(std::make_shared<Shovel>(shared_from_this()));

    // create seeds
    gameObjects.push_back(std::make_shared<SunflowerSeed>(130, WINDOW_HEIGHT -44, shared_from_this()));
    gameObjects.push_back(std::make_shared<PeaShooterSeed>(130+60, WINDOW_HEIGHT -44, shared_from_this()));
    gameObjects.push_back(std::make_shared<RepeaterSeed>(130+60*2, WINDOW_HEIGHT -44, shared_from_this()));
    gameObjects.push_back(std::make_shared<WallnutSeed>(130+60*3, WINDOW_HEIGHT -44, shared_from_this()));
    gameObjects.push_back(std::make_shared<CherryBombSeed>(130+60*4, WINDOW_HEIGHT -44, shared_from_this()));

}

LevelStatus GameWorld::Update() {
    // update all game objects
    // SunProducer Update
    if (SunProducer::Update()) {
        AddObject(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, shared_from_this(), false));
    }

    // Check and remove dead objects
    std::list<pGameObject> toRemove;
    for (auto &obj : gameObjects) {
        obj->Update();
        if (obj->GetDead()) {
            toRemove.push_back(obj);
        }
    }
    RemoveObject(toRemove);

    // Check if the level is over
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
    ClearHandObjectUseFunction();
    gameObjects.clear();
}

void GameWorld::AddObject(pGameObject obj) {
    gameObjects.push_back(std::move(obj));
}

void GameWorld::RemoveObject(const std::list<pGameObject> &toRemove) {
    for (auto &obj : toRemove) {
        gameObjects.remove(obj);
    }
}

void GameWorld::ChangeSun(int sunValueDelta) {
    sun += sunValueDelta;
}

int GameWorld::GetSun(){
    return sun;
}

void GameWorld::SetHandObjectUseFunction(std::function<void(int &&, int &&)> lambda, bool isShovel) {
    handObjectUseFunction = std::move(lambda);
    isHandShovel = isShovel;
}

std::function<void(int &&, int &&)> GameWorld::GetHandObjectUseFunction() {
    return handObjectUseFunction;
}

bool GameWorld::IsHandEmpty() {
    return handObjectUseFunction == nullptr;
}

bool GameWorld::IsHandShovel(){
    return isHandShovel;
}

void GameWorld::ClearHandObjectUseFunction() {
    handObjectUseFunction = nullptr;
    isHandShovel = false;
    // this may be changed with destructor of an object which can be better
}