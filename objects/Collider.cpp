//
// Created by wailer on 05/03/2022.
//

#include "Collider.h"

bool Collider::isColliding(Collider *col) const {
    Vector2 position = getPosition();
    Vector2 colPosition = col->getPosition();

    Vector2 p1 = colPosition + col->getDimensions();
    Vector2 p2 = position + getDimensions();


    // return pos is within other col or pos+dimensions is within other col
    return ((position.x <= p2.x && position.x >= colPosition.x) || (p1.x <= p2.x && p1.x >= colPosition.x))
                       && ((position.y <= p2.y && position.y >= colPosition.y) || (p1.y <= p2.y && p1.y >= colPosition.y));
}

int Collider::getPhysicsId() const {
    return _physics_id;
}

void Collider::setPhysicsId(int physicsId) {
    _physics_id = physicsId;
}

Vector2 Collider::getColliderVelocity() const {
    return {0, 0};
}

int Collider::getPlayerInteraction() const {
    return _player_interaction;
}
