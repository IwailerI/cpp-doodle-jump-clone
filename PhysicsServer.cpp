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
        // delete if necessary
        if (_bodies[i]->getPhysicsDeletionMark() != 0) {
            remove(i, _bodies[i]->getPhysicsDeletionMark() - 1);
            i--;
            continue;
        }
        if (_player->isColliding(_bodies[i])){
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

void PhysicsServer::remove(int i, bool clear) {
    if (clear)
        delete _bodies[i];
    _bodies[i] = _bodies[--_size];
    _bodies[_size] = nullptr;
}

void PhysicsServer::Clear(bool soft) {
    if (soft) {
        for (int i = 0; i < _size; i++) {
            _bodies[i] = nullptr;
        }
    } else {
        for (int i = 0; i < _size; i++) {
            if (_bodies[i] != nullptr) {
                delete _bodies[i];
                _bodies[i] = nullptr;
            }
        }
        delete _player;
        _player = nullptr;
    }
    _size = 0;
}
