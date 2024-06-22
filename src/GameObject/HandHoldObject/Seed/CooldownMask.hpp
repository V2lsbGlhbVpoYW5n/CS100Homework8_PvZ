#ifndef PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_COOLDOWNMASK_HPP
#define PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_COOLDOWNMASK_HPP

#include "GameObject.hpp"

class TextBase;
using pTextBase = std::shared_ptr<TextBase>;

class CooldownMask : public GameObject {
public:
    CooldownMask(int x, int y, pGameWorld gameWorld, int livingTime);
    CooldownMask(const CooldownMask &other) = delete;
    CooldownMask(CooldownMask &&other) = delete;
    CooldownMask &operator=(const CooldownMask &other) = delete;
    CooldownMask &operator=(CooldownMask &&other) = delete;
    ~CooldownMask() override = default;

    void Update() override;
    void OnClick() override;
private:
    int livingTime;
    pTextBase cooldownText;
};

#endif //PVZ_SRC_GAMEOBJECT_HANDHOLDOBJECT_SEED_COOLDOWNMASK_HPP
