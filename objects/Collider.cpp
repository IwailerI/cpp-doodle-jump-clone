//
// Created by wailer on 05/03/2022.
//

#include "Collider.h"

double absf(double n) {if (n<0) return -n; return n;}

bool Collider::isColliding(Collider *col) const {
    Vector2 ext1 = getDimensions() * .5;
    Vector2 ext2 = col->getDimensions() * .5;

    Vector2 center1 = getPosition() + ext1;
    Vector2 center2 = col->getPosition() + ext2;

    bool colliding = (absf(center1.x-center2.x) <= ext1.x + ext2.x) && (absf(center1.y-center2.y) <= ext1.y + ext2.y);

    if (col->isOneway()) {
        colliding = colliding && getColliderVelocity().y > 0;
    }

    return colliding;
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
