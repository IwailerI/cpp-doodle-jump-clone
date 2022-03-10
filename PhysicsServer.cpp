//
// Created by wailer on 05/03/2022.
//

#include "PhysicsServer.h"

void PhysicsServer::RegisterPlayer(Collider *player) {
    _player = player;
}

void PhysicsServer::Update() {
    if (_player == nullptr) return;
    for (int i = 0; i < _size; ++i) {
        if (_player->isColliding(_bodies[i])) {
            _player->onCollision(_bodies[i]);
            _bodies[i]->onCollision(_player);
        }
    }
}

int PhysicsServer::Add(Collider *s) {
    if (_size >= MAX_BODIES) return -1;
    _bodies[_size] = s;
    _bodies[_size]->setPhysicsId(_size);
    _size++;
    return _size-1;
}

void PhysicsServer::Remove(int i) {
    _bodies[i] = _bodies[_size-1];
    delete _bodies[_size-1];
    _bodies[_size--] = nullptr;
}
