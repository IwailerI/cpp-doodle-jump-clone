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

Platform::Platform(Vector2 position): Sprite()
{
    _sprite = ResourceManager::Instance().sprite_platform;
    _oneway = true;
    _player_interaction = Bounce;
    _position = position;
}

Vector2 Platform::getPosition() const {
    return _position;
}

Vector2 Platform::getDimensions() const {
    return GetImageSize();
}

void Platform::onCollision(Collider *col) {
    // do nothing
}