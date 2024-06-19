#ifndef PVZ_SRC_GAMEOBJECT_PLANTINGSPOT_HPP
#define PVZ_SRC_GAMEOBJECT_PLANTINGSPOT_HPP

#include "GameObject.hpp"

class PlantingSpot : public GameObject {
public:
    PlantingSpot(int x, int y, pGameWorld gameWorld);
    PlantingSpot(const PlantingSpot &other) = delete;
    PlantingSpot(PlantingSpot &&other) = delete;
    PlantingSpot &operator=(const PlantingSpot &other) = delete;
    PlantingSpot &operator=(PlantingSpot &&other) = delete;
    ~PlantingSpot() override = default;

    void Update() override;
    void OnClick() override;

    bool operator==(const ObjectBase &other) override;


};

#endif //PVZ_SRC_GAMEOBJECT_PLANTINGSPOT_HPP
