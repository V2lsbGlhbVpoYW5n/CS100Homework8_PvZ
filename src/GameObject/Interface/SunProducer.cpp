#include "SunProducer.hpp"
#include "GameWorld.hpp"

SunProducer::SunProducer(int firstSunTime, int sunInterval) : firstSunTime(firstSunTime), sunInterval(sunInterval) {
}

bool SunProducer::Update() {
    if (currentInterval == 0) {
        currentInterval = sunInterval;
        return true;
    } else {
        currentInterval--;
        return false;
    }
}