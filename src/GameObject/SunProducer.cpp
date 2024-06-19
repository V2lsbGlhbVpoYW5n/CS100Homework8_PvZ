#include "SunProducer.hpp"
#include "GameWorld.hpp"

SunProducer::SunProducer(int firstSunTime, int sunInterval) : firstSunTime(firstSunTime), sunInterval(sunInterval) {
}

void SunProducer::Update() {
    if (currentInterval == 0) {
        currentInterval = sunInterval;
    } else {
        currentInterval--;
    }
}

int SunProducer::GetCurrentInterval() const {
    return currentInterval;
}