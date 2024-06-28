#ifndef PVZ_SRC_GAMEOBJECT_INTERFACE_ASH_HPP
#define PVZ_SRC_GAMEOBJECT_INTERFACE_ASH_HPP

class Ash {
public:
    Ash(int timer);
    ~Ash() = default;

    bool Update();
private:
    int timer;
};

#endif //PVZ_SRC_GAMEOBJECT_INTERFACE_ASH_HPP
