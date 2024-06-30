//
// Created by wailer on 05/03/2022.
//

#include "PhysicsServer.h"

void PhysicsServer::RegisterPlayer(std::shared_ptr<Collider> player) {
    _player = player;
}

void PhysicsServer::Update() {
    if (_player == nullptr) return;
    for (int i = 0; i < _bodies.size(); ++i) {
        if (_bodies[i]->isMarkedForDeletion()) {
            remove(i);
            i--;
        } else if (_player->isColliding(_bodies[i])) {
            _player->onCollision(_bodies[i]);
            _bodies[i]->onCollision(_player);
        }
    }
}

int PhysicsServer::AddCollider(std::shared_ptr<Collider> s) {
    s->setPhysicsId(_bodies.size());
    _bodies.push_back(s);
    return s->getPhysicsId();
}

void PhysicsServer::remove(int i) {
    _bodies[i] = _bodies.back();
    _bodies.pop_back();
}

void PhysicsServer::Clear() {
    _bodies.clear();
    _player = nullptr;
}
