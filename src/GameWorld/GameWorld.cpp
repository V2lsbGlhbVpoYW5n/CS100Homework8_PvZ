#include "GameWorld.hpp"
#include "Background.hpp"

GameWorld::GameWorld() {
    gameObjects.push_back(
        std::make_shared<Background>(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND,
                                     WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION));
}

GameWorld::~GameWorld() {
}

void GameWorld::Init() {
    // YOUR CODE HERE
    for (auto& obj : gameObjects) {

    }
}

LevelStatus GameWorld::Update() {
    // YOUR CODE HERE
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
    // YOUR CODE HERE
}

