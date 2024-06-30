//
// Created by wailer on 05/03/2022.
//

#ifndef PROJECT_PHYSICS_SERVER_H
#define PROJECT_PHYSICS_SERVER_H

#include <memory>
#include <vector>

#include "objects/Collider.h"

class PhysicsServer {
   private:
    PhysicsServer() = default;

   protected:
    std::shared_ptr<Collider> _player;
    std::vector<std::shared_ptr<Collider>> _bodies;

    void remove(int i);

   public:
    // get the singleton instance
    static PhysicsServer &Instance() {
        static PhysicsServer instance;
        return instance;
    }

    void RegisterPlayer(std::shared_ptr<Collider> player);

    int AddCollider(std::shared_ptr<Collider> col);

    void Update();

    void Clear();
};

#endif  // PROJECT_PHYSICS_SERVER_H
