//
// Created by wailer on 05/03/2022.
//

#include "Collider.h"

double absf(double n) {
    if (n < 0) return -n;
    return n;
}

bool Collider::isColliding(std::shared_ptr<Collider> col,
                           bool alternative) const {
    Vector2 ext1 = getDimensions(alternative) * .5;
    Vector2 ext2 = col->getDimensions(alternative) * .5;

    Vector2 center1 = getColliderPosition(alternative) + ext1;
    Vector2 center2 = col->getColliderPosition(alternative) + ext2;

    return (absf(center1.x - center2.x) <= ext1.x + ext2.x) &&
           (absf(center1.y - center2.y) <= ext1.y + ext2.y);
}

int Collider::getPhysicsId() const { return _physics_id; }

void Collider::setPhysicsId(int physicsId) { _physics_id = physicsId; }

PlayerInteraction Collider::getPlayerInteraction() const {
    return _player_interaction;
}
