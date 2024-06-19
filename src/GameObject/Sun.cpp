#include "Sun.hpp"
#include "GameWorld.hpp"

Sun::Sun(int x, int y, pGameWorld gameWorld, bool plantProduced) :
    GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, gameWorld), plantProduced(plantProduced) {
    // Set FallingTime
    if (plantProduced == false) {
        fallingTime = randInt(63, 263);
    } else {
        fallingTime = PLANTPRODUCED_FALLINGTIME;
    }
}

void Sun::Update() {
    //Remove
    if (fallingTime <= -300) {
        Die();
        return;
    }

    //Fall
    if (plantProduced == false) {
        if (fallingTime > 0) {
            MoveTo(GetX(), GetY() - 2);
        }
    } else {
        if (fallingTime > 0) {
            MoveTo(GetX() - 1, GetY() + (4 - (PLANTPRODUCED_FALLINGTIME - fallingTime)));
        }
    }

    --fallingTime;
}

void Sun::OnClick() {
    gameWorld->ChangeSun(sunValue);
    Die();
}

bool Sun::operator==(const ObjectBase &other) {
    return GameObject::operator==(other);
}