#ifndef PVZ_SRC_GAMEOBJECT_SUNPRODUCER_HPP
#define PVZ_SRC_GAMEOBJECT_SUNPRODUCER_HPP

class SunProducer {
public:
    SunProducer(int firstSunTime, int sunInterval);
    ~SunProducer() = default;

    bool Update();
    void Reset();

private:
    int firstSunTime;
    int sunInterval;
    int currentInterval = firstSunTime;
};

#endif //PVZ_SRC_GAMEOBJECT_SUNPRODUCER_HPP
