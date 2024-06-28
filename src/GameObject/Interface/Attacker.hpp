#ifndef PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP
#define PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP

class Attacker {
public:
    Attacker(int attackInterval, int attackTimes, int roundInterval);
    ~Attacker() = default;

    bool Update();

private:
    int attackInterval;
    int attackTimes;
    int roundInterval;
    int currentInterval = roundInterval;
    int currentTimes = 0;
};

#endif //PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP
