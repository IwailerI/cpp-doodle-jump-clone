//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PHYSICSSERVER_H
#define PROJECT_PHYSICSSERVER_H

#include "objects/Collider.h"
#include "Player.h"

const int MAX_BODIES = 100;

class PhysicsServer {
private:
    PhysicsServer() = default;

protected:
    Player *_player;
    Collider *_bodies[MAX_BODIES];


    int _size;
public:
    // returns current singleton instance or creates a new one
    static PhysicsServer &Instance() {
        static PhysicsServer instance;
        return instance;
    }

    void RegisterPlayer(Player *player);

    int Add(Collider *col);
    void Remove(int i);

    void Update();


};

#endif //PROJECT_PHYSICSSERVER_H
