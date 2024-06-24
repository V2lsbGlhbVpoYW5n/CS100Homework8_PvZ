#include "GameWorld.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Sun.hpp"
#include "HandHoldObject/Shovel.hpp"
// TODO: Seed maker
#include "HandHoldObject/Seed/SunflowerSeed.hpp"
#include "HandHoldObject/Seed/PeashooterSeed.hpp"
#include "HandHoldObject/Seed/RepeaterSeed.hpp"
#include "HandHoldObject/Seed/WallnutSeed.hpp"
#include "HandHoldObject/Seed/CherryBombSeed.hpp"

// TODO: Zombie maker
#include "Zombie/RegularZombie.hpp"
#include "Zombie/BucketHeadZombie.hpp"
#include "Zombie/PoleVaultingZombie.hpp"

GameWorld::GameWorld() : SunProducer(180, 300),
                         sunText(std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, "0", 0, 0, 0)),
                         waveText(std::make_shared<TextBase>(WINDOW_WIDTH - 150, 30, "Wave: 0", 1.0, 1.0, 1.0, false)),
                         handText(std::make_shared<TextBase>(650, WINDOW_HEIGHT - 40, "Hand: Empty", 0, 0, 0, false)) {
}

GameWorld::~GameWorld() {
}

void GameWorld::Init() {
    // initialize sun and wave
    sun = 5000;
    wave = 0;

    // create planting spots
    gameObjects.push_back(std::make_shared<Background>(shared_from_this()));
    for (int i = 0; i < GAME_ROWS; i++) {
        for (int j = 0; j < GAME_COLS; j++) {
            gameObjects.push_back(std::make_shared<PlantingSpot>(FIRST_COL_CENTER + j * LAWN_GRID_WIDTH,
                                                                 FIRST_ROW_CENTER + i * LAWN_GRID_HEIGHT,
                                                                 shared_from_this()));
        }
    }

    //create shovel
    gameObjects.push_back(std::make_shared<Shovel>(shared_from_this()));

    // create seeds
    gameObjects.push_back(std::make_shared<SunflowerSeed>(130, WINDOW_HEIGHT - 44, shared_from_this()));
    gameObjects.push_back(std::make_shared<PeaShooterSeed>(130 + 60, WINDOW_HEIGHT - 44, shared_from_this()));
    gameObjects.push_back(std::make_shared<RepeaterSeed>(130 + 60 * 2, WINDOW_HEIGHT - 44, shared_from_this()));
    gameObjects.push_back(std::make_shared<WallnutSeed>(130 + 60 * 3, WINDOW_HEIGHT - 44, shared_from_this()));
    gameObjects.push_back(std::make_shared<CherryBombSeed>(130 + 60 * 4, WINDOW_HEIGHT - 44, shared_from_this()));
    AddObject(std::make_shared<PoleVaultingZombie
    >(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER
        + randInt(0, GAME_ROWS - 1) * LAWN_GRID_HEIGHT, shared_from_this()));
}

LevelStatus GameWorld::Update() {
    // SunProducer Update
    if (SunProducer::Update()) {
        AddObject(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, shared_from_this(), false));
    }

    // Update all game objects
    for (auto &obj : gameObjects) {
        obj->Update();
    }

    // Check Collide
    for (auto it1 = gameObjects.begin(); it1 != gameObjects.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != gameObjects.end(); ++it2) {
            if ((*it1)->CanCollide() && (*it2)->CanCollide()) {
                (*it1)->OnCollide(*it2);
                (*it2)->OnCollide(*it1);
            }
        }
    }

    // Check dead objects
    // Find Zombies
    std::list<pGameObject> zombies;
    std::list<pGameObject> toRemove;
    for (auto &obj : gameObjects) {
        if (obj->GetDead()) {
            toRemove.push_back(obj);
        } else if (obj->HasTag(ObjectTag::TAG_ZOMBIE)) {
            zombies.push_back(obj);
        }
    }

    // Check if the level is over
    if (!zombies.empty()) {
        for (auto &zombie : zombies) {
            if (zombie->GetX() < 0) {
                waveText->SetText(std::to_string(wave - 1));
                waveText->MoveTo(500, 80);
                return LevelStatus::LOSING;
            }
        }
    }

    // Check Collide Again to keep zombie status correct
    for (auto &zombie : zombies) {
        for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
            if ((*it)->HasTag(ObjectTag::TAG_PLANT)) {
                zombie->OnCollide(*it);
            }
        }
    }

    // Remove dead objects
    RemoveObject(toRemove);

    sunText->SetText(std::to_string(sun));
    handText->SetText(std::string("Hand: ") + (IsHandEmpty() ? "Empty" : (IsHandShovel() ? "Shovel" : "Plant")));

    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
    ClearHandObjectUseFunction();
    gameObjects.clear();
    SunProducer::Reset();
    ZombieSpawner::Reset();
    sunText->SetText("0");
    waveText->SetText("Wave: 0");
    handText->SetText("Hand: Empty");
    waveText->MoveTo(WINDOW_WIDTH - 150, 30);
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

int GameWorld::GetSun() {
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

bool GameWorld::IsHandShovel() {
    return isHandShovel;
}

void GameWorld::ClearHandObjectUseFunction() {
    handObjectUseFunction = nullptr;
    isHandShovel = false;
    // TODO: this may be changed with destructor of an object which can be better
}

bool GameWorld::IsPoleVaultingZombieJump(pGameObject zombie) {
    for (auto &obj : gameObjects) {
        if (obj->HasTag(ObjectTag::TAG_PLANT) && !obj->GetDead()) {
            if (abs(zombie->GetX() - 40 - obj->GetX()) < (obj->GetWidth() + zombie->GetWidth())/2
                && abs(zombie->GetY() - obj->GetY()) < (obj->GetHeight() + zombie->GetHeight())/2) {
                return true;
            }
        }
    }
    return false;
}