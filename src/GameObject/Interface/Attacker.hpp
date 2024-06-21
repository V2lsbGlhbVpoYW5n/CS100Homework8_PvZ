#ifndef PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP
#define PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP

class Attacker {
public:
    Attacker(int firstAttackTime, int attackInterval);
    ~Attacker() = default;

    bool Update();

private:
    int firstAttackTime;
    int attackInterval;
    int currentInterval = firstAttackTime;
};

#endif //PVZ_SRC_GAMEOBJECT_INTERFACE_ATTACKER_HPP
