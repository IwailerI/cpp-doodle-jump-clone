//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PHYSICSSERVER_H
#define PROJECT_PHYSICSSERVER_H

#include "objects/Collider.h"

const int MAX_BODIES = 100;

class PhysicsServer {
private:
    PhysicsServer() = default;

protected:
    Collider *_player;
    Collider *_bodies[MAX_BODIES];

    int _size;

    void remove(int i, bool clear = true);
public:
    // returns current singleton instance or creates a new one
    static PhysicsServer &Instance() {
        static PhysicsServer instance;
        return instance;
    }

    void RegisterPlayer(Collider *player);

    int Add(Collider *col);


    void Update();

    void Clear(bool soft = true);
};

#endif //PROJECT_PHYSICSSERVER_H
