
#ifndef PVZ_SRC_GAMEWORLD_ZOMBIESPAWNER_HPP
#define PVZ_SRC_GAMEWORLD_ZOMBIESPAWNER_HPP

class ZombieSpawner {
public:
    ZombieSpawner() = default;
    ZombieSpawner(const ZombieSpawner &other) = delete;
    ZombieSpawner(ZombieSpawner &&other) = delete;
    ZombieSpawner &operator=(const ZombieSpawner &other) = delete;
    ZombieSpawner &operator=(ZombieSpawner &&other) = delete;
    ~ZombieSpawner() = default;

    int Update(int wave);
    int GetNextTimer(int wave);
    void Reset();

private:
    int timer = 1200;
};

#endif //PVZ_SRC_GAMEWORLD_ZOMBIESPAWNER_HPP
