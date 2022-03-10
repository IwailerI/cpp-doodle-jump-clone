//
// Created by wailer on 10/03/2022.
//

#include "Platform.h"

void Platform::_update() {
    if (GameObject::_position.y >= DELETE_TRESHOLD) {
        _suicide();
    }
}

void Platform::_suicide() {
    if (_marked_for_object_deletion != 0 || _marked_for_physics_deletion != 0) return;

    _visible = false;
    if (_physics_id != -1 && _object_id != -1) {
        markForObjectDeletion(true);
        markForPhysicsDeletion(false);
    } else if (_object_id != -1) {
        markForObjectDeletion(true);
    } else if (_physics_id != -1) {
        markForPhysicsDeletion(true);
    } else
        delete this;
}

Platform::Platform(Vector2 position):
    Sprite(al_map_rgb(255, 255, 0), Vector2(100, 20))
    {
    _oneway = true;
    _player_interaction = Bounce;
    _position = position;
}

const Vector2 &Platform::getPosition() const {
    return _position;
}

const Vector2 &Platform::getDimensions() const {
    return _dimensions;
}

void Platform::onCollision(Collider *col) {
    // do nothing
}